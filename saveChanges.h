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
string pCapStyle(Qt::PenCapStyle penCapStyle){
    switch(penCapStyle){
  case Qt::RoundCap: return "RoundCap";
    break;
  case Qt::FlatCap: return "FlatCap";
    break;
  case Qt::SquareCap: return "SquareCap";
    break;
  default: return "none";
    }
}
string pJoinStyle(Qt::PenJoinStyle penJoinStyle){
    switch(penJoinStyle){
      case Qt::MiterJoin: return "MiterJoin";
        break;
      case Qt::RoundJoin: return "RoundJoin";
        break;
      case Qt::BevelJoin: return "BevelJoin";
        break;
      case Qt::SvgMiterJoin: return "SvgMiterJoin";
        break;
      default: return "none";
      }
}
string pBrushStyle(Qt::BrushStyle penBrushStyle){
      switch(penBrushStyle){
        case Qt::NoBrush: return "NoBrush";
          break;
        case Qt::SolidPattern: return "SolidPattern";
          break;
        case Qt::Dense1Pattern: return "Dense1Pattern";
          break;
        case Qt::Dense2Pattern: return "Dense2Pattern";
          break;
        case Qt::Dense3Pattern: return "Dense3Pattern";
          break;
        case Qt::Dense4Pattern: return "Dense4Pattern";
          break;
        case Qt::Dense5Pattern: return "Dense5Pattern";
          break;
        case Qt::Dense6Pattern: return "Dense6Pattern";
          break;
        case Qt::Dense7Pattern: return "Dense7Pattern";
          break;
        case Qt::HorPattern: return "HorPattern";
          break;
        case Qt::VerPattern: return "VerPattern";
          break;
        case Qt::CrossPattern: return "CrossPattern";
          break;
        default: return "none";
          break;
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
            fout << "PenCapStyle: " << pCapStyle(s->get_pen().capStyle()) << '\n';
            fout << "PenJoinStyle: " << pJoinStyle(s->get_pen().joinStyle()) << '\n';
            if (s->get_shape() != Shape::shapeType::Line && s->get_shape() != Shape::shapeType::Polyline) {
                fout << "BrushColor: " << sColor(s->get_brush().color()) << '\n';
                fout << "BrushStyle: " << pBrushStyle(s->get_brush().style()) << '\n';
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
    }
    fout.close();
}


