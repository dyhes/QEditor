#include "explorer.h"

Explorer::Explorer(QWidget *parent) : QWidget(parent),header(new QLabel("Explorer")),layout(new QVBoxLayout),fileTree(new QTreeWidget)
{
    setupLayout();
    connect(fileTree,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(open_in_editor(QTreeWidgetItem*,int)));
}

void Explorer::addRootDir(QDir dir)
{
    QTreeWidgetItem *root=new QTreeWidgetItem();
    root->setText(0,dir.dirName());
    root->setData(0,Qt::UserRole,dir.absolutePath());
    QFileInfoList children=dir.entryInfoList();
    for(auto& child:children){
        QString childname=child.fileName();
        if(childname=="."||childname=="..")continue;
        addNode(child,root);
    }
    fileTree->addTopLevelItem(root);
    root->setExpanded(true);
}

void Explorer::addNode(QFileInfo &info, QTreeWidgetItem *root)
{
    QTreeWidgetItem *child=new QTreeWidgetItem();
    QString path=info.absoluteFilePath();
    if(info.isDir()){
        QDir cur=QDir(path);
        child->setText(0,cur.dirName());
        child->setData(0,Qt::UserRole,path);
        QFileInfoList children=cur.entryInfoList();
        for(auto& achild:children){
            QString childname=achild.fileName();
            if(childname=="."||childname=="..")continue;
            addNode(achild,child);
        }
    }else{
        child->setText(0,info.fileName());
        child->setData(0,Qt::UserRole,path);
    }
    root->addChild(child);
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

void Explorer::open_in_editor(QTreeWidgetItem *item, int column)
{
    QString file_path=item->data(0,Qt::UserRole).toString();
    QFile file{file_path};
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    QTextStream in(&file);
    QString context{""};
    while(!in.atEnd()){
        context.append(in.readLine());
    }
    editor->edit->setText(context);
}
