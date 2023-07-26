#pragma once

#include "vector.h"
#include "shape.h"
#include <string>
#include <fstream>


// this files need to be created
#include "line.h"
#include "polygon.h"
#include "polyline.h"
#include "Text.h"
#include "Rectangle.h"
#include "Ellipse.h"

int const moveP_ID=9;
int const moveP_Type=11;
int const moveP_Dimentions=17;
int const moveP_Pen=10;
int const moveP_PenCapStyle=13;
int const moveP_PenJoinStyle=14;
int const moveP_Brush=12;

using namespace std;
using namespace Qt;

// these methods are the swtich stuctures
GlobalColor getColor(string&);
PenStyle getPenStyle(string&);
PenCapStyle getCapStyle(string&);
PenJoinStyle getJoinStyle(string&);
BrushStyle getBrushStyle(string&);
QFont::Weight	getTextFontWeight(string&);
AlignmentFlag getAlignment(string&);
QFont::Style getTextFontStyle(string&);


class readFile{

	private:
	fstream inFile;

	public:
    vector<Shape*> list;

    readFile(string);
    ~readFile() {};

	// all of these methods can be protected

	// would return the shape object and push_it_back to the vector
    Shape* ReadLine(fstream&, int);
    Shape* ReadPolyLine(fstream&, int);
    Shape* ReadPolygon(fstream& , int);
    Shape* ReadRectangle(fstream& , int);
    Shape* ReadSquare(fstream& , int);
    Shape* ReadCircle(fstream& , int);
    Shape* ReadEcllipce(fstream& , int);
    Shape* ReadText(fstream& , int);




    vector<Shape*> getVector();

};
