
#include <QtWidgets>
#include "Brushes.h"
Brushes::Brushes(QWidget *parent) :
	QWidget(parent)
{

	setAttribute(Qt::WA_StaticContents);

	myPenWidth = 1;
	myPenColor = Qt::blue;
	myCapStyle = Qt::RoundCap; 
	myPenJoinStyle = Qt::RoundJoin;
	myBrush = Qt::SolidPattern;
	
}

//setters
bool Brushes::initialBrush = true;

void Brushes::setPenColor(const QColor &newColor) {
	myPenColor = newColor;
}

void Brushes::setPenWidth(int newWidth) {
	myPenWidth = newWidth;
}
void Brushes::setPenCapStyle(Qt::PenCapStyle capStyle) {
	myCapStyle = capStyle;
}
void Brushes::setPenJoinStyle(Qt::PenJoinStyle penJoinStyle) {
	myPenJoinStyle = penJoinStyle;
}

void Brushes::setBrush(QBrush brush) {
	myBrush = brush;
}

//getters

void Brushes::pen() {
	myPenWidth = 2;
}
void Brushes::marker() {
	myPenWidth = 20;
}

void Brushes::oilBrush() {
	myPenWidth = 20;
}

void Brushes::waterColorBrush() {
	myPenWidth = 20;
}

void Brushes::eraser() {
	myPenColor = Qt::white;
}
