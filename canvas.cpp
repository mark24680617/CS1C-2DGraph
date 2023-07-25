#include "canvas.h"
#include <QPainter>
//#include "mainwindow.h"

canvas::canvas(QWidget *parent) : QWidget(parent)
{

}

void canvas::setShapes(const vector<Shape*>& shapes)
{
    this->shapes = shapes;
    update(); // Trigger a repaint when the shapes are updated <--- THIS IS FOR CHANGING STUFF
}

void canvas::paintEvent(QPaintEvent *event)
{
    //Q_UNUSED(event); // stop unused parimeter warnings

    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    for (Shape* a : shapes)
    {
        qDebug()<<a->getID()<<endl;
        qDebug()<<a->perimeter()<<endl;
        a->draw(painter, 0, 0);
    }
}
