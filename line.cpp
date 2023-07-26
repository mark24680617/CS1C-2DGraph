#include "line.h"

void Line::set_points(const vector<QPoint>& points) {
    this->point_begin = points[0];
    this->point_end = points[1];
}

void Line::set_points(const QPoint& point_begin, const QPoint& point_end)
{
    this->point_begin = point_begin;
    this->point_end = point_end;
}

void Line::draw(QPainter& painter, const int translate_x, const int translate_y)
{
    painter.setPen(get_pen());
    painter.setBrush(get_brush());


    painter.drawLine(point_begin, point_end);

    //get_qpainter().restore(); SOMEONE MAY NEED THIS FOR THE MOVE FUNCTIONS
}

//Euclidean distance formula
double Line::perimeter() const
{
    double perimeter = 0.0;

    const QPoint& begin = point_begin;
    const QPoint& end = point_end;
    perimeter = std::sqrt(std::pow(end.x() - begin.x(), 2) + std::pow(end.y() - begin.y(), 2));

    return perimeter;
}
