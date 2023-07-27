#include "shape.h"
#include "Text.h"
#include <fstream>

//DashLine,DotLine,DashDotLine,DashDotDotLine
// antoy

using std::string;

string sPoints(myStd::vector<QPoint> pointsList) {
    string output;

    for (int i = 0; i < pointsList.size(); ++i) {
        output += to_string(pointsList[i].x());
        output += ',';
        output += to_string(pointsList[i].y());
        if (i != pointsList.size()-1) {
            output += ',';
        }
    }

    return output;
}

string sStyle(PenStyle temp){

    switch(temp){

    case SolidLine: return "SolidLIne";
        break;

    case DotLine: return "DotLine";
        break;
<<<<<<< HEAD
    case NoPen: return "NoPen";
        break;
    case DashLine: return "DashLine";
        break;
    case DashDotLine: return "DashDotLine";
        break;
    case DashDotDotLine: return "DashDotDotLine";
        break;
    case CustomDashLine: return "CustomDashLine";
        break;
    case MPenStyle: return "MPenStyle";
        break;
    default: return "empty";
    }
}

string sShape(Shape::shapeType shape){

    switch (shape) {
    case Shape::shapeType(0) : return "Line";
        break;

    case Shape::shapeType(1): return "Polyline";
        break;
    case Shape::shapeType(1): return "Polyline";
        break;
    case Shape::shapeType(1): return "Polyline";
        break;


=======

    case DashLine: return "DashLine";
        break;

    case DashDotLine: return "DashDotLine";
        break;

    case DashDotDotLine: return "DashDotDotLine";
        break;

    default: return "empty";
        break;
    }

}

string sShape(Shape::shapeType shape) {
    switch (shape) {
    case Shape::shapeType::Line:
        return "Line";
    case Shape::shapeType::Polyline:
        return "Polyline";
    case Shape::shapeType::Polygon:
        return "Polygon";
    case Shape::shapeType::Rectangle:
        return "Rectangle";
    case Shape::shapeType::Ellipse:
        return "Ellipse";
    case Shape::shapeType::Text:
        return "Text";
    default:
        return "Unknown";
>>>>>>> 6b301590479f64e0907b4d1949b247f963e36bce
    }
}

string sColor(QColor color){

    if (color == QColor(Qt::white)) {
        return "white";
    } else if (color == QColor(Qt::blue)) {
        return "blue";
    } else if (color == QColor(Qt::red)) {
        return "red";
    } else if (color == QColor(Qt::green)) {
        return "green";
    } else if (color == QColor(Qt::gray)) {
        return "gray";
    } else if (color == QColor(Qt::cyan)) {
        return "cyan";
    } else if (color == QColor(Qt::magenta)) {
        return "magenta";
    } else if (color == QColor(Qt::yellow)) {
        return "yellow";
    } else {
        return "black";
    }
}

void saveChanges(myStd::vector<Shape*>  shapes)
{
    ofstream fout("../shapes.txt");
    for(auto s : shapes)
    {
        if (s->get_shape() != Shape::shapeType::Text) {
            fout << '\n';
            fout << "ShapeId: " << s->getID() << '\n';
            fout << "ShapeType: " << sShape(s->get_shape()) << '\n';
            fout << "ShapeDimensions: " << sPoints(s->get_points()) << '\n';
            fout << "PenColor: " << sColor(s->get_pen().color()) << '\n';
            fout << "PenWidth: " << s->get_pen().width() << '\n';
            fout << "PenStyle: " << sStyle(s->get_pen().style()) << '\n';
            fout << "PenCapStyle: " << s->get_pen().capStyle() << '\n';
            fout << "PenJoinStyle: " << s->get_pen().joinStyle() << '\n';
            if (s->get_shape() != Shape::shapeType::Line && s->get_shape() != Shape::shapeType::Polyline) {
                fout << "BrushColor: " << sColor(s->get_brush().color()) << '\n';
                fout << "BrushStyle: " << s->get_brush().style() << '\n';
            }
        } else {
            Text text(nullptr, s->getID());

            fout << '\n';
            fout << "ShapeId: " << s->getID() << '\n';
            fout << "ShapeType: " << sShape(s->get_shape()) << '\n';
            fout << "ShapeDimensions: " << sPoints(s->get_points()) << '\n';
            fout << "TextString: " << text.getString() << '\n';
            fout << "TextColor: " << text.getColor() << '\n';
            fout << "TextAlignment: " << text.getAlignment() << '\n';
            fout << "TextPointSize: " << text.getPointSize() << '\n';
            fout << "TextFontFamily: " << text.getFontFamily() << '\n';
            fout << "TextFontStyle: " << text.getFontStyle() << '\n';
            fout << "TextFontWeight: " << text.getFontWeight() << '\n';
        }
//        sStyle(s->get_pen().style())
    }
    fout.close();
}


