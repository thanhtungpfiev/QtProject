/**
 * \author thanhtung thanhtungpfiev@gmail.com
 *
 * \date 31 - 12 - 2016
 *
 * \class
 *
 * \brief
 *
 *
 */
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
