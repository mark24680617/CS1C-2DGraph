#ifndef CONTACT_H
#define CONTACT_H

#include <QDialog>

namespace Ui {
class contact;
}

class contact : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief explicit constructor
     * @param parent QWidget
     */
    explicit contact(QWidget *parent = nullptr);

    /**
     * @brief read from the txt file and display on ui
     * @param filePath string file
     */
    void readAndDisplayFile(const QString& filePath);

    /**
     * @brief destructor
     */
    ~contact();

private slots:
    /**
     * @brief link to github
     */
    void on_linkgit_clicked();

    /**
     * @brief link to mainWindow
     */
    void on_backhome_clicked();

    /**
     * @brief send comment to txt file
     */
    void on_sendComment_clicked();


private:
    /**
     * ui for contact page
     */
    Ui::contact *ui;
};

#endif // CONTACT_H
