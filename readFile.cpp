#include "readFile.h"

readFile::readFile(string address){

	inFile.open(address);
	int id;

	while (inFile) {
		
		string typeStr;

        for(int i=0;i<moveP_ID;i++){
            inFile.ignore();
        }
		inFile>>id;

        for(int i=0;i<moveP_Type;i++){
            inFile.ignore();
        }
		inFile>>typeStr;

		if(inFile.eof()){
			break;
		}

		switch (typeStr[1])
		{
		case 'L': list.push_back(ReadLine(inFile , id));
			break;
		
		case 'P': 
                if(typeStr[5]=='l'){
                    list.push_back(ReadPolyLine(inFile , id));
                } else if  (typeStr[5]=='g'){
                    list.push_back(ReadPolygon(inFile , id));
                }
			break;
		case 'R': list.push_back(ReadRectangle(inFile , id));
			break;		

		case 'S': list.push_back(ReadRectangle(inFile , id));
			break;

		case 'E': list.push_back(ReadEcllipce(inFile , id));
			break;

		case 'C': list.push_back(ReadCircle(inFile , id));
			break;

		case 'T': list.push_back(ReadText(inFile , id));
			break;
		}
	}
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

    for(int i=0;i<moveP_Dimentions;i++){
        inFile.ignore();
    }
	inFile>>x;
	inFile.ignore();
	inFile>>y;
	inFile.ignore();
	inFile>>x2;
	inFile.ignore();
	inFile>>y2;

	QPoint first(x , y);
	QPoint second(x2 , y2);

    for(int i=0;i<moveP_Pen;i++){
        inFile.ignore();
    }
	getline(inFile , color);

	QColor lineColor (getColor(color));

    for(int i=0;i<moveP_Pen;i++){
        inFile.ignore();
    }
	inFile>>w;

    for(int i=0;i<moveP_Pen;i++){
        inFile.ignore();
    }
	getline(inFile , style);

    for(int i=0;i<moveP_PenCapStyle;i++){
        inFile.ignore();
    }
	getline(inFile , capStyle);

    for(int i=0;i<moveP_PenJoinStyle;i++){
        inFile.ignore();
    }
	getline(inFile , Jstyle);

	Line line;
	line.set_points(first , second);
	line.set_pen(lineColor , w , getPenStyle(style) , getCapStyle(capStyle) , getJoinStyle(Jstyle) );
	line.set_shapeID(id);
	return line;
}


Shape* readFile::ReadPolygon(fstream& inFile , int id){

	int x1 , y1 , x2 , y2 , x3 , y3 , x4 , y4 ;
	int w;

	string color;
	string style;
	string capStyle;
	string Jstyle;

    for(int i=0;i<moveP_Dimentions;i++){
        inFile.ignore();
    }
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
	inFile.ignore();

    for(int i=0;i<moveP_Pen;i++){
        inFile.ignore();
    }
	getline(inFile , color);

	QColor lineColor (getColor(color));

    for(int i=0;i<moveP_Pen;i++){
        inFile.ignore();
    }
	inFile>>w;

    for(int i=0;i<moveP_Pen;i++){
        inFile.ignore();
    }
	getline(inFile , style);

    for(int i=0;i<moveP_PenCapStyle;i++){
        inFile.ignore();
    }
	getline(inFile , capStyle);

    for(int i=0;i<moveP_PenJoinStyle;i++){
        inFile.ignore();
    }
	getline(inFile , Jstyle);

	QPoint first(x1 , y1);
	QPoint second(x2 , y2);
	QPoint third(x3 , y3);
	QPoint forth(x4 , y4);


	polygon *result;
	result->set_point(first);
	result->set_point(second);
	result->set_point(third);
	result->set_point(forth);
	result->set_shapeID(id);
	result->set_pen(lineColor , w , getPenStyle(style) , getCapStyle(capStyle) , getJoinStyle(Jstyle) );

	return result;
}


