#include "glview.hpp"
#include "ui_glview.h"

glView::glView(QWidget *parent) : QGLWidget(parent)
{
//    ui->setupUi(this);
    setWindowTitle("3DVIEWER");
//    setGeometry(2,21,950,750);

//    connect(&timer,SIGNAL(timeout()),this,SLOT(updateGL()));
//    timer.start(16);

}

glView::~glView()
{
//    delete ui;
}

void glView::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
}

void glView::resizeGL(int w, int h)
{     double scale = glData.scale+5.0;

      glViewport(0, 0, w, h);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glOrtho(-scale,scale,-scale,scale,scale,-scale);
//      qDebug() << "SCALE : " << scale;

}

void glView::paintGL()
{
    glClearColor(0.2,0.2,0.2,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    glMatrixMode(GL_MODELVIEW); // for static moves, turn off when timer is on
    glLoadIdentity(); // for static moves, turn off when timer is on

//    glRotatef(0.5,-3,-3,-3); // for timer
    double factor = glData.factor;
    double angle = glData.angle;
    double move_ud = glData.step_ud;
    double move_lr = glData.step_lr;
    double rotX = glData.rotX;
    double rotY = glData.rotY;
    double rotZ = glData.rotZ;

//    qDebug() << "ANGLE : " << angle;

    glRotated(angle, rotX, rotY, rotZ);
    glScaled(factor, factor, factor);
    glTranslated(move_lr, move_ud, 1.0);


 static GLfloat pColors[] = {
         1.0f, 0.0f, 0.0f, // red
         0.0f, 1.0f, 0.0f, // green
         0.0f, 0.0f, 1.0f, // blue
         1.0f, 1.0f, 0.0f, // yellow
         1.0f, 0.0f, 1.0f, // magenta
         0.0f, 1.0f, 1.0f, // cyan
         0.5f, 0.5f, 0.5f, // gray
         1.0f, 1.0f, 1.0f, // white
   };


    glRotatef(xRot, 0.5, 0, 0);
    glRotatef(yRot, 0, 0.5, 0);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3,GL_DOUBLE,0,glData.pVerts);
    glColorPointer(3, GL_FLOAT, 0, pColors);

    glPointSize(5.0f); // Set point size

//    glDrawArrays(GL_POINTS, 0, glData.vertex_count);

//    glDrawElements(GL_LINE_LOOP, 36, GL_UNSIGNED_INT, glData.pInds);


    for(unsigned int i = 0; i < glData.facets_count; i++) {
//        glDrawElements(GL_LINE_LOOP,polygons[i].count,GL_UNSIGNED_INT,polygons[i].array);
        glDrawElements(GL_LINE_LOOP,glData.polygons[i].count_v,GL_UNSIGNED_INT,glData.polygons[i].pInds);
    }


    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);



}

void glView :: mousePressEvent(QMouseEvent *mo) {
    mPos = mo->pos();
}

void glView :: mouseMoveEvent(QMouseEvent *mo) {
    xRot = 0.03 / M_PI *(mo->pos().y() - mPos.y());
    yRot = 0.03 / M_PI *(mo->pos().x() - mPos.x());
    updateGL();

}

void glView :: setScale(double factor) {
//    qDebug() << "FACTOR : " << factor;
    glData.factor = factor;

    updateGL();
}

void glView :: setAngleX(double angle) {
    glData.angle = angle;
    glData.rotX = 1.0;
    glData.rotY = 0.1;
    glData.rotZ = 0.1;

    updateGL();
}

void glView :: setAngleY(double angle) {
    glData.angle = angle;
    glData.rotX = 0.1;
    glData.rotY = 1.0;
    glData.rotZ = 0.1;

    updateGL();
}

void glView :: setAngleZ(double angle) {
    glData.rotX = 0.1;
    glData.rotY = 0.1;
    glData.rotZ = 1.0;
    glData.angle = angle;

    updateGL();
}

void glView :: setStepUd(double step) {
    glData.step_ud = step;

    updateGL();
}

void glView :: setStepLr(double step) {
    glData.step_lr = step;

    updateGL();
}

