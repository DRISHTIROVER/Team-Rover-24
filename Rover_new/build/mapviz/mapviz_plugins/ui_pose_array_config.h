/********************************************************************************
** Form generated from reading UI file 'pose_array_config.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSE_ARRAY_CONFIG_H
#define UI_POSE_ARRAY_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include <mapviz/color_button.h>

QT_BEGIN_NAMESPACE

class Ui_pose_array_config
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *topic;
    QPushButton *selecttopic;
    QLabel *label_3;
    mapviz::ColorButton *color;
    QLabel *label_7;
    QComboBox *drawstyle;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout;
    QCheckBox *static_arrow_sizes;
    QSlider *arrow_size;
    QLabel *label_2;
    QLabel *status;
    QSpacerItem *verticalSpacer;
    QDoubleSpinBox *positiontolerance;
    QLabel *label_4;

    void setupUi(QWidget *pose_array_config)
    {
        if (pose_array_config->objectName().isEmpty())
            pose_array_config->setObjectName(QString::fromUtf8("pose_array_config"));
        pose_array_config->resize(400, 208);
        pose_array_config->setStyleSheet(QString::fromUtf8(""));
        formLayout = new QFormLayout(pose_array_config);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(pose_array_config);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setPointSize(8);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        topic = new QLineEdit(pose_array_config);
        topic->setObjectName(QString::fromUtf8("topic"));
        topic->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, topic);

        selecttopic = new QPushButton(pose_array_config);
        selecttopic->setObjectName(QString::fromUtf8("selecttopic"));
        selecttopic->setMaximumSize(QSize(55, 16777215));
        selecttopic->setFont(font);
        selecttopic->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(1, QFormLayout::FieldRole, selecttopic);

        label_3 = new QLabel(pose_array_config);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        color = new mapviz::ColorButton(pose_array_config);
        color->setObjectName(QString::fromUtf8("color"));
        color->setMaximumSize(QSize(24, 24));
        color->setAutoFillBackground(false);
        color->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(2, QFormLayout::FieldRole, color);

        label_7 = new QLabel(pose_array_config);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_7);

        drawstyle = new QComboBox(pose_array_config);
        drawstyle->addItem(QString());
        drawstyle->addItem(QString());
        drawstyle->setObjectName(QString::fromUtf8("drawstyle"));
        drawstyle->setMaximumSize(QSize(16777215, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Sans Serif"));
        font1.setPointSize(9);
        drawstyle->setFont(font1);

        formLayout->setWidget(3, QFormLayout::FieldRole, drawstyle);

        label_8 = new QLabel(pose_array_config);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        static_arrow_sizes = new QCheckBox(pose_array_config);
        static_arrow_sizes->setObjectName(QString::fromUtf8("static_arrow_sizes"));

        horizontalLayout->addWidget(static_arrow_sizes);

        arrow_size = new QSlider(pose_array_config);
        arrow_size->setObjectName(QString::fromUtf8("arrow_size"));
        arrow_size->setMinimum(1);
        arrow_size->setMaximum(500);
        arrow_size->setValue(25);
        arrow_size->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(arrow_size);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout);

        label_2 = new QLabel(pose_array_config);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_2);

        status = new QLabel(pose_array_config);
        status->setObjectName(QString::fromUtf8("status"));
        status->setFont(font);
        status->setStyleSheet(QString::fromUtf8(""));
        status->setWordWrap(true);

        formLayout->setWidget(6, QFormLayout::FieldRole, status);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(7, QFormLayout::FieldRole, verticalSpacer);

        positiontolerance = new QDoubleSpinBox(pose_array_config);
        positiontolerance->setObjectName(QString::fromUtf8("positiontolerance"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(positiontolerance->sizePolicy().hasHeightForWidth());
        positiontolerance->setSizePolicy(sizePolicy);
        positiontolerance->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        positiontolerance->setValue(1.000000000000000);

        formLayout->setWidget(5, QFormLayout::FieldRole, positiontolerance);

        label_4 = new QLabel(pose_array_config);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_4);


        retranslateUi(pose_array_config);

        drawstyle->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(pose_array_config);
    } // setupUi

    void retranslateUi(QWidget *pose_array_config)
    {
        pose_array_config->setWindowTitle(QApplication::translate("pose_array_config", "Form", nullptr));
        label->setText(QApplication::translate("pose_array_config", "Topic:", nullptr));
        selecttopic->setText(QApplication::translate("pose_array_config", "Select", nullptr));
        label_3->setText(QApplication::translate("pose_array_config", "Color:", nullptr));
        color->setText(QString());
        label_7->setText(QApplication::translate("pose_array_config", "Draw Style:", nullptr));
        drawstyle->setItemText(0, QApplication::translate("pose_array_config", "arrows", nullptr));
        drawstyle->setItemText(1, QApplication::translate("pose_array_config", "points", nullptr));

        drawstyle->setCurrentText(QApplication::translate("pose_array_config", "arrows", nullptr));
        label_8->setText(QApplication::translate("pose_array_config", "Static Arrow Sizes:", nullptr));
        static_arrow_sizes->setText(QString());
        label_2->setText(QApplication::translate("pose_array_config", "Status:", nullptr));
        status->setText(QApplication::translate("pose_array_config", "No topic", nullptr));
        positiontolerance->setSuffix(QString());
        label_4->setText(QApplication::translate("pose_array_config", "Position Tolerance:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pose_array_config: public Ui_pose_array_config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSE_ARRAY_CONFIG_H
