#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QVBoxLayout>
#include "efilebar.h"
#include <QTextEdit>

class Editor : public QWidget
{
    Q_OBJECT
public:
    explicit Editor(QWidget *parent = nullptr);
    QVBoxLayout *layout;
    EfileBar *efilebar;
    QTextEdit *edit;
private:
    void setupLayout();
signals:

public slots:
};

#endif // EDITOR_H
