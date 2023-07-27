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



myStd::vector<int> stringToInt(string number){
    int currentNum = 0;
        myStd::vector<int> list;
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

myStd::vector<QPoint> getPoint(myStd::vector<int>& source){
    int limit = source.size();
    myStd::vector<QPoint> result;
        for(int i=0;i<limit;i=i+2){
            QPoint temp(source[i] , source[i+1]);
            result.push_back(temp);
        }
    return result;
}

Shape* getLine(int id , myStd::vector<QPoint> points , string color, int w, string penStyle , string cap , string join){
    Line* line = new Line;
    line->set_shapeID(id);
    line->set_points(points[0] , points[1]);
    line->set_pen(getColor(color) , w , getPenStyle(penStyle) , getCapStyle(cap) , getJoinStyle(join) );
    return line;
}

Shape* getPolyline(int id , myStd::vector<QPoint> points , string color, int w, string penStyle , string cap , string join){
    PolyLine * newPoly= new PolyLine;
    newPoly->set_shapeID(id);

    for(QPoint a : points)
        newPoly->set_point(a);

    newPoly->set_pen(getColor(color) , w , getPenStyle(penStyle) , getCapStyle(cap) , getJoinStyle(join) );
    return newPoly;
}

Shape* getPolygon(int id , myStd::vector<QPoint> points , string color, int w, string penStyle , string cap , string join , string bColor , string bStyle){
    polygon * newPoly= new polygon;
    newPoly->set_shapeID(id);

    for(QPoint a : points)
        newPoly->set_point(a);

    newPoly->set_pen(getColor(color) , w , getPenStyle(penStyle) , getCapStyle(cap) , getJoinStyle(join) );
    newPoly->set_brush(getColor(bColor) , getBrushStyle(bStyle));
    return newPoly;
}

Shape* getRectangle(int id , myStd::vector<QPoint> points , string color, int w, string penStyle , string cap , string join , string bColor , string bStyle){

    Rectangle*newRec = new Rectangle;
    newRec->set_shapeID(id);

    newRec->set_points(points[0] , points[1]);
    newRec->set_pen(getColor(color) , w , getPenStyle(penStyle) , getCapStyle(cap) , getJoinStyle(join) );
    newRec->set_brush(getColor(bColor) , getBrushStyle(bStyle));

    return newRec;
}

Shape * getEllipce(int id , myStd::vector<int> number , string color, int w, string penStyle , string cap , string join , string bColor , string bStyle){
    Ellipse* newEll = new Ellipse;
    newEll->set_shapeID(id);
    QRect rec(number[0],number[1],number[2],number[3]);
    newEll->set_rect(rec);

    newEll->set_pen(getColor(color) , w , getPenStyle(penStyle) , getCapStyle(cap) , getJoinStyle(join) );
    newEll->set_brush(getColor(bColor) , getBrushStyle(bStyle));

    return newEll;
}

Shape* getSqure(int id , myStd::vector<int> number , string color, int w, string penStyle , string cap , string join , string bColor , string bStyle){

    Rectangle* newS = new Rectangle;
    newS->set_shapeID(id);


    int length = number[0]-number[2];
    QPoint topLeft(number[0] , number[1]);
    QPoint buttomRight (number[2] , number[1]-length);

    newS->set_points(topLeft , buttomRight);

    newS->set_pen(getColor(color) , w , getPenStyle(penStyle) , getCapStyle(cap) , getJoinStyle(join) );
    newS->set_brush(getColor(bColor) , getBrushStyle(bStyle));

    return newS;
}

Shape* getCircle(int id , myStd::vector<int> number , string color, int w, string penStyle , string cap , string join , string bColor , string bStyle){

    Ellipse *newC= new Ellipse;
    newC->set_shapeID(id);

    QRect rec(number[0],number[1],number[2] , number[2]);

    newC->set_rect(rec);

    newC->set_pen(getColor(color) , w , getPenStyle(penStyle) , getCapStyle(cap) , getJoinStyle(join) );
    newC->set_brush(getColor(bColor) , getBrushStyle(bStyle));
    return newC;
}

void MainWindow::updateLists() {
    int size = results.size();
    for(int i=0;i<size;i++){
        QString a=QString::number(results[i]->getID());
        ui->comboBox_remove->addItem(a);
        ui->comboBox_move->addItem(a);
    }
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

    updateLists();

    canvas1->setShapes(results);
    ui->tabWidget->setDisabled(true);


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
    delete canvas1;
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
    myStd::vector<int> dTion=stringToInt(dimentions);
    myStd::vector<QPoint> points=getPoint(dTion);

    switch (type) {
    case 0:
        results.push_back(getLine(id , points , color , penW , penStyle , penCap , penJoin));  // line
        break;
    case 1:
        results.push_back(getPolyline(id , points , color , penW , penStyle , penCap , penJoin));  // polyline
        break;
    case 2:
        results.push_back(getPolygon(id , points , color , penW , penStyle , penCap , penJoin, bColor , bStyle));  // polygon
        break;

        // rectangle
    case 3: results.push_back(getRectangle(id , points , color , penW , penStyle , penCap , penJoin, bColor , bStyle));
        break;

        // ellipse
    case 4: results.push_back(getEllipce(id , dTion , color , penW , penStyle , penCap , penJoin, bColor , bStyle));
        break;
        // squre
    case 5: results.push_back(getSqure(id , dTion , color , penW , penStyle , penCap , penJoin, bColor , bStyle));
        break;
        // circle
    case 6: results.push_back(getCircle(id , dTion , color , penW , penStyle , penCap , penJoin, bColor , bStyle));
        break;
    }

    canvas1->setShapes(results);

}

void MainWindow::on_pushButton_5_clicked()  // remove button
{
    QString data= ui->comboBox_remove->currentText();
    int id = data.toInt();
    int sizeResult = results.size();
    for(int i=0 ; i<sizeResult;i++){
        if(id == results[i]->getID()){
           results.erase(results.begin()+i);
           break;
        }
    }

    ui->comboBox_remove->clear();
    updateLists();

    canvas1->setShapes(results);
}


void MainWindow::on_pushButton_4_clicked() { // add text {

    Text *newText = new Text;

     int id = ui->lineEdit_textID->text().toInt();
    newText->set_shapeID(id);

    string dimentions = ui->lineEdit_textD->text().toStdString();
    myStd::vector<int> dTion=stringToInt(dimentions);
    myStd::vector<QPoint> points=getPoint(dTion);
    newText->set_points(points[0] , points[1]);

    QString Qtext = ui->lineEdit_TEXT->text() ;
    newText->set_text(Qtext);

    string color = ui->lineEdit_textColor->text().toStdString();
    newText->set_text_color(getColor(color));

    string alignment = ui->lineEdit_alignment->text().toStdString();
    newText->set_text_alignment(getAlignment(alignment));

    int w = ui->lineEdit_textSize->text().toInt();
    newText->set_text_point_size(w);

    QString fontFamily = ui->lineEdit_fontFamily->text();
    string fontStyle = ui->lineEdit_fontStyle->text().toStdString();
    string fontWeight = ui->lineEdit_fontWeight->text().toStdString();

    newText->set_text_font(fontFamily , getTextFontStyle(fontStyle), getTextFontWeight(fontWeight));

    results.push_back(newText);

    canvas1->setShapes(results);
}

void MainWindow::setLoggedIn() {
    qDebug()<<"Logged In"<<endl;
    ui->tabWidget->setVisible(true);
}

void MainWindow::on_save_button_clicked()
{
    //write below for saving the vector info to a file
}

void MainWindow::on_pushButton_6_clicked() //Move button clicked
{
    QString data= ui->comboBox_move->currentText();
    int id = data.toInt();
    int sizeResult = results.size();

    for(int i = 0 ; i < sizeResult; ++i){
        if (id == results[i]->getID()){
            Shape *selectedShape = results[i];
            myStd::vector<int> pointCoords = stringToInt(ui->lineEdit_coords->text().toStdString());
            myStd::vector<QPoint> points;

            //Ensure the text box was filled
            if (pointCoords.size() != 0) {
                points = getPoint(pointCoords);
                selectedShape->set_points(points);
            }
        }
    }

    canvas1->setShapes(results);

//    Shape::shapeType selectedShape = results[ui->lineEdit_20->text().toInt()]->get_shape();
}
