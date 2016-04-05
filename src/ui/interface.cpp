#include "../../include/ui/interface.hpp"
#include "../../include/ui/newWindow.hpp"
#include "../../include/databaseConnection/test_connection.hpp"

using namespace std;
using namespace pqxx;

Interface::Interface() : QMainWindow(){
    mainWidget = new QWidget;
    registerWidget = new QWidget;
    lobbyWidget = new QWidget;
    stackedWidget = new QStackedWidget;

    mainLayout = new QVBoxLayout;
    registerLayout = new QVBoxLayout;
    lobbyLayout = new QVBoxLayout;

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

    createGame = new QPushButton("create game");


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


    lobbyLayout->addWidget(createGame);

    mainWidget->setLayout(mainLayout);
    registerWidget->setLayout(registerLayout);
    lobbyWidget->setLayout(lobbyLayout);

    stackedWidget->addWidget(mainWidget);
    stackedWidget->addWidget(registerWidget);
    stackedWidget->addWidget(lobbyWidget);
    
    QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(registr, SIGNAL(clicked()), this, SLOT(openRegisterWidget()));
    QObject::connect(retrn, SIGNAL(clicked()), this, SLOT(openMainWidget()));
    QObject::connect(login, SIGNAL(clicked()), this, SLOT(connectionRequest()));
    QObject::connect(valid, SIGNAL(clicked()), this, SLOT(registerRequest()));


    
    testConnection = new TestConnection;
    testConnection->databaseConnection();
    
    setCentralWidget(stackedWidget);
    setWindowTitle(tr("virus"));
}

void Interface::connectionRequest(){
    int result;
    QString l = editLogin->text();
    QString p = editPassword->text();
    cout << l.toStdString() << endl;
    cout << p.toStdString() << endl;
    string request = "SELECT count(1) from registration where login = '"
            + l.toStdString() +"' and password = '" + p.toStdString() + "'";
    result = testConnection->sendSqlRequest(request.c_str());

    cout << "result: " << result << endl;
    if (result){
        cout << "login ok" << endl;
        stackedWidget->setCurrentWidget(lobbyWidget);
    }
    else{
        cout << "login failed" << endl;
        stackedWidget->setCurrentWidget(mainWidget);
    }
}

void Interface::registerRequest(){
    int validLogin;
    QString l = registerEditLogin->text();
    QString p = registerEditPassword->text();
    QString pAgain = registerEditPasswordAgain->text();
    if (p != pAgain) {
        registerEditPassword->clear();
        registerEditPasswordAgain->clear();
        cout << "error: passwords doesn't match" << endl;
        return;
    }

    string validLoginRequest = "SELECT count(1) from registration where login = '"
            + l.toStdString() +"'";

    validLogin = testConnection->sendSqlRequest(validLoginRequest.c_str());
    if (validLogin) {
        cout << "login already registered" << endl;
        return;
    }
    else {
        string request = "INSERT INTO registration(login, password) VALUES ('" + l.toStdString()
        + "', '" + p.toStdString() + "')";
        testConnection->sendSqlRequest(request.c_str());
    }
    

}

void Interface::openRegisterWidget(){
    cout << "register button clicked !" << endl;
    stackedWidget->setCurrentWidget(registerWidget);
}

void Interface::openMainWidget(){
    cout << "register button clicked !" << endl;
    stackedWidget->setCurrentWidget(mainWidget);
}

