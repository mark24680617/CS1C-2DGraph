#include "shape.h"
#include "polygon.h"
#include <cmath>

void polygon::set_point(const QPoint& point)
{
    points.push_back(point);
}

void polygon::draw(const int translate_x, const int translate_y)
{
    get_qpainter().setPen(get_pen());
    get_qpainter().setBrush(get_brush());

    //get_qpainter().save(); may not need
    //get_qpainter().translate(translate_x, translate_y); dont worry/ dont need

    get_qpainter().drawPolygon(points.begin(), points.size());

    get_qpainter().restore();
}

double polygon::perimeter() const
{
    double perimeter;
    double other;
    other = 0;
    perimeter = 0;
    for (auto i = points.begin(); i != points.end(); i++)
    {
        QPoint begin = *i;
        QPoint end = *(i+1);
        other = 0;
        other = std::sqrt(std::pow(end.x() - begin.x(), 2) + std::pow(end.y() - begin.y(), 2));
        perimeter = perimeter + std::sqrt(other);
    }

    QPoint begin = *(points.end() - 1);
    QPoint end = *(points.begin());
    other = 0;

    other = std::sqrt(std::pow(end.x() - begin.x(), 2) + std::pow(end.y() - begin.y(), 2));
    perimeter += std::sqrt(other);
    return perimeter;
}

double polygon::area() const
{
    double area;

    int j = points.size() - 1)
    for(int i = 0; i < points.size(); i++)
    {
        area = area + (points[j].x() + points[i].x()) * (points[j].y() + points[i].y());
        j = i;
    };

    return abs(area / 2.0);
}








