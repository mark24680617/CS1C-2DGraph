#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include "vector.h"
#include "shape.h"

class canvas : public QWidget
{
public:
    // What: The constructor
    // Pre-Condition: None
    // Post-Condition: The object gets constructed
    explicit canvas(QWidget *parent = nullptr);

    // What: Sets Vector
    // Pre-Condition: None
    // Post-Condition: The local vector gets updated with the passed in vector
    void setShapes(const vector<Shape*>& shapes);
protected:
    // What: Paint Event
    // Pre-Condition: None
    // Post-Condition: All shapes get drawn
    void paintEvent(QPaintEvent *event) override;
private:
    vector<Shape*> shapes;

};

#endif // CANVAS_H
