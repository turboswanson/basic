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

    ui->scaleLbl->setText(QString::number(ui->scaleSlider->value()));
//    glWidget = new glView(this);

//    glWidget->setParent(ui->glBox);

//    QVBoxLayout *layout = new QVBoxLayout(ui->glBox);
//    layout->setContentsMargins(0, 0, 0, 0);
//    layout->addWidget(glWidget);

//    ui->glBox->setLayout(layout);

//    glWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

//    char *filename = "/home/mitchelk/Qt/s21_3dViewer/cube.obj";
//    parser(&glWidget->glData,filename);

//    QObject::connect(glWidget, &QObject::destroyed, this, &MainWindow::cleanupGLData);

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
    ui->scaleLbl->setText(QString::number(value));
    if(init) glWidget->setScale(value/10.0);

}

