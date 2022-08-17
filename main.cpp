#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QGridLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //QWidget *centralWidget =  new QWidget(&w);

    QGridLayout * layout = new QGridLayout();
    layout->addWidget(new QPushButton("Button 1"),0,0);
    layout->addWidget(new QPushButton("Button 2"),0,1);
    //layout->addWidget(new QPushButton("Button 3"),0,2);

    QPushButton *pb0 = new QPushButton("Button 3");
    pb0->setMaximumSize(100,100);
    pb0->setMinimumSize(30,30);
    layout->addWidget(pb0,0,2);

    QPushButton *pb1 = new QPushButton("Button 4");
    pb1->setMaximumSize(100,100);
    pb1->setMinimumSize(10,10);
    layout->addWidget(pb1,1,2);

    //centralWidget->setLayout(layout);
    //w.setCentralWidget(centralWidget);
    w.show();

    return a.exec();
}
