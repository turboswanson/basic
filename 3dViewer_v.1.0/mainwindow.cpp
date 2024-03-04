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
            glWidget->glData.factor = 1.0;
            glWidget->glData.angle = 0.0;
            glWidget->glData.step_ud = 0.0;
            glWidget->glData.step_lr = 0.0;
            glWidget->glData.rotX = 0.0;
            glWidget->glData.rotY = 0.0;
            glWidget->glData.rotZ = 0.0;

            glWidget->setParent(ui->glBox);

            QVBoxLayout *layout = new QVBoxLayout(ui->glBox);
            layout->setContentsMargins(0, 0, 0, 0);
            layout->addWidget(glWidget);

            ui->glBox->setLayout(layout);

            glWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

            QObject::connect(glWidget, &QObject::destroyed, this, &MainWindow::cleanupGLData);

}


void MainWindow::on_scaleSlider_valueChanged(int value)
{
   if(init) glWidget->setScale(value/10.0);

}

void MainWindow::on_rotationSlider_valueChanged(int value)
{
    if(init) glWidget->setAngleX(value);
}

void MainWindow::on_rotateYSlider_valueChanged(int value)
{
    if(init) glWidget->setAngleY(value);
}


void MainWindow::on_rotateZSlider_valueChanged(int value)
{
    if(init) glWidget->setAngleZ(value);
}

void MainWindow::on_moveSlider_valueChanged(int value)
{
    if(init) glWidget->setStepUd(value);
}


void MainWindow::on_movelrSlider_valueChanged(int value)
{
    if(init) glWidget->setStepLr(value);
}



