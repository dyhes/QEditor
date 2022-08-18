#ifndef EXPLORER_H
#define EXPLORER_H

#include <QWidget>
#include "helper.h"
class Explorer : public QWidget
{
    Q_OBJECT
public:
    explicit Explorer(QWidget *parent = nullptr);
    QTreeWidget *fileTree;
    QVBoxLayout *layout;
    QLabel *header;
    void addRootDir(QDir dir);
private:
    void addNode(QFileInfo &info,QTreeWidgetItem *root);
    void setupLayout();
signals:

public slots:
};

#endif // EXPLORER_H
