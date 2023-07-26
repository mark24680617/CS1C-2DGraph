#include "Rectangle.h"

void Rectangle::set_points(const vector<QPoint>& pointsList)
{
    this->top_left = pointsList[0];
    this->bottom_right = pointsList[1];
}

void Rectangle::set_points(const QPoint& top_left, const QPoint& bottom_right)
{
    this->top_left = top_left;
    this->bottom_right = bottom_right;
}

void Rectangle::draw(QPainter& painter, const int translate_x, const int translate_y)
{
    painter.setPen(get_pen());
    painter.setBrush(get_brush());

    QRect rect(top_left.x() + translate_x, top_left.y() + translate_y,
               bottom_right.x() - top_left.x(), bottom_right.y() - top_left.y());

    painter.drawRect(rect);

    //painter.restore();
}

double Rectangle::perimeter() const
{
    double width = bottom_right.x() - top_left.x();
    double height = bottom_right.y() - top_left.y();
    return 2 * (width + height);
}

double Rectangle::area() const
{
    double width = bottom_right.x() - top_left.x();
    double height = bottom_right.y() - top_left.y();
    return width * height;
}
