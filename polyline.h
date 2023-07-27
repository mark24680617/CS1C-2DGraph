#ifndef POLYLINE_H
#define POLYLINE_H


#include "shape.h"

#include "qpaintdevice.h"
class PolyLine: public Shape
{
public:
    /**
     * @brief constructor of polyline
     * @param device QpaintDevice
     * @param id id number of shape
     */
    PolyLine(QPaintDevice* device = nullptr, int id = -1): Shape{device, id, shapeType::Polyline}{};

    /**
     * @brief Destructor of Rectangle
     */
    ~PolyLine() override{}

    void set_points(const myStd::vector<QPoint>& pointsList) override;

    /**
     * @brief set points for shape
     * @param qpoint point
     */
    void set_point(const QPoint& point);

    /**
     * @brief draw polyline using vector of qpoints
     * @param translate_x point x
     * @param translate_y point y
     */
    void draw(QPainter& painter, const int translate_x = 0, const int translate_y = 0) override;

    /**
     * @brief get perimeter of polyline
     * @return perimeter
     */
    double perimeter() const override;

    /**
     * @brief get area of polyline
     * @return area
     */
    double area() const override {return 0;}

private:
    /**
     * stores a vector of qpoints
     */
    myStd::vector<QPoint> points;
};

#endif // POLYLINE_H
