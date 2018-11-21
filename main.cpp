#include <QApplication>
#include <QFile>
#include "Widget.h"

void setStyle(const QString &qssFile)
{
    QFile qss(qssFile);
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    setStyle(":/style.qss");

    Widget w;
    w.show();

    return a.exec();
}
