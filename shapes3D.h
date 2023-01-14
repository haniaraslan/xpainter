#ifndef SHAPES3D_H
#define SHAPES3D_H

#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkCylinderSource.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkRegularPolygonSource.h>
#include <array>
#include <QString>
#include <QWidget>
#include <QtWidgets>
#include <QColor>
#include <QPointer>
#include <QVTKOpenGLNativeWidget.h>

namespace Ui {
	class shapes3D;
}
class shapes3D : public QWidget
{
	Q_OBJECT
public:
	explicit shapes3D(QWidget *parent = nullptr);
	
	//void setColor(vtkNamedColors color);
	//vtkNamedColors getColor();
	QVTKOpenGLNativeWidget *createPolygon(QString type, QColor color);

private:
	//vtkNew<vtkNamedColors> colors;
	//vtkNew<vtkRegularPolygonSource> polygonSource;
	std::string type;
};

#endif