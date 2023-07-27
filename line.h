#ifndef LINE_H
#define LINE_H


#include "shape.h"
#include "vector.h"
class Line: public Shape
{
public:
    /**
     * @brief constructor of line
     * @param device QpaintDevice
     * @param id id number of shape
     */
    Line(QPaintDevice* device = nullptr, int id = -1): Shape{device, id, shapeType::Line}
    {}

    /**
     * @brief Destructor of line
     */
    ~Line() override {}

    virtual myStd::vector<QPoint> get_points() const override;

    // What: Sets the points for the line
    // Pre-Condition: None
    // Post-Condition: arributtes point_begin and point_end get set with the passed in parameters from the vector
    void set_points(const myStd::vector<QPoint>& pointsList) override;

    /**
     * @brief set points for shape
     * @param top_left top left point
     * @param bottom_right bottom right point
     */
    void set_points(const QPoint& point_begin, const QPoint& point_end) override;

    /**
     * @brief draw line using two points
     * @param translate_x point x
     * @param translate_y point y
     */
    void draw(QPainter& painter, const int translate_x = 0, const int translate_y = 0) override;

    /**
     * @brief get perimeter of line
     * @return perimeter
     */
    double perimeter() const override;

    /**
     * @brief get area of line
     * @return area
     */
    double area() const override {return 0;}

private:
    /**
     * store start point
     */
    QPoint point_begin;
    /**
     * store end point
     */
    QPoint point_end;

};


#endif // LINE_H
