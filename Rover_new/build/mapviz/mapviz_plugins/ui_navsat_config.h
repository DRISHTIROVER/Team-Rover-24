/********************************************************************************
** Form generated from reading UI file 'navsat_config.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVSAT_CONFIG_H
#define UI_NAVSAT_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include <mapviz/color_button.h>

QT_BEGIN_NAMESPACE

class Ui_navsat_config
{
public:
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLabel *status;
    QLabel *label_4;
    QSpinBox *buffersize;
    QLabel *label_3;
    QPushButton *buttonResetBuffer;
    QPushButton *selecttopic;
    QDoubleSpinBox *positiontolerance;
    QLineEdit *topic;
    mapviz::ColorButton *color;
    QComboBox *drawstyle;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_7;
    QSpacerItem *verticalSpacer;
    QCheckBox *use_latest_transforms;
    QLabel *label_5;

    void setupUi(QWidget *navsat_config)
    {
        if (navsat_config->objectName().isEmpty())
            navsat_config->setObjectName(QString::fromUtf8("navsat_config"));
        navsat_config->resize(400, 186);
        navsat_config->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(navsat_config);
        gridLayout->setContentsMargins(2, 2, 2, 2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(4);
        label_6 = new QLabel(navsat_config);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setPointSize(8);
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 7, 0, 1, 1);

        status = new QLabel(navsat_config);
        status->setObjectName(QString::fromUtf8("status"));
        status->setFont(font);
        status->setStyleSheet(QString::fromUtf8(""));
        status->setWordWrap(true);

        gridLayout->addWidget(status, 8, 1, 1, 2);

        label_4 = new QLabel(navsat_config);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        buffersize = new QSpinBox(navsat_config);
        buffersize->setObjectName(QString::fromUtf8("buffersize"));
        buffersize->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        buffersize->setMaximum(99999999);

        gridLayout->addWidget(buffersize, 7, 1, 1, 1);

        label_3 = new QLabel(navsat_config);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        buttonResetBuffer = new QPushButton(navsat_config);
        buttonResetBuffer->setObjectName(QString::fromUtf8("buttonResetBuffer"));
        buttonResetBuffer->setMaximumSize(QSize(55, 16777215));

        gridLayout->addWidget(buttonResetBuffer, 7, 2, 1, 1);

        selecttopic = new QPushButton(navsat_config);
        selecttopic->setObjectName(QString::fromUtf8("selecttopic"));
        selecttopic->setMaximumSize(QSize(55, 16777215));
        selecttopic->setFont(font);
        selecttopic->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(selecttopic, 2, 2, 1, 1);

        positiontolerance = new QDoubleSpinBox(navsat_config);
        positiontolerance->setObjectName(QString::fromUtf8("positiontolerance"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(positiontolerance->sizePolicy().hasHeightForWidth());
        positiontolerance->setSizePolicy(sizePolicy);
        positiontolerance->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        positiontolerance->setValue(1.000000000000000);

        gridLayout->addWidget(positiontolerance, 6, 1, 1, 1);

        topic = new QLineEdit(navsat_config);
        topic->setObjectName(QString::fromUtf8("topic"));
        topic->setFont(font);

        gridLayout->addWidget(topic, 2, 1, 1, 1);

        color = new mapviz::ColorButton(navsat_config);
        color->setObjectName(QString::fromUtf8("color"));
        color->setMaximumSize(QSize(24, 24));
        color->setAutoFillBackground(false);
        color->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(color, 3, 1, 1, 1);

        drawstyle = new QComboBox(navsat_config);
        drawstyle->addItem(QString());
        drawstyle->addItem(QString());
        drawstyle->setObjectName(QString::fromUtf8("drawstyle"));
        drawstyle->setMaximumSize(QSize(16777215, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Sans Serif"));
        font1.setPointSize(9);
        drawstyle->setFont(font1);

        gridLayout->addWidget(drawstyle, 4, 1, 1, 1);

        label = new QLabel(navsat_config);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_2 = new QLabel(navsat_config);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 8, 0, 1, 1);

        label_7 = new QLabel(navsat_config);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 9, 1, 1, 1);

        use_latest_transforms = new QCheckBox(navsat_config);
        use_latest_transforms->setObjectName(QString::fromUtf8("use_latest_transforms"));

        gridLayout->addWidget(use_latest_transforms, 5, 1, 1, 1);

        label_5 = new QLabel(navsat_config);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font2;
        font2.setPointSize(8);
        label_5->setFont(font2);

        gridLayout->addWidget(label_5, 5, 0, 1, 1);


        retranslateUi(navsat_config);

        QMetaObject::connectSlotsByName(navsat_config);
    } // setupUi

    void retranslateUi(QWidget *navsat_config)
    {
        navsat_config->setWindowTitle(QApplication::translate("navsat_config", "Form", nullptr));
        label_6->setText(QApplication::translate("navsat_config", "Buffer Size:", nullptr));
        status->setText(QApplication::translate("navsat_config", "No topic", nullptr));
        label_4->setText(QApplication::translate("navsat_config", "Position Tolerance:", nullptr));
        label_3->setText(QApplication::translate("navsat_config", "Color:", nullptr));
        buttonResetBuffer->setText(QApplication::translate("navsat_config", "Clear", nullptr));
        selecttopic->setText(QApplication::translate("navsat_config", "Select", nullptr));
        positiontolerance->setSuffix(QString());
        color->setText(QString());
        drawstyle->setItemText(0, QApplication::translate("navsat_config", "lines", nullptr));
        drawstyle->setItemText(1, QApplication::translate("navsat_config", "points", nullptr));

        label->setText(QApplication::translate("navsat_config", "Topic:", nullptr));
        label_2->setText(QApplication::translate("navsat_config", "Status:", nullptr));
        label_7->setText(QApplication::translate("navsat_config", "Draw Style:", nullptr));
        use_latest_transforms->setText(QString());
        label_5->setText(QApplication::translate("navsat_config", "Use Latest Transforms:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class navsat_config: public Ui_navsat_config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVSAT_CONFIG_H
