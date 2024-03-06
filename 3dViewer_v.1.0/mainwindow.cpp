#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "parser.h"
#include "glview.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init = 0;
}

void MainWindow::cleanupGLData() {
    free_data(&glWidget->glData);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fileBtn_clicked()
{
   QString fileName = QFileDialog::getOpenFileName(nullptr, "Open OBJ File", QDir::homePath(), "OBJ Files (*.obj)");

   if (fileName.isEmpty()) {
        qDebug() << "Selected file doesn't exist" << fileName;
    } else {
        if(!init)
        {
            initializeGlWidget();
        }else{
            free_data(&glWidget->glData);
        }

        QByteArray byteArray = fileName.toUtf8();
        char *filename = byteArray.data();
        parser(&glWidget->glData,filename);

        glWidget->resizeGL(800,700);
        glWidget->updateGL();

    }
}

void MainWindow::initializeGlWidget() {
    init = 1;
    glWidget = new glView(this);

    glWidget->setParent(ui->glBox);

    QVBoxLayout *layout = new QVBoxLayout(ui->glBox);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(glWidget);
    ui->glBox->setLayout(layout);

    glWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QObject::connect(glWidget, &QObject::destroyed, this, &MainWindow::cleanupGLData);

}

void MainWindow::on_moveRightX_clicked()
{
    if(init){
        translation(&glWidget->glData,0.1,0,0);

        glWidget->update();
    }
}


void MainWindow::on_moveLeftX_clicked()
{
    if(init){
        translation(&glWidget->glData,-0.1,0,0);

        glWidget->update();
    }
}


void MainWindow::on_moveDownY_clicked()
{
    if(init){
        translation(&glWidget->glData,0,-0.1,0);

        glWidget->update();
    }
}


void MainWindow::on_moveUpY_clicked()
{
    if(init){
        translation(&glWidget->glData,0,0.1,0);

        glWidget->update();
    }
}


void MainWindow::on_moveBackZ_clicked()
{
    if(init){
        translation(&glWidget->glData,0,0,-1.0);

        glWidget->update();
    }
}


void MainWindow::on_moveForthZ_clicked()
{
    if(init){
        translation(&glWidget->glData,0,0,1.0);

        glWidget->update();
    }
}


void MainWindow::on_scaleMinus_clicked()
{

    if(init){
        scaling(&glWidget->glData,0.95);
        glWidget->update();
    }
}


void MainWindow::on_scalePlus_clicked()
{
    if(init){
        scaling(&glWidget->glData,1.05);
        glWidget->update();
    }
}


void MainWindow::on_rotateXplus_clicked()
{
    if(init) {
        rotation_by_ox(&glWidget->glData,0.1);
        glWidget->update();
    }
}


void MainWindow::on_rotateXminus_clicked()
{
    if(init) {
        rotation_by_ox(&glWidget->glData,-0.1);
        glWidget->update();
    }
}


void MainWindow::on_rotateYplus_clicked()
{
    if(init) {
        rotation_by_oy(&glWidget->glData,0.1);
        glWidget->update();
    }
}


void MainWindow::on_rotateYminus_clicked()
{
    if(init) {
        rotation_by_oy(&glWidget->glData,-0.1);
        glWidget->update();
    }
}


void MainWindow::on_rotateZminus_clicked()
{
    if(init) {
        rotation_by_oz(&glWidget->glData,-0.1);
        glWidget->update();
    }
}


void MainWindow::on_rotateZplus_clicked()
{
    if(init) {
        rotation_by_oz(&glWidget->glData,0.1);
        glWidget->update();
    }
}

