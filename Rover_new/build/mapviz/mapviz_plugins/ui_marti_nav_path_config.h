/********************************************************************************
** Form generated from reading UI file 'marti_nav_path_config.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARTI_NAV_PATH_CONFIG_H
#define UI_MARTI_NAV_PATH_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mapviz/color_button.h>

QT_BEGIN_NAMESPACE

class Ui_marti_nav_path_config
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *topic;
    QPushButton *select_topic;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QLineEdit *frame;
    QPushButton *select_frame;
    QHBoxLayout *horizontalLayout_3;
    QFormLayout *formLayout_2;
    QCheckBox *draw_lines;
    QCheckBox *draw_points;
    QCheckBox *draw_yaw;
    QLabel *label_5;
    QDoubleSpinBox *line_width;
    QLabel *label_6;
    QDoubleSpinBox *arrow_length;
    QLabel *label_7;
    QSpinBox *history_size;
    QFormLayout *formLayout;
    QLabel *label_3;
    mapviz::ColorButton *forward_color;
    QLabel *label_4;
    mapviz::ColorButton *reverse_color;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *status;

    void setupUi(QWidget *marti_nav_path_config)
    {
        if (marti_nav_path_config->objectName().isEmpty())
            marti_nav_path_config->setObjectName(QString::fromUtf8("marti_nav_path_config"));
        marti_nav_path_config->resize(409, 302);
        marti_nav_path_config->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(marti_nav_path_config);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(marti_nav_path_config);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setPointSize(8);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        topic = new QLineEdit(marti_nav_path_config);
        topic->setObjectName(QString::fromUtf8("topic"));
        topic->setFont(font);

        horizontalLayout->addWidget(topic);

        select_topic = new QPushButton(marti_nav_path_config);
        select_topic->setObjectName(QString::fromUtf8("select_topic"));
        select_topic->setMaximumSize(QSize(55, 16777215));
        select_topic->setFont(font);
        select_topic->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(select_topic);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_8 = new QLabel(marti_nav_path_config);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        horizontalLayout_4->addWidget(label_8);

        frame = new QLineEdit(marti_nav_path_config);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFont(font);

        horizontalLayout_4->addWidget(frame);

        select_frame = new QPushButton(marti_nav_path_config);
        select_frame->setObjectName(QString::fromUtf8("select_frame"));
        select_frame->setMaximumSize(QSize(55, 16777215));
        select_frame->setFont(font);
        select_frame->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(select_frame);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        draw_lines = new QCheckBox(marti_nav_path_config);
        draw_lines->setObjectName(QString::fromUtf8("draw_lines"));
        draw_lines->setFont(font);
        draw_lines->setChecked(true);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, draw_lines);

        draw_points = new QCheckBox(marti_nav_path_config);
        draw_points->setObjectName(QString::fromUtf8("draw_points"));
        draw_points->setFont(font);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, draw_points);

        draw_yaw = new QCheckBox(marti_nav_path_config);
        draw_yaw->setObjectName(QString::fromUtf8("draw_yaw"));
        draw_yaw->setFont(font);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, draw_yaw);

        label_5 = new QLabel(marti_nav_path_config);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_5);

        line_width = new QDoubleSpinBox(marti_nav_path_config);
        line_width->setObjectName(QString::fromUtf8("line_width"));
        line_width->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setPointSize(8);
        line_width->setFont(font1);
        line_width->setDecimals(1);
        line_width->setMinimum(0.100000000000000);
        line_width->setValue(1.000000000000000);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, line_width);

        label_6 = new QLabel(marti_nav_path_config);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_6);

        arrow_length = new QDoubleSpinBox(marti_nav_path_config);
        arrow_length->setObjectName(QString::fromUtf8("arrow_length"));
        arrow_length->setMaximumSize(QSize(16777215, 16777215));
        arrow_length->setFont(font1);
        arrow_length->setMinimum(0.010000000000000);
        arrow_length->setMaximum(20.000000000000000);
        arrow_length->setSingleStep(0.100000000000000);
        arrow_length->setValue(0.800000000000000);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, arrow_length);

        label_7 = new QLabel(marti_nav_path_config);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_7);

        history_size = new QSpinBox(marti_nav_path_config);
        history_size->setObjectName(QString::fromUtf8("history_size"));
        history_size->setFont(font1);
        history_size->setMinimum(1);
        history_size->setMaximum(10000000);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, history_size);


        horizontalLayout_3->addLayout(formLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_3 = new QLabel(marti_nav_path_config);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        forward_color = new mapviz::ColorButton(marti_nav_path_config);
        forward_color->setObjectName(QString::fromUtf8("forward_color"));
        forward_color->setMaximumSize(QSize(24, 24));
        forward_color->setAutoFillBackground(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, forward_color);

        label_4 = new QLabel(marti_nav_path_config);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        reverse_color = new mapviz::ColorButton(marti_nav_path_config);
        reverse_color->setObjectName(QString::fromUtf8("reverse_color"));
        reverse_color->setMaximumSize(QSize(24, 24));
        reverse_color->setAutoFillBackground(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, reverse_color);


        horizontalLayout_3->addLayout(formLayout);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(marti_nav_path_config);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(40, 16777215));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        status = new QLabel(marti_nav_path_config);
        status->setObjectName(QString::fromUtf8("status"));
        status->setFont(font);
        status->setStyleSheet(QString::fromUtf8(""));
        status->setWordWrap(true);

        horizontalLayout_2->addWidget(status);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(marti_nav_path_config);

        QMetaObject::connectSlotsByName(marti_nav_path_config);
    } // setupUi

    void retranslateUi(QWidget *marti_nav_path_config)
    {
        marti_nav_path_config->setWindowTitle(QApplication::translate("marti_nav_path_config", "Form", nullptr));
        label->setText(QApplication::translate("marti_nav_path_config", "Topic:", nullptr));
        select_topic->setText(QApplication::translate("marti_nav_path_config", "Select", nullptr));
        label_8->setText(QApplication::translate("marti_nav_path_config", "Frame:", nullptr));
        select_frame->setText(QApplication::translate("marti_nav_path_config", "Select", nullptr));
        draw_lines->setText(QApplication::translate("marti_nav_path_config", "Draw lines", nullptr));
        draw_points->setText(QApplication::translate("marti_nav_path_config", "Draw points", nullptr));
        draw_yaw->setText(QApplication::translate("marti_nav_path_config", "Draw yaw", nullptr));
        label_5->setText(QApplication::translate("marti_nav_path_config", "Line width:", nullptr));
        label_6->setText(QApplication::translate("marti_nav_path_config", "Arrow length:", nullptr));
        label_7->setText(QApplication::translate("marti_nav_path_config", "History", nullptr));
        label_3->setText(QApplication::translate("marti_nav_path_config", "Forward color:", nullptr));
        forward_color->setText(QString());
        label_4->setText(QApplication::translate("marti_nav_path_config", "Reverse color:", nullptr));
        reverse_color->setText(QString());
        label_2->setText(QApplication::translate("marti_nav_path_config", "Status:", nullptr));
        status->setText(QApplication::translate("marti_nav_path_config", "No topic", nullptr));
    } // retranslateUi

};

namespace Ui {
    class marti_nav_path_config: public Ui_marti_nav_path_config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARTI_NAV_PATH_CONFIG_H
