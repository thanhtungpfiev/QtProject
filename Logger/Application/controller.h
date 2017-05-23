/**
 * \author tungdt9 thanhtungpfiev@gmail.com
 *
 * \date 12/25/2016
 *
 * \class Controller
 *
 * \brief
 *
 *
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QString>

class LogConfig;

class Controller
{
public:
    Controller();
    virtual ~Controller();

public:
    void init();

private:
    void initLogger();
    bool readLogConfigFile(const QString &filePath, LogConfig &logConfig);

private:
    static const QString LOG_CONFIG_FILE_NAME;
};

#endif // CONTROLLER_H
