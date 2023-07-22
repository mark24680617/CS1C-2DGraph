#include "Ellipse.h"
void Ellipse::set_rect(const QRect& rect)
{
    this->rect = rect;
}
/*
void Ellipse::draw(const int translate_x, const int translate_y)
{
    get_qpainter().setPen(get_pen());
    get_qpainter().setBrush(get_brush());

    QRect translatedRect(rect.x() + translate_x, rect.y() + translate_y,
                         rect.width(), rect.height());

    get_qpainter().drawEllipse(translatedRect);

    get_qpainter().restore();
}*/

double Ellipse::perimeter() const
{
    // Approximation using the Ramanujan's formula
    double a = rect.width() / 2.0;
    double b = rect.height() / 2.0;
    return M_PI * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
}

double Ellipse::area() const
{
    return M_PI * (rect.width() / 2.0) * (rect.height() / 2.0);
}
