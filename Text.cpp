#include "Text.h"

void Text::set_points(const vector<QPoint>& pointsList)
{
    // Set the bounding rectangle using the provided points
    boundingRect = QRect(pointsList[0], pointsList[1]);
}

void Text::set_points(const QPoint& top_left, const QPoint& bottom_right) {
    // Set the bounding rectangle using the provided points
    boundingRect = QRect(top_left, bottom_right);
}

void Text::set_text(const QString& text)
{
    this->text = text;
}

void Text::set_text_color(Qt::GlobalColor color)
{
    textColor = color;
}

void Text::set_text_alignment(Qt::AlignmentFlag alignment)
{
    textAlignment = alignment;
}

void Text::set_text_point_size(int pointSize)
{
    textPointSize = pointSize;
}

void Text::set_text_font(const QString& fontFamily, QFont::Style fontStyle, int fontWeight)
{
    textFontFamily = fontFamily;
    textFontStyle = fontStyle;
    textFontWeight = fontWeight;
}

void Text::draw(QPainter& painter, const int translate_x, const int translate_y)
{

    painter.setPen(textColor);
    painter.setFont(QFont(textFontFamily, textPointSize, textFontWeight, textFontStyle));

    // Calculate the center position of the text within the bounding rectangle
    int xCenter = boundingRect.left() + boundingRect.width() / 2;
    int yCenter = boundingRect.top() + boundingRect.height() / 2;

    // Draw the text at the center position
    painter.drawText(QPoint(xCenter,yCenter), text);
}
