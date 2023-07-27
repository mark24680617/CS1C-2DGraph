#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
class polygon : public Shape
{
public:
    /**
     * @brief constructor of polygon
     * @param device QpaintDevice
     * @param id id number of shape
     */
    polygon(QPaintDevice* device = nullptr, int id = -1) : Shape{device, id, shapeType::Polygon} {};

    /**
     * @brief Destructor of polygon
     */
    ~polygon() override{ }

    void set_points(const vector<QPoint>& pointsList) override;

    /**
     * @brief set points for shape
     * @param qpoint point
     */
    void set_point(const QPoint& point);

    /**
     * @brief draw polygon using vector of qpoints
     * @param translate_x point x
     * @param translate_y point y
     */
    void draw(QPainter& painter, const int translate_x = 0, const int translate_y = 0) override;

    /**
     * @brief get perimeter of polygon
     * @return perimeter
     */
    double perimeter() const override;

    /**
     * @brief get area of polygon
     * @return area
     */
    double area() const override;

private:
    /**
     * stores a vector of qpoints
     */
    vector<QPoint> points;
};

#endif // POLYGON_H
