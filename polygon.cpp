#include "shape.h"
#include "polygon.h"
#include <cmath>

myStd::vector<QPoint> polygon::get_points() const {
    myStd::vector<QPoint> pointsList;
    for (int i = 0; i < points.size(); ++i) {
        pointsList.push_back(points[i]);
    }

    return pointsList;
}

void polygon::set_points(const myStd::vector<QPoint>& pointsList)
{
    for (int i = 0; i < points.size() && i < pointsList.size(); ++i) {
        points[i] = pointsList[i];
    }

}

void polygon::set_point(const QPoint& point)
{
    points.push_back(point);
}


void polygon::draw(QPainter& painter, const int translate_x, const int translate_y)
{
    painter.setPen(get_pen());
    painter.setBrush(get_brush());

    //get_qpainter().save(); may not need
    //get_qpainter().translate(translate_x, translate_y); dont worry/ dont need

    painter.drawPolygon(&points[0], points.size()); //Review: There are no matching function to called drawPolygon // This may have fixed it

    //painter.restore(); SOMEONE MAY NEED THIS FOR THE MOVE FUNCTIONS
}

/* Wrong D: it wasnt accessing the last element
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
}*/

double polygon::perimeter() const
{
    double perimeter = 0.0;
    for (size_t i = 0; i < points.size() - 1; i++)
    {
        const QPoint& begin = points[i];
        const QPoint& end = points[i + 1];
        double sideLength = std::sqrt(std::pow(end.x() - begin.x(), 2) + std::pow(end.y() - begin.y(), 2));
        perimeter += sideLength;
    }

    // Handle the last side connecting the last and first points
    const QPoint& begin = points[points.size() - 1];
    const QPoint& end = points[0];
    double sideLength = std::sqrt(std::pow(end.x() - begin.x(), 2) + std::pow(end.y() - begin.y(), 2));
    perimeter += sideLength;

    return perimeter;
}


/* Wrong D:
double polygon::area() const
{
    double area;

    int j = (points.size() - 1);
    for(int i = 0; i < points.size(); i++)
    {
        area = area + (points[j].x() + points[i].x()) * (points[j].y() + points[i].y());
        j = i;
    };

    return abs(area / 2.0);
} */

double polygon::area() const
{
    double area = 0.0;

    unsigned int j = points.size() - 1;
    for (unsigned int i = 0; i < points.size(); i++)
    {
        area += (points[j].x() + points[i].x()) * (points[j].y() - points[i].y());
        j = i;
    }

    return std::abs(area) * 0.5;
}






