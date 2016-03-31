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


class Interface : public QMainWindow{
    Q_OBJECT;
    public:
        Interface();
    public slots:
        void openRegisterWidget();
        void openMainWidget();
    private:
        QWidget* mainWidget;
        QWidget* registerWidget;

        QStackedWidget* stackedWidget;

        QVBoxLayout* mainLayout;
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

        NewWindow* myNewWindow;

};

#endif
