#include <QtWidgets>
//#if defined(QT_PRINTSUPPORT_LIB)
//#include <QtPrintSupport/qtprintsupportglobal.h>
//#if QT_CONFIG(printer)
//#if QT_CONFIG(printdialog)
//#include <QPrintDialog>
//#endif // QT_CONFIG(printdialog)
//#include <QPrinter>
//#endif // QT_CONFIG(printer)
//#endif // QT_PRINTSUPPORT_LIB

#include "drawarea.h"
#include "ui_drawarea.h"
#include "Brushes.h"


DrawArea::DrawArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawArea)
{
    //ui->setupUi(this);
	brushes = new Brushes();
    setAttribute(Qt::WA_StaticContents);
    modified = false;
    drawing = false;

}

DrawArea::~DrawArea()
{
    delete ui;
}

//load img and place it into widget
bool DrawArea::openImage(const QString &fileName){
    QImage loadedImage;
    if(!loadedImage.load(fileName))
        return false;
	QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    image = loadedImage;
    modified = false;
    update();
    return true;
}

bool DrawArea::saveImage(const QString &fileName, const char *fileFormat){
    QImage visibleImage = image;
    resizeImage(&visibleImage, size());
    if(visibleImage.save(fileName, fileFormat)){
        modified = false;
        return true;
    }else{
        return false;
    }
}

void DrawArea::clearImage(){
    image.fill(qRgb(255,255,255));
    modified = true; //they need to resave it
    update();
}

void DrawArea::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){ //creates movement
        lastPoint = event->pos();
        drawing = true;
    }
}

void DrawArea::mouseMoveEvent(QMouseEvent *event){
    if((event->buttons() & Qt::LeftButton) && drawing){
        //track movement
        drawLineTo(event->pos());
    }
}

void DrawArea::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton && drawing){
        drawLineTo(event->pos());
        drawing = false;
    }
}

void DrawArea::paintEvent(QPaintEvent *event){
    //sends to widgets to update themselves
    QPainter painter(this);
    QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, image, dirtyRect);
}

void DrawArea::resizeEvent(QResizeEvent *event){
    //resize if img is larger than the window itself
    if(width() > image.width() || height() > image.height()){
        int newWidth = qMax(width()+128 , image.width());
        int newHeight = qMax(height()+12, image.height());
        resizeImage(&image, QSize(newWidth,newHeight));
		
        update();
    }
    QWidget::resizeEvent(event);
}

void DrawArea::drawLineTo(const QPoint &endPoint){
    QPainter painter(&image);
	if (Brushes::initialBrush) {
		QBrush brush = brushes->getQBrush();
		brush.setColor(brushes->penColor());
		brushes->setBrush(brush);
	}
	QPen pen;
	pen.setBrush(brushes->getQBrush());

	pen.setWidth(brushes->penWidth());
	pen.setStyle(Qt::SolidLine);
	pen.setCapStyle(brushes->capStyle());
	pen.setJoinStyle(brushes->penJoinStyle());

	painter.setPen(pen);
    painter.drawLine(lastPoint, endPoint);
    modified = true;
    int rad = (brushes->penWidth()/2)+2;
    update(QRect(lastPoint,endPoint).normalized().adjusted(-rad, -rad, +rad, +rad));
    lastPoint = endPoint;
}


void DrawArea::resizeImage(QImage *image, const QSize &newSize){
    if(image->size() == newSize){
        return;
    }

    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(255,255,255));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0,0), *image);
    *image = newImage;
}

//void DrawArea::print(){
//#if QT_CONFIG(printdialog)
//    QPrinter printer(QPrinter::HighResolution);
//    QPrintDialog printDialog(&printer, this);
//    if(printDialog.exec() == QDialog::Accepted){
//        QPainter painter(&printer);
//        QRect rect = painter.viewPort();
//        QSize size = image.size();
//        size.scale(rect.size(), Qt::KeepAspectRatio);
//        painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
//        painter.setWindow(image.rect());
//        painter.drawImage(0,0,image);
//    }
//#endif
//}
//


void DrawArea::addWidget(QWidget *widget) {
	/*ui->layout()->addWidget(widget);*/
	widget->show();
}

