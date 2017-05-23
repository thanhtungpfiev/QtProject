/**
 * \author tungdt9 thanhtungpfiev@gmail.com
 *
 * \date 12/25/2016
 *
 * \class BoostLogCfg
 *
 * \brief
 *
 *
 */

#include "boostlogcfg.h"

#include <boost/core/null_deleter.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/trivial.hpp>

static const char *BOOST_LOG_FORMAT_TIMESTAMP = "%Y-%m-%d %H:%M:%S.%f";

#define ATTR_NAME_TIMESTAMP boost::log::aux::default_attribute_names::timestamp()
#define ATTR_NAME_THREADID boost::log::aux::default_attribute_names::thread_id()

#define BOOST_LOG_SET_FORMATTER(p) \
    (p)->set_formatter( \
    boost::log::expressions::stream \
    << boost::log::expressions::format_date_time<boost::posix_time::ptime>(ATTR_NAME_TIMESTAMP, BOOST_LOG_FORMAT_TIMESTAMP) \
    << " [" << boost::log::expressions::attr<boost::log::aux::thread::id>(ATTR_NAME_THREADID)<<"]" \
    << " [" << boost::log::trivial::severity<<"]" \
    << " " << boost::log::expressions::smessage \
    )

BoostLogCfg *BoostLogCfg::getInstance()
{
    if (!theInstance) {
        theInstance = new BoostLogCfg();
    }
    return theInstance;
}

BoostLogCfg *BoostLogCfg::theInstance = NULL;

void BoostLogCfg::setConsoleCfg(const LogCfg::StrmSinkCfg &cfg)
{
    if (consoleSink && getConsoleCfg().sync != cfg.sync) {
        boost::log::core::get()->remove_sink(consoleSink);
        consoleSink.reset();
    }

    LogCfg::setConsoleCfg(cfg);

    if (!consoleSink) {
        if (!consoleBackend) {
            consoleBackend = boost::make_shared<StrmBackend>();
            consoleBackend->add_stream(boost::shared_ptr<std::ostream>(&std::clog, boost::null_deleter()));
        }

        boost::log::sinks::basic_formatting_sink_frontend<StrmBackend::char_type> *sink =	NULL;
        if (getConsoleCfg().sync) {
            sink = new SyncStrmSink(consoleBackend);
        } else {
            sink = new AsyncStrmSink(consoleBackend);
        }

        BOOST_LOG_SET_FORMATTER(sink);

        consoleSink.reset(sink);
    }

    consoleSink->set_filter(boost::log::trivial::severity >= convertLogLevelToSeverity(getConsoleCfg().level));

    boost::log::core::get()->add_sink(consoleSink);
}

void BoostLogCfg::setFileCfg(const LogCfg::FileSinkCfg &cfg)
{
    const FileSinkCfg& currentCfg = getFileCfg();
    if (fileSink && (currentCfg.sync != cfg.sync || currentCfg.dir != cfg.dir
                     || currentCfg.namePrefix != cfg.namePrefix
                     || currentCfg.nameSuffix != cfg.nameSuffix
                     || currentCfg.fileSize != cfg.fileSize
                     || currentCfg.collectionSize != cfg.collectionSize)) {
        boost::log::core::get()->remove_sink(fileSink);
        fileSink.reset();
    }

    LogCfg::setFileCfg(cfg);

    if (currentCfg.level > 0) {
        if (!fileSink) {
            fileBackend.reset(new FileBackend(
                                  boost::log::keywords::file_name = currentCfg.dir + currentCfg.namePrefix + "%Y%m%d_%H%M%S"	+ currentCfg.nameSuffix,
                                  boost::log::keywords::open_mode = std::ios::app,
                                  boost::log::keywords::rotation_size = currentCfg.fileSize,
                                  boost::log::keywords::auto_flush = true));

            fileBackend->set_file_collector(boost::log::sinks::file::make_collector(boost::log::keywords::target = currentCfg.dir,
                                                                             boost::log::keywords::max_size = currentCfg.collectionSize));
            fileBackend->scan_for_files();

            boost::log::sinks::basic_formatting_sink_frontend<FileBackend::char_type> *sink = NULL;
            if (cfg.sync) {
                sink = new SyncFileSink(fileBackend);
            } else {
                sink = new AsyncFileSink(fileBackend);
            }

            BOOST_LOG_SET_FORMATTER(sink);

            fileSink.reset(sink);
        }

        fileSink->set_filter(boost::log::trivial::severity	>= convertLogLevelToSeverity(currentCfg.level));

        boost::log::core::get()->add_sink(fileSink);
    }
}

BoostLogCfg::BoostLogCfg()
{
    boost::log::core::get()->remove_all_sinks();

    boost::log::core::get()->add_global_attribute(ATTR_NAME_TIMESTAMP,	boost::log::attributes::local_clock());
    boost::log::core::get()->add_global_attribute(ATTR_NAME_THREADID,	boost::log::attributes::current_thread_id());

    setConsoleCfg(getConsoleCfg());
}

BoostLogCfg::~BoostLogCfg()
{

}

boost::log::trivial::severity_level BoostLogCfg::convertLogLevelToSeverity(int level)
{
    return (boost::log::trivial::severity_level)(boost::log::trivial::fatal - level);
}
