/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *glBox;
    QGroupBox *groupBox;
    QPushButton *fileBtn;
    QLabel *moveXlbl;
    QPushButton *moveRightX;
    QPushButton *moveLeftX;
    QLabel *moveYlbl;
    QPushButton *moveDownY;
    QPushButton *moveUpY;
    QLabel *moveZlbl;
    QPushButton *moveBackZ;
    QPushButton *moveForthZ;
    QLabel *scale;
    QPushButton *scaleMinus;
    QPushButton *scalePlus;
    QLabel *rotateX;
    QPushButton *rotateXminus;
    QPushButton *rotateXplus;
    QLabel *rotateY;
    QPushButton *rotateYminus;
    QPushButton *rotateYplus;
    QLabel *rotateY_2;
    QPushButton *rotateZminus;
    QPushButton *rotateZplus;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 800);
        MainWindow->setMinimumSize(QSize(1200, 800));
        MainWindow->setMaximumSize(QSize(1200, 800));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        glBox = new QGroupBox(centralwidget);
        glBox->setObjectName(QString::fromUtf8("glBox"));
        glBox->setGeometry(QRect(20, 20, 800, 700));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(840, 0, 340, 721));
        QFont font;
        font.setPointSize(13);
        groupBox->setFont(font);
        groupBox->setAlignment(Qt::AlignCenter);
        fileBtn = new QPushButton(groupBox);
        fileBtn->setObjectName(QString::fromUtf8("fileBtn"));
        fileBtn->setGeometry(QRect(120, 30, 111, 31));
        moveXlbl = new QLabel(groupBox);
        moveXlbl->setObjectName(QString::fromUtf8("moveXlbl"));
        moveXlbl->setGeometry(QRect(130, 70, 100, 20));
        moveRightX = new QPushButton(groupBox);
        moveRightX->setObjectName(QString::fromUtf8("moveRightX"));
        moveRightX->setGeometry(QRect(180, 100, 80, 25));
        moveLeftX = new QPushButton(groupBox);
        moveLeftX->setObjectName(QString::fromUtf8("moveLeftX"));
        moveLeftX->setGeometry(QRect(80, 100, 80, 25));
        moveYlbl = new QLabel(groupBox);
        moveYlbl->setObjectName(QString::fromUtf8("moveYlbl"));
        moveYlbl->setGeometry(QRect(130, 140, 100, 20));
        moveDownY = new QPushButton(groupBox);
        moveDownY->setObjectName(QString::fromUtf8("moveDownY"));
        moveDownY->setGeometry(QRect(80, 170, 80, 25));
        moveUpY = new QPushButton(groupBox);
        moveUpY->setObjectName(QString::fromUtf8("moveUpY"));
        moveUpY->setGeometry(QRect(180, 170, 80, 25));
        moveZlbl = new QLabel(groupBox);
        moveZlbl->setObjectName(QString::fromUtf8("moveZlbl"));
        moveZlbl->setGeometry(QRect(130, 210, 100, 20));
        moveBackZ = new QPushButton(groupBox);
        moveBackZ->setObjectName(QString::fromUtf8("moveBackZ"));
        moveBackZ->setGeometry(QRect(80, 240, 80, 25));
        moveForthZ = new QPushButton(groupBox);
        moveForthZ->setObjectName(QString::fromUtf8("moveForthZ"));
        moveForthZ->setGeometry(QRect(180, 240, 80, 25));
        scale = new QLabel(groupBox);
        scale->setObjectName(QString::fromUtf8("scale"));
        scale->setGeometry(QRect(130, 280, 100, 20));
        scaleMinus = new QPushButton(groupBox);
        scaleMinus->setObjectName(QString::fromUtf8("scaleMinus"));
        scaleMinus->setGeometry(QRect(80, 310, 80, 25));
        scalePlus = new QPushButton(groupBox);
        scalePlus->setObjectName(QString::fromUtf8("scalePlus"));
        scalePlus->setGeometry(QRect(180, 310, 80, 25));
        rotateX = new QLabel(groupBox);
        rotateX->setObjectName(QString::fromUtf8("rotateX"));
        rotateX->setGeometry(QRect(130, 350, 100, 20));
        rotateXminus = new QPushButton(groupBox);
        rotateXminus->setObjectName(QString::fromUtf8("rotateXminus"));
        rotateXminus->setGeometry(QRect(80, 380, 80, 25));
        rotateXplus = new QPushButton(groupBox);
        rotateXplus->setObjectName(QString::fromUtf8("rotateXplus"));
        rotateXplus->setGeometry(QRect(180, 380, 80, 25));
        rotateY = new QLabel(groupBox);
        rotateY->setObjectName(QString::fromUtf8("rotateY"));
        rotateY->setGeometry(QRect(130, 420, 100, 20));
        rotateYminus = new QPushButton(groupBox);
        rotateYminus->setObjectName(QString::fromUtf8("rotateYminus"));
        rotateYminus->setGeometry(QRect(80, 450, 80, 25));
        rotateYplus = new QPushButton(groupBox);
        rotateYplus->setObjectName(QString::fromUtf8("rotateYplus"));
        rotateYplus->setGeometry(QRect(180, 450, 80, 25));
        rotateY_2 = new QLabel(groupBox);
        rotateY_2->setObjectName(QString::fromUtf8("rotateY_2"));
        rotateY_2->setGeometry(QRect(130, 490, 100, 20));
        rotateZminus = new QPushButton(groupBox);
        rotateZminus->setObjectName(QString::fromUtf8("rotateZminus"));
        rotateZminus->setGeometry(QRect(80, 520, 80, 25));
        rotateZplus = new QPushButton(groupBox);
        rotateZplus->setObjectName(QString::fromUtf8("rotateZplus"));
        rotateZplus->setGeometry(QRect(180, 520, 80, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "3D_VIEWER", nullptr));
        glBox->setTitle(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Control Panel", nullptr));
        fileBtn->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
        moveXlbl->setText(QCoreApplication::translate("MainWindow", "Move X :", nullptr));
        moveRightX->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        moveLeftX->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        moveYlbl->setText(QCoreApplication::translate("MainWindow", "Move Y :", nullptr));
        moveDownY->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        moveUpY->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        moveZlbl->setText(QCoreApplication::translate("MainWindow", "Move Z :", nullptr));
        moveBackZ->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        moveForthZ->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        scale->setText(QCoreApplication::translate("MainWindow", "Scale :", nullptr));
        scaleMinus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        scalePlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        rotateX->setText(QCoreApplication::translate("MainWindow", "Rotate X :", nullptr));
        rotateXminus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        rotateXplus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        rotateY->setText(QCoreApplication::translate("MainWindow", "Rotate Y :", nullptr));
        rotateYminus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        rotateYplus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        rotateY_2->setText(QCoreApplication::translate("MainWindow", "Rotate Z :", nullptr));
        rotateZminus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        rotateZplus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
