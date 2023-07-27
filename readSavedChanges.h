#include <fstream>
#include "shape.h"
//STILL NEED TO IMPLEMENT DIMENSIONS
template<typename T>
vector<Shape*> readSaved()
{

    vector<Shape*> v;

    ifstream fin("savedChanges.txt");
    T s;
    int id;
    Shape::shapeType shape;
    //dimensions;
    GlobalColor gColor;
    BrushStyle brushStyle;
    int width;
    PenStyle penStyle;
    PenCapStyle penCapStyle;
    PenJoinStyle penJoinStyle;
    BrushStyle bColor;

    string penJoinStyleType;
    string penCapStyleType;
    string colorType;
    string shapeType;
    string penStyleType;
    string brushColorType;
    string brushStyleType;
    id = 0;

    //Runs through first two Shapes. First Two shapes do not have brushes and brush styles
    //Shape Dimensions is missing
    while (fin >> id && id < 3)
    {
        s.setID(id);

        fin >> shapeType;
        if(shapeType == "NoShape")
            shape = Shape::shapeType::NoShape;
        else if(shapeType == "Line")
        {
            shape = Shape::shapeType::Line;
        }
        else if (shapeType == "Polyline")
        {
            shape = Shape::shapeType::Polyline;
        }
        else if(shapeType == "Polygon" )
        {
            shape = Shape::shapeType::Polygon;
        }
        else if(shapeType == "Rectanlge")
        {
            shape = Shape::shapeType::Rectangle;
        }
        else if (shapeType == "Ellipse")
        {
            shape = Shape::shapeType::Ellipse;
        }
        else if (shapeType == "Text")
        {
            shape = Shape::shapeType::Text;
        }
        s.set_shape(shape);

        fin >> colorType;

        if (colorType == "blue")
        {
            gColor = Qt::GlobalColor::blue;
        }
        else if (colorType == "green")
        {
            gColor = Qt::GlobalColor::green;
        }
        else if (colorType == "cyan")
        {
            gColor = Qt::GlobalColor::cyan;
        }        
        else if (colorType == "red")
        {
            gColor = Qt::GlobalColor::red;
        }
        else if (colorType == "black")
        {
            gColor = Qt::GlobalColor::black;
        }
        
        fin >> width;

        fin >> penStyleType;
        
        if(penStyleType == "DashDotLine")
        {
            penStyle = Qt::PenStyle::DashDotLine;
        }
        else if (penStyleType == "SolidLine")
        {
            penStyle = Qt::PenStyle::SolidLine;
        }
        else if (penStyleType == "DashDotDotLine")
        {
            penStyle = Qt::PenStyle::DashDotDotLine;
        }
        else if(penStyleType == "DashLine")
        {
            penStyle = Qt::PenStyle::DashLine;
        }

        fin >> penCapStyleType;

        if(penCapStyleType == "FlatCap")
        {
            penCapStyle = Qt::PenCapStyle::FlatCap;
        }
        else if(penCapStyleType == "RoundCap")
        {
            penCapStyle = Qt::PenCapStyle::RoundCap;
        }

        fin >> penJoinStyleType;

        if(penJoinStyleType == "MiterJoin")
        {
            penJoinStyle = Qt::PenJoinStyle::MiterJoin;
        }
        else if(penJoinStyleType == "RoundJoin")
        {
            penJoinStyle = Qt::PenJoinStyle::RoundJoin;
        }

        s.set_pen(gColor,width,penStyle,penCapStyle,penJoinStyle);

        v.push_back(s);
    }



//-----------------------------------------------------
//Shapes 2-7 Have brushes included, also need dimensions added
    while (fin >> id && id < 8)
    {
        s.setID(id);

        fin >> shapeType;
        if(shapeType == "NoShape")
            shape = Shape::shapeType::NoShape;
        else if(shapeType == "Line")
        {
            shape = Shape::shapeType::Line;
        }
        else if (shapeType == "Polyline")
        {
            shape = Shape::shapeType::Polyline;
        }
        else if(shapeType == "Polygon" )
        {
            shape = Shape::shapeType::Polygon;
        }
        else if(shapeType == "Rectanlge")
        {
            shape = Shape::shapeType::Rectangle;
        }
        else if (shapeType == "Ellipse")
        {
            shape = Shape::shapeType::Ellipse;
        }
        else if (shapeType == "Text")
        {
            shape = Shape::shapeType::Text;
        }
        s.set_shape(shape);

        fin >> colorType;

        if (colorType == "blue")
        {
            gColor = Qt::GlobalColor::blue;
        }
        else if (colorType == "green")
        {
            gColor = Qt::GlobalColor::green;
        }
        else if (colorType == "cyan")
        {
            gColor = Qt::GlobalColor::cyan;
        }        
        else if (colorType == "red")
        {
            gColor = Qt::GlobalColor::red;
        }
        else if (colorType == "black")
        {
            gColor = Qt::GlobalColor::black;
        }
        
        fin >> width;

        fin >> penStyleType;
        
        if(penStyleType == "DashDotLine")
        {
            penStyle = Qt::PenStyle::DashDotLine;
        }
        else if (penStyleType == "SolidLine")
        {
            penStyle = Qt::PenStyle::SolidLine;
        }
        else if (penStyleType == "DashDotDotLine")
        {
            penStyle = Qt::PenStyle::DashDotDotLine;
        }
        else if (penStyleType == "DashLine")
        {
            penStyle = Qt::PenStyle::DashLine;
        }

        fin >> penCapStyleType;

        if(penCapStyleType == "FlatCap")
        {
            penCapStyle = Qt::PenCapStyle::FlatCap;
        }
        else if (penCapStyleType == "RoundCap")
        {
            penCapStyle = Qt::PenCapStyle::RoundCap;
        }

        fin >> penJoinStyleType;

        if(penJoinStyleType == "MiterJoin")
        {
            penJoinStyle = Qt::PenJoinStyle::MiterJoin;
        }
        else if (penJoinStyleType == "RoundJoin")
        {
            penJoinStyle = Qt::PenJoinStyle::RoundJoin;
        }
        
        fin >> brushColorType;

        if(brushColorType == "yellow")
        {
            bColor = Qt::BrushStyle(yellow);
        }
        else if(brushColorType == "red")
        {
            bColor = Qt::BrushStyle(red);
        }
        else if (brushColorType == "blue")
        {
            bColor = Qt::BrushStyle(blue);
        }
        else if (brushColorType == "white")
        {
            bColor = Qt::BrushStyle(white);
        }
        else if (brushColorType == "magenta")
        {
            bColor = Qt::BrushStyle(magenta);
        }

        if (brushStyleType == "SolidPattern")
        {
        brushStyle = Qt::BrushStyle::SolidPattern;
        }
        else if(brushStyleType == "VerPattern")
        {
            brushStyle = Qt::BrushStyle::VerPattern;
        }
        else if(brushStyleType == "HorPattern")
        {
            brushStyle = Qt::BrushStyle::HorPattern;
        }        
        else if (brushStyleType == "NoBrush")
        {
            brushStyle = Qt::BrushStyle::NoBrush;
        }

        s.set_pen(gColor,width,penStyle,penCapStyle,penJoinStyle);
        s.set_brush(bColor,brushStyle);
        v.push_back(s);
    }
    //Shape 8 has different properties after the first two. Need to be implemented 
    // and also needs Dimensions.
    while (fin >> id && id == 8)
    {
        fin >> shapeType;
        if(shapeType == "NoShape")
            shape = Shape::shapeType::NoShape;
        else if(shapeType == "Line")
        {
            shape = Shape::shapeType::Line;
        }
        else if (shapeType == "Polyline")
        {
            shape = Shape::shapeType::Polyline;
        }
        else if(shapeType == "Polygon" )
        {
            shape = Shape::shapeType::Polygon;
        }
        else if(shapeType == "Rectanlge")
        {
            shape = Shape::shapeType::Rectangle;
        }
        else if (shapeType == "Ellipse")
        {
            shape = Shape::shapeType::Ellipse;
        }
        else if(shapeType == "Text")
        {
            shape = Shape::shapeType::Text;
        }
        s.set_shape(shape);

        // REST OF PROPERTIES FOR SHAPE 8 NEED TO BE ADDED: SHAPE DIMENSIONS 
        // TEXT STRING
        // TEXT COLOR
        //TEXT ALIGNMENT
        // TEXT POINT SIZE
        //TEXT FONT FAMILY
        //TEXT FONT STYLE
        //TEXT FONT WEIGHT
    }


    fin.close();

    return v;


}


