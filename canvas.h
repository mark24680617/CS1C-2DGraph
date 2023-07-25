#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include "vector.h"
#include "shape.h"

class canvas : public QWidget
{
public:
    explicit canvas(QWidget *parent = nullptr);
    void setShapes(const vector<Shape*>& shapes);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    vector<Shape*> shapes;

};

#endif // CANVAS_H
