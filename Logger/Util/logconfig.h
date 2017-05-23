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

#ifndef LOGCONFIG_H
#define LOGCONFIG_H

#include <string>

class LogConfig
{
public:
    LogConfig();

    bool getSync() const;
    void setSync(bool value);

    std::string getDir() const;
    void setDir(const std::string &value);

    std::string getNamePrefix() const;
    void setNamePrefix(const std::string &value);

    size_t getFileSize() const;
    void setFileSize(const size_t &value);

    size_t getCollectionSize() const;
    void setCollectionSize(const size_t &value);

    int getConsoleLevel() const;
    void setConsoleLevel(int value);

    int getFileLevel() const;
    void setFileLevel(int value);

private:
    bool sync;
    std::string dir;
    std::string namePrefix;
    size_t fileSize;
    size_t collectionSize;
    int consoleLevel;
    int fileLevel;
};

#endif // LOGCONFIG_H
