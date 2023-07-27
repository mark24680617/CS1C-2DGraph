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

/// file spaces needed to be skipped
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
/*!
 * \brief getColor from a string
 * \return GlobalColor QT
 */
GlobalColor getColor(string&);

/*!
 * \brief getPenStyle from a string
 * \return PenSyle QT
 */
PenStyle getPenStyle(string&);

/*!
 * \brief getCapStyle from a string
 * \return PenCapStyle QT
 */
PenCapStyle getCapStyle(string&);

/*!
 * \brief getJoinStyle from a string
 * \return PenJoinStyle QT
 */
PenJoinStyle getJoinStyle(string&);

/*!
 * \brief getBrushStyle from a string
 * \return BrushStyle QT
 */
BrushStyle getBrushStyle(string&);

/*!
 * \brief getTextFontWeight from a string
 * \return QFont::Weight QT
 */
QFont::Weight	getTextFontWeight(string&);

/*!
 * \brief getAlignment from a string
 * \return AlignmentFlag QT
 */
AlignmentFlag getAlignment(string&);

/*!
 * \brief getTextFontStyle from a string
 * \return QFont::Style QT
 */
QFont::Style getTextFontStyle(string&);


class readFile{

	private:
    fstream inFile;        ///file stream

	public:
    vector<Shape*> list;  /// to store all shape info

    /*!
     * \brief constructor, use to readin file
     */
    readFile(string);
    ~readFile() {};

	// all of these methods can be protected

	// would return the shape object and push_it_back to the vector
    /*!
     * \brief ReadLine read line from file
     * \return line object
     */
    Shape* ReadLine(fstream&, int);

    /*!
     * \brief ReadPolyLine read polyline from file
     * \return polyline object
     */
    Shape* ReadPolyLine(fstream&, int);

    /*!
     * \brief ReadPolygon read polygon from file
     * \return polygon object
     */
    Shape* ReadPolygon(fstream& , int);

    /*!
     * \brief ReadRectangle read rectangle from file
     * \return rectangle object
     */
    Shape* ReadRectangle(fstream& , int);

    /*!
     * \brief ReadSquare read square from file
     * \return square object
     */
    Shape* ReadSquare(fstream& , int);

    /*!
     * \brief ReadCircle read circle from file
     * \return circle object
     */
    Shape* ReadCircle(fstream& , int);

    /*!
     * \brief ReadEcllipce read Ecllipse from file
     * \return ellicpse object
     */
    Shape* ReadEcllipce(fstream& , int);

    /*!
     * \brief ReadText read Text from file
     * \return text object
     */
    Shape* ReadText(fstream& , int);




    vector<Shape*> getVector();

};
