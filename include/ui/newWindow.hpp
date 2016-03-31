#ifndef NEWWINDOW_HPP
#define NEWWINDOW_HPP

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtWidgets>
#include <QLineEdit>


class NewWindow : public QMainWindow{
    Q_OBJECT;
    public:
        NewWindow();
    public slots:
    private:
        QWidget* window;
        QVBoxLayout* mainLayout;
        QLineEdit* editLogin;
        QLineEdit* editPassword;
        QLineEdit* editPasswordAgain;
        QPushButton* valid; 
        QPushButton* retrn;
};

#endif

