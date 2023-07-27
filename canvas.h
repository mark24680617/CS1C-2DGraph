#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include "vector.h"
#include "shape.h"

class canvas : public QWidget
{
public:
    /**
     * @brief constructor of canvas
     * @param parent QWidget
     */
    explicit canvas(QWidget *parent = nullptr);

    /**
     * @brief set shapes in vector
     * @param vector shapes
     */
    void setShapes(const vector<Shape*>& shapes);
protected:
    /**
     * @brief sets up a paint event
     * @param QPaintEvent event
     */
    void paintEvent(QPaintEvent *event) override;
private:
    vector<Shape*> shapes;

};

#endif // CANVAS_H
