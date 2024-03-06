#ifndef GLVIEW_HPP
#define GLVIEW_HPP

#include <QGLWidget>
#include <QMouseEvent>
#include <QTimer>
#include "parser.h"
#include "transform.h"
#include <QtOpenGL>
#include <QPoint>
#include <GL/gl.h>

QT_BEGIN_NAMESPACE
namespace Ui { class glView; }
QT_END_NAMESPACE

class glView : public QGLWidget
{
    Q_OBJECT

public:
       glView(QWidget *parent = nullptr);
       Data glData;
       void initializeGL() override;
       void paintGL() override;
       void resizeGL(int w, int h) override;
       void update();

       ~glView();

private:
    Ui::glView *ui;
    double xRot, yRot, zRot;
    QPoint mPos;
    QTimer timer;
    void mousePressEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;

};
#endif // GLVIEW_HPP
