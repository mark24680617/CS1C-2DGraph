#include "polyline.h"


void PolyLine::set_point(const QPoint& point)
{
    points.push_back(point);
}


void PolyLine::draw(QPainter& painter, const int translate_x, const int translate_y)
{
    painter.setPen(get_pen());
    painter.setBrush(get_brush());

    //get_qpainter().save(); may not need
    //get_qpainter().translate(translate_x, translate_y); dont worry/ dont need

    painter.drawPolyline(&points[0], points.size()); //Review: There are no function to call drawPolyline // This may have fixed it

    //painter.restore(); SOMEONE MAY NEED THIS FOR THE MOVE FUNCTIONS
}
// Euclidean distance formula for perimeter :D
double PolyLine::perimeter() const
{
    double perimeter = 0.0;

    for (size_t i = 0; i < points.size() - 1; i++)
    {
        const QPoint& begin = points[i];
        const QPoint& end = points[i + 1];
        double sideLength = std::sqrt(std::pow(end.x() - begin.x(), 2) + std::pow(end.y() - begin.y(), 2));
        perimeter += sideLength;
    }

    return perimeter;
}
