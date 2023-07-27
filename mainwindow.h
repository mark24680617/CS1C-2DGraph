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
    /**
     * @brief MainWindow constructor for mainwindow
     * @param parent QWidget
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief destructor
     */
    ~MainWindow();

    /**
     * @brief updateLists helper function to update combo_box id list
     */
    void updateLists();



protected:
    //void paintEvent(QPaintEvent *event) override;

private slots:

    /**
     * @brief on_pushButton_clicked page to contact us page
     */
    void on_pushButton_clicked();

    /**
     * @brief on_pushButton_2_clicked page to log in page
     */
    void on_pushButton_2_clicked();

    /**
     * @brief on_pushButton_3_clicked button to add shapes to vector
     */
    void on_pushButton_3_clicked();

    /**
     * @brief on_pushButton_5_clicked button to add text to vector
     */
    void on_pushButton_5_clicked();

    /**
     * @brief on_pushButton_4_clicked button to remove shape
     */
    void on_pushButton_4_clicked();

    /**
     * @brief on_save_button_clicked button to save stuff to file
     */
    void on_save_button_clicked();

    /**
     * @brief setLoggedIn helper function to set log in
     */
    void setLoggedIn();

    /**
     * @brief on_pushButton_6_clicked button to modify dimensions for shapes
     */
    void on_pushButton_6_clicked();

    //void on_comboBox_move_activated(int index);

    //void on_comboBox_remove_activated(int index);

private:
    Ui::MainWindow *ui;     /*!ui for mainwindow*/
    vector<Shape*> results; /*!main vector to store shape info*/
    canvas* canvas1;        /*!pointer to canvase object*/
    bool loggedin = false;  /*!logged in value*/

};
#endif // MAINWINDOW_H
