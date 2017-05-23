/**
 * \author tungdt9 thanhtungpfiev@gmail.com
 *
 * \date 12/25/2016
 *
 * \class LogCfg
 *
 * \brief
 *
 *
 */

#include "logcfg.h"

LogCfg::LogCfg()
{
}

LogCfg::~LogCfg()
{

}

const LogCfg::StrmSinkCfg &LogCfg::getConsoleCfg() const
{
    return consoleCfg;
}

void LogCfg::setConsoleCfg(const LogCfg::StrmSinkCfg &cfg)
{
    consoleCfg = cfg;
}

const LogCfg::FileSinkCfg &LogCfg::getFileCfg() const
{
    return fileCfg;
}

void LogCfg::setFileCfg(const LogCfg::FileSinkCfg &cfg)
{
    fileCfg = cfg;
}
