/********************************************************************************
** Form generated from reading UI file 'dsoundknete.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DSOUNDKNETE_H
#define UI_DSOUNDKNETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "videowidget.h"

QT_BEGIN_NAMESPACE

class Ui_DSoundKnete
{
public:
    QAction *actionKamera_ffnen;
    QAction *actionPlay;
    QAction *actionVideo_Top;
    QAction *actionVideo_Front;
    QWidget *centralWidget;
    VideoWidget *inputFrameTop;
    VideoWidget *processedFrameTop;
    VideoWidget *inputFrameFront;
    VideoWidget *processedFrameFront;
    QLabel *x1;
    QLabel *y1;
    QLabel *y2;
    QLabel *x2;
    QLabel *label;
    QLabel *xges;
    QLabel *yges;
    QLabel *zges;
    QSlider *hmax;
    QSlider *smin;
    QSlider *hmin;
    QSlider *smax;
    QSlider *vmin;
    QSlider *vmax;
    QMenuBar *menuBar;
    QMenu *menuVideo;
    QMenu *menuVideodatei_ffnen;
    QMenu *menuPlay;

    void setupUi(QMainWindow *DSoundKnete)
    {
        if (DSoundKnete->objectName().isEmpty())
            DSoundKnete->setObjectName(QStringLiteral("DSoundKnete"));
        DSoundKnete->resize(644, 382);
        actionKamera_ffnen = new QAction(DSoundKnete);
        actionKamera_ffnen->setObjectName(QStringLiteral("actionKamera_ffnen"));
        actionPlay = new QAction(DSoundKnete);
        actionPlay->setObjectName(QStringLiteral("actionPlay"));
        actionVideo_Top = new QAction(DSoundKnete);
        actionVideo_Top->setObjectName(QStringLiteral("actionVideo_Top"));
        actionVideo_Front = new QAction(DSoundKnete);
        actionVideo_Front->setObjectName(QStringLiteral("actionVideo_Front"));
        centralWidget = new QWidget(DSoundKnete);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        inputFrameTop = new VideoWidget(centralWidget);
        inputFrameTop->setObjectName(QStringLiteral("inputFrameTop"));
        inputFrameTop->setGeometry(QRect(20, 20, 191, 141));
        inputFrameTop->setFrameShape(QFrame::Box);
        inputFrameTop->setScaledContents(false);
        inputFrameTop->setAlignment(Qt::AlignCenter);
        processedFrameTop = new VideoWidget(centralWidget);
        processedFrameTop->setObjectName(QStringLiteral("processedFrameTop"));
        processedFrameTop->setGeometry(QRect(290, 20, 150, 110));
        processedFrameTop->setFrameShape(QFrame::Box);
        processedFrameTop->setScaledContents(false);
        processedFrameTop->setAlignment(Qt::AlignCenter);
        inputFrameFront = new VideoWidget(centralWidget);
        inputFrameFront->setObjectName(QStringLiteral("inputFrameFront"));
        inputFrameFront->setGeometry(QRect(20, 190, 191, 141));
        inputFrameFront->setFrameShape(QFrame::Box);
        inputFrameFront->setScaledContents(false);
        inputFrameFront->setAlignment(Qt::AlignCenter);
        processedFrameFront = new VideoWidget(centralWidget);
        processedFrameFront->setObjectName(QStringLiteral("processedFrameFront"));
        processedFrameFront->setGeometry(QRect(460, 20, 150, 110));
        processedFrameFront->setFrameShape(QFrame::Box);
        processedFrameFront->setScaledContents(false);
        processedFrameFront->setAlignment(Qt::AlignCenter);
        x1 = new QLabel(centralWidget);
        x1->setObjectName(QStringLiteral("x1"));
        x1->setGeometry(QRect(300, 140, 47, 13));
        y1 = new QLabel(centralWidget);
        y1->setObjectName(QStringLiteral("y1"));
        y1->setGeometry(QRect(300, 160, 47, 13));
        y2 = new QLabel(centralWidget);
        y2->setObjectName(QStringLiteral("y2"));
        y2->setGeometry(QRect(470, 160, 47, 13));
        x2 = new QLabel(centralWidget);
        x2->setObjectName(QStringLiteral("x2"));
        x2->setGeometry(QRect(470, 140, 47, 13));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 220, 81, 16));
        xges = new QLabel(centralWidget);
        xges->setObjectName(QStringLiteral("xges"));
        xges->setGeometry(QRect(310, 250, 47, 13));
        yges = new QLabel(centralWidget);
        yges->setObjectName(QStringLiteral("yges"));
        yges->setGeometry(QRect(310, 270, 47, 13));
        zges = new QLabel(centralWidget);
        zges->setObjectName(QStringLiteral("zges"));
        zges->setGeometry(QRect(310, 290, 47, 13));
        hmax = new QSlider(centralWidget);
        hmax->setObjectName(QStringLiteral("hmax"));
        hmax->setGeometry(QRect(460, 200, 160, 16));
        hmax->setMaximum(179);
        hmax->setOrientation(Qt::Horizontal);
        smin = new QSlider(centralWidget);
        smin->setObjectName(QStringLiteral("smin"));
        smin->setGeometry(QRect(460, 230, 160, 16));
        smin->setMaximum(255);
        smin->setOrientation(Qt::Horizontal);
        hmin = new QSlider(centralWidget);
        hmin->setObjectName(QStringLiteral("hmin"));
        hmin->setGeometry(QRect(460, 180, 160, 16));
        hmin->setMaximum(179);
        hmin->setOrientation(Qt::Horizontal);
        smax = new QSlider(centralWidget);
        smax->setObjectName(QStringLiteral("smax"));
        smax->setGeometry(QRect(460, 250, 160, 16));
        smax->setMaximum(255);
        smax->setOrientation(Qt::Horizontal);
        vmin = new QSlider(centralWidget);
        vmin->setObjectName(QStringLiteral("vmin"));
        vmin->setGeometry(QRect(460, 290, 160, 16));
        vmin->setMaximum(255);
        vmin->setOrientation(Qt::Horizontal);
        vmax = new QSlider(centralWidget);
        vmax->setObjectName(QStringLiteral("vmax"));
        vmax->setGeometry(QRect(460, 310, 160, 16));
        vmax->setMaximum(255);
        vmax->setOrientation(Qt::Horizontal);
        DSoundKnete->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DSoundKnete);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 644, 20));
        menuVideo = new QMenu(menuBar);
        menuVideo->setObjectName(QStringLiteral("menuVideo"));
        menuVideodatei_ffnen = new QMenu(menuVideo);
        menuVideodatei_ffnen->setObjectName(QStringLiteral("menuVideodatei_ffnen"));
        menuPlay = new QMenu(menuBar);
        menuPlay->setObjectName(QStringLiteral("menuPlay"));
        DSoundKnete->setMenuBar(menuBar);

        menuBar->addAction(menuVideo->menuAction());
        menuBar->addAction(menuPlay->menuAction());
        menuVideo->addAction(menuVideodatei_ffnen->menuAction());
        menuVideo->addAction(actionKamera_ffnen);
        menuVideodatei_ffnen->addAction(actionVideo_Top);
        menuVideodatei_ffnen->addAction(actionVideo_Front);
        menuPlay->addAction(actionPlay);

        retranslateUi(DSoundKnete);
        QObject::connect(hmin, SIGNAL(valueChanged(int)), hmin, SLOT(setValue(int)));
        QObject::connect(hmax, SIGNAL(valueChanged(int)), hmax, SLOT(setValue(int)));
        QObject::connect(smax, SIGNAL(valueChanged(int)), smax, SLOT(setValue(int)));
        QObject::connect(smin, SIGNAL(valueChanged(int)), smin, SLOT(setValue(int)));
        QObject::connect(vmax, SIGNAL(valueChanged(int)), vmax, SLOT(setValue(int)));
        QObject::connect(vmin, SIGNAL(valueChanged(int)), vmin, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(DSoundKnete);
    } // setupUi

    void retranslateUi(QMainWindow *DSoundKnete)
    {
        DSoundKnete->setWindowTitle(QApplication::translate("DSoundKnete", "DSoundKnete", Q_NULLPTR));
        actionKamera_ffnen->setText(QApplication::translate("DSoundKnete", "Kamera \303\226ffnen", Q_NULLPTR));
        actionPlay->setText(QApplication::translate("DSoundKnete", "Play", Q_NULLPTR));
        actionVideo_Top->setText(QApplication::translate("DSoundKnete", "Video Top", Q_NULLPTR));
        actionVideo_Front->setText(QApplication::translate("DSoundKnete", "Video Front", Q_NULLPTR));
        inputFrameTop->setText(QString());
        processedFrameTop->setText(QString());
        inputFrameFront->setText(QString());
        processedFrameFront->setText(QString());
        x1->setText(QApplication::translate("DSoundKnete", "X1:", Q_NULLPTR));
        y1->setText(QApplication::translate("DSoundKnete", "Y1:", Q_NULLPTR));
        y2->setText(QApplication::translate("DSoundKnete", "Y2:", Q_NULLPTR));
        x2->setText(QApplication::translate("DSoundKnete", "X2:", Q_NULLPTR));
        label->setText(QApplication::translate("DSoundKnete", "In 3D-Space:", Q_NULLPTR));
        xges->setText(QApplication::translate("DSoundKnete", "X ges:", Q_NULLPTR));
        yges->setText(QApplication::translate("DSoundKnete", "Y ges:", Q_NULLPTR));
        zges->setText(QApplication::translate("DSoundKnete", "Z ges:", Q_NULLPTR));
        menuVideo->setTitle(QApplication::translate("DSoundKnete", "Video", Q_NULLPTR));
        menuVideodatei_ffnen->setTitle(QApplication::translate("DSoundKnete", "Videodatei \303\226ffnen ...", Q_NULLPTR));
        menuPlay->setTitle(QApplication::translate("DSoundKnete", "Play", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DSoundKnete: public Ui_DSoundKnete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DSOUNDKNETE_H
