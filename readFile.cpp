#include "readFile.h"

readFile::readFile(){
	list = nullptr;
}

readFile::readFile(string address){

	inFile.open(address);
	int id;

	while (inFile) {
		
		string typeStr;

		inFile.ignore(numeric_limits<streamsize>::max() , ":");
		inFile>>id;

		inFile.ignore(numeric_limits<streamsize>::max() , ":");
		inFile>>typeStr;

		if(inFile.eof()){
			break;
		}

		switch (typeStr)
		{
		case "Line": list.push_back(ReadLine(inFile , id));
			break;
		
		case "Polyline": list.push_back(ReadPolyLine(inFile , id));
			break;

		case "Polygon": list.push_back(ReadPolygon(inFile , id));
			break;

		case "Rectangle": list.push_back(ReadRectangle(inFile , id));
			break;		

		case "Square": list.push_back(ReadRectangle(inFile , id));
			break;

		case "Ellipse": list.push_back(ReadEcllipce(inFile , id));
			break;

		case "Circle": list.push_back(ReadCircle(inFile , id));
			break;

		case "Text": list.push_back(ReadText(inFile , id));
			break;

		default:
			cout<<"error"<<endl;
		
		}
	}
}

shape* readFile::ReadLine(fstream& inFile , int id){

	int x;
	int y;
	int x2;
	int y2;
	string color;
	int w;
	string style;
	string capStyle;
	string Jstyle;

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	inFile>>x;
	inFile.ignore();
	inFile>>y;
	inFile.ignore();
	inFile>>x2;
	inFile.ignore();
	inFile>>y2;

	QPoint first(x , y);
	QPoint second(x2 , y2);

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

	Line *line;
	line->set_points(first , second);
	line->set_pen(linecolor , w , getPenStyle(style) , getCapStyle(capStyle) , getJoinStyle(Jstyle) );
	line->set_shapeID(id);
	return line;
}


shape* readFile::ReadPolygon(fstream& inFile , int id){

	int x1 , y1 , x2 , y2 , x3 , y3 , x4 , y4 ;
	int w;

	string color;
	int w;
	string style;
	string capStyle;
	string Jstyle;

	inFile.ignore(numeric_limits<streamsize>::max() , ":");
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
	result->set_pen(linecolor , w , getPenStyle(style) , getCapStyle(capStyle) , getJoinStyle(Jstyle) );

	return result;
}


shape* readFile::ReadPolyLine(fstream& inFile , int id){

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
	result->set_brush(linecolor2 , getBrushStyle(bStyle));
	result->set_pen(linecolor , w , getPenStyle(style) , getCapStyle(capStyle) , getJoinStyle(Jstyle) );

	return result;
}

shape* readFile::ReadRectangle(fstream& inFile , int id){

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


	inFile.ignore(numeric_limits<streamsize>::max() , ":");
	inFile>>x;
	inFile.ignore();
	inFile>>y;
	inFile.ignore();
	inFile>>x2;
	inFile.ignore();
	inFile>>y2;

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

	QPoint topRight(x1,y1);
	QPoint buttomLeft(x2 ,y2);

	Rectangle *result;
	result->set_shapeID(id);
	result->set_points(topRight , buttomLeft);
	result->set_brush(linecolor2 , getBrushStyle(bStyle));
	result->set_pen(linecolor , w , getPenStyle(style) , getCapStyle(capStyle) , getJoinStyle(Jstyle) );
	
	return result;
}

