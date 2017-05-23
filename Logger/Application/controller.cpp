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

#include "controller.h"

#include <QDebug>
#include <QFile>
#include <QStringList>

#include "logcfg.h"
#include "logcfgfactory.h"
#include "logconfig.h"

const QString Controller::LOG_CONFIG_FILE_NAME = "logger.conf";

Controller::Controller()
{
}

Controller::~Controller()
{

}

void Controller::init()
{
    this->initLogger();
}

void Controller::initLogger()
{
    LogConfig logConfig;
    if (this->readLogConfigFile(LOG_CONFIG_FILE_NAME, logConfig)) {
        qDebug() << "Find file log config";
        LogCfg::FileSinkCfg lcfg;

        lcfg.sync = logConfig.getSync();
        lcfg.dir = logConfig.getDir();
        lcfg.namePrefix = logConfig.getNamePrefix();
        lcfg.fileSize = logConfig.getFileSize();
        lcfg.collectionSize = logConfig.getCollectionSize();

        // set console level and add to log console config
        lcfg.level = logConfig.getConsoleLevel();

        LogCfgFactory::getLogCfg()->setConsoleCfg(lcfg);

        // set file level and add to log file config
        lcfg.level = logConfig.getFileLevel();

        LogCfgFactory::getLogCfg()->setFileCfg(lcfg);
    } else {
        qDebug() << "Not find file log config";
        LogCfg::FileSinkCfg lcfg;

        lcfg.sync = "true";
        lcfg.dir = "log/";
        lcfg.namePrefix = "app_";
        lcfg.fileSize = 100 * 1024 * 1024;
        lcfg.collectionSize = 10 * lcfg.fileSize;

        // set console level and add to log console config
        lcfg.level = 4;
        LogCfgFactory::getLogCfg()->setConsoleCfg(lcfg);

        // set file level and add to log file conCONFIG += staticlibfig
        lcfg.level = 4;
        LogCfgFactory::getLogCfg()->setFileCfg(lcfg);
    }
}

bool Controller::readLogConfigFile(const QString &filePath, LogConfig &logConfig)
{
    QFile inputFile(filePath);
    if (inputFile.open(QIODevice::ReadOnly)) {
        QTextStream in(&inputFile);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList strList = line.split("=");
            if (strList.size () == 2) {
                if (strList[0].trimmed () == "sync") logConfig.setSync(strList[1].trimmed() == "1" ? true : false);
                else if (strList[0].trimmed() == "dir") logConfig.setDir(strList[1].trimmed().toStdString());
                else if (strList[0].trimmed() == "namePrefix") logConfig.setNamePrefix(strList[1].trimmed().toStdString());
                else if (strList[0].trimmed() == "fileSize") logConfig.setFileSize(strList[1].trimmed().toLongLong());
                else if (strList[0].trimmed() == "collectionSize") logConfig.setCollectionSize(strList[1].trimmed().toLongLong());
                else if (strList[0].trimmed() == "consoleLevel") logConfig.setConsoleLevel(strList[1].trimmed().toInt());
                else if (strList[0].trimmed() == "fileLevel") logConfig.setFileLevel(strList[1].trimmed().toInt());
            }
        }
        inputFile.close();
        return true;
    } else {
        return false;
    }
}
