#include "readFile.h"
#include <QDebug>

readFile::readFile(string address){

	inFile.open(address);
	int id;

    while (inFile) {
		string typeStr;

        inFile.ignore(moveP_ID);
		inFile>>id;

        inFile.ignore(256, '\n');

        inFile.ignore(moveP_Type);
		inFile>>typeStr;

		if(inFile.eof()){
			break;
		}

        switch (typeStr[0])
		{
		case 'L': list.push_back(ReadLine(inFile , id));
			break;
		
		case 'P': 
                if(typeStr[4]=='l'){
                    list.push_back(ReadPolyLine(inFile , id));
                } else {
                    list.push_back(ReadPolygon(inFile , id));
                }
			break;

        case 'R': list.push_back(ReadRectangle(inFile , id));
			break;		

        case 'S': list.push_back(ReadSquare(inFile , id));
			break;


		case 'E': list.push_back(ReadEcllipce(inFile , id));
			break;

        case 'C': list.push_back(ReadCircle(inFile , id));
            break;

		case 'T': list.push_back(ReadText(inFile , id));
			break;

		}
	}

    inFile.close();
}

Shape* readFile::ReadLine(fstream& inFile , int id){

	int x;
	int y;
	int x2;
	int y2;
	string color;
	int w;
	string style;
	string capStyle;
	string Jstyle;


    inFile.ignore(moveP_Dimentions);
    inFile>>x;
    inFile.ignore();
    inFile>>y;
    inFile.ignore();
    inFile>>x2;
    inFile.ignore();
	inFile>>y2;
    inFile.ignore();

	QPoint first(x , y);
	QPoint second(x2 , y2);

    inFile.ignore(moveP_Pen);
	getline(inFile , color);


    inFile.ignore(moveP_Pen);
	inFile>>w;

    inFile.ignore(256, '\n');

    inFile.ignore(moveP_Pen);
	getline(inFile , style);


    inFile.ignore(moveP_PenCapStyle);
	getline(inFile , capStyle);


    inFile.ignore(moveP_PenJoinStyle);
	getline(inFile , Jstyle);

    Line *line = new Line;
    line->set_points(first , second);
    line->set_pen(getColor(color) , w , getPenStyle(style) , getCapStyle(capStyle) , getJoinStyle(Jstyle) );
    line->set_shapeID(id);

    //qDebug()<<x << y<<x2<<y2<<w<<endl;

	return line;
}


Shape* readFile::ReadPolyLine(fstream& inFile , int id){

	int x1 , y1 , x2 , y2 , x3 , y3 , x4 , y4 ;
	int w;

	string color;
	string style;
	string capStyle;
	string Jstyle;

    inFile.ignore(moveP_Dimentions);
	inFile>>x1;
	inFile.ignore();
	inFile>>y1;
	inFile.ignore();
	inFile>>x2;
	inFile.ignore();
	inFile>>y2;
	inFile.ignore();
	inFile>>x3;
	inFile.ignore();
	inFile>>y3;
	inFile.ignore();
	inFile>>x4;
	inFile.ignore();
	inFile>>y4;
    //inFile.ignore();

    inFile.ignore(256, '\n');

    inFile.ignore(moveP_Pen);
	getline(inFile , color);


    inFile.ignore(moveP_Pen);
	inFile>>w;

    inFile.ignore(256, '\n');

    inFile.ignore(moveP_Pen);
	getline(inFile , style);


    inFile.ignore(moveP_PenCapStyle);
	getline(inFile , capStyle);


    inFile.ignore(moveP_PenJoinStyle);
	getline(inFile , Jstyle);

	QPoint first(x1 , y1);
	QPoint second(x2 , y2);
	QPoint third(x3 , y3);
	QPoint forth(x4 , y4);


    PolyLine *result = new PolyLine;
	result->set_point(first);
	result->set_point(second);
	result->set_point(third);
	result->set_point(forth);
	result->set_shapeID(id);
    result->set_pen(getColor(color) , w , getPenStyle(style) , getCapStyle(capStyle) , getJoinStyle(Jstyle) );

    //qDebug()<<x1 << y1<<x2<<y2<<x3<<y3<<x4<<y4<<w;
	return result;
}


