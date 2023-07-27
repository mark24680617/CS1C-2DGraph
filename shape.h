/*
Worked on by: Daniel Price
Worked on by:
Worked on by:
*/

#ifndef SHAPE_H_
#define SHAPE_H_

#include <QBrush>
#include <QPainter>
#include <QPen>
#include <QPoint>
#include <QFont>
#include <QDebug>

using namespace std;
using namespace Qt;

class Shape
{
public:
    enum class shapeType {NoShape, Line, Polyline, Polygon, Rectangle, Ellipse, Text};

    Shape (QPaintDevice* device = nullptr, int id = -1, shapeType shape = shapeType::NoShape)
        : id(id), shape(shape)
   	 {
       		 pen = Qt::SolidLine;
        	 brush = Qt::NoBrush;
    	 }
	//Shape(/* Maybe change the type of QPainter*/ QPainter* qpaint, int penWidth,
	//		int shapeId, Shape::shapeType shape) :
	//	id(shapeId), shape(shape), qpainter(qpaint) {} // I added implementation -Daniel
	virtual ~Shape(){};

    int getID() const
    {
             return id;
         }

	shapeType get_shape() const
	{
		return shape;
	}
	const QPen& get_pen() const
	{
		return pen;
	}
	const QBrush& get_brush() const
	{
		return brush;
	}

	void set_shape(shapeType shapeIn)
	{
		shape = shapeIn; // I added implementation -Daniel
	}
	void set_pen(Qt::GlobalColor color, int width, Qt::PenStyle penStyle, Qt::PenCapStyle penCapStyle, Qt::PenJoinStyle penJoinStyle)
	{
		pen.setColor(color); // I added implementation -Daniel
		pen.setWidth(width);
		pen.setStyle(penStyle);
		pen.setCapStyle(penCapStyle);
		pen.setJoinStyle(penJoinStyle);
	}
/*
	void set_pen(Qt::GlobalColor color)
	{
		pen.setColor(color); // I added implementation -Daniel
	}
  */
	void set_brush(Qt::GlobalColor color, Qt::BrushStyle brushStyle) // I added method -Daniel
	{
		brush.setColor(color); // I added implementation -Daniel
		brush.setStyle(brushStyle);
	}

	void set_shapeID(const int &inId) // I added method -Daniel
	{
		id = inId; // I added implementation -Daniel
	}

    void set_qPainter(QPainter qpainter){
        this->qpainter = &qpainter;
    }

	void default_style()
	{
		pen = Qt::SolidLine; // I added implementation -Daniel
		brush = Qt::NoBrush;
		qpainter->setPen(pen);
		qpainter->setBrush(brush);
	}

    //don't use cout for QT, use Debug() <------------- Fix this
	static void printlisting(vector<Shape*> shapes){ //all couts have been changed to qDebug() coming from the QDebug library
       for(auto shape : shapes) {
           qDebug() << "ShapeID: " << shape->id << "\n";
           qDebug() <<"ShapeType : " << shape->shape << "\n";
           qDebug() << "ShapeDimensions: " << shape->dimensions << "\n";
           qDebug() << "Pen Color: "<< shape->pen.color << "\n";
           qDebug() << "Pen Width: " << shape->pen.width << "\n";
           qDebug() << "Pen Style: " << shape->pen.penStyle<< "\n";
           qDebug() << "Pen Cap Style: " << shape->pen.penCapStyle << "\n";
           qDebug() << "Pen Join Style: " << shape->pen.penJoinStyle << "\n";
           qDebug() << "Brush Color: " << shape->brush.color << "\n";
           qDebug() << "Brush Color: " << shape->brush.brushStyle << "\n";
       }
   }

	void draw_rect(int width, int height); // NO IMPLEMENTATION YET

    virtual void draw(QPainter& painter, const int translate_x, const int translate_y) = 0;

	virtual double perimeter() const = 0;

	virtual double area() const = 0;

protected:
	QPainter& get_qpainter() const
	{
		return *qpainter; // not sure if this is the right return I just added * to the front
	}

private:
	QPainter* qpainter;
	int id;
	shapeType shape;
	QPen pen;
	QBrush brush;

};



#endif /* SHAPE_H_ */
