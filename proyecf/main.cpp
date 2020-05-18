#include "proyecfi.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    proyecfi w;
    w.show();
    return a.exec();
}
