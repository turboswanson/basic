/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionBackground_color;
    QAction *actionSave_settings;
    QAction *actionParallel;
    QAction *actionCentral;
    QAction *actionSize_Edge;
    QAction *actionColor_Edge;
    QAction *actionSolidLine_Edge;
    QAction *actionLineDots_Edge;
    QAction *actionSize_Vertex;
    QAction *actionColor_Vertex;
    QAction *actionNone;
    QAction *actionCircle;
    QAction *actionSquere;
    QAction *actionEdge;
    QAction *actionVertex;
    QAction *actionDisplay_Method;
    QAction *actionDisplay_Method_2;
    QAction *actionOnly_vertex;
    QAction *actionOnly_edge;
    QAction *actionMix;
    QAction *actionImage;
    QAction *actionGIF;
    QWidget *centralwidget;
    QGroupBox *glBox;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *fileBtn;
    QPushButton *PB_Normalize;
    QHBoxLayout *horizontalLayout_4;
    QLabel *moveXlbl;
    QLineEdit *moveStepX;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *moveXleft;
    QPushButton *moveXright;
    QHBoxLayout *horizontalLayout_5;
    QLabel *moveYlbl;
    QLineEdit *moveStepY;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *moveYdown;
    QPushButton *moveYup;
    QHBoxLayout *horizontalLayout_7;
    QLabel *moveZlbl;
    QLineEdit *moveStepZ;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *moveZfar;
    QPushButton *moveZnear;
    QHBoxLayout *horizontalLayout_9;
    QLabel *scale;
    QLineEdit *scaleStep;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *scaleMinus;
    QPushButton *scalePlus;
    QHBoxLayout *horizontalLayout_12;
    QLabel *rotateX;
    QLineEdit *rotateStepX;
    QHBoxLayout *horizontalLayout_13;
    QPushButton *rotateXminus;
    QPushButton *rotateXplus;
    QHBoxLayout *horizontalLayout_14;
    QLabel *rotateY;
    QLineEdit *rotateStepY;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *rotateYminus;
    QPushButton *rotateYplus;
    QHBoxLayout *horizontalLayout_16;
    QLabel *rotateZ;
    QLineEdit *rotateStepZ;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *rotateZminus;
    QPushButton *rotateZplus;
    QPushButton *stopBtn;
    QLabel *fileNameLbl;
    QLabel *vertexInfo;
    QLabel *edgeInfo;
    QMenuBar *menubar;
    QMenu *menuSettings;
    QMenu *menuType_of_projection;
    QMenu *menuDisplay;
    QMenu *menuType_edge;
    QMenu *menuSave;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 800);
        MainWindow->setMinimumSize(QSize(1200, 800));
        MainWindow->setMaximumSize(QSize(1200, 800));
        actionBackground_color = new QAction(MainWindow);
        actionBackground_color->setObjectName("actionBackground_color");
        actionSave_settings = new QAction(MainWindow);
        actionSave_settings->setObjectName("actionSave_settings");
        actionParallel = new QAction(MainWindow);
        actionParallel->setObjectName("actionParallel");
        actionParallel->setCheckable(true);
        actionCentral = new QAction(MainWindow);
        actionCentral->setObjectName("actionCentral");
        actionCentral->setCheckable(true);
        actionSize_Edge = new QAction(MainWindow);
        actionSize_Edge->setObjectName("actionSize_Edge");
        actionSize_Edge->setCheckable(false);
        actionColor_Edge = new QAction(MainWindow);
        actionColor_Edge->setObjectName("actionColor_Edge");
        actionSolidLine_Edge = new QAction(MainWindow);
        actionSolidLine_Edge->setObjectName("actionSolidLine_Edge");
        actionSolidLine_Edge->setCheckable(true);
        actionSolidLine_Edge->setChecked(true);
        actionLineDots_Edge = new QAction(MainWindow);
        actionLineDots_Edge->setObjectName("actionLineDots_Edge");
        actionLineDots_Edge->setCheckable(true);
        actionLineDots_Edge->setChecked(false);
        actionSize_Vertex = new QAction(MainWindow);
        actionSize_Vertex->setObjectName("actionSize_Vertex");
        actionColor_Vertex = new QAction(MainWindow);
        actionColor_Vertex->setObjectName("actionColor_Vertex");
        actionNone = new QAction(MainWindow);
        actionNone->setObjectName("actionNone");
        actionNone->setCheckable(true);
        actionNone->setChecked(true);
        actionNone->setEnabled(true);
        actionCircle = new QAction(MainWindow);
        actionCircle->setObjectName("actionCircle");
        actionCircle->setCheckable(true);
        actionSquere = new QAction(MainWindow);
        actionSquere->setObjectName("actionSquere");
        actionSquere->setCheckable(true);
        actionEdge = new QAction(MainWindow);
        actionEdge->setObjectName("actionEdge");
        actionEdge->setEnabled(false);
        actionVertex = new QAction(MainWindow);
        actionVertex->setObjectName("actionVertex");
        actionVertex->setEnabled(false);
        actionDisplay_Method = new QAction(MainWindow);
        actionDisplay_Method->setObjectName("actionDisplay_Method");
        actionDisplay_Method->setEnabled(false);
        actionDisplay_Method_2 = new QAction(MainWindow);
        actionDisplay_Method_2->setObjectName("actionDisplay_Method_2");
        actionDisplay_Method_2->setEnabled(false);
        actionOnly_vertex = new QAction(MainWindow);
        actionOnly_vertex->setObjectName("actionOnly_vertex");
        actionOnly_vertex->setCheckable(true);
        actionOnly_edge = new QAction(MainWindow);
        actionOnly_edge->setObjectName("actionOnly_edge");
        actionOnly_edge->setCheckable(true);
        actionMix = new QAction(MainWindow);
        actionMix->setObjectName("actionMix");
        actionMix->setCheckable(true);
        actionMix->setChecked(true);
        actionImage = new QAction(MainWindow);
        actionImage->setObjectName("actionImage");
        actionGIF = new QAction(MainWindow);
        actionGIF->setObjectName("actionGIF");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        glBox = new QGroupBox(centralwidget);
        glBox->setObjectName("glBox");
        glBox->setGeometry(QRect(20, 9, 800, 711));
        groupBox_2 = new QGroupBox(glBox);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 690, 621, 41));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(840, 0, 340, 721));
        QFont font;
        font.setPointSize(13);
        groupBox->setFont(font);
        groupBox->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 30, 341, 691));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        fileBtn = new QPushButton(verticalLayoutWidget);
        fileBtn->setObjectName("fileBtn");

        verticalLayout->addWidget(fileBtn);

        PB_Normalize = new QPushButton(verticalLayoutWidget);
        PB_Normalize->setObjectName("PB_Normalize");

        verticalLayout->addWidget(PB_Normalize);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        moveXlbl = new QLabel(verticalLayoutWidget);
        moveXlbl->setObjectName("moveXlbl");

        horizontalLayout_4->addWidget(moveXlbl);

        moveStepX = new QLineEdit(verticalLayoutWidget);
        moveStepX->setObjectName("moveStepX");

        horizontalLayout_4->addWidget(moveStepX);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        moveXleft = new QPushButton(verticalLayoutWidget);
        moveXleft->setObjectName("moveXleft");

        horizontalLayout_3->addWidget(moveXleft);

        moveXright = new QPushButton(verticalLayoutWidget);
        moveXright->setObjectName("moveXright");

        horizontalLayout_3->addWidget(moveXright);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        moveYlbl = new QLabel(verticalLayoutWidget);
        moveYlbl->setObjectName("moveYlbl");

        horizontalLayout_5->addWidget(moveYlbl);

        moveStepY = new QLineEdit(verticalLayoutWidget);
        moveStepY->setObjectName("moveStepY");

        horizontalLayout_5->addWidget(moveStepY);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        moveYdown = new QPushButton(verticalLayoutWidget);
        moveYdown->setObjectName("moveYdown");

        horizontalLayout_6->addWidget(moveYdown);

        moveYup = new QPushButton(verticalLayoutWidget);
        moveYup->setObjectName("moveYup");

        horizontalLayout_6->addWidget(moveYup);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        moveZlbl = new QLabel(verticalLayoutWidget);
        moveZlbl->setObjectName("moveZlbl");

        horizontalLayout_7->addWidget(moveZlbl);

        moveStepZ = new QLineEdit(verticalLayoutWidget);
        moveStepZ->setObjectName("moveStepZ");

        horizontalLayout_7->addWidget(moveStepZ);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        moveZfar = new QPushButton(verticalLayoutWidget);
        moveZfar->setObjectName("moveZfar");

        horizontalLayout_8->addWidget(moveZfar);

        moveZnear = new QPushButton(verticalLayoutWidget);
        moveZnear->setObjectName("moveZnear");

        horizontalLayout_8->addWidget(moveZnear);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        scale = new QLabel(verticalLayoutWidget);
        scale->setObjectName("scale");

        horizontalLayout_9->addWidget(scale);

        scaleStep = new QLineEdit(verticalLayoutWidget);
        scaleStep->setObjectName("scaleStep");

        horizontalLayout_9->addWidget(scaleStep);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        scaleMinus = new QPushButton(verticalLayoutWidget);
        scaleMinus->setObjectName("scaleMinus");

        horizontalLayout_10->addWidget(scaleMinus);

        scalePlus = new QPushButton(verticalLayoutWidget);
        scalePlus->setObjectName("scalePlus");

        horizontalLayout_10->addWidget(scalePlus);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        rotateX = new QLabel(verticalLayoutWidget);
        rotateX->setObjectName("rotateX");

        horizontalLayout_12->addWidget(rotateX);

        rotateStepX = new QLineEdit(verticalLayoutWidget);
        rotateStepX->setObjectName("rotateStepX");

        horizontalLayout_12->addWidget(rotateStepX);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        rotateXminus = new QPushButton(verticalLayoutWidget);
        rotateXminus->setObjectName("rotateXminus");

        horizontalLayout_13->addWidget(rotateXminus);

        rotateXplus = new QPushButton(verticalLayoutWidget);
        rotateXplus->setObjectName("rotateXplus");

        horizontalLayout_13->addWidget(rotateXplus);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        rotateY = new QLabel(verticalLayoutWidget);
        rotateY->setObjectName("rotateY");

        horizontalLayout_14->addWidget(rotateY);

        rotateStepY = new QLineEdit(verticalLayoutWidget);
        rotateStepY->setObjectName("rotateStepY");

        horizontalLayout_14->addWidget(rotateStepY);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        rotateYminus = new QPushButton(verticalLayoutWidget);
        rotateYminus->setObjectName("rotateYminus");

        horizontalLayout_15->addWidget(rotateYminus);

        rotateYplus = new QPushButton(verticalLayoutWidget);
        rotateYplus->setObjectName("rotateYplus");

        horizontalLayout_15->addWidget(rotateYplus);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        rotateZ = new QLabel(verticalLayoutWidget);
        rotateZ->setObjectName("rotateZ");

        horizontalLayout_16->addWidget(rotateZ);

        rotateStepZ = new QLineEdit(verticalLayoutWidget);
        rotateStepZ->setObjectName("rotateStepZ");

        horizontalLayout_16->addWidget(rotateStepZ);


        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        rotateZminus = new QPushButton(verticalLayoutWidget);
        rotateZminus->setObjectName("rotateZminus");

        horizontalLayout_17->addWidget(rotateZminus);

        rotateZplus = new QPushButton(verticalLayoutWidget);
        rotateZplus->setObjectName("rotateZplus");

        horizontalLayout_17->addWidget(rotateZplus);


        verticalLayout->addLayout(horizontalLayout_17);

        stopBtn = new QPushButton(centralwidget);
        stopBtn->setObjectName("stopBtn");
        stopBtn->setGeometry(QRect(970, 730, 89, 25));
        fileNameLbl = new QLabel(centralwidget);
        fileNameLbl->setObjectName("fileNameLbl");
        fileNameLbl->setGeometry(QRect(20, 730, 481, 17));
        vertexInfo = new QLabel(centralwidget);
        vertexInfo->setObjectName("vertexInfo");
        vertexInfo->setGeometry(QRect(500, 730, 151, 17));
        edgeInfo = new QLabel(centralwidget);
        edgeInfo->setObjectName("edgeInfo");
        edgeInfo->setGeometry(QRect(660, 730, 161, 17));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setEnabled(true);
        menubar->setGeometry(QRect(0, 0, 1200, 22));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName("menuSettings");
        menuSettings->setEnabled(false);
        menuType_of_projection = new QMenu(menuSettings);
        menuType_of_projection->setObjectName("menuType_of_projection");
        menuDisplay = new QMenu(menuSettings);
        menuDisplay->setObjectName("menuDisplay");
        menuDisplay->setEnabled(false);
        menuType_edge = new QMenu(menuDisplay);
        menuType_edge->setObjectName("menuType_edge");
        menuSave = new QMenu(menubar);
        menuSave->setObjectName("menuSave");
        menuSave->setEnabled(false);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menuSave->menuAction());
        menuSettings->addSeparator();
        menuSettings->addAction(menuType_of_projection->menuAction());
        menuSettings->addAction(menuDisplay->menuAction());
        menuSettings->addAction(actionBackground_color);
        menuSettings->addAction(actionSave_settings);
        menuType_of_projection->addAction(actionParallel);
        menuType_of_projection->addAction(actionCentral);
        menuDisplay->addSeparator();
        menuDisplay->addAction(actionDisplay_Method_2);
        menuDisplay->addAction(actionOnly_edge);
        menuDisplay->addAction(actionOnly_vertex);
        menuDisplay->addAction(actionMix);
        menuDisplay->addSeparator();
        menuDisplay->addAction(actionEdge);
        menuDisplay->addAction(actionSize_Edge);
        menuDisplay->addAction(actionColor_Edge);
        menuDisplay->addAction(menuType_edge->menuAction());
        menuDisplay->addSeparator();
        menuDisplay->addAction(actionVertex);
        menuDisplay->addAction(actionSize_Vertex);
        menuDisplay->addAction(actionColor_Vertex);
        menuDisplay->addSeparator();
        menuDisplay->addAction(actionDisplay_Method);
        menuDisplay->addAction(actionNone);
        menuDisplay->addAction(actionCircle);
        menuDisplay->addAction(actionSquere);
        menuType_edge->addAction(actionSolidLine_Edge);
        menuType_edge->addAction(actionLineDots_Edge);
        menuSave->addAction(actionImage);
        menuSave->addAction(actionGIF);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "3D_VIEWER", nullptr));
        actionBackground_color->setText(QCoreApplication::translate("MainWindow", "Background color", nullptr));
        actionSave_settings->setText(QCoreApplication::translate("MainWindow", "Save settings", nullptr));
        actionParallel->setText(QCoreApplication::translate("MainWindow", "Parallel", nullptr));
        actionCentral->setText(QCoreApplication::translate("MainWindow", "Central", nullptr));
        actionSize_Edge->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        actionColor_Edge->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        actionSolidLine_Edge->setText(QCoreApplication::translate("MainWindow", "Solid line", nullptr));
        actionLineDots_Edge->setText(QCoreApplication::translate("MainWindow", "Dotted line", nullptr));
        actionSize_Vertex->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        actionColor_Vertex->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        actionNone->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        actionCircle->setText(QCoreApplication::translate("MainWindow", "Circle", nullptr));
        actionSquere->setText(QCoreApplication::translate("MainWindow", "Squere", nullptr));
        actionEdge->setText(QCoreApplication::translate("MainWindow", "        Edge", nullptr));
        actionVertex->setText(QCoreApplication::translate("MainWindow", "        Vertex", nullptr));
        actionDisplay_Method->setText(QCoreApplication::translate("MainWindow", "        Display Method Vertex", nullptr));
        actionDisplay_Method_2->setText(QCoreApplication::translate("MainWindow", "        Display Method", nullptr));
        actionOnly_vertex->setText(QCoreApplication::translate("MainWindow", "Only vertex", nullptr));
        actionOnly_edge->setText(QCoreApplication::translate("MainWindow", "Only edge", nullptr));
        actionMix->setText(QCoreApplication::translate("MainWindow", "Mix", nullptr));
        actionImage->setText(QCoreApplication::translate("MainWindow", "Image", nullptr));
        actionGIF->setText(QCoreApplication::translate("MainWindow", "GIF", nullptr));
        glBox->setTitle(QString());
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "  Info", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Control Panel", nullptr));
        fileBtn->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
        PB_Normalize->setText(QCoreApplication::translate("MainWindow", "Normalization", nullptr));
        moveXlbl->setText(QCoreApplication::translate("MainWindow", "Move X :", nullptr));
        moveStepX->setText(QString());
        moveXleft->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        moveXright->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        moveYlbl->setText(QCoreApplication::translate("MainWindow", "Move Y :", nullptr));
        moveStepY->setText(QString());
        moveYdown->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        moveYup->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        moveZlbl->setText(QCoreApplication::translate("MainWindow", "Move Z :", nullptr));
        moveStepZ->setText(QString());
        moveZfar->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        moveZnear->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        scale->setText(QCoreApplication::translate("MainWindow", "Scale :", nullptr));
        scaleStep->setText(QString());
        scaleMinus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        scalePlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        rotateX->setText(QCoreApplication::translate("MainWindow", "Rotate X :", nullptr));
        rotateStepX->setText(QString());
        rotateXminus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        rotateXplus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        rotateY->setText(QCoreApplication::translate("MainWindow", "Rotate Y :", nullptr));
        rotateStepY->setText(QString());
        rotateYminus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        rotateYplus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        rotateZ->setText(QCoreApplication::translate("MainWindow", "Rotate Z :", nullptr));
        rotateStepZ->setText(QString());
        rotateZminus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        rotateZplus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        stopBtn->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        fileNameLbl->setText(QCoreApplication::translate("MainWindow", "Filename", nullptr));
        vertexInfo->setText(QCoreApplication::translate("MainWindow", "Vertex", nullptr));
        edgeInfo->setText(QCoreApplication::translate("MainWindow", "Edge", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        menuType_of_projection->setTitle(QCoreApplication::translate("MainWindow", "Type of projection", nullptr));
        menuDisplay->setTitle(QCoreApplication::translate("MainWindow", "Display", nullptr));
        menuType_edge->setTitle(QCoreApplication::translate("MainWindow", "Type edge", nullptr));
        menuSave->setTitle(QCoreApplication::translate("MainWindow", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
