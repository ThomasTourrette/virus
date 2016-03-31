#include "../../include/ui/newWindow.hpp"

NewWindow::NewWindow() : QMainWindow(){
    window = new QWidget;
    mainLayout = new QVBoxLayout;

    editLogin = new QLineEdit;
    editPassword = new QLineEdit;
    editPasswordAgain = new QLineEdit;
    valid = new QPushButton("valid");
    retrn = new QPushButton("return");


    mainLayout->addWidget(editLogin);
    mainLayout->addWidget(editPassword);
    mainLayout->addWidget(editPasswordAgain);
    mainLayout->addWidget(valid);
    mainLayout->addWidget(retrn);
    //QObject::connect(rtrn, SIGNAL(clicked()), qApp, SLOT(quit()));

    window->setLayout(mainLayout);

    setCentralWidget(window);
    setWindowTitle(tr("virus"));
}
