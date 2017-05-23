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

#ifndef LOGCFG_H
#define LOGCFG_H

#include <string>

class LogCfg
{
public:
    LogCfg();
    virtual ~LogCfg();

public:
    class StrmSinkCfg
    {
    public:
        int level; // 0 for no log, the higher level, the more log output
        bool sync; // 'true' for sync, 'false' for async

    public:
        StrmSinkCfg() :	level(3), sync(true) {}
    };

    class FileSinkCfg : public StrmSinkCfg
    {
    public:
        std::string dir;
        std::string namePrefix;
        std::string nameSuffix;

        size_t fileSize;
        size_t collectionSize;

    public:
        FileSinkCfg() :	dir("logs/"), namePrefix("app_"), nameSuffix(".log"), fileSize(10 * 1024 * 1024), collectionSize(100 * fileSize) {}
    };

public:
    virtual const StrmSinkCfg& getConsoleCfg() const;
    virtual void setConsoleCfg(const StrmSinkCfg& cfg);

    virtual const FileSinkCfg& getFileCfg() const;
    virtual void setFileCfg(const FileSinkCfg& cfg);

private:
    StrmSinkCfg consoleCfg;
    FileSinkCfg fileCfg;
};


#endif // LOGCFG_H
