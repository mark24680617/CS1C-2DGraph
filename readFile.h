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


using namespace std;
using namespace Qt;

class readFile{

	private:
	vector<*shape> list;
	fstream inFile;

	public:

	readFile();
	readFile(string);

	// all of these methods can be protected

	// would return the shape object and push_it_back to the vector
	shape* ReadLine(fstream&, int);
	shape* ReadPolyLine(fstream&, int);
	shape* ReadPolygon(fstream& , int);
	shape* ReadRectangle(fstream& , int);
	shape* ReadSquare(fstream$ , int);
	shape* ReadCircle(fstream& , int);
	shape* ReadEcllipce(fstream& , int);
	shape* ReadText(fstream& , int);


	// these methods are the swtich stuctures
	GlobalColor getColor(string&);
	PenStyle getPenStyle(string&);
	PenCapStyle getCapStyle(string&);
	PenJoinStyle getJoinStyle(string&);
	BrushStyle getBrushStyle(string&);
	Weight	getTextFontWeight(string&);
	AlignmentFlag getAlignment(string&);
	QFont getTextFontStyle(string&);

};