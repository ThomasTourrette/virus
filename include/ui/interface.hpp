#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtWidgets>
#include <QLineEdit>
#include <QStackedWidget>
#include "newWindow.hpp"
#include "../../include/databaseConnection/test_connection.hpp"



class Interface : public QMainWindow{
    Q_OBJECT;
    public:
        Interface();
    public slots:
        void openRegisterWidget();
        void openMainWidget();
        void connectionRequest();
        void registerRequest();
    private:
        QWidget* mainWidget;
        QWidget* registerWidget;
        QWidget* lobbyWidget;

        QStackedWidget* stackedWidget;

        QVBoxLayout* mainLayout;
        QVBoxLayout* lobbyLayout;
        QLineEdit* editLogin;
        QLineEdit* editPassword;
        QPushButton* login; 
        QPushButton* registr;
        QPushButton* quit;

        QVBoxLayout* registerLayout;
        QLineEdit* registerEditLogin;
        QLineEdit* registerEditPassword;
        QLineEdit* registerEditPasswordAgain;
        QPushButton* valid;
        QPushButton* retrn;

        QPushButton* createGame;

        NewWindow* myNewWindow;

        TestConnection *testConnection;

};

#endif
