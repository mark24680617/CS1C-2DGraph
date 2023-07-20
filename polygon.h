#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
class polygon : public Shape
{
public:
    polygon(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id shapeType::Polygon} {};
    ~polygon() override{ }
    void set_point(const QPoint& point);
    void draw(const int translate_x = 0, const int translate_y = 0) override;

    double perimeter() const override;
    double area() const override;

private:
    vector<QPoint> points;
};

#endif // POLYGON_H
