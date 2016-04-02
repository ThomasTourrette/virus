#include "../../include/ui/interface.hpp"
#include "../../include/ui/newWindow.hpp"
#include "../../include/databaseConnection/test_connection.hpp"

using namespace std;
using namespace pqxx;

Interface::Interface() : QMainWindow(){
    mainWidget = new QWidget;
    registerWidget = new QWidget;
    stackedWidget = new QStackedWidget;

    mainLayout = new QVBoxLayout;
    registerLayout = new QVBoxLayout;

    editLogin = new QLineEdit;
    editPassword = new QLineEdit;
    login = new QPushButton("login");
    registr = new QPushButton("register");
    quit = new QPushButton("quit");
    
    registerEditLogin = new QLineEdit;
    registerEditPassword = new QLineEdit;
    registerEditPasswordAgain = new QLineEdit;
    valid = new QPushButton("valid");
    retrn = new QPushButton("return");


    mainLayout->addWidget(editLogin);
    mainLayout->addWidget(editPassword);
    mainLayout->addWidget(login);
    mainLayout->addWidget(registr);
    mainLayout->addWidget(quit);


    registerLayout->addWidget(registerEditLogin);
    registerLayout->addWidget(registerEditPassword);
    registerLayout->addWidget(registerEditPasswordAgain);
    registerLayout->addWidget(valid);
    registerLayout->addWidget(retrn);

    mainWidget->setLayout(mainLayout);
    registerWidget->setLayout(registerLayout);

    stackedWidget->addWidget(mainWidget);
    stackedWidget->addWidget(registerWidget);
    
    QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(registr, SIGNAL(clicked()), this, SLOT(openRegisterWidget()));
    QObject::connect(retrn, SIGNAL(clicked()), this, SLOT(openMainWidget()));
    QObject::connect(login, SIGNAL(clicked()), this, SLOT(dbConnection()));
    QObject::connect(valid, SIGNAL(clicked()), this, SLOT(registerRequest()));


    
    testConnection = new TestConnection;
    testConnection->databaseConnection();
    
    setCentralWidget(stackedWidget);
    setWindowTitle(tr("virus"));
}

void Interface::dbConnection(){
    testConnection->sendSqlRequest("SELECT * from person;");
}

void Interface::registerRequest(){
    testConnection->sendSqlRequest("INSERT INTO person VALUES ('vincent', 'mignolet', 28)");
    cout << "registerRequest" << endl;
}

void Interface::openRegisterWidget(){
    cout << "register button clicked !" << endl;
    stackedWidget->setCurrentWidget(registerWidget);
}

void Interface::openMainWidget(){
    cout << "register button clicked !" << endl;
    stackedWidget->setCurrentWidget(mainWidget);
}

