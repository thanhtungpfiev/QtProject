/**
 * \author tungdt9 thanhtungpfiev@gmail.com
 *
 * \date 12/25/2016
 *
 * \class LogConfig
 *
 * \brief
 *
 *
 */

#include "logconfig.h"
LogConfig::LogConfig()
{

}

bool LogConfig::getSync() const
{
    return sync;
}

void LogConfig::setSync(bool value)
{
    sync = value;
}

std::string LogConfig::getDir() const
{
    return dir;
}

void LogConfig::setDir(const std::string &value)
{
    dir = value;
}

std::string LogConfig::getNamePrefix() const
{
    return namePrefix;
}

void LogConfig::setNamePrefix(const std::string &value)
{
    namePrefix = value;
}

size_t LogConfig::getFileSize() const
{
    return fileSize;
}

void LogConfig::setFileSize(const size_t &value)
{
    fileSize = value;
}

size_t LogConfig::getCollectionSize() const
{
    return collectionSize;
}

void LogConfig::setCollectionSize(const size_t &value)
{
    collectionSize = value;
}

int LogConfig::getConsoleLevel() const
{
    return consoleLevel;
}

void LogConfig::setConsoleLevel(int value)
{
    consoleLevel = value;
}

int LogConfig::getFileLevel() const
{
    return fileLevel;
}

void LogConfig::setFileLevel(int value)
{
    fileLevel = value;
}

