#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QtWidgets>
#include <QColor>
#include <QPoint>
#include <QImage>
#include <QWidget>
#include <QColorDialog>

class Brushes;

namespace Ui {
class DrawArea;
}

class DrawArea : public QWidget
{
    Q_OBJECT

public:

    explicit DrawArea(QWidget *parent = nullptr);
    bool openImage(const QString &fileName);
    bool saveImage(const QString &fileName, const char *fileFormat);
	void addWidget(QWidget *widget);
    bool isModified() const {return modified;}

	Brushes* getBrushObject() const { return brushes; }

    ~DrawArea();

private slots:
    //event handler
    void clearImage();
//    void print();

protected:

    //mouse events
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent (QPaintEvent *event) override;
    void resizeEvent (QResizeEvent *event) override;

private:
    Ui::DrawArea *ui;
	Brushes *brushes;

	//void addDock();
    void drawLineTo (const QPoint &endPoint);
	void eraseLineTo(const QPoint &endPoint);

    void resizeImage(QImage *image, const QSize &newSize);
    bool modified; //monitor to know if the image is modified or not
    bool drawing; //is the user currently drawing
    QImage image;
    QPoint lastPoint; //to know where the mouse was standing in order to move to next

};

#endif // DRAWAREA_H
