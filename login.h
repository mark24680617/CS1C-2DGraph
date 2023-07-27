#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief login constructor
     * @param parent QWidget
     */
    explicit login(QWidget *parent = nullptr);

    /**
     * @brief destructor
     */
    ~login();

signals:
    /**
     * @brief loggedInSignal signal to log in page
     */
    void loggedInSignal();

private slots:
    /**
     * @brief on_login_pushButton_clicked after log in page clicked
     */
    void on_login_pushButton_clicked();

private:
    /*!
     * \brief ui for log in page ui
     */
    Ui::login *ui;
};

#endif // LOGIN_H
