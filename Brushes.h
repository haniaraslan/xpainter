#ifndef BRUSHES_H
#define BRUSHES_H

#include <QtWidgets>
#include <QColor>
#include <QPoint>
#include <QImage>
#include <QWidget>
#include <QColorDialog>
#include <string>

namespace Ui {
	class Brushes;
}

class Brushes : public QWidget 
{
		Q_OBJECT
public:

	explicit Brushes(QWidget *parent = nullptr);

	void setPenColor(const QColor &newColor);
	void setPenWidth(int newWidth);
	void setPenCapStyle(Qt::PenCapStyle capStyle);
	void setPenJoinStyle(Qt::PenJoinStyle penJoinStyle);
	void setBrush(QBrush brush);

	QColor penColor() const { return myPenColor; }
	int penWidth() const { return myPenWidth; }
	Qt::PenCapStyle capStyle() const { return myCapStyle; }
	Qt::PenJoinStyle penJoinStyle() const { return myPenJoinStyle; }
	QBrush getQBrush() const { return myBrush; }

	void pen();
	void marker();
	void eraser();
	void oilBrush();
	void waterColorBrush();
	static bool initialBrush ;
	

private:

	int myPenWidth;
	QColor myPenColor;
	Qt::PenCapStyle myCapStyle;
	Qt::PenJoinStyle myPenJoinStyle;
	QBrush myBrush;
	
};
#endif