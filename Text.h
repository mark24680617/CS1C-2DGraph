#ifndef CS1C_2DGRAPH_TEXT_H
#define CS1C_2DGRAPH_TEXT_H
#include "shape.h"
#include <QString>

class Text : public Shape{
public:
    /**
     * @brief constructor of Text
     * @param device QPaintDevice
     * @param id shape id
     */
    Text(QPaintDevice* device = nullptr, int id = -1) : Shape(device, id, shapeType::Text) {}

    /**
     * @brief destructor of Text
     */
    ~Text() override {}

    /**
     * @brief Set the top-left and bottom-right points of the text's bounding rectangle using a vector.
     * @param top_left The top-left point of the bounding rectangle.
     * @param bottom_right The bottom-right point of the bounding rectangle.
     */
    void set_points(const vector<QPoint>& pointsList) override;

    /**
     * @brief Set the top-left and bottom-right points of the text's bounding rectangle.
     * @param top_left The top-left point of the bounding rectangle.
     * @param bottom_right The bottom-right point of the bounding rectangle.
     */
    void set_points(const QPoint& top_left, const QPoint& bottom_right);

    /**
     * @brief set text string
     * @param text QString
     */
    void set_text(const QString& text);

    /**
     * @brief set text color
     * @param color Qt::GlobalColor
     */
    void set_text_color(Qt::GlobalColor color);

    /**
     * @brief set text alignment
     * @param alignment QT::AlignmentFlag
     */
    void set_text_alignment(Qt::AlignmentFlag alignment);

    /**
     * @brief set text point size
     * @param pointSize int
     */
    void set_text_point_size(int pointSize);

    /**
     * @brief set text font
     * @param fontFamily QString
     * @param fontStyle QFont::Style
     * @param fontWeight int
     */
    void set_text_font(const QString& fontFamily, QFont::Style fontStyle, int fontWeight);

    /**
     * @brief draw the text, note that to set the properties before use this function
     * @param translate_x xPosition
     * @param translate_y yPosition
     */
    void draw(QPainter& painter, const int translate_x, const int translate_y) override;

    /**
     * @brief perimeter for text
     * @return 0
     */
    double perimeter() const override { return 0; }

    /**
     * @brief area for text
     * @return 0
     */
    double area() const override { return 0; }

private:
    QString text;
    QRect boundingRect; // The bounding rectangle of the text
    Qt::GlobalColor textColor;
    Qt::AlignmentFlag textAlignment;
    int textPointSize;
    QString textFontFamily;
    QFont::Style textFontStyle;
    int textFontWeight;

    QPoint point1;
    QPoint point2;

};


#endif //CS1C_2DGRAPH_TEXT_H
