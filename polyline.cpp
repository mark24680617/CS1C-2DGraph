#include "polyline.h"


void PolyLine::set_point(const QPoint& point)
{
    points.push_back(point);
}

void PolyLine::draw(const int translate_x, const int translate_y)
{
    get_qpainter().setPen(get_pen());
    get_qpainter().setBrush(get_brush());

    //get_qpainter().save(); may not need
    //get_qpainter().translate(translate_x, translate_y); dont worry/ dont need

    //get_qpainter().drawPolyline(points.begin(), points.size()); //Review: There are no function to call drawPolyline

    get_qpainter().restore();
}
