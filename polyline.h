#ifndef POLYLINE_H
#define POLYLINE_H


#include "shape.h"

#include "qpaintdevice.h"
class PolyLine: public Shape
{
public:
    // What: The constructor
    // Pre-Condition: None
    // Post-Condition: The object gets constructed with the passed in parameters
    PolyLine(QPaintDevice* device = nullptr, int id = -1): Shape{device, id, shapeType::Polyline}{};

    // What: The destructor
    // Pre-Condition: The object is still in a valid state
    // Post-Condition: The object gets deconstructed and put into an invalid state
    ~PolyLine() override{}

    // What: Sets the points
    // Pre-Condition: None
    // Post-Condition: The passed in parameter gets pushed back into the vector points
    void set_point(const QPoint& point);

    // What: Polyline drawn
    // Pre-Condition: None
    // Post-Condition: The polyline gets drawn using the vector of points
    void draw(QPainter& painter, const int translate_x = 0, const int translate_y = 0) override;

    // What: Gets perimeter
    // Pre-Condition: None
    // Post-Condition: The perimeter of the polyline gets returned to the caller
    double perimeter() const override;

    // What: Gets area
    // Pre-Condition: None
    // Post-Condition: The area of the polyline gets returned to the caller
    double area() const override {return 0;}

private:
    vector<QPoint> points;
};

#endif // POLYLINE_H
