#ifndef PAINT3D_H
#define PAINT3D_H

#include "Brushes.h"

#include <QList>
#include <QMainWindow>
#include <QFileDialog>
#include <qbrush.h>
#include <QtWidgets>
#include <QColor>
#include <QString>
#include <vtkGenericOpenGLRenderWindow.h>


QT_BEGIN_NAMESPACE
namespace Ui { class Paint3D; }
QT_END_NAMESPACE

class DrawArea;
class Brushes;
class Paint3D : public QMainWindow
{
    Q_OBJECT

public:
    Paint3D(QWidget *parent = nullptr);
    ~Paint3D();
	
private:
    Ui::Paint3D *ui;

protected:
    void closeEvent(QCloseEvent *event) override;  //stops user from closing the app without saving

private slots:
    //they kind of responsible for the actions
    void open();
    void save();
    void penColor();
    void penWidth();
    void about();
	void pen();
	void marker();
	void eraser();
	void oilBrush();
	void waterColorBrush();
	void undo();
	void redo();
	void add2DShape(QString shape);
	void add3DShape(QString shape);



private:
    //all the methods needed
    void createActions();
	void setBrushProp(int penWidth, Qt::PenCapStyle capStyle, Qt::PenJoinStyle joinStyle,QBrush brushStyle );
	void addDock();
    bool saveCheck();
    bool saveFile(const QByteArray &fileFormat);
    //all variables needed
    DrawArea* drawArea;
	Brushes* brushes;
	QString shape;

	QPushButton* circleButton;
	QPushButton* squareButton;
	QPushButton* triangleButton;
	QPushButton* sphereButton;
	QPushButton* cubeButton;
	QPushButton* coneButton;

};

#endif // PAINT3D_H
