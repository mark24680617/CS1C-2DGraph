#ifndef CS1C_2DGRAPH_ELLIPSE_H
#define CS1C_2DGRAPH_ELLIPSE_H

#include "shape.h"

class Ellipse : public Shape {
public:
    /**
     * @brief constructor of Ellipse
     * @param device QpaintDevice
     * @param id id number of shape
     */
    Ellipse(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, shapeType::Ellipse) {}

    /**
     * @brief Destructor of Ellipse
     */
    ~Ellipse() override {}

    void set_points(const vector<QPoint>& pointsList) override;

    /**
     * @brief set points for shape
     * @param rect QRectangle to identify points
     */
    void set_rect(const QRect& rect);

    /**
     * @brief draw Ellipse using two points
     * @param translate_x point x
     * @param translate_y point y
     */
    void draw(QPainter& painter, const int translate_x = 0, const int translate_y = 0) override;

    /**
     * @brief get perimeter of Ellipse
     * @return perimeter
     */
    double perimeter() const override;

    /**
     * @brief get area of Ellipse
     * @return area
     */
    double area() const override;

private:
    /**
     * store QRectangle
     */
    QRect rect;
};


#endif //CS1C_2DGRAPH_ELLIPSE_H
