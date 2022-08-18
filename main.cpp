#include "mainwindow.h"
#include <QApplication>
#include "helper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

void myDebug(QString str){
    qDebug()<<str<<endl;
}

void myDebug(int num){
    qDebug()<<QString::number(num)<<endl;
}
