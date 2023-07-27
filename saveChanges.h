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
    }
    return "empty";
}

string sShape(shapeType shape){

    switch (shape) {
    case shapeType(0) : return "Line";
        break;

    case shapeType(1): return "Polyline";
        break;



    }


    return "empty";
}


void saveChanges(vector<Shape*>  shapes)
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


