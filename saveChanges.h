#include "shape.h"
#include <fstream>


void saveChanges(vector<Shape*>  shapes)
{
    ofstream fout("savedChanges.txt");
    for(auto s : shapes)
    {
        fout << s->id;
        fout << s->shape;
        fout << s->dimensions;
        fout << s->pen.color;
        fout << s->pen.width;
        fout << s->pen.penStyle;
        fout << s->pen.penCapStyle;
        fout << s->pen.penJoinStyle;
        fout << s->brush.color;
        fout << s->brush.brushStyle;
    }
    fout.close();
}

