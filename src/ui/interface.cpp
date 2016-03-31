#include "../include/ui/interface.hpp"

Interface::Interface() : QMainWindow(){
    window = new QWidget;
    mainLayout = new QVBoxLayout;

    editLogin = new QLineEdit;
    editPassword = new QLineEdit;
    login = new QPushButton("login");
    registr = new QPushButton("register");
    quit = new QPushButton("quit");


    mainLayout->addWidget(editLogin);
    mainLayout->addWidget(editPassword);
    mainLayout->addWidget(login);
    mainLayout->addWidget(registr);
    mainLayout->addWidget(quit);
    QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    window->setLayout(mainLayout);

    setCentralWidget(window);
    setWindowTitle(tr("virus"));
}
