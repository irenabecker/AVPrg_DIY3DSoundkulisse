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
    QSlider *hmax;
    QSlider *smin;
    QSlider *hmin;
    QSlider *smax;
    QSlider *vmin;
    QSlider *vmax;
    QLabel *hminLabel;
    QLabel *hmaxLabel;
    QLabel *sminLabel;
    QLabel *smaxLabel;
    QLabel *vminLabel;
    QLabel *vmaxLabel;
    QMenuBar *menuBar;
    QMenu *menuVideo;
    QMenu *menuVideodatei_ffnen;
    QMenu *menuPlay;

    void setupUi(QMainWindow *DSoundKnete)
    {
        if (DSoundKnete->objectName().isEmpty())
            DSoundKnete->setObjectName(QStringLiteral("DSoundKnete"));
        DSoundKnete->resize(901, 577);
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
        processedFrameTop->setGeometry(QRect(250, 10, 631, 321));
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
        processedFrameFront->setGeometry(QRect(340, 340, 541, 211));
        processedFrameFront->setFrameShape(QFrame::Box);
        processedFrameFront->setScaledContents(false);
        processedFrameFront->setAlignment(Qt::AlignCenter);
        hmax = new QSlider(centralWidget);
        hmax->setObjectName(QStringLiteral("hmax"));
        hmax->setGeometry(QRect(40, 360, 160, 16));
        hmax->setMaximum(255);
        hmax->setOrientation(Qt::Horizontal);
        smin = new QSlider(centralWidget);
        smin->setObjectName(QStringLiteral("smin"));
        smin->setGeometry(QRect(40, 400, 160, 16));
        smin->setMaximum(255);
        smin->setOrientation(Qt::Horizontal);
        hmin = new QSlider(centralWidget);
        hmin->setObjectName(QStringLiteral("hmin"));
        hmin->setGeometry(QRect(40, 380, 160, 16));
        hmin->setMaximum(255);
        hmin->setValue(255);
        hmin->setOrientation(Qt::Horizontal);
        smax = new QSlider(centralWidget);
        smax->setObjectName(QStringLiteral("smax"));
        smax->setGeometry(QRect(40, 420, 160, 16));
        smax->setMaximum(255);
        smax->setValue(255);
        smax->setOrientation(Qt::Horizontal);
        vmin = new QSlider(centralWidget);
        vmin->setObjectName(QStringLiteral("vmin"));
        vmin->setGeometry(QRect(40, 440, 160, 16));
        vmin->setMaximum(255);
        vmin->setOrientation(Qt::Horizontal);
        vmax = new QSlider(centralWidget);
        vmax->setObjectName(QStringLiteral("vmax"));
        vmax->setGeometry(QRect(40, 460, 160, 16));
        vmax->setMaximum(255);
        vmax->setValue(255);
        vmax->setOrientation(Qt::Horizontal);
        hminLabel = new QLabel(centralWidget);
        hminLabel->setObjectName(QStringLiteral("hminLabel"));
        hminLabel->setGeometry(QRect(220, 380, 47, 13));
        hmaxLabel = new QLabel(centralWidget);
        hmaxLabel->setObjectName(QStringLiteral("hmaxLabel"));
        hmaxLabel->setGeometry(QRect(220, 360, 47, 13));
        sminLabel = new QLabel(centralWidget);
        sminLabel->setObjectName(QStringLiteral("sminLabel"));
        sminLabel->setGeometry(QRect(220, 400, 47, 13));
        smaxLabel = new QLabel(centralWidget);
        smaxLabel->setObjectName(QStringLiteral("smaxLabel"));
        smaxLabel->setGeometry(QRect(220, 420, 47, 13));
        vminLabel = new QLabel(centralWidget);
        vminLabel->setObjectName(QStringLiteral("vminLabel"));
        vminLabel->setGeometry(QRect(220, 440, 47, 13));
        vmaxLabel = new QLabel(centralWidget);
        vmaxLabel->setObjectName(QStringLiteral("vmaxLabel"));
        vmaxLabel->setGeometry(QRect(220, 460, 47, 13));
        DSoundKnete->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DSoundKnete);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 901, 20));
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
        QObject::connect(hmax, SIGNAL(valueChanged(int)), hmax, SLOT(setValue(int)));
        QObject::connect(smax, SIGNAL(valueChanged(int)), smax, SLOT(setValue(int)));
        QObject::connect(smin, SIGNAL(valueChanged(int)), smin, SLOT(setValue(int)));
        QObject::connect(vmax, SIGNAL(valueChanged(int)), vmax, SLOT(setValue(int)));
        QObject::connect(vmin, SIGNAL(valueChanged(int)), vmin, SLOT(setValue(int)));
        QObject::connect(hmin, SIGNAL(valueChanged(int)), hminLabel, SLOT(setNum(int)));
        QObject::connect(hmax, SIGNAL(valueChanged(int)), hmaxLabel, SLOT(setNum(int)));
        QObject::connect(smax, SIGNAL(valueChanged(int)), smaxLabel, SLOT(setNum(int)));
        QObject::connect(smin, SIGNAL(valueChanged(int)), sminLabel, SLOT(setNum(int)));
        QObject::connect(vmin, SIGNAL(valueChanged(int)), vminLabel, SLOT(setNum(int)));
        QObject::connect(vmax, SIGNAL(valueChanged(int)), vmaxLabel, SLOT(setNum(int)));

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
        hminLabel->setText(QApplication::translate("DSoundKnete", "255", Q_NULLPTR));
        hmaxLabel->setText(QApplication::translate("DSoundKnete", "0", Q_NULLPTR));
        sminLabel->setText(QApplication::translate("DSoundKnete", "0", Q_NULLPTR));
        smaxLabel->setText(QApplication::translate("DSoundKnete", "255", Q_NULLPTR));
        vminLabel->setText(QApplication::translate("DSoundKnete", "0", Q_NULLPTR));
        vmaxLabel->setText(QApplication::translate("DSoundKnete", "255", Q_NULLPTR));
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
