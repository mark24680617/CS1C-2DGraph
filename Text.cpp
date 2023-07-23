#include "Text.h"

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
/*
void Text::draw(const int translate_x, const int translate_y)
{
    QPainter& painter = get_qpainter();
    painter.setPen(textColor);
    painter.setFont(QFont(textFontFamily, textPointSize, textFontWeight, textFontStyle));
    painter.drawText(QPoint(translate_x, translate_y), text);
    painter.restore();
}*/
