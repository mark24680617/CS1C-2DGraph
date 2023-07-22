#ifndef LINE_H
#define LINE_H


#include "shape.h"
class Line: public Shape
{
public:
    Line(QPaintDevice* device = nullptr, int id = -1): Shape{device, id, shapeType::Line}
    {}
    ~Line() override {}

    void set_points(const QPoint& point_begin, const QPoint& point_end);
    void draw(QPainter& painter, const int translate_x = 0, const int translate_y = 0) override;
    double perimeter() const override;
    double area() const override {return 0;}

private:
    QPoint point_begin;
    QPoint point_end;

};


#endif // LINE_H
