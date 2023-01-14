#include "shapes3D.h"


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
#include <vtkSphereSource.h>
#include <vtkCubeSource.h>
#include <vtkConeSource.h>



shapes3D::shapes3D(QWidget *parent) :
	QWidget(parent)
{
	
}


//void setColor(vtkNamedColors color) {}
//<vtkNamedColors> getColor() {}

QVTKOpenGLNativeWidget *shapes3D::createPolygon(QString shape, QColor color) {

	vtkNew<vtkNamedColors> colors;
	colors->SetColor("Current", color.redF() , color.greenF(), color.blueF(), 1);
	
	QPointer<QVTKOpenGLNativeWidget> vtkRenderWidget =
		new QVTKOpenGLNativeWidget();

	vtkNew<vtkGenericOpenGLRenderWindow> window;
	vtkRenderWidget->setRenderWindow(window.Get());
	vtkRenderWidget->setAutoFillBackground(false);

	vtkNew<vtkPolyDataMapper> mapper;

	if (shape == "sphere") {
		vtkNew<vtkSphereSource> source;
		source->SetCenter(0.0, 0.0, 0.0);
		source->Update();
		mapper->SetInputConnection(source->GetOutputPort());

	}
	else if(shape == "cube") {
		vtkNew<vtkCubeSource> source;
		source->SetCenter(0.0, 0.0, 0.0);
		source->Update();
		mapper->SetInputConnection(source->GetOutputPort());
	}
	else if (shape == "cone") {
		vtkNew<vtkConeSource> source;
		source->SetCenter(0.0, 0.0, 0.0);
		source->Update();
		mapper->SetInputConnection(source->GetOutputPort());
	}

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
	renderer->GetActiveCamera()->Zoom(1.2);

	window->SetAlphaBitPlanes(1);
	vtkRenderWidget->setStyleSheet("background-color: rgba(255, 255, 255,0);");
	window->AddRenderer(renderer);


	return vtkRenderWidget;

}