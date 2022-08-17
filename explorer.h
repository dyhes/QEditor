#ifndef EXPLORER_H
#define EXPLORER_H

#include <QWidget>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QDir>

class Explorer : public QWidget
{
    Q_OBJECT
public:
    explicit Explorer(QWidget *parent = nullptr);
    QTreeWidget *fileTree;
    QVBoxLayout *layout;
    QLabel *header;
    void addDir(QDir dir);
private:
    void setupLayout();
signals:

public slots:
};

#endif // EXPLORER_H
