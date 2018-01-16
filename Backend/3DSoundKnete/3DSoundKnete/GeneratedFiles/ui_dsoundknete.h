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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QPushButton *calibrateButton;
    QLabel *calibrateLabel;
    QRadioButton *radioButton2D;
    QRadioButton *radioButton3D;
    QMenuBar *menuBar;
    QMenu *menuVideo;
    QMenu *menuVideodatei_ffnen;
    QMenu *menuPlay;

    void setupUi(QMainWindow *DSoundKnete)
    {
        if (DSoundKnete->objectName().isEmpty())
            DSoundKnete->setObjectName(QStringLiteral("DSoundKnete"));
        DSoundKnete->setEnabled(true);
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
        calibrateButton = new QPushButton(centralWidget);
        calibrateButton->setObjectName(QStringLiteral("calibrateButton"));
        calibrateButton->setEnabled(false);
        calibrateButton->setGeometry(QRect(50, 350, 131, 41));
        calibrateButton->setCheckable(false);
        calibrateLabel = new QLabel(centralWidget);
        calibrateLabel->setObjectName(QStringLiteral("calibrateLabel"));
        calibrateLabel->setGeometry(QRect(50, 410, 211, 41));
        QFont font;
        font.setPointSize(12);
        calibrateLabel->setFont(font);
        calibrateLabel->setWordWrap(true);
        radioButton2D = new QRadioButton(centralWidget);
        radioButton2D->setObjectName(QStringLiteral("radioButton2D"));
        radioButton2D->setGeometry(QRect(300, 350, 82, 17));
        radioButton3D = new QRadioButton(centralWidget);
        radioButton3D->setObjectName(QStringLiteral("radioButton3D"));
        radioButton3D->setGeometry(QRect(300, 390, 82, 17));
        radioButton3D->setAcceptDrops(false);
        radioButton3D->setAutoFillBackground(false);
        radioButton3D->setChecked(true);
        DSoundKnete->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DSoundKnete);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 901, 21));
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
        menuPlay->addAction(actionPlay);

        retranslateUi(DSoundKnete);

        QMetaObject::connectSlotsByName(DSoundKnete);
    } // setupUi

    void retranslateUi(QMainWindow *DSoundKnete)
    {
        DSoundKnete->setWindowTitle(QApplication::translate("DSoundKnete", "DSoundKnete", Q_NULLPTR));
        actionKamera_ffnen->setText(QApplication::translate("DSoundKnete", "Kamera \303\226ffnen", Q_NULLPTR));
        actionPlay->setText(QApplication::translate("DSoundKnete", "Play", Q_NULLPTR));
        actionVideo_Top->setText(QApplication::translate("DSoundKnete", "Open Video", Q_NULLPTR));
        actionVideo_Front->setText(QApplication::translate("DSoundKnete", "Video Front", Q_NULLPTR));
        inputFrameTop->setText(QString());
        processedFrameTop->setText(QString());
        calibrateButton->setText(QApplication::translate("DSoundKnete", "Calibrate", Q_NULLPTR));
        calibrateLabel->setText(QApplication::translate("DSoundKnete", "Place two black cubes to calibrate your room.", Q_NULLPTR));
        radioButton2D->setText(QApplication::translate("DSoundKnete", "2D", Q_NULLPTR));
        radioButton3D->setText(QApplication::translate("DSoundKnete", "3D", Q_NULLPTR));
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
