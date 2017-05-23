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

#ifndef LOGCFGFACTORY_H
#define LOGCFGFACTORY_H

class LogCfg;

class LogCfgFactory
{
public:
    LogCfgFactory();

public:
    static LogCfg *getLogCfg();

};

#endif // LOGCFGFACTORY_H