Shape* readFile::ReadPolygon(fstream& inFile , int id){

	int x1 , y1 , x2 , y2 , x3 , y3 , x4 , y4 ;
	string color;
	int w;
	string style;
	string capStyle;
	string Jstyle;
	string bStyle;
	string bColor;

    inFile.ignore(moveP_Dimentions);
    inFile>>x1;
    inFile.ignore();
    inFile>>y1;
    inFile.ignore();
    inFile>>x2;
    inFile.ignore();
    inFile>>y2;
    inFile.ignore();
    inFile>>x3;
    inFile.ignore();
    inFile>>y3;
    inFile.ignore();
    inFile>>x4;
    inFile.ignore();
    inFile>>y4;
    //inFile.ignore();

    inFile.ignore(256, '\n');


    inFile.ignore(moveP_Pen);
	getline(inFile , color);

    inFile.ignore(moveP_Pen);
	inFile>>w;

    inFile.ignore(256, '\n');

    inFile.ignore(moveP_Pen);
	getline(inFile , style);

    inFile.ignore(moveP_PenCapStyle);
	getline(inFile , capStyle);

    inFile.ignore(moveP_PenJoinStyle);
	getline(inFile , Jstyle);

    inFile.ignore(moveP_Brush);
    getline(inFile , bColor);

    inFile.ignore(moveP_Brush);
	getline(inFile , bStyle);

	QPoint first(x1 , y1);
	QPoint second(x2 , y2);
	QPoint third(x3 , y3);
	QPoint forth(x4 , y4);

    polygon *result = new polygon;
	result->set_point(first);
	result->set_point(second);
	result->set_point(third);
	result->set_point(forth);
	result->set_shapeID(id);
    result->set_brush(getColor(bColor) , getBrushStyle(bStyle));
    result->set_pen(getColor(color) , w , getPenStyle(style) , getCapStyle(capStyle) , getJoinStyle(Jstyle) );

    //qDebug()<<x1 << y1<<x2<<y2<<w<<endl;
	return result;
}

Shape* readFile::ReadRectangle(fstream& inFile , int id){

	int x;
	int y;
	int x2;
	int y2;
	string color;
	int w;
	string style;
	string capStyle;
	string Jstyle;
	string bColor;
	string bStyle;


    inFile.ignore(moveP_Dimentions);
	inFile>>x;
	inFile.ignore();
	inFile>>y;
	inFile.ignore();
	inFile>>x2;
	inFile.ignore();
	inFile>>y2;
    inFile.ignore();

    inFile.ignore(moveP_Pen);
	getline(inFile , color);

    inFile.ignore(moveP_Pen);
	inFile>>w;

    inFile.ignore();

    inFile.ignore(moveP_Pen);
	getline(inFile , style);

    inFile.ignore(moveP_PenCapStyle);
	getline(inFile , capStyle);

    inFile.ignore(moveP_PenJoinStyle);
	getline(inFile , Jstyle);

    inFile.ignore(moveP_Brush);
    getline(inFile , bColor);

    inFile.ignore(moveP_Brush);
    getline(inFile , bStyle);

    QPoint topRight(x,y);
	QPoint buttomLeft(x2 ,y2);

    Rectangle *result = new Rectangle;
	result->set_shapeID(id);
	result->set_points(topRight , buttomLeft);
    result->set_brush(getColor(color) , getBrushStyle(bStyle));
    result->set_pen(getColor(bColor) , w , getPenStyle(style) , getCapStyle(capStyle) , getJoinStyle(Jstyle) );
	
	return result;
}


Shape* readFile::ReadCircle(fstream& inFile , int id){  // have no idea

	int a , b, c;
	string color;
	int w;
	string style;
	string capStyle;
	string Jstyle;
	string bStyle;
	string bColor;

    inFile.ignore(moveP_Dimentions);
	inFile>>a;
	inFile.ignore();
	inFile>>b;
	inFile.ignore();
	inFile>>c;
	inFile.ignore();

    inFile.ignore(moveP_Pen);
	getline(inFile , color);


    inFile.ignore(moveP_Pen);
	inFile>>w;

    inFile.ignore();

    inFile.ignore(moveP_Pen);
	getline(inFile , style);

    inFile.ignore(moveP_PenCapStyle);
	getline(inFile , capStyle);

    inFile.ignore(moveP_PenJoinStyle);
	getline(inFile , Jstyle);

    inFile.ignore(moveP_Brush);
    getline(inFile , bColor);

    inFile.ignore(moveP_Brush);
	getline(inFile , bStyle);


	QRect rect(a,b,c,c);
	
    Ellipse *result = new Ellipse;
	result->set_shapeID(id);
	result->set_rect(rect);
    result->set_brush(getColor(bColor) , getBrushStyle(bStyle));
    result->set_pen(getColor(color) , w , getPenStyle(style) , getCapStyle(capStyle) , getJoinStyle(Jstyle) );
	
	return result;
	
}