shape* readFile::ReadCircle(fstream& inFile , int id){  // have no idea

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


shape* readFile::ReadSquare(fstream& inFile , int id){

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
	QPoint buttomRight (c , b-length)

	Rectangle *result;
	result->set_shapeID(id);
	result->set_points(topLeft , buttomRight);
	result->set_brush(linecolor2 , getBrushStyle(bStyle));
	result->set_pen(linecolor , w , getPenStyle(style) , getCapStyle(capStyle) , getJoinStyle(Jstyle) );

	return result;
}


shape* readFile::ReadEcllipce(fstream& inFile , int id){

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
	result->set_brush(linecolor2 , getBrushStyle(bStyle));
	result->set_pen(linecolor , w , getPenStyle(style) , getCapStyle(capStyle) , getJoinStyle(Jstyle) );
	
	return result;
}

shape* readFile::ReadText(fstream& inFile , int id){  // need more work

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

	string temp2 = tolower(temp);

	switch (temp2)
	{
	case "white": return GlobalColor::white;
		break;
	case "black" : return GlobalColor::black;
		break;
	case "red" : return GlobalColor::red;
		break;
	case "green" : return GlobalColor::green;
		break;
	case "blue" : return GlobalColor::blue;
		break;
	case "cyan" : return GlobalColor::cyan;
		break;
	case "magneta" : return GlobalColor::magenta;
		break;
	case "gray" : return GlobalColor::gray;
		break;
	case "yellow" : return GlobalColor::yellow;
		break;

	default: return GlobalColor::black;
		break;
	}
	
}

BrushStyle readFile::getBrushStyle(string& temp){

	string temp2 = tolower(temp);

	switch (temp2)
	{
	case "solidpattern": return BrushStyle::SolidPattern;
		break;
	case "horpattern": return BrushStyle::HorPattern;
		break;
	case "verpattern": return BrushStyle::Verpattern;
		break;
	default: return BrushStyle::NoBrush; 
		break;
	}

}

Weight readFile::getTextFontWeight(string& temp){

	string temp2=tolower(temp);

	switch (temp2)
	{
	case "thin": return weight::Thin;
		break;
	case "light": return weight::Light;
		break;
	case "bold": return weight::Bold;
		break;
	
	default: return weight::Normal;
		break;

	}

}

PenCapStyle readFile::getCapStyle(string& temp){

	string temp2= tolower(temp);

	switch (temp2)
	{
	case "flatcap": return PenCapStyle::FlatCap;
		break;
	case "squarecap": return PenCapStyle::SquareCap;
		break;
	case "roundcap": return PenCapStyle::RoundCap;
		break;

	default: return PenCapStyle::FlatCap;
		break;
	}

}

PenJoinStyle readFile::getJoinStyle(string& temp){

	string temp2= tolower(temp);

	switch (temp2)
	{
	case "miterjoin": return PenJointStyle::MiterJoin;
		break;
	
	case "beveljoin": return PenJointStyle::Beveljoin;
		break;

	case "roundjoin": return PenJointStyle::RoundJoin;
		break;

	default: return PenJointStyle::MiterJoin;
		break;

	}

}

PenStyle readFile::getPenStyle(string& temp){

	string temp2 = tolower(temp);

	switch (temp2)
	{
	case "solidline" : return PenStyle::SolidLine;
		break;
	case "dashline" : return PenStyle::DashLine;
		break;
	case "dotline" : return PenStyle::DotLine;
		break;
	case "dashdotline" : return PenStyle::DashDotLine;
		break;

	default: return PenStyle::noPen;
		break;
	}

}

AlignmentFlag readFile::getAlignment(string& temp){

	string temp2=tolower(temp);

	switch (temp2)
	{
	case "alignleft": return AlignmentFlag::AlighnLeft;
		break;
	case "alignright": return AlignmentFlag::AlighnRight;
		break;
	case "aligntop": return AlignmentFlag::AlighnTop;
		break;
	case "alignbottom": return AlignmentFlag::AlighnBotton;
		break;
	case "aligncenter": return AlignmentFlag::AlighnCenter;
		break;

	default:return AlignmentFlag::AlighnLeft;
		break;
	}

}

QFont readFile::getTextFontStyle(string& temp){

	string temp2=tolower(temp);

	switch (temp2)
	{
	case "stylenormal": return QFont::StyleNormal;
		break;
	case "styleitalic": return QFont::StyleItalic;
		break;
	case "styleoblique": return QFont::StyleOblique;
		break;
	}

}
