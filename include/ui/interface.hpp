#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtWidgets>
#include <QLineEdit>


class Interface : public QMainWindow{
    Q_OBJECT;
    public:
        Interface();
    private:
        QWidget* window;
        QVBoxLayout* mainLayout;
        QLineEdit* editLogin;
        QLineEdit* editPassword;
        QPushButton* login; 
        QPushButton* registr;
        QPushButton* quit;

};

#endif