Shape* readFile::ReadSquare(fstream& inFile , int id){

	int a,b,c;
	string color;
	int w;
	string style;
	string capStyle;
	string Jstyle;
	string bColor;
	string bStyle;

    inFile.ignore(moveP_Dimentions);
	inFile>>a;
	inFile.ignore();
	inFile>>b;
	inFile.ignore();
	inFile>>c;
	inFile.ignore();

    inFile.ignore(moveP_Pen);
	getline(inFile , color);

    inFile.ignore(moveP_Pen);
	inFile>>w;

    inFile.ignore();

    inFile.ignore(moveP_Pen);
	getline(inFile , style);

    inFile.ignore(moveP_PenCapStyle);
	getline(inFile , capStyle);

    inFile.ignore(moveP_PenJoinStyle);
	getline(inFile , Jstyle);

    inFile.ignore(moveP_Brush);
    getline(inFile , bColor);

    inFile.ignore(moveP_Brush);
	getline(inFile , bStyle);



	int length = a-c;

	QPoint topLeft(a , b);
	QPoint buttomRight (c , b-length);

    Rectangle *result = new Rectangle;
	result->set_shapeID(id);
	result->set_points(topLeft , buttomRight);
    result->set_brush(getColor(bColor), getBrushStyle(bStyle));
    result->set_pen(getColor(color) , w , getPenStyle(style) , getCapStyle(capStyle) , getJoinStyle(Jstyle) );

	return result;
}


Shape* readFile::ReadEcllipce(fstream& inFile , int id){

	int a ,b, c,d;
	string color;
	int w;
	string style;
	string capStyle;
	string Jstyle;
	string bStyle;
	string bColor;

    inFile.ignore(moveP_Dimentions);
	inFile>>a;
	inFile.ignore();
	inFile>>b;
	inFile.ignore();
	inFile>>c;
	inFile.ignore();
	inFile>>d;
    inFile.ignore();

    inFile.ignore(moveP_Pen);
	getline(inFile , color);

    inFile.ignore(moveP_Pen);
	inFile>>w;

    inFile.ignore();

    inFile.ignore(moveP_Pen);
	getline(inFile , style);

    inFile.ignore(moveP_PenCapStyle);
	getline(inFile , capStyle);

    inFile.ignore(moveP_PenJoinStyle);
	getline(inFile , Jstyle);

    inFile.ignore(moveP_Brush);
    getline(inFile , bColor);

    inFile.ignore(moveP_Brush);
	getline(inFile , bStyle);


    QRect rect(QPoint(a, b), QPoint(c, d));

    Ellipse *result = new Ellipse;
	result->set_shapeID(id);
	result->set_rect(rect);
    result->set_brush(getColor(bColor) , getBrushStyle(bStyle));
    result->set_pen(getColor(color) , w , getPenStyle(style) , getCapStyle(capStyle) , getJoinStyle(Jstyle) );
	
	return result;
}


Shape* readFile::ReadText(fstream& inFile , int id){  // need more work

	int a ,b, c,d;
	string color;
	int pointSize;
	string textString;
	string aligne;
	string fontFamily;
	string fontStyle;
	string fontWeight;

    inFile.ignore(moveP_Dimentions);
	inFile>>a;
	inFile.ignore();
	inFile>>b;
	inFile.ignore();
	inFile>>c;
	inFile.ignore();
	inFile>>d;
    inFile.ignore();

    inFile.ignore(12);
	getline(inFile,textString);

    inFile.ignore(moveP_Pen+1);
	getline(inFile , color);

    inFile.ignore(15);
	getline(inFile , aligne);

    inFile.ignore(15);
	inFile>>pointSize;

    inFile.ignore();

    inFile.ignore(16);
	getline(inFile , fontFamily);


    inFile.ignore(15);
	getline(inFile , fontStyle);


    //inFile.ignore(15);
    //getline(inFile , fontFamily);


    inFile.ignore(16);
	getline(inFile , fontWeight);

    QString qString = QString::fromStdString(fontFamily);
    QString qString2 = QString::fromStdString(textString);
    QPoint point1(a,b);
    QPoint point2(c,d);

    Text *result = new Text;
    result->set_points(point1,point2);
    result->set_shapeID(id);
    result->set_text_color(getColor(color));
    result->set_text_alignment(getAlignment(aligne));
    result->set_text_point_size(pointSize);
    result->set_text_font(qString , getTextFontStyle(fontStyle), getTextFontWeight(fontWeight) );
    result->set_text(qString2);
    return result;
}


