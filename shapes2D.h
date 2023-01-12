#ifndef SHAPES2D_H
#define SHAPES2D_H

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
#include <string>
#include <QWidget>
#include <QtWidgets>

#include <QPointer>
#include <QVTKOpenGLNativeWidget.h>

namespace Ui {
	class shapes2D;
}
class shapes2D : public QWidget
{
	Q_OBJECT
public:
	explicit shapes2D(QWidget *parent = nullptr);
	
	//void setColor(vtkNamedColors color);
	//vtkNamedColors getColor();
	QPointer<QVTKOpenGLNativeWidget> createPolygon(std::string type);

private:
	//vtkNew<vtkNamedColors> colors;
	//vtkNew<vtkRegularPolygonSource> polygonSource;
	std::string type;
};

#endif