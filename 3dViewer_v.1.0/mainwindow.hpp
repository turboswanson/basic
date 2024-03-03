#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "glview.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void initializeGlWidget();
    int init;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_fileBtn_clicked();

    void on_scaleSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    glView *glWidget;
    void cleanupGLData();
};

#endif // MAINWINDOW_HPP
