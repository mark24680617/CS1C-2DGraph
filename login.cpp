#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "mainwindow.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_login_pushButton_clicked()
{
    QString username = ui->username_LineEdit->text();
    QString password = ui->password_LineEdit->text();

    if(username == "Admin" && password == "password")
    {
        QMessageBox::information(this, "Login", "Logged in");
        // Emit the signal when the login is successful
        emit loggedInSignal();


        QList<QWidget*> topLevelWidgets = qApp->topLevelWidgets();
        foreach(QWidget *widget, topLevelWidgets) {
            QMainWindow *mainWindow = qobject_cast<QMainWindow*>(widget);
            if (mainWindow) {
                // Show the main window if it was previously hidden
                if (!mainWindow->isVisible()) {
                    mainWindow->show();

                }
                break;
            }
        }
        hide();


    }
    else
    {
        QMessageBox::warning(this, "Login", "Username or Password is Incorrect");
    }
}

