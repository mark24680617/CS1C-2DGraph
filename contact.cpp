#include "contact.h"
#include "ui_contact.h"
#include "mainwindow.h"
#include <QUrl>
#include <QDesktopServices>
#include <QFile>
#include <QTextStream>
#include <QDebug>

contact::contact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contact)
{
    ui->setupUi(this);
    readAndDisplayFile("../Review.txt");
}

contact::~contact()
{
    delete ui;
}

void contact::on_linkgit_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/mark24680617/CS1C-2DGraph", QUrl::TolerantMode));
}


void contact::on_backhome_clicked()
{
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


void contact::on_sendComment_clicked()
{
    QString fileName = "../Review.txt";  // File name
    QFile file(fileName);
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Failed to open file:" << file.errorString();
        return;
    }

    QTextStream out(&file);
    out << ui->userReview->toPlainText();

    file.close();
    ui->userReview->clear();
    readAndDisplayFile("../Review.txt");

}

void contact::readAndDisplayFile(const QString& filePath)
{
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file:" << file.errorString();
        return;
    }

    QTextStream in(&file);
    QString line;

    for (int i = 1; i <= 3; ++i) {
        if (in.atEnd()) {
            break;  // Break the loop if there are fewer lines in the file than labels
        }

        line = in.readLine();

        // Assign the line to the respective QLabel based on 'i'
        QString labelName = QString("user%1").arg(i);
        QLabel* label = findChild<QLabel*>(labelName);

        if (label) {
            label->setText(line);
        } else {
            qDebug() << "Label not found:" << labelName;
        }
    }

    file.close();
}
