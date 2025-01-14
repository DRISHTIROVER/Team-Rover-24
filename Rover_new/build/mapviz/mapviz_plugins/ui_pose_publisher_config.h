/********************************************************************************
** Form generated from reading UI file 'pose_publisher_config.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSE_PUBLISHER_CONFIG_H
#define UI_POSE_PUBLISHER_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pose_publisher_config
{
public:
    QGridLayout *gridLayout;
    QComboBox *outputframe;
    QLabel *label;
    QLabel *output_frame;
    QLineEdit *topic;
    QLabel *status;
    QLabel *point_publisher_status;
    QPushButton *pushButtonPose;

    void setupUi(QWidget *pose_publisher_config)
    {
        if (pose_publisher_config->objectName().isEmpty())
            pose_publisher_config->setObjectName(QString::fromUtf8("pose_publisher_config"));
        pose_publisher_config->resize(400, 300);
        pose_publisher_config->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(pose_publisher_config);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(4);
        gridLayout->setContentsMargins(2, 2, 2, 2);
        outputframe = new QComboBox(pose_publisher_config);
        outputframe->setObjectName(QString::fromUtf8("outputframe"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(outputframe->sizePolicy().hasHeightForWidth());
        outputframe->setSizePolicy(sizePolicy);
        outputframe->setMaximumSize(QSize(16777215, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setPointSize(8);
        outputframe->setFont(font);
        outputframe->setEditable(true);

        gridLayout->addWidget(outputframe, 3, 1, 1, 1);

        label = new QLabel(pose_publisher_config);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        output_frame = new QLabel(pose_publisher_config);
        output_frame->setObjectName(QString::fromUtf8("output_frame"));
        output_frame->setFont(font);

        gridLayout->addWidget(output_frame, 3, 0, 1, 1);

        topic = new QLineEdit(pose_publisher_config);
        topic->setObjectName(QString::fromUtf8("topic"));
        topic->setFont(font);

        gridLayout->addWidget(topic, 2, 1, 1, 1);

        status = new QLabel(pose_publisher_config);
        status->setObjectName(QString::fromUtf8("status"));
        status->setFont(font);
        status->setStyleSheet(QString::fromUtf8(""));
        status->setWordWrap(true);

        gridLayout->addWidget(status, 5, 1, 1, 1);

        point_publisher_status = new QLabel(pose_publisher_config);
        point_publisher_status->setObjectName(QString::fromUtf8("point_publisher_status"));
        point_publisher_status->setFont(font);

        gridLayout->addWidget(point_publisher_status, 5, 0, 1, 1);

        pushButtonPose = new QPushButton(pose_publisher_config);
        pushButtonPose->setObjectName(QString::fromUtf8("pushButtonPose"));
        pushButtonPose->setCheckable(true);

        gridLayout->addWidget(pushButtonPose, 4, 0, 1, 1);


        retranslateUi(pose_publisher_config);

        QMetaObject::connectSlotsByName(pose_publisher_config);
    } // setupUi

    void retranslateUi(QWidget *pose_publisher_config)
    {
        pose_publisher_config->setWindowTitle(QApplication::translate("pose_publisher_config", "Form", nullptr));
#ifndef QT_NO_TOOLTIP
        outputframe->setToolTip(QApplication::translate("pose_publisher_config", "The reference frame that points will be published in.\n"
"                        ", nullptr));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("pose_publisher_config", "Topic:", nullptr));
        output_frame->setText(QApplication::translate("pose_publisher_config", "Frame:", nullptr));
        topic->setText(QApplication::translate("pose_publisher_config", "/selected_pose", nullptr));
        status->setText(QApplication::translate("pose_publisher_config", "No topic", nullptr));
        point_publisher_status->setText(QApplication::translate("pose_publisher_config", "Status:", nullptr));
        pushButtonPose->setText(QApplication::translate("pose_publisher_config", "Publish Pose", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pose_publisher_config: public Ui_pose_publisher_config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSE_PUBLISHER_CONFIG_H
