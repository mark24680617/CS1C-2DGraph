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
    explicit contact(QWidget *parent = nullptr);
    void readAndDisplayFile(const QString& filePath);

    ~contact();

private slots:
    void on_linkgit_clicked();

    void on_backhome_clicked();

    void on_sendComment_clicked();


private:
    Ui::contact *ui;
};

#endif // CONTACT_H