GlobalColor getColor(string& temp){
    
    char temp2=tolower(temp[0]);

	switch (temp2)
	{
	case 'w': return GlobalColor::white;
		break;
    case 'b' : if(tolower(temp[3])=='c'){
            return GlobalColor::black;
        } else if(tolower(temp[3])=='e'){
            return GlobalColor::blue;
        }
		break;
	case 'r' : return GlobalColor::red;
		break;
    case 'g' : if(tolower(temp[3])=='e'){
             return GlobalColor::green;
        } else if(tolower(temp[3])=='y'){
            return GlobalColor::gray;
        }
		break;
	case 'c' : return GlobalColor::cyan;
		break;
	case 'm' : return GlobalColor::magenta;
		break;
	case 'y' : return GlobalColor::yellow;
		break;
	}
    return GlobalColor::black;
}

BrushStyle getBrushStyle(string& temp){

    switch (tolower(temp[0]))
	{
    case 's': return BrushStyle::SolidPattern;
		break;
    case 'h': return BrushStyle::HorPattern;
		break;
    case 'v': return BrushStyle::VerPattern;
		break;
	default: return BrushStyle::NoBrush; 
		break;
	}
    return BrushStyle::SolidPattern;
}

QFont:: Weight getTextFontWeight(string& temp){

    switch (temp[0])
	{
    case 't': return QFont::Weight::Thin;
		break;
    case 'l': return QFont::Weight::Light;
		break;
    case 'b': return QFont::Weight::Bold;
		break;

	} 
    return QFont::Weight::Normal;
}

PenCapStyle getCapStyle(string& temp){

    switch (tolower(temp[0]))
	{
    case 'f': return PenCapStyle::FlatCap;
		break;
    case 's': return PenCapStyle::SquareCap;
		break;
    case 'r': return PenCapStyle::RoundCap;
		break;
	}
    return PenCapStyle::FlatCap;
}

PenJoinStyle getJoinStyle(string& temp){


    switch (tolower(temp[0]))
	{
    case 'm': return PenJoinStyle::MiterJoin;
		break;
	
    case 'b': return PenJoinStyle::BevelJoin;
		break;

    case 'r': return PenJoinStyle::RoundJoin;
		break;
	}
    return PenJoinStyle::MiterJoin;
}

PenStyle getPenStyle(string& temp){

    switch (temp.length())
	{
    case 9 : return PenStyle::SolidLine;
		break;
    case 8 : return PenStyle::DashLine;
		break;
    case 7 : return PenStyle::DotLine;
		break;

    //fixed: should be 11 characters
    case 11 : return PenStyle::DashDotLine;
		break;

    //fixed: include dashdotdotline
    case 14 : return PenStyle::DashDotDotLine;
        break;
	}
    return PenStyle::NoPen;
}

AlignmentFlag getAlignment(string& temp){


    switch (tolower(temp[5]))
	{
    case 'l': return AlignmentFlag::AlignLeft;
		break;
    case 'r': return AlignmentFlag::AlignRight;
		break;
    case 't': return AlignmentFlag::AlignTop;
		break;
    case 'b': return AlignmentFlag::AlignBottom;
		break;
    case 'c': return AlignmentFlag::AlignCenter;
		break;
	}
    return AlignmentFlag::AlignLeft;
}

QFont::Style getTextFontStyle(string& temp){
    switch (tolower(temp[5]))
	{
    case 'n': return QFont::StyleNormal;
		break;
    case 'e': return QFont::StyleItalic;
		break;
    case 'o': return QFont::StyleOblique;
		break;
	}
    return QFont::StyleNormal;
}

myStd::vector<Shape*>readFile::getVector(){
    return list;
}
