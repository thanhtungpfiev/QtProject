/**
 * \author tungdt9 thanhtungpfiev@gmail.com
 *
 * \date 12/25/2016
 *
 * \class LogCfgFactory
 *
 * \brief
 *
 *
 */

#include "logcfgfactory.h"

#include "boostlogcfg.h"

LogCfgFactory::LogCfgFactory()
{
}

LogCfg *LogCfgFactory::getLogCfg()
{
    return BoostLogCfg::getInstance();
}
