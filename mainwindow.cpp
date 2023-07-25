#include "mainwindow.h"
#include "qpainter.h"
#include "qpen.h"
#include "ui_mainwindow.h"
#include "contact.h"
#include "login.h"
#include "line.h"
#include "shape.h"
#include "polygon.h"
#include "polyline.h"
#include "readFile.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readFile file("../shapes.txt");
    results = file.getVector();
    update();

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    /*
    QMainWindow::paintEvent(event); // Call the base class paintEvent

    QPainter painter(this);

    // Set the pen and brush properties for the rectangle
    QPen pen(Qt::blue);
    pen.setWidth(2);
    painter.setPen(pen);

    QBrush brush(Qt::yellow, Qt::DiagCrossPattern);
    painter.setBrush(brush);

    // Draw the rectangle with the specified coordinates (x, y, width, height)
    int x = 50;
    int y = 50;
    int width = 200;
    int height = 100;
    painter.drawRect(x, y, width, height);*/

    // THIS IS MANUALLY ENTERING THE INFO!!! NOT USING PARSER OR VECTOR YET!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! <--- IMPORTANT! - daniel
    /*
    int offsetX = 150;
    int offsetY = 150;


    QMainWindow::paintEvent(event);
    QPainter painter(this);

    Line line(this);
    line.set_points(QPoint(20, 90 + offsetY), QPoint(100, 20 + offsetY));
    line.set_pen(Qt::blue, 2, Qt::DashDotLine, Qt::FlatCap, Qt::MiterJoin);

    line.draw(painter, 0, 0);

    polygon poly(this); // Assuming the QPaintDevice* is the main window itself
    poly.set_point(QPoint(20 + offsetX, 90 + offsetY));
    poly.set_point(QPoint(100 + offsetX, 20 + offsetY));
    poly.set_point(QPoint(120 + offsetX, 100 + offsetY));

    // Set the pen and brush properties for the polygon
    poly.set_pen(Qt::blue, 2, Qt::DashDotLine, Qt::FlatCap, Qt::MiterJoin);
    poly.set_brush(Qt::yellow, Qt::DiagCrossPattern);

    // Draw the polygon
    poly.draw(painter, 0, 0);

    PolyLine polyline(this); // Assuming the QPaintDevice* is the main window itself
    int polylineOffsetX = 300; // Adjust this value to control the distance between the Polygon and PolyLine
    polyline.set_point(QPoint(20 + polylineOffsetX, 90 + offsetY));
    polyline.set_point(QPoint(100 + polylineOffsetX, 20 + offsetY));
    polyline.set_point(QPoint(120 + polylineOffsetX, 100 + offsetY));
    polyline.set_pen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);
    polyline.draw(painter, 0, 0);
*/

    QMainWindow::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    readFile file("../shapes.txt");


    results = file.getVector();
    for(Shape* a : results){
        qDebug()<<a->getID()<<endl;
        qDebug()<<a->perimeter()<<endl;

        a->draw(painter , 0 , 0);
    }
}



MainWindow::~MainWindow()
{
    for (Shape* shape : results) {
        delete shape;
    }
    results.clear();
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


void MainWindow::on_pushButton_3_clicked()  // line
{

}


void MainWindow::on_pushButton_4_clicked()  // polyline
{

}


void MainWindow::on_pushButton_5_clicked()  // polygon
{

}

