#include "glview.hpp"
#include "transform.h"
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
{
      glViewport(0, 0, w, h);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      //      qDebug() << "SCALE : " << scale;
      //      qDebug() << "SCALE : " << scale;
      //      qDebug() << "SCALE : " << scale;
      //      qDebug() << "SCALE : " << scale;
      //      qDebug() << "SCALE : " << scale;
      //      qDebug() << "SCALE : " << scale;

      for(int i = 0; i < 6; i++) {
          qDebug() << "SCALE : \n" << glData.scale[i];
      }

      glFrustum(glData.scale[0]-10.0,glData.scale[1]+10.0,glData.scale[2]-10.0,glData.scale[3]+10.0,glData.scale[4]+10.0,glData.scale[5]-10.0);
        //glOrtho

}

void glView::paintGL()
{
    glClearColor(0.2,0.2,0.2,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); // for static moves, turn off when timer is on
    glLoadIdentity(); // for static moves, turn off when timer is on

//    glRotatef(0.5,-3,-3,-3); // for timer


//    glRotated(angle, rotX, rotY, rotZ);
//    glScaled(factor, factor, factor);
//    glTranslated(move_lr, move_ud, 1.0);


    GLfloat colors[][3] = {
        {1.0, 0.0, 0.0},   // Red
        {0.0, 1.0, 0.0},   // Green
        {0.0, 0.0, 1.0},   // Blue
        {1.0, 1.0, 0.0},   // Yellow
        {1.0, 0.0, 1.0},   // Magenta
        {0.0, 1.0, 1.0},   // Cyan
        {0.5, 0.5, 0.5},   // Gray
        {1.0, 0.5, 0.0}    // Orange
    };

int num_colors = sizeof(colors) / sizeof(colors[0]);

//    glRotatef(xRot, 0.5, 0, 0);
//    glRotatef(yRot, 0, 0.5, 0);

    int f_count = glData.facets_count;
    int index = 0;
//     qDebug() << "Scale : " << angle;

    for(int i = 0; i < f_count; i++) {
        glBegin(GL_LINE_LOOP);
        glColor3fv(colors[i % num_colors]);

        for(int j = 0; j < 3; j++){
          index = glData.polygons[i].pInds[j];

          glVertex3f(glData.vertexes.matrix[index][0],glData.vertexes.matrix[index][1],glData.vertexes.matrix[index][2]);

       }
        glEnd();
    }



//    glEnableClientState(GL_VERTEX_ARRAY);
//    glEnableClientState(GL_COLOR_ARRAY);

//    glVertexPointer(3,GL_DOUBLE,0,glData.pVerts);
//    glColorPointer(3, GL_FLOAT, 0, pColors);

//    glPointSize(5.0f); // Set point size

//    for(unsigned int i = 0; i < glData.facets_count; i++) {
//        glDrawElements(GL_LINE_LOOP,glData.polygons[i].count_v,GL_UNSIGNED_INT,glData.polygons[i].pInds);
//    }


//    glDisableClientState(GL_COLOR_ARRAY);
//    glDisableClientState(GL_VERTEX_ARRAY);



}

void glView :: mousePressEvent(QMouseEvent *mo) {
    mPos = mo->pos();
}

void glView :: mouseMoveEvent(QMouseEvent *mo) {
    xRot = 0.03 / M_PI *(mo->pos().y() - mPos.y());
    yRot = 0.03 / M_PI *(mo->pos().x() - mPos.x());
    updateGL();

}



void glView :: update() {

    updateGL();
}

