#ifndef EXPLORER_H
#define EXPLORER_H

#include <QWidget>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <QLabel>

class Explorer : public QWidget
{
    Q_OBJECT
public:
    explicit Explorer(QWidget *parent = nullptr);
private:
    QTreeWidget *fileTree;
    QVBoxLayout *layout;
    QLabel *header;
private:
    void setupLayout();
signals:

public slots:
};

#endif // EXPLORER_H