Shape* readFile::ReadPolyLine(fstream& inFile , int id){

	int x1 , y1 , x2 , y2 , x3 , y3 , x4 , y4 ;
	string color;
	int w;
	string style;
	string capStyle;
	string Jstyle;
	string bStyle;
	string bColor;

    inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , color);

	QColor lineColor (getColor(color));

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	inFile>>w;

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , style);

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , capStyle);

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , Jstyle);

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , bStyle);

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , bColor);

	QColor lineColor2 (getColor(bColor));

	QPoint first(x1 , y1);
	QPoint second(x2 , y2);
	QPoint third(x3 , y3);
	QPoint forth(x4 , y4);

	PolyLine *result;
	result->set_point(first);
	result->set_point(second);
	result->set_point(third);
	result->set_point(forth);
	result->set_shapeID(id);
	result->set_brush(lineColor2 , getBrushStyle(bStyle));
	result->set_pen(lineColor , w , getPenStyle(style) , getCapStyle(capStyle) , getJoinStyle(Jstyle) );

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


    for(int i=0;i<moveP_Dimentions;i++){
        inFile.ignore();
    }
	inFile>>x;
	inFile.ignore();
	inFile>>y;
	inFile.ignore();
	inFile>>x2;
	inFile.ignore();
	inFile>>y2;

    for(int i=0;i<moveP_Pen;i++){
        inFile.ignore();
    }
	getline(inFile , color);

	QColor lineColor (getColor(color));

    for(int i=0;i<moveP_Pen;i++){
        inFile.ignore();
    }
	inFile>>w;

    for(int i=0;i<moveP_Pen;i++){
        inFile.ignore();
    }
	getline(inFile , style);

    for(int i=0;i<moveP_PenCapStyle;i++){
        inFile.ignore();
    }
	getline(inFile , capStyle);

    for(int i=0;i<moveP_PenJoinStyle;i++){
        inFile.ignore();
    }
	getline(inFile , Jstyle);

    for(int i=0;i<moveP_Pen;i++){
        inFile.ignore();
    }
	getline(inFile , bStyle);

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , bColor);

	QColor lineColor2 (getColor(bColor));

	QPoint topRight(x1,y1);
	QPoint buttomLeft(x2 ,y2);

    Rectangle result;
	result->set_shapeID(id);
	result->set_points(topRight , buttomLeft);
    result->set_brush(lineColor2 , getBrushStyle(bStyle));
    result->set_pen(lineColor , w , getPenStyle(style) , getCapStyle(capStyle) , getJoinStyle(Jstyle) );
	
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

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	inFile>>a;
	inFile.ignore();
	inFile>>b;
	inFile.ignore();
	inFile>>c;
	inFile.ignore();

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , color);

	QColor lineColor (getColor(color));

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	inFile>>w;

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , style);

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , capStyle);

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , Jstyle);

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , bStyle);

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , bColor);

	QColor lineColor2 (getColor(bColor));

	QRect rect(a,b,c,c);
	
	Ellipse *result;
	result->set_shapeID(id);
	result->set_rect(rect);
	result->set_brush(linecolor2 , getBrushStyle(bStyle));
	result->set_pen(linecolor , w , getPenStyle(style) , getCapStyle(capStyle) , getJoinStyle(Jstyle) );
	
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

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	inFile>>a;
	inFile.ignore();
	inFile>>b;
	inFile.ignore();
	inFile>>c;
	inFile.ignore();

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , color);

	QColor lineColor (getColor(color));

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	inFile>>w;

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , style);

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , capStyle);

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , Jstyle);

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , bStyle);

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , bColor);

	QColor lineColor2 (getColor(bColor));

	int length = a-c;


	QPoint topLeft(a , b);
	QPoint buttomRight (c , b-length);

	Rectangle *result;
	result->set_shapeID(id);
	result->set_points(topLeft , buttomRight);
    result->set_brush(lineColor2 , getBrushStyle(bStyle));
    result->set_pen(lineColor , w , getPenStyle(style) , getCapStyle(capStyle) , getJoinStyle(Jstyle) );

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

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	inFile>>a;
	inFile.ignore();
	inFile>>b;
	inFile.ignore();
	inFile>>c;
	inFile.ignore();
	inFile>>d;

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , color);

	QColor lineColor (getColor(color));

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	inFile>>w;

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , style);

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , capStyle);

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , Jstyle);

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , bStyle);

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , bColor);

	QColor lineColor2 (getColor(bColor));

	QRect rect(a,b,c,d);

	Ellipse *result;
	result->set_shapeID(id);
	result->set_rect(rect);
    result->set_brush(lineColor2 , getBrushStyle(bStyle));
    result->set_pen(lineColor , w , getPenStyle(style) , getCapStyle(capStyle) , getJoinStyle(Jstyle) );
	
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

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	inFile>>a;
	inFile.ignore();
	inFile>>b;
	inFile.ignore();
	inFile>>c;
	inFile.ignore();
	inFile>>d;

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile,textString);

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , color);

	QColor lineColor (getColor(color));

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , aligne);

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	inFile>>pointSize;

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , fontFamily);


	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , fontStyle);


	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , fontFamily);


	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	getline(inFile , fontWeight);

	Text *result;
	

	
}


GlobalColor readFile::getColor(string& temp){
    
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

	default: return GlobalColor::black;
		break;
	}
	
}

BrushStyle readFile::getBrushStyle(string& temp){

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

}

QFont:: Weight readFile::getTextFontWeight(string& temp){

    switch (temp[0])
	{
    case 't': return QFont::Weight::Thin;
		break;
    case 'l': return QFont::Weight::Light;
		break;
    case 'b': return QFont::Weight::Bold;
		break;
	
    default: return QFont::Weight::Normal;
		break;

	}

}

PenCapStyle readFile::getCapStyle(string& temp){

    switch (tolower(temp[0]))
	{
    case 'f': return PenCapStyle::FlatCap;
		break;
    case 's': return PenCapStyle::SquareCap;
		break;
    case 'r': return PenCapStyle::RoundCap;
		break;

	default: return PenCapStyle::FlatCap;
		break;
	}

}

PenJoinStyle readFile::getJoinStyle(string& temp){


    switch (tolower(temp[0]))
	{
    case 'm': return PenJoinStyle::MiterJoin;
		break;
	
    case 'b': return PenJoinStyle::BevelJoin;
		break;

    case 'r': return PenJoinStyle::RoundJoin;
		break;

    default: return PenJoinStyle::MiterJoin;
		break;

	}

}

PenStyle readFile::getPenStyle(string& temp){

    switch (temp.length())
	{
    case 9 : return PenStyle::SolidLine;
		break;
    case 8 : return PenStyle::DashLine;
		break;
    case 7 : return PenStyle::DotLine;
		break;
    case 14 : return PenStyle::DashDotLine;
		break;

    default: return PenStyle::NoPen;
		break;
	}

}

AlignmentFlag readFile::getAlignment(string& temp){


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

    default:return AlignmentFlag::AlignLeft;
		break;
	}

}

QFont::Style readFile::getTextFontStyle(string& temp){
    switch (tolower(temp[5]))
	{
    case 'n': return QFont::StyleNormal;
		break;
    case 'e': return QFont::StyleItalic;
		break;
    case 'o': return QFont::StyleOblique;
		break;
	}

}
