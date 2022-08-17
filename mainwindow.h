#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include "emenu.h"
#include <QGridLayout>
#include "esidebar.h"
#include "explorer.h"
#include "editor.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void setupLayout();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    EMenu *menubar;
    QGridLayout *layout;
    QWidget *central;
    ESideBar *sidebar;
    Explorer *explorer;
    Editor *editor;
};
#endif // MAINWINDOW_H
