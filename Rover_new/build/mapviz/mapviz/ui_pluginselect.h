/********************************************************************************
** Form generated from reading UI file 'pluginselect.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLUGINSELECT_H
#define UI_PLUGINSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_pluginselect
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *displaylist;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *pluginselect)
    {
        if (pluginselect->objectName().isEmpty())
            pluginselect->setObjectName(QString::fromUtf8("pluginselect"));
        pluginselect->resize(400, 300);
        pluginselect->setModal(true);
        horizontalLayout = new QHBoxLayout(pluginselect);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        displaylist = new QListWidget(pluginselect);
        displaylist->setObjectName(QString::fromUtf8("displaylist"));
        displaylist->setSortingEnabled(true);

        horizontalLayout->addWidget(displaylist);

        buttonBox = new QDialogButtonBox(pluginselect);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        retranslateUi(pluginselect);
        QObject::connect(buttonBox, SIGNAL(accepted()), pluginselect, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), pluginselect, SLOT(reject()));
        QObject::connect(displaylist, SIGNAL(doubleClicked(QModelIndex)), pluginselect, SLOT(accept()));

        QMetaObject::connectSlotsByName(pluginselect);
    } // setupUi

    void retranslateUi(QDialog *pluginselect)
    {
        pluginselect->setWindowTitle(QApplication::translate("pluginselect", "Select New Display", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pluginselect: public Ui_pluginselect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLUGINSELECT_H
