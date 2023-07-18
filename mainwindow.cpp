#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contact.h"
#include "login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    contact info;
    info.setModal(true);
    hide();
    info.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    login info;
    info.setModal(true);
    hide();
    info.exec();
}

