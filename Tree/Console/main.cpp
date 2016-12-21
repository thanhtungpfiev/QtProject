#include <QCoreApplication>

#include "util.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Util::test();

    return a.exec();
}
