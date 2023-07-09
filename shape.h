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

using namespace std;
using namespace Qt;

class Shape
{
public:
	enum class shapeType {NoShape, Line, Polyline, Polygon, Rectangle, Ellipse, Test};

	Shape(/* Maybe change the type of QPainter*/ QPainter* qpaint, int penWidth,
			int shapeId, Shape::shapeType shape) :
		id(shapeId), shapeType(shape), qpainter(qpaint) {} // I added implementation -Daniel
	virtual ~Shape(){};


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

	void set_pen(Qt::GlobalColor color)
	{
		pen.setColor(color); // I added implementation -Daniel
	}
	void set_brush(Qt::GlobalColor color, Qt::BrushStyle brushStyle) // I added method -Daniel
	{
		brush.setColor(color); // I added implementation -Daniel
		brush.setStyle(brushStyle);
	}

	void set_shapeID(const int &inId) // I added method -Daniel
	{
		id = inId; // I added implementation -Daniel
	}

	void default_style()
	{
		pen = Qt::SolidLine; // I added implementation -Daniel
		brush = Qt::NoBrush;
		qpainter.setPen(pen);
		qpainter.setBrush(brush);
	}
	void draw_rect(int width, int height); // NO IMPLEMENTATION YET

	virtual void draw( /* May Need to add something here... like the object? idk */const int translate_x, const int translate_y) = 0;

	virtual double perimeter() const = 0;

	virtual double area() const = 0;

protected:
	QPainter& get_qpainter() const
	{
		return qpainter;
	}

private:
	QPainter* qpainter;
	int id;
	shapeType shape;
	QPen pen;
	QBrush brush;

};



#endif /* SHAPE_H_ */
