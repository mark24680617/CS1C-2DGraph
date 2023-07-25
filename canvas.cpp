#include "canvas.h"
#include <QPainter>


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
    Q_UNUSED(event); // stop unused parimeter warnings

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    for (Shape* a : shapes)
    {
        a->draw(painter, 0, 0);
    }
}
