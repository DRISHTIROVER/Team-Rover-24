/********************************************************************************
** Form generated from reading UI file 'mapviz.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPVIZ_H
#define UI_MAPVIZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mapviz/color_button.h>
#include "mapviz/widgets.h"

QT_BEGIN_NAMESPACE

class Ui_mapviz
{
public:
    QAction *actionExit;
    QAction *actionOpen_config;
    QAction *actionSaveAs_config;
    QAction *actionConfig_Dock;
    QAction *actionFix_Orientation;
    QAction *actionForce_720p;
    QAction *actionForce_480p;
    QAction *actionResizable;
    QAction *actionSet_Capture_Directory;
    QAction *actionShow_Status_Bar;
    QAction *actionShow_Capture_Tools;
    QAction *actionRotate_90;
    QAction *actionEnable_Antialiasing;
    QAction *actionImage_Transport;
    QAction *actionClear_History;
    QAction *actionClear;
    QAction *actionSave_Config;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menu_View;
    QMenu *menuData;
    QStatusBar *statusbar;
    QDockWidget *configdock;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    mapviz::ColorButton *bg_color;
    QComboBox *targetframe;
    QComboBox *fixedframe;
    mapviz::PluginConfigList *configs;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addbutton;
    QPushButton *removebutton;

    void setupUi(QMainWindow *mapviz)
    {
        if (mapviz->objectName().isEmpty())
            mapviz->setObjectName(QString::fromUtf8("mapviz"));
        mapviz->resize(600, 600);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mapviz->sizePolicy().hasHeightForWidth());
        mapviz->setSizePolicy(sizePolicy);
        mapviz->setMinimumSize(QSize(600, 400));
        actionExit = new QAction(mapviz);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionOpen_config = new QAction(mapviz);
        actionOpen_config->setObjectName(QString::fromUtf8("actionOpen_config"));
        actionSaveAs_config = new QAction(mapviz);
        actionSaveAs_config->setObjectName(QString::fromUtf8("actionSaveAs_config"));
        actionConfig_Dock = new QAction(mapviz);
        actionConfig_Dock->setObjectName(QString::fromUtf8("actionConfig_Dock"));
        actionConfig_Dock->setCheckable(true);
        actionConfig_Dock->setChecked(true);
        actionFix_Orientation = new QAction(mapviz);
        actionFix_Orientation->setObjectName(QString::fromUtf8("actionFix_Orientation"));
        actionFix_Orientation->setCheckable(true);
        actionForce_720p = new QAction(mapviz);
        actionForce_720p->setObjectName(QString::fromUtf8("actionForce_720p"));
        actionForce_720p->setCheckable(true);
        actionForce_480p = new QAction(mapviz);
        actionForce_480p->setObjectName(QString::fromUtf8("actionForce_480p"));
        actionForce_480p->setCheckable(true);
        actionResizable = new QAction(mapviz);
        actionResizable->setObjectName(QString::fromUtf8("actionResizable"));
        actionResizable->setCheckable(true);
        actionResizable->setChecked(true);
        actionSet_Capture_Directory = new QAction(mapviz);
        actionSet_Capture_Directory->setObjectName(QString::fromUtf8("actionSet_Capture_Directory"));
        actionShow_Status_Bar = new QAction(mapviz);
        actionShow_Status_Bar->setObjectName(QString::fromUtf8("actionShow_Status_Bar"));
        actionShow_Status_Bar->setCheckable(true);
        actionShow_Status_Bar->setChecked(true);
        actionShow_Capture_Tools = new QAction(mapviz);
        actionShow_Capture_Tools->setObjectName(QString::fromUtf8("actionShow_Capture_Tools"));
        actionShow_Capture_Tools->setCheckable(true);
        actionShow_Capture_Tools->setChecked(true);
        actionRotate_90 = new QAction(mapviz);
        actionRotate_90->setObjectName(QString::fromUtf8("actionRotate_90"));
        actionRotate_90->setCheckable(true);
        actionEnable_Antialiasing = new QAction(mapviz);
        actionEnable_Antialiasing->setObjectName(QString::fromUtf8("actionEnable_Antialiasing"));
        actionEnable_Antialiasing->setCheckable(true);
        actionEnable_Antialiasing->setChecked(true);
        actionImage_Transport = new QAction(mapviz);
        actionImage_Transport->setObjectName(QString::fromUtf8("actionImage_Transport"));
        actionClear_History = new QAction(mapviz);
        actionClear_History->setObjectName(QString::fromUtf8("actionClear_History"));
        actionClear = new QAction(mapviz);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        actionSave_Config = new QAction(mapviz);
        actionSave_Config->setObjectName(QString::fromUtf8("actionSave_Config"));
        menubar = new QMenuBar(mapviz);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 27));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menu_View = new QMenu(menubar);
        menu_View->setObjectName(QString::fromUtf8("menu_View"));
        menuData = new QMenu(menubar);
        menuData->setObjectName(QString::fromUtf8("menuData"));
        mapviz->setMenuBar(menubar);
        statusbar = new QStatusBar(mapviz);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setEnabled(true);
        mapviz->setStatusBar(statusbar);
        configdock = new QDockWidget(mapviz);
        configdock->setObjectName(QString::fromUtf8("configdock"));
        configdock->setMinimumSize(QSize(332, 301));
        configdock->setFeatures(QDockWidget::DockWidgetMovable);
        configdock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(2, 0, 0, 0);
        widget_2 = new QWidget(dockWidgetContents);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(85, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setPointSize(9);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(85, 16777215));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 2, 1);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(85, 16777215));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        bg_color = new mapviz::ColorButton(widget_2);
        bg_color->setObjectName(QString::fromUtf8("bg_color"));
        bg_color->setMaximumSize(QSize(24, 24));
        bg_color->setAutoFillBackground(false);
        bg_color->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(bg_color, 5, 1, 1, 1);

        targetframe = new QComboBox(widget_2);
        targetframe->setObjectName(QString::fromUtf8("targetframe"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(targetframe->sizePolicy().hasHeightForWidth());
        targetframe->setSizePolicy(sizePolicy1);
        targetframe->setMaximumSize(QSize(16777215, 25));
        targetframe->setFont(font);
        targetframe->setEditable(true);

        gridLayout->addWidget(targetframe, 1, 1, 2, 2);

        fixedframe = new QComboBox(widget_2);
        fixedframe->setObjectName(QString::fromUtf8("fixedframe"));
        sizePolicy1.setHeightForWidth(fixedframe->sizePolicy().hasHeightForWidth());
        fixedframe->setSizePolicy(sizePolicy1);
        fixedframe->setMaximumSize(QSize(16777215, 25));
        fixedframe->setFont(font);
        fixedframe->setEditable(true);

        gridLayout->addWidget(fixedframe, 0, 1, 1, 2);


        verticalLayout->addWidget(widget_2);

        configs = new mapviz::PluginConfigList(dockWidgetContents);
        configs->setObjectName(QString::fromUtf8("configs"));
        configs->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        configs->setDragEnabled(true);
        configs->setDragDropMode(QAbstractItemView::InternalMove);
        configs->setDefaultDropAction(Qt::MoveAction);
        configs->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

        verticalLayout->addWidget(configs);

        widget = new QWidget(dockWidgetContents);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 4, -1, 4);
        addbutton = new QPushButton(widget);
        addbutton->setObjectName(QString::fromUtf8("addbutton"));
        addbutton->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(addbutton);

        removebutton = new QPushButton(widget);
        removebutton->setObjectName(QString::fromUtf8("removebutton"));
        removebutton->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(removebutton);


        verticalLayout->addWidget(widget);

        configdock->setWidget(dockWidgetContents);
        mapviz->addDockWidget(static_cast<Qt::DockWidgetArea>(1), configdock);
        QWidget::setTabOrder(fixedframe, targetframe);
        QWidget::setTabOrder(targetframe, bg_color);
        QWidget::setTabOrder(bg_color, configs);
        QWidget::setTabOrder(configs, addbutton);
        QWidget::setTabOrder(addbutton, removebutton);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menu_View->menuAction());
        menubar->addAction(menuData->menuAction());
        menuFile->addAction(actionOpen_config);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_Config);
        menuFile->addAction(actionSaveAs_config);
        menuFile->addAction(actionClear);
        menuFile->addSeparator();
        menuFile->addAction(actionSet_Capture_Directory);
        menuFile->addAction(actionExit);
        menu_View->addAction(actionFix_Orientation);
        menu_View->addAction(actionRotate_90);
        menu_View->addAction(actionEnable_Antialiasing);
        menu_View->addSeparator();
        menu_View->addAction(actionForce_720p);
        menu_View->addAction(actionForce_480p);
        menu_View->addAction(actionResizable);
        menu_View->addSeparator();
        menu_View->addAction(actionConfig_Dock);
        menu_View->addAction(actionShow_Status_Bar);
        menu_View->addAction(actionShow_Capture_Tools);
        menu_View->addSeparator();
        menuData->addAction(actionClear_History);

        retranslateUi(mapviz);
        QObject::connect(addbutton, SIGNAL(clicked()), mapviz, SLOT(SelectNewDisplay()));
        QObject::connect(removebutton, SIGNAL(clicked()), mapviz, SLOT(RemoveDisplay()));
        QObject::connect(actionConfig_Dock, SIGNAL(toggled(bool)), mapviz, SLOT(ToggleConfigPanel(bool)));
        QObject::connect(fixedframe, SIGNAL(editTextChanged(QString)), mapviz, SLOT(FixedFrameSelected(QString)));
        QObject::connect(targetframe, SIGNAL(editTextChanged(QString)), mapviz, SLOT(TargetFrameSelected(QString)));
        QObject::connect(actionFix_Orientation, SIGNAL(toggled(bool)), mapviz, SLOT(ToggleFixOrientation(bool)));
        QObject::connect(actionOpen_config, SIGNAL(triggered()), mapviz, SLOT(OpenConfig()));
        QObject::connect(actionSaveAs_config, SIGNAL(triggered()), mapviz, SLOT(SaveConfigAs()));
        QObject::connect(actionForce_720p, SIGNAL(toggled(bool)), mapviz, SLOT(Force720p(bool)));
        QObject::connect(actionForce_480p, SIGNAL(toggled(bool)), mapviz, SLOT(Force480p(bool)));
        QObject::connect(actionResizable, SIGNAL(toggled(bool)), mapviz, SLOT(SetResizable(bool)));
        QObject::connect(actionSet_Capture_Directory, SIGNAL(triggered()), mapviz, SLOT(SetCaptureDirectory()));
        QObject::connect(actionShow_Status_Bar, SIGNAL(toggled(bool)), mapviz, SLOT(ToggleStatusBar(bool)));
        QObject::connect(actionShow_Capture_Tools, SIGNAL(triggered(bool)), mapviz, SLOT(ToggleCaptureTools(bool)));
        QObject::connect(actionRotate_90, SIGNAL(toggled(bool)), mapviz, SLOT(ToggleRotate90(bool)));
        QObject::connect(actionEnable_Antialiasing, SIGNAL(toggled(bool)), mapviz, SLOT(ToggleEnableAntialiasing(bool)));
        QObject::connect(actionSave_Config, SIGNAL(triggered()), mapviz, SLOT(SaveConfig()));

        QMetaObject::connectSlotsByName(mapviz);
    } // setupUi

    void retranslateUi(QMainWindow *mapviz)
    {
        mapviz->setWindowTitle(QApplication::translate("mapviz", "mapviz", nullptr));
        actionExit->setText(QApplication::translate("mapviz", "Exit", nullptr));
        actionOpen_config->setText(QApplication::translate("mapviz", "Open Config", nullptr));
        actionSaveAs_config->setText(QApplication::translate("mapviz", "Save Config As...", nullptr));
        actionConfig_Dock->setText(QApplication::translate("mapviz", "Show Config Panel", nullptr));
#ifndef QT_NO_STATUSTIP
        actionConfig_Dock->setStatusTip(QApplication::translate("mapviz", "Show the display configuration panel", nullptr));
#endif // QT_NO_STATUSTIP
        actionFix_Orientation->setText(QApplication::translate("mapviz", "Fix Orientation", nullptr));
#ifndef QT_NO_STATUSTIP
        actionFix_Orientation->setStatusTip(QApplication::translate("mapviz", "Fix the orientation of the camera", nullptr));
#endif // QT_NO_STATUSTIP
        actionForce_720p->setText(QApplication::translate("mapviz", "Force 720p", nullptr));
#ifndef QT_NO_STATUSTIP
        actionForce_720p->setStatusTip(QApplication::translate("mapviz", "Lock the display canvas to 720p", nullptr));
#endif // QT_NO_STATUSTIP
        actionForce_480p->setText(QApplication::translate("mapviz", "Force 480p", nullptr));
#ifndef QT_NO_STATUSTIP
        actionForce_480p->setStatusTip(QApplication::translate("mapviz", "Lock the display canvas to 480p", nullptr));
#endif // QT_NO_STATUSTIP
        actionResizable->setText(QApplication::translate("mapviz", "Resizable", nullptr));
#ifndef QT_NO_STATUSTIP
        actionResizable->setStatusTip(QApplication::translate("mapviz", "Make the window resizable", nullptr));
#endif // QT_NO_STATUSTIP
        actionSet_Capture_Directory->setText(QApplication::translate("mapviz", "Set Capture Directory", nullptr));
#ifndef QT_NO_STATUSTIP
        actionSet_Capture_Directory->setStatusTip(QApplication::translate("mapviz", "Set the capture directory for screeshots and videos", nullptr));
#endif // QT_NO_STATUSTIP
        actionShow_Status_Bar->setText(QApplication::translate("mapviz", "Show Status Bar", nullptr));
#ifndef QT_NO_STATUSTIP
        actionShow_Status_Bar->setStatusTip(QApplication::translate("mapviz", "Show the status bar", nullptr));
#endif // QT_NO_STATUSTIP
        actionShow_Capture_Tools->setText(QApplication::translate("mapviz", "Show Capture Tools", nullptr));
#ifndef QT_NO_STATUSTIP
        actionShow_Capture_Tools->setStatusTip(QApplication::translate("mapviz", "Show the capture tools on the status bar", nullptr));
#endif // QT_NO_STATUSTIP
        actionRotate_90->setText(QApplication::translate("mapviz", "Rotate 90\302\260", nullptr));
#ifndef QT_NO_STATUSTIP
        actionRotate_90->setStatusTip(QApplication::translate("mapviz", "Rotate the camera by 90 degrees", nullptr));
#endif // QT_NO_STATUSTIP
        actionEnable_Antialiasing->setText(QApplication::translate("mapviz", "Enable Antialiasing", nullptr));
#ifndef QT_NO_STATUSTIP
        actionEnable_Antialiasing->setStatusTip(QApplication::translate("mapviz", "Enable antialiasing on the GL surface", nullptr));
#endif // QT_NO_STATUSTIP
        actionImage_Transport->setText(QApplication::translate("mapviz", "Image Transport", nullptr));
        actionClear_History->setText(QApplication::translate("mapviz", "Clear History", nullptr));
        actionClear->setText(QApplication::translate("mapviz", "Clear Config", nullptr));
        actionSave_Config->setText(QApplication::translate("mapviz", "Save Config", nullptr));
        menuFile->setTitle(QApplication::translate("mapviz", "&File", nullptr));
        menu_View->setTitle(QApplication::translate("mapviz", "&View", nullptr));
        menuData->setTitle(QApplication::translate("mapviz", "Data", nullptr));
        configdock->setWindowTitle(QApplication::translate("mapviz", "Config", nullptr));
        label->setText(QApplication::translate("mapviz", "Fixed Frame:", nullptr));
        label_2->setText(QApplication::translate("mapviz", "Target Frame:", nullptr));
        label_3->setText(QApplication::translate("mapviz", "Background:", nullptr));
#ifndef QT_NO_TOOLTIP
        bg_color->setToolTip(QApplication::translate("mapviz", "Set the background color", nullptr));
#endif // QT_NO_TOOLTIP
        bg_color->setText(QString());
#ifndef QT_NO_TOOLTIP
        targetframe->setToolTip(QApplication::translate("mapviz", "The reference frame for the camera view", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        fixedframe->setToolTip(QApplication::translate("mapviz", "The reference frame used to denote the \"world\" frame\n"
"                                            ", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        addbutton->setToolTip(QApplication::translate("mapviz", "Add a new display", nullptr));
#endif // QT_NO_TOOLTIP
        addbutton->setText(QApplication::translate("mapviz", "Add", nullptr));
#ifndef QT_NO_TOOLTIP
        removebutton->setToolTip(QApplication::translate("mapviz", "Remove the selected display", nullptr));
#endif // QT_NO_TOOLTIP
        removebutton->setText(QApplication::translate("mapviz", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mapviz: public Ui_mapviz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPVIZ_H
