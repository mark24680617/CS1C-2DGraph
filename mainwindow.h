#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vector.h"
#include "shape.h"
#include "canvas.h"
#include "line.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateLists();



protected:
    //void paintEvent(QPaintEvent *event) override;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_save_button_clicked();

    void setLoggedIn();

    void on_pushButton_6_clicked();

    void on_comboBox_move_activated(int index);

    void on_comboBox_remove_activated(int index);

private:
    Ui::MainWindow *ui;
    vector<Shape*> results;
    canvas* canvas1;
    bool loggedin = false;

};
#endif // MAINWINDOW_H
