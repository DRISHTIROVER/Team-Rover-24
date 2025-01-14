/********************************************************************************
** Form generated from reading UI file 'object_config.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBJECT_CONFIG_H
#define UI_OBJECT_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <mapviz/color_button.h>

QT_BEGIN_NAMESPACE

class Ui_object_config
{
public:
    QGridLayout *gridLayout;
    QLabel *status;
    QLineEdit *topic;
    QLabel *label_2;
    QPushButton *selecttopic;
    QLabel *label;
    QLabel *label_3;
    mapviz::ColorButton *color;
    QLabel *label_4;
    QCheckBox *show_ids;
    QLabel *label_5;
    QCheckBox *show_inactive;

    void setupUi(QWidget *object_config)
    {
        if (object_config->objectName().isEmpty())
            object_config->setObjectName(QString::fromUtf8("object_config"));
        object_config->resize(400, 300);
        object_config->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(object_config);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(4);
        gridLayout->setContentsMargins(2, 2, 2, 2);
        status = new QLabel(object_config);
        status->setObjectName(QString::fromUtf8("status"));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setPointSize(8);
        status->setFont(font);
        status->setStyleSheet(QString::fromUtf8(""));
        status->setWordWrap(true);

        gridLayout->addWidget(status, 6, 3, 1, 2);

        topic = new QLineEdit(object_config);
        topic->setObjectName(QString::fromUtf8("topic"));
        topic->setFont(font);

        gridLayout->addWidget(topic, 2, 3, 1, 1);

        label_2 = new QLabel(object_config);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 6, 0, 1, 1);

        selecttopic = new QPushButton(object_config);
        selecttopic->setObjectName(QString::fromUtf8("selecttopic"));
        selecttopic->setMaximumSize(QSize(55, 16777215));
        selecttopic->setFont(font);
        selecttopic->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(selecttopic, 2, 4, 1, 1);

        label = new QLabel(object_config);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_3 = new QLabel(object_config);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        color = new mapviz::ColorButton(object_config);
        color->setObjectName(QString::fromUtf8("color"));
        color->setMaximumSize(QSize(24, 24));
        color->setAutoFillBackground(false);
        color->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(color, 3, 3, 1, 1);

        label_4 = new QLabel(object_config);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        show_ids = new QCheckBox(object_config);
        show_ids->setObjectName(QString::fromUtf8("show_ids"));

        gridLayout->addWidget(show_ids, 4, 3, 1, 1);

        label_5 = new QLabel(object_config);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        show_inactive = new QCheckBox(object_config);
        show_inactive->setObjectName(QString::fromUtf8("show_inactive"));
        show_inactive->setChecked(true);

        gridLayout->addWidget(show_inactive, 5, 3, 1, 1);


        retranslateUi(object_config);

        QMetaObject::connectSlotsByName(object_config);
    } // setupUi

    void retranslateUi(QWidget *object_config)
    {
        object_config->setWindowTitle(QApplication::translate("object_config", "Form", nullptr));
        status->setText(QApplication::translate("object_config", "No topic", nullptr));
        label_2->setText(QApplication::translate("object_config", "Status:", nullptr));
        selecttopic->setText(QApplication::translate("object_config", "Select", nullptr));
        label->setText(QApplication::translate("object_config", "Topic:", nullptr));
        label_3->setText(QApplication::translate("object_config", "Color:", nullptr));
        color->setText(QString());
        label_4->setText(QApplication::translate("object_config", "Show IDs:", nullptr));
        show_ids->setText(QString());
        label_5->setText(QApplication::translate("object_config", "Show Inactive:", nullptr));
        show_inactive->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class object_config: public Ui_object_config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBJECT_CONFIG_H
