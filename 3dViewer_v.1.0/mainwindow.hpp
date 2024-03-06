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

    void on_moveRightX_clicked();

    void on_moveLeftX_clicked();

    void on_moveDownY_clicked();

    void on_moveUpY_clicked();

    void on_moveBackZ_clicked();

    void on_moveForthZ_clicked();

    void on_scaleMinus_clicked();

    void on_scalePlus_clicked();

    void on_rotateXplus_clicked();

    void on_rotateXminus_clicked();

    void on_rotateYplus_clicked();

    void on_rotateYminus_clicked();

    void on_rotateZminus_clicked();

    void on_rotateZplus_clicked();

private:
    Ui::MainWindow *ui;
    glView *glWidget;
    void cleanupGLData();
};

#endif // MAINWINDOW_HPP
