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
#include "vector.h"

using namespace std;
using namespace Qt;


class Shape
{
public:
    /**
     * @brief The shapeType enum difference kind of shapes
     */
    enum class shapeType {NoShape, Line, Polyline, Polygon, Rectangle, Ellipse, Text};

    /**
     * @brief Shape constructor
     * @param device QPaintDevice
     * @param id id for shape
     * @param shape shape type
     */
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

     /**
     * @brief getID accessor to shape if
     * @return int id
     */
    int getID() const
    {
             return id;
    }

    /**
     * @brief accessor to shapeType
     * @return shape type
     */
	shapeType get_shape() const
	{
		return shape;
	}

    /**
     * @brief accessor to pen
     * @return QPen
     */
	const QPen& get_pen() const
	{
		return pen;
	}

    /**
     * @brief accessor to brush
     * @return QBrush
     */
	const QBrush& get_brush() const
	{
		return brush;
	}

    /**
     * @brief mutator of shape
     * @param shapeIn shapeType
     */
	void set_shape(shapeType shapeIn)
	{
		shape = shapeIn; // I added implementation -Daniel
	}

    /**
     * @brief mutator of pen
     * @param color Qt::GlobalColor
     * @param width int pen width
     * @param penStyle Qt::PenStyle
     * @param penCapStyle Qt::PenCapStyle
     * @param penJoinStyle Qt::PenJoinStyle
     */
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

    /**
     * @brief mutator of brush
     * @param color Qt::GlobalColor
     * @param brushStyle Qt::BrushStyle
     */
	void set_brush(Qt::GlobalColor color, Qt::BrushStyle brushStyle) // I added method -Daniel
	{
		brush.setColor(color); // I added implementation -Daniel
		brush.setStyle(brushStyle);
	}

    /**
     * @brief mutator of id
     * @param inId id number
     */
	void set_shapeID(const int &inId) // I added method -Daniel
	{
		id = inId; // I added implementation -Daniel
	}

    /**
     * @brief mutator of qPainter
     * @param qpainter QPainter
     */
    void set_qPainter(QPainter qpainter){
        this->qpainter = &qpainter;
    }

    /**
     * @brief default setting for pen and brush
     */
	void default_style()
	{
		pen = Qt::SolidLine; // I added implementation -Daniel
		brush = Qt::NoBrush;
		qpainter->setPen(pen);
		qpainter->setBrush(brush);
	}

    /* //lead the program to crash, shape->shape, shape->pen.color....and so on can not be printed directly
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
    */
    /**
     * @brief helper function to draw a rectangle
     * @param width width of rectangle
     * @param height height of rectangle
     */
	void draw_rect(int width, int height);

    /**
     * @brief virtual function to draw a shape
     * @param painter QPainter object
     * @param translate_x helper x axis
     * @param translate_y helper y axis
     */
    virtual void draw(QPainter& painter, const int translate_x, const int translate_y) = 0;

    virtual myStd::vector<QPoint> get_points() const = 0;

    /**
     * @brief virtual function to set point
     * @param points myStd::vector<QPoint>
     */
    virtual void set_points(const myStd::vector<QPoint>& points) {};

    /**
     * @brief addition virtual function to move shapes
     * @param point_begin QPoint
     * @param point_end QPoint
     */
    virtual void set_points(const QPoint& point_begin, const QPoint& point_end) {};

    /**
     * @brief virtual calculate perimeter
     * @return double value
     */
	virtual double perimeter() const = 0;

    /**
     * @brief virtual calculate area
     * @return double value
     */
	virtual double area() const = 0;

protected:
    /**
     * @brief helper function to get painter object
     * @return QPainter
     */
    QPainter& get_qpainter() const
    {
        return *qpainter; // not sure if this is the right return I just added * to the front
    }

private:
	QPainter* qpainter; /// qPainter to draw shapes
	int id;             /// shape id
	shapeType shape;    /// shapeType for shapes
	QPen pen;           /// pen for qPainter
	QBrush brush;       /// brush for qPainter

};



#endif /* SHAPE_H_ */
