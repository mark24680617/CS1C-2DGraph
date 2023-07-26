#ifndef LINE_H
#define LINE_H


#include "shape.h"
class Line: public Shape
{
public:
    // What: It constructs an object
    // Pre-Condition: None
    // Post-Condition: The object gets constructed with the passed in parameters device and id.
    Line(QPaintDevice* device = nullptr, int id = -1): Shape{device, id, shapeType::Line}
    {}

    // What: Destructs the object
    // Pre-Condition: The object is still in a valid state
    // Post-Condition: The object gets destructed
    ~Line() override {}

    // What: Sets the points for the line
    // Pre-Condition: None
    // Post-Condition: arributtes point_begin and point_end get set with the passed in parameters from the vector
    void set_points(const vector<QPoint>& points) override;

    // What: Sets the points for the line
    // Pre-Condition: None
    // Post-Condition: arributtes point_begin and point_end get set with the passed in parameters
    void set_points(const QPoint& point_begin, const QPoint& point_end) override;

    // What: Line Drawn
    // Pre-Condition: None
    // Post-Condition: A line gets drawn with two points
    void draw(QPainter& painter, const int translate_x = 0, const int translate_y = 0) override;

    // What: Gets the perimeter
    // Pre-Condition: None
    // Post-Condition: The perimeter of the line gets returned to the caller
    double perimeter() const override;

    // What: Gets the area
    // Pre-Condition: None
    // Post-Condition: The area of the line gets returned to the caller
    double area() const override {return 0;}

private:
    QPoint point_begin;
    QPoint point_end;

};


#endif // LINE_H
