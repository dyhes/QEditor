#ifndef EMENU_H
#define EMENU_H

#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

class EMenu : public QMenuBar
{
    Q_OBJECT
public:
    explicit EMenu(QWidget *parent = nullptr);
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *runMenu;
    QMenu *helpMenu;

    QAction *openAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *newFileAct;

    QAction *undoAct;
    QAction *redoAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *cutAct;

    QAction *compileAct;
    QAction *runAct;
signals:

public slots:
    void on_open_click();
    void on_save_click();
    void on_new_file_click();
    void on_save_as_click();

    void on_copy_click();
    void on_paste_click();
    void on_cut_click();
    void on_undo_click();
    void on_redo_click();

    void on_compile_click();
    void on_run_click();
};

#endif // EMENU_H
