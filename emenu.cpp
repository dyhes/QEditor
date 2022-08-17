#include "emenu.h"
#include <QFileDialog>
#include <QMessageBox>

EMenu::EMenu(QWidget *parent) : QMenuBar(parent)
{
    fileMenu=new QMenu("File");
    this->addMenu(fileMenu);

    editMenu=new QMenu("Edit");
    this->addMenu(editMenu);

    runMenu=new QMenu("Run");
    this->addMenu(runMenu);

    helpMenu=new QMenu("Help");
    this->addMenu(helpMenu);

    openAct=new QAction("Open");
    openAct->setShortcut(tr("Ctrl+O"));
    fileMenu->addAction(openAct);

    saveAct=new QAction("Save");
    saveAct->setShortcut(tr("Ctrl+S"));
    fileMenu->addAction(saveAct);

    saveAsAct=new QAction("Save As");
    saveAsAct->setShortcut(tr("Ctrl+Shift+S"));
    fileMenu->addAction(saveAsAct);

    newFileAct=new QAction("New File");
    newFileAct->setShortcut(tr("Ctrl+N"));
    fileMenu->addAction(newFileAct);

    connect(openAct,SIGNAL(triggered()),this,SLOT(on_open_click()));
    connect(saveAct,SIGNAL(triggered()),this,SLOT(on_save_click()));
    connect(saveAsAct,SIGNAL(triggered()),this,SLOT(on_save_as_click()));
    connect(newFileAct,SIGNAL(triggered()),this,SLOT(on_new_file_click()));
}

void EMenu::on_open_click()
{
    QString file_path=QFileDialog::getOpenFileName();
    if(file_path.isEmpty())
        return;
    FILE *p =fopen(file_path.toStdString().data(),"r");
    if(p==NULL)
    {
        QMessageBox::information(this,"notify","open file failure.");
        return;
    }
    QString content;
    char buf[1024]={0};

    while(!feof(p)){
        content+=  fgets(buf,sizeof(buf),p);
    }
    fclose(p);
    editor->edit->setText(content);
}

void EMenu::on_save_click(){}

void EMenu::on_new_file_click(){}
void EMenu::on_save_as_click(){}
void EMenu::on_copy_click(){}
void EMenu::on_paste_click(){}
void EMenu::on_cut_click(){}
void EMenu::on_undo_click(){}
void EMenu::on_redo_click(){}
void EMenu::on_compile_click(){}
void EMenu::on_run_click(){}
