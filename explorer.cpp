#include "explorer.h"
#include <QPushButton>
#include <QTreeWidgetItem>
#include <QIcon>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QFont>

Explorer::Explorer(QWidget *parent) : QWidget(parent),header(new QLabel("Explorer")),layout(new QVBoxLayout),fileTree(new QTreeWidget)
{
    setupLayout();
}

void Explorer::addDir(QDir dir)
{
    //    QStringList a=QStringList();
    //    QTreeWidgetItem *imageItem1 =new QTreeWidgetItem(fileTree,a);
    //    QTreeWidgetItem *imageItem1_1 =new QTreeWidgetItem(imageItem1,QStringList(QString("1#车间")));
    //    imageItem1->addChild(imageItem1_1);
}

void Explorer::setupLayout()
{
    layout->addWidget(header);
    layout->addWidget(fileTree);
    layout->setMargin(0);
    layout->setSpacing(0);

    QFont font=QFont("Microsoft YaHei", 10, 75);
    header->alignment();
    header->setFont(font);
    header->setAlignment(Qt::AlignCenter);

    fileTree->setHeaderHidden(true);
    this->setLayout(layout);
}
