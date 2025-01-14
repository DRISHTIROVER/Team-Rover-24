/********************************************************************************
** Form generated from reading UI file 'topic_select.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPIC_SELECT_H
#define UI_TOPIC_SELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_topicselect
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *displaylist;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *topicselect)
    {
        if (topicselect->objectName().isEmpty())
            topicselect->setObjectName(QString::fromUtf8("topicselect"));
        topicselect->resize(400, 300);
        topicselect->setModal(true);
        horizontalLayout = new QHBoxLayout(topicselect);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        displaylist = new QListWidget(topicselect);
        displaylist->setObjectName(QString::fromUtf8("displaylist"));
        displaylist->setSortingEnabled(true);

        horizontalLayout->addWidget(displaylist);

        buttonBox = new QDialogButtonBox(topicselect);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        retranslateUi(topicselect);
        QObject::connect(buttonBox, SIGNAL(accepted()), topicselect, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), topicselect, SLOT(reject()));

        QMetaObject::connectSlotsByName(topicselect);
    } // setupUi

    void retranslateUi(QDialog *topicselect)
    {
        topicselect->setWindowTitle(QApplication::translate("topicselect", "Select Topic", nullptr));
    } // retranslateUi

};

namespace Ui {
    class topicselect: public Ui_topicselect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPIC_SELECT_H
