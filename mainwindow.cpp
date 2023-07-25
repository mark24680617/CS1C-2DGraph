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

vector<int> stringToInt(string number){
    int currentNum = 0;
        vector<int> list;
        int sizeString=number.size();
        // Traversing string
        for (int j=0;j<sizeString;j++) {
            // Checking if the element is number
          char c = number[j];
            if (c >= '0' && c <= '9') {
                currentNum = currentNum * 10 + (c - '0');
                if(number[j+1]==',' || number[j+1]=='\0'){
                  list.push_back(currentNum);
                  j++;
                  currentNum=0;
                }
            }
        }
   return list;
}

vector<QPoint> getPoint(vector<int>& source){
    int limit = source.size();
    vector<QPoint> result;

    if(limit==3){
        // write the code for squre and cirlce

    } else{
        for(int i=0;i<limit;i=i+2){
            QPoint temp(source[i] , source[i+1]);
            result.push_back(temp);
        }
    }
    return result;
}

Shape* getLine(int id , vector<QPoint> points , string color, int w, string penStyle , string cap , string join){
    Line* line = new Line;
    line->set_shapeID(id);
    line->set_points(points[0] , points[1]);
    line->set_pen(getColor(color) , w , getPenStyle(penStyle) , getCapStyle(cap) , getJoinStyle(join) );
    return line;
}

Shape* getPolyline(int id , vector<QPoint> points , string color, int w, string penStyle , string cap , string join){
    PolyLine * newPoly= new PolyLine;
    newPoly->set_shapeID(id);

    for(QPoint a : points)
        newPoly->set_point(a);

    newPoly->set_pen(getColor(color) , w , getPenStyle(penStyle) , getCapStyle(cap) , getJoinStyle(join) );
    return newPoly;
}

Shape* getPolygon(int id , vector<QPoint> points , string color, int w, string penStyle , string cap , string join , string bColor , string bStyle){
    polygon * newPoly= new polygon;
    newPoly->set_shapeID(id);

    for(QPoint a : points)
        newPoly->set_point(a);

    newPoly->set_pen(getColor(color) , w , getPenStyle(penStyle) , getCapStyle(cap) , getJoinStyle(join) );
    newPoly->set_brush(getColor(bColor) , getBrushStyle(bStyle));
    return newPoly;
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    canvas1 = new canvas(this);
    canvas1->setGeometry(10, 60, 1000, 1000);
    canvas1->show();

    readFile file("../shapes.txt");
    results = file.getVector();

    canvas1->setShapes(results);

}
/*
void MainWindow::paintEvent(QPaintEvent *event)
{

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
/*
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
*/


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



void MainWindow::on_pushButton_3_clicked()  // add shape
{

    int type = ui->comboBox->currentIndex();  // get the type of shape

    int id = ui->lineEdit->text().toInt();
    int penW = ui->lineEdit_width->text().toInt();
    string color = ui->lineEdit_Pcolor->text().toStdString();
    string penStyle = ui->lineEdit_penStyle->text().toStdString();
    string penCap = ui->lineEdit_cap->text().toStdString();
    string penJoin = ui->lineEdit_Join->text().toStdString();
    string dimentions = ui->lineEdit_D->text().toStdString();
    string bColor=ui->lineEdit_bColor->text().toStdString();
    string bStyle=ui->lineEdit_bStyle->text().toStdString();
    vector<int> dTion=stringToInt(dimentions);
    vector<QPoint> points=getPoint(dTion);

    switch (type) {
    case 0:
        results.push_back(getLine(id , points , color , penW , penStyle , penCap , penJoin));
        break;
    case 1:
        results.push_back(getPolyline(id , points , color , penW , penStyle , penCap , penJoin));
        break;
    case 2:
        results.push_back(getPolygon(id , points , color , penW , penStyle , penCap , penJoin, bColor , bStyle));
        break;
        /*
    case 3:
        results.push_back(getEllipse(id, points, color, penQ, penStyle, penCap, penJoin, bColor, bStyle));
        break;
    case 4:
        results.push_back(getRectangle(id, points, color, penQ, penStyle, penCap, penJoin, bColor, bStyle));
        break;
    */
    }
    update();
}


