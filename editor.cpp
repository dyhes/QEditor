#include "editor.h"


Editor::Editor(QWidget *parent) : QWidget(parent),layout(new QVBoxLayout),efilebar(new EfileBar),edit(new QTextEdit)
{
    setupLayout();
}

void Editor::setupLayout()
{
    layout->addWidget(efilebar);
    layout->addWidget(edit);
    layout->setMargin(0);
    layout->setSpacing(0);
    this->setLayout(layout);

    efilebar->setFixedHeight(25);
}
