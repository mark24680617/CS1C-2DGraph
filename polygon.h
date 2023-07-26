#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
class polygon : public Shape
{
public:
    // What: The constructor
    // Pre-Condition: None
    // Post-Condition: The object gets constructed with the passed in parameters device and id
    polygon(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, shapeType::Polygon} {};

    // What: The destructor
    // Pre-Condition: The object is still in a valid state
    // Post-Condition: The object gets destructed and put into an invalid state
    ~polygon() override{ }

    // What: Sets the points
    // Pre-Condition: None
    // Post-Condition: pushes back the passed in point into the points vector
    void set_point(const QPoint& point);

    // What: Polygon Drawn
    // Pre-Condition: None
    // Post-Condition: The polygon gets drawn using the vector of points
    void draw(QPainter& painter, const int translate_x = 0, const int translate_y = 0) override;

    // What: Gets perimeter
    // Pre-Condition: None
    // Post-Condition: The perimeter gets returned to caller
    double perimeter() const override;

    // What: Gets area
    // Pre-Condition: None
    // Post-Condition: The area gets returned to caller
    double area() const override;

private:
    vector<QPoint> points;
};

#endif // POLYGON_H
