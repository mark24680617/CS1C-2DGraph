#include "shape.h"
#include <fstream>

//DashLine,DotLine,DashDotLine,DashDotDotLine
// antoy
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


    }


    return "empty";
}


void saveChanges(myStd::vector<Shape*>  shapes)
{
    ofstream fout("savedChanges.txt");
    for(auto s : shapes)
    {
        PenStyle temp = s->get_pen().style();
        fout << s->getID();
        fout << s->shape;
        fout << s->dimensions;
        fout << s->pen.color;
        fout << s->get_pen().width();
        fout << sStyle(temp);
        fout << s->pen.penCapStyle;
        fout << s->pen.penJoinStyle;
        fout << s->brush.color;
        fout << s->brush.brushStyle;
    }
    fout.close();
}


