/**
 * \author tungdt9 thanhtungpfiev@gmail.com
 *
 * \date 12/25/2016
 *
 * \class
 *
 * \brief
 *
 *
 */

#include <QCoreApplication>

#include "boostlogger.h"
#include "controller.h"
#include "typedef.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ControllerPtr controller = ControllerPtr(new Controller());

    controller->init();

    LOG_INFO << "test";

    return a.exec();
}
