#include "Rectangle.h"
void Rectangle::set_points(const QPoint& top_left, const QPoint& bottom_right)
{
    this->top_left = top_left;
    this->bottom_right = bottom_right;
}

void Rectangle::draw(const int translate_x, const int translate_y)
{
    get_qpainter().setPen(get_pen());
    get_qpainter().setBrush(get_brush());

    QRect rect(top_left.x() + translate_x, top_left.y() + translate_y,
               bottom_right.x() - top_left.x(), bottom_right.y() - top_left.y());

    get_qpainter().drawRect(rect);

    get_qpainter().restore();
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