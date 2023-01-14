#include "paint3d.h"
#include "./ui_paint3d.h"
#include "shapes2D.h"
#include "shapes3D.h"
#include "drawarea.h"

#include <QtWidgets>
#include <QColor>
#include <QMainWindow>
#include <QDockWidget>
#include <string>
#include <QVTKOpenGLNativeWidget.h>


Paint3D::Paint3D(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Paint3D)
{

    ui->setupUi(this);

    drawArea = new DrawArea();
	setCentralWidget(drawArea);

	brushes = drawArea->getBrushObject();

    createActions();

	resize(1500, 1000);
	//addShape();
	addDock();
	shape = "circle";
}


void Paint3D::addDock() {

	QDockWidget *controlDock = new QDockWidget(this);

	addDockWidget(Qt::RightDockWidgetArea, controlDock);

	controlDock->setWindowTitle("Sidebar");

	QWidget *layoutContainer = new QWidget(this);
	//2d buttons
	circleButton = new QPushButton("Circle", layoutContainer);
	squareButton = new QPushButton("Square", layoutContainer);
	triangleButton = new QPushButton("Triangle", layoutContainer);

	//3d buttons
	sphereButton = new QPushButton("Sphere", layoutContainer);
	cubeButton = new QPushButton("Cube", layoutContainer);
	coneButton = new QPushButton("Cone", layoutContainer);

	QPointer<QGridLayout> dockLayout = new QGridLayout();

	dockLayout->addWidget(circleButton,0,0);
	dockLayout->addWidget(squareButton, 0, 1);
	dockLayout->addWidget(triangleButton, 0, 2);

	dockLayout->addWidget(sphereButton,1,0);
	dockLayout->addWidget(cubeButton, 1, 1);
	dockLayout->addWidget(coneButton, 1, 2);

	layoutContainer->setLayout(dockLayout);

	controlDock->setWidget(layoutContainer);

	connect(circleButton, &QPushButton::released, this, [=]()->void { add2DShape("circle"); });
	connect(squareButton, &QPushButton::released, this, [=]()->void { add2DShape("square"); });
	connect(triangleButton, &QPushButton::released, this, [=]()->void { add2DShape("triangle"); });

	connect(sphereButton, &QPushButton::released, this, [=]()->void { add3DShape("sphere"); });
	connect(cubeButton, &QPushButton::released, this, [=]()->void { add3DShape("cube"); });
	connect(coneButton, &QPushButton::released, this, [=]()->void { add3DShape("cone"); });

	controlDock->show();
}


void Paint3D::closeEvent(QCloseEvent *event){
    if(saveCheck())
        event->accept();
    else
        event->ignore();
}

void Paint3D::open(){
    //check if img is changed first before opening a new file
    if(saveCheck()){
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath());
        if(!fileName.isEmpty()){
            drawArea->openImage(fileName);
        }
    }
}

void Paint3D::save(){
    QAction *action = qobject_cast<QAction *>(sender());
    QByteArray fileFormat = action->data().toByteArray();
    saveFile(fileFormat);
}

void Paint3D::setBrushProp(int penWidth, Qt::PenCapStyle capStyle, Qt::PenJoinStyle joinStyle, QBrush brushStyle){\
	brushes->setPenWidth(penWidth);
	brushes->setPenCapStyle(capStyle);
	brushes->setPenJoinStyle(joinStyle);
	brushes->setBrush(brushStyle);
	Brushes::initialBrush = false;
}

void Paint3D::penColor() {

	QColor newColor = QColorDialog::getColor(brushes->penColor());

	if (newColor.isValid()) {
		brushes->setPenColor(newColor);
	}
	QBrush brush;

	update();
}


void Paint3D::penWidth(){
    bool ok;
	int oldWidth = brushes->penWidth();
    int newWidth = QInputDialog::getInt(this, tr("Draw"), tr("Select pen width"), oldWidth, 1,50,1,&ok);
    if(ok){
        brushes->setPenWidth(newWidth);
    }
}

void Paint3D::pen() {

	int newWidth = 2;
	QBrush brush;
	brush.setColor(brushes->penColor());
	brush.setStyle(Qt::SolidPattern);
	setBrushProp(newWidth, Qt::SquareCap, Qt::RoundJoin, brush);

}

void Paint3D::marker() {

	int newWidth = 4;
	QBrush brush;
	brush.setColor(brushes->penColor());
	brush.setStyle(Qt::SolidPattern);
	setBrushProp(newWidth, Qt::RoundCap, Qt::BevelJoin, brush);

}


void Paint3D::oilBrush() {

	//delay in changing colors -->try static

	int newWidth = 10;
	QBrush brush;
	brush.setColor(brushes->penColor());
	QColor color = brushes->penColor();
	QImage img(":/brushes/brushes images/oilBrush.png");

	int y = 0;
	int x = 0;
	for (int x = 0; x < img.height(); x++) {
		for (int y = 0; y < img.width(); y++) {
			color.setAlpha(img.pixelColor(x, y).alpha());
			img.setPixelColor(x, y, color);
		}
	}
	
	QPixmap pixMap = QPixmap::fromImage(img);
	brush.setTexture(pixMap.scaledToWidth(8, Qt::SmoothTransformation));
	brush.setStyle(Qt::TexturePattern);
	setBrushProp(newWidth, Qt::RoundCap, Qt::RoundJoin, brush);

}

