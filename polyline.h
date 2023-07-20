#ifndef POLYLINE_H
#define POLYLINE_H


#include "shape.h"

#include "qpaintdevice.h"
class PolyLine: public Shape
{
public:
    PolyLine(QPaintDevice* device = nullptr, int id = -1): Shape{device, id, shapeType::Polyline}{};
    ~PolyLine() override{}
    void set_point(const QPoint& point);
    void draw(const int translate_x = 0, const int translate_y = 0) override;
    double perimeter() const override {return 0;}
    double area() const override {return 0;}

private:
    vector<QPoint> points;
};

#endif // POLYLINE_H
