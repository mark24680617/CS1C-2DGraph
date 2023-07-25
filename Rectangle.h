#ifndef CS1C_2DGRAPH_RECTANGLE_H
#define CS1C_2DGRAPH_RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
public:
    /**
     * @brief constructor of Rectangle
     * @param device QpaintDevice
     * @param id id number of shape
     */
    Rectangle(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, shapeType::Rectangle) {}

    /**
     * @brief Destructor of Rectangle
     */
    ~Rectangle() override {}

    /**
     * @brief set points for shape
     * @param top_left top left point
     * @param bottom_right bottom right point
     */
    void set_points(const QPoint& top_left, const QPoint& bottom_right);

    /**
     * @brief draw rectangle using two points
     * @param translate_x point x
     * @param translate_y point y
     */
    void draw(QPainter& painter, const int translate_x = 0, const int translate_y = 0) override;

    /**
     * @brief get perimeter of rectangle
     * @return perimeter
     */
    double perimeter() const override;

    /**
     * @brief get area of rectangle
     * @return area
     */
    double area() const override;

private:
    /**
     * store top left point
     */
    QPoint top_left;
    /**
     * store bottom right point
     */
    QPoint bottom_right;

};


#endif //CS1C_2DGRAPH_RECTANGLE_H