void Paint3D::waterColorBrush() {
	
	//delay in changing colors -->try static

	int newWidth = 10;
	QColor color = brushes->penColor();
	QBrush brush;
	brush.setColor(brushes->penColor());

	QImage img(":/brushes/brushes images/watercolor.png");

	int y = 0;
	int x = 0;
	for (int x = 0; x < img.height(); x++) {
		for (int y = 0; y < img.width(); y++) {
			color.setAlpha(img.pixelColor(x, y).alpha());
			img.setPixelColor(x, y, color);
		}
	}

	QPixmap pixMap = QPixmap::fromImage(img);
	brush.setTexture(pixMap.scaledToWidth(20, Qt::SmoothTransformation));
	brush.setStyle(Qt::TexturePattern);

	setBrushProp(newWidth, Qt::RoundCap, Qt::MPenJoinStyle, brush);

}

void Paint3D::eraser() {
	QBrush brush;
	brush.setColor(Qt::white);
	brush.setStyle(Qt::SolidPattern);
	setBrushProp(brushes->penWidth(), brushes->capStyle(), brushes->penJoinStyle(), brush);
}

void Paint3D::about(){
    QMessageBox::about(this, tr("About Paint"), tr("<p>the <b>paint</b> is a 3D paint application</p>"));
}

void Paint3D::undo() {
	//ui->drawArea->undo();
}

void Paint3D::redo() {
	//ui->drawArea->redo();
}

void Paint3D::add2DShape(QString shape) {

	this->shape = shape;
	shapes2D *newShape = new shapes2D();
	QVTKOpenGLNativeWidget *widgetPtr = newShape->createPolygon(shape,brushes->penColor() );
	widgetPtr->setAutoFillBackground(false);

	QPointer<QVBoxLayout> layout = new QVBoxLayout();
	layout->addWidget(widgetPtr);
	
	QFrame *layoutContainer = new QFrame(this);
	layoutContainer->setLayout(layout); 
	layoutContainer->setGeometry(200, 200, 200, 200);
	layoutContainer->setAutoFillBackground(false);
	layoutContainer->setStyleSheet("background-color: rgba(255, 255, 255,0);");
	layoutContainer->show();
	Paint3D::update();
	
}


void Paint3D::add3DShape(QString shape) {

	this->shape = shape;
	shapes3D *newShape = new shapes3D();
	QVTKOpenGLNativeWidget *widgetPtr = newShape->createPolygon(shape, brushes->penColor());
	widgetPtr->setAutoFillBackground(false);

	QPointer<QVBoxLayout> layout = new QVBoxLayout();
	layout->addWidget(widgetPtr);

	QFrame *layoutContainer = new QFrame(this);
	layoutContainer->setLayout(layout);
	layoutContainer->setGeometry(400,200, 200, 200);
	layoutContainer->setAutoFillBackground(false);
	layoutContainer->setStyleSheet("background-color: rgba(255, 255, 255,0);");
	layoutContainer->show();
	Paint3D::update();

}


// all menu systems
void Paint3D::createActions(){

    connect(ui->actionOpen,SIGNAL(triggered()),this, SLOT(open()));

    //save as supported file formats
    foreach (QByteArray format, QImageWriter:: supportedImageFormats()) {
        QString text = tr("%1...").arg(QString(format).toUpper());
        //create an action for each file format
        QAction *action = new QAction(text, this);
        action->setData(format);
        connect(action, SIGNAL(triggered()), this, SLOT(save()));
		ui->menuSaveAs->addAction(action);
    }

    connect(ui->actionExit, SIGNAL(triggered()),this, SLOT(close()));

	connect(ui->actionPenColor,SIGNAL(triggered()), this, SLOT(penColor()));

    connect(ui->actionPenWidth,SIGNAL(triggered()), this, SLOT(penWidth()));

    connect(ui->actionClearScreen, SIGNAL(triggered()), drawArea, SLOT(clearImage()));

	connect(ui->actionAbout, SIGNAL(triggered()), SLOT(about()));

    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp ,SLOT(aboutQt()));

	connect(ui->actionPen, SIGNAL(triggered()), this, SLOT(pen()));
	connect(ui->actionEraser, SIGNAL(triggered()), this, SLOT(eraser()));
	connect(ui->actionMarker, SIGNAL(triggered()), this, SLOT(marker()));
	connect(ui->actionOilBrush, SIGNAL(triggered()), this, SLOT(oilBrush()));
	connect(ui->actionWaterColorBrush, SIGNAL(triggered()), this, SLOT(waterColorBrush()));
	connect(ui->actionUndo, SIGNAL(triggered()), this, SLOT(undo()));
	connect(ui->actionRedo, SIGNAL(triggered()), this, SLOT(redo()));


	//drawCircleAction = new QAction(tr("&drawCircleButton"), this);
	//connect(this->circleButton, SIGNAL(clicked()), this, SLOT(addShape())); 

}


bool Paint3D::saveCheck(){
    if(drawArea->isModified()){
        int ret = QMessageBox::warning(this,
                                   tr("Paint"),
                                   tr("The Image has been modified.\n"
                                      "Do you want to save changes?"),
                                   QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel,
                                       QMessageBox::Save);
        if(ret == QMessageBox::Save){
            return saveFile("png");
        }else if(ret == QMessageBox::Cancel){
            return false;
        }
    }
    return true;
}

bool Paint3D::saveFile(const QByteArray &fileFormat){
    QString initialPath = QDir::currentPath() + "/untitled." + fileFormat;
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save As"),
                                                    initialPath,
                                                    tr("%1 Files (*.%2);; All Files(*)")
                                                    .arg(QString::fromLatin1(fileFormat.toUpper()))
                                                    .arg(QString::fromLatin1(fileFormat)));
    if(fileName.isEmpty())
        return false;
    else
        return drawArea->saveImage(fileName, fileFormat.constData());
}


Paint3D::~Paint3D()
{
	delete ui;
}