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

#ifndef BOOSTLOGCFG_H
#define BOOSTLOGCFG_H

#ifndef BOOST_ALL_DYN_LINK
#define BOOST_ALL_DYN_LINK
#endif

#include <boost/log/common.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/trivial.hpp>

#include "logcfg.h"

class BoostLogCfg : public LogCfg
{    
public:
    static BoostLogCfg *getInstance();

public:
    virtual void setConsoleCfg(const StrmSinkCfg &cfg);
    virtual void setFileCfg(const FileSinkCfg &cfg);

private:
    BoostLogCfg();
    virtual ~BoostLogCfg();
    boost::log::trivial::severity_level convertLogLevelToSeverity(int level);

private:
    static BoostLogCfg *theInstance;

private:
    typedef boost::log::sinks::text_ostream_backend StrmBackend;
    typedef boost::shared_ptr<StrmBackend> StrmBackendPtr;
    typedef boost::log::sinks::text_file_backend FileBackend;
    typedef boost::shared_ptr<FileBackend> FileBackendPtr;
    typedef boost::log::sinks::synchronous_sink<StrmBackend> SyncStrmSink;
    typedef boost::log::sinks::asynchronous_sink<StrmBackend> AsyncStrmSink;
    typedef boost::log::sinks::synchronous_sink<FileBackend> SyncFileSink;
    typedef boost::log::sinks::asynchronous_sink<FileBackend> AsyncFileSink;
    typedef boost::shared_ptr<boost::log::sinks::basic_sink_frontend> SinkPtr;

private:
    StrmBackendPtr consoleBackend;
    SinkPtr consoleSink;
    FileBackendPtr fileBackend;
    SinkPtr fileSink;

};

#endif // BOOSTLOGCFG_H
