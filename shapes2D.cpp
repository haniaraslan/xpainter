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

QPointer<QVTKOpenGLNativeWidget> shapes2D::createPolygon(std::string type) {
	vtkNew<vtkNamedColors> colors;
	vtkNew<vtkRegularPolygonSource> polygonSource;

	polygonSource->GeneratePolygonOff();

	if (type == "circle") {
		polygonSource->SetNumberOfSides(50); 
	}
	else if (type == "square") {
		polygonSource->SetNumberOfSides(4); 
	}
	else if (type == "triangle") {
		polygonSource->SetNumberOfSides(3); 
	}
	else if (type == "pentagon") {
		polygonSource->SetNumberOfSides(5); 
	}
	else if (type == "hexagon") {
		polygonSource->SetNumberOfSides(6); 
	}

	//TODO:: set center to mouse location

		//visualize
	vtkNew<vtkPolyDataMapper> mapper;
	mapper->SetInputConnection(polygonSource->GetOutputPort());

	vtkNew<vtkActor> actor;
	actor->SetMapper(mapper);
	actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

	vtkNew<vtkRenderer> renderer;
	renderer->AddActor(actor);
	renderer->SetBackground(colors->GetColor3d("DarkGreen").GetData());

	vtkNew<vtkRenderWindow> renderWindow;
	renderWindow->SetSize(300, 300);
	renderWindow->AddRenderer(renderer);
	renderWindow->SetWindowName(type.c_str());

	//-----------------rendering---------------------------//
	/*vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
	renderWindowInteractor->SetRenderWindow(renderWindow);

	vtkNew <vtkInteractorStyleTrackballCamera> style;
	renderWindowInteractor->SetInteractorStyle(style);

	renderWindow->Render();
	renderWindowInteractor->Start();*/

	QPointer<QVTKOpenGLNativeWidget> vtkRenderWidget =
		new QVTKOpenGLNativeWidget();
	//mainWindow.setCentralWidget(vtkRenderWidget);

	// VTK part
	vtkNew<vtkGenericOpenGLRenderWindow> window;
	vtkRenderWidget->setRenderWindow(window.Get());
	window->SetAlphaBitPlanes(1);
	window->AddRenderer(renderer);

	return vtkRenderWidget;

}