#include "shapes2D.h"
//#include "ui_shapes2D.h"
//#include "shapes2D.ui"


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
#include <QVTKOpenGLNativeWidget.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <QPointer>


shapes2D::shapes2D(QWidget *parent) :
	QWidget(parent)
{
	
}

//shapes2D::~shapes2D()
//{
//	delete ui;
//}
//
//void setColor(vtkNamedColors color) {}
//<vtkNamedColors> getColor() {}

QVTKOpenGLNativeWidget *shapes2D::createPolygon(QString shape, QColor color) {
	
	vtkNew<vtkNamedColors> colors;
	colors->SetColor("Current", color.redF(), color.greenF(), color.blueF(), 1);

	QPointer<QVTKOpenGLNativeWidget> vtkRenderWidget = new QVTKOpenGLNativeWidget();
	
	vtkNew<vtkGenericOpenGLRenderWindow> window;
	vtkRenderWidget->setRenderWindow(window.Get());
	vtkRenderWidget->setAutoFillBackground(false);

	vtkNew<vtkRegularPolygonSource> polygonSource;

	polygonSource->GeneratePolygonOff();

	if (shape == "circle") {
		polygonSource->SetNumberOfSides(50);
	}
	else if (shape == "square") {
		polygonSource->SetNumberOfSides(4);
	}
	else if (shape == "triangle") {
		polygonSource->SetNumberOfSides(3);
	}
	else if (shape == "pentagon") {
		polygonSource->SetNumberOfSides(5);
	}
	else if (shape == "hexagon") {
		polygonSource->SetNumberOfSides(6);
	}

	vtkNew<vtkPolyDataMapper> mapper;
	mapper->SetInputConnection(polygonSource->GetOutputPort());

	vtkNew<vtkActor> actor;
	actor->SetMapper(mapper);
	actor->GetProperty()->SetColor(colors->GetColor3d("Current").GetData());

	vtkNew<vtkRenderer> renderer;
	renderer->AddActor(actor);
	renderer->SetBackgroundAlpha(0.0);
	renderer->SetBackground(1.0,1.0,1.0);
	
	renderer->SetUseDepthPeeling(1);
	renderer->SetOcclusionRatio(0.2);

	renderer->ResetCamera();

	renderer->GetActiveCamera()->Zoom(1.4);

	window->SetAlphaBitPlanes(1);
	vtkRenderWidget->setStyleSheet("background-color: rgba(255, 255, 255,0);");
	window->AddRenderer(renderer);

	this->widget = vtkRenderWidget;

	return vtkRenderWidget;

}
