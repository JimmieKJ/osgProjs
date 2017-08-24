/********************************************************************************
** Form generated from reading UI file 'ExportDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTDIALOG_H
#define UI_EXPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExportDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *exportPathEdit;
    QPushButton *exportPathBrowseButton;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *earthFileCheckBox;
    QLineEdit *earthFilePathEdit;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *boundsCheckBox;
    QLabel *boundsLabel;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *maxLevelCheckBox;
    QSpinBox *maxLevelSpinBox;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *overwriteCheckBox;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *keepEmptiesCheckBox;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpinBox *concurrencySpinBox;
    QRadioButton *rbModeSingle;
    QRadioButton *rbModeMT;
    QRadioButton *rbModeMP;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QLabel *estimateLabel;
    QLabel *errorLabel;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *ExportDialog)
    {
        if (ExportDialog->objectName().isEmpty())
            ExportDialog->setObjectName(QStringLiteral("ExportDialog"));
        ExportDialog->resize(565, 357);
        verticalLayout = new QVBoxLayout(ExportDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(ExportDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        exportPathEdit = new QLineEdit(ExportDialog);
        exportPathEdit->setObjectName(QStringLiteral("exportPathEdit"));

        horizontalLayout->addWidget(exportPathEdit);

        exportPathBrowseButton = new QPushButton(ExportDialog);
        exportPathBrowseButton->setObjectName(QStringLiteral("exportPathBrowseButton"));

        horizontalLayout->addWidget(exportPathBrowseButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        earthFileCheckBox = new QCheckBox(ExportDialog);
        earthFileCheckBox->setObjectName(QStringLiteral("earthFileCheckBox"));

        horizontalLayout_2->addWidget(earthFileCheckBox);

        earthFilePathEdit = new QLineEdit(ExportDialog);
        earthFilePathEdit->setObjectName(QStringLiteral("earthFilePathEdit"));
        earthFilePathEdit->setEnabled(false);

        horizontalLayout_2->addWidget(earthFilePathEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        boundsCheckBox = new QCheckBox(ExportDialog);
        boundsCheckBox->setObjectName(QStringLiteral("boundsCheckBox"));
        boundsCheckBox->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(boundsCheckBox->sizePolicy().hasHeightForWidth());
        boundsCheckBox->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(boundsCheckBox);

        boundsLabel = new QLabel(ExportDialog);
        boundsLabel->setObjectName(QStringLiteral("boundsLabel"));
        boundsLabel->setEnabled(false);

        horizontalLayout_7->addWidget(boundsLabel);


        verticalLayout->addLayout(horizontalLayout_7);

        groupBox = new QGroupBox(ExportDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        maxLevelCheckBox = new QCheckBox(groupBox);
        maxLevelCheckBox->setObjectName(QStringLiteral("maxLevelCheckBox"));
        maxLevelCheckBox->setChecked(true);

        horizontalLayout_3->addWidget(maxLevelCheckBox);

        maxLevelSpinBox = new QSpinBox(groupBox);
        maxLevelSpinBox->setObjectName(QStringLiteral("maxLevelSpinBox"));
        maxLevelSpinBox->setEnabled(true);
        maxLevelSpinBox->setMinimum(1);
        maxLevelSpinBox->setMaximum(99);
        maxLevelSpinBox->setValue(10);

        horizontalLayout_3->addWidget(maxLevelSpinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        overwriteCheckBox = new QCheckBox(groupBox);
        overwriteCheckBox->setObjectName(QStringLiteral("overwriteCheckBox"));

        horizontalLayout_5->addWidget(overwriteCheckBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        keepEmptiesCheckBox = new QCheckBox(groupBox);
        keepEmptiesCheckBox->setObjectName(QStringLiteral("keepEmptiesCheckBox"));

        horizontalLayout_6->addWidget(keepEmptiesCheckBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_6);

        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        concurrencySpinBox = new QSpinBox(widget);
        concurrencySpinBox->setObjectName(QStringLiteral("concurrencySpinBox"));
        concurrencySpinBox->setEnabled(false);
        concurrencySpinBox->setMinimum(1);

        horizontalLayout_4->addWidget(concurrencySpinBox);

        rbModeSingle = new QRadioButton(widget);
        rbModeSingle->setObjectName(QStringLiteral("rbModeSingle"));
        rbModeSingle->setChecked(true);

        horizontalLayout_4->addWidget(rbModeSingle);

        rbModeMT = new QRadioButton(widget);
        rbModeMT->setObjectName(QStringLiteral("rbModeMT"));

        horizontalLayout_4->addWidget(rbModeMT);

        rbModeMP = new QRadioButton(widget);
        rbModeMP->setObjectName(QStringLiteral("rbModeMP"));

        horizontalLayout_4->addWidget(rbModeMP);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget);


        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        estimateLabel = new QLabel(ExportDialog);
        estimateLabel->setObjectName(QStringLiteral("estimateLabel"));

        verticalLayout->addWidget(estimateLabel);

        errorLabel = new QLabel(ExportDialog);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));

        verticalLayout->addWidget(errorLabel);

        hboxLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(ExportDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(ExportDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout->addWidget(cancelButton);


        verticalLayout->addLayout(hboxLayout);


        retranslateUi(ExportDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), ExportDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ExportDialog);
    } // setupUi

    void retranslateUi(QDialog *ExportDialog)
    {
        ExportDialog->setWindowTitle(QApplication::translate("ExportDialog", "Export Settings", 0));
        label->setText(QApplication::translate("ExportDialog", "Export location:", 0));
        exportPathBrowseButton->setText(QApplication::translate("ExportDialog", "Browse", 0));
        earthFileCheckBox->setText(QApplication::translate("ExportDialog", "Generate .earth file:", 0));
        earthFilePathEdit->setText(QApplication::translate("ExportDialog", "out.earth", 0));
        boundsCheckBox->setText(QApplication::translate("ExportDialog", "Bounds:", 0));
        boundsLabel->setText(QApplication::translate("ExportDialog", "unspecified", 0));
        groupBox->setTitle(QApplication::translate("ExportDialog", "Details", 0));
        maxLevelCheckBox->setText(QApplication::translate("ExportDialog", "Max level (no max level = infinity):", 0));
        overwriteCheckBox->setText(QApplication::translate("ExportDialog", "Overwrite existing tiles", 0));
        keepEmptiesCheckBox->setText(QApplication::translate("ExportDialog", "Keep empty (transparent) image tiles", 0));
        label_2->setText(QApplication::translate("ExportDialog", "Concurrency", 0));
        rbModeSingle->setText(QApplication::translate("ExportDialog", "Single Threaded", 0));
        rbModeMT->setText(QApplication::translate("ExportDialog", "Multithreaded", 0));
        rbModeMP->setText(QApplication::translate("ExportDialog", "Multiprocess", 0));
        estimateLabel->setText(QApplication::translate("ExportDialog", "Estimate", 0));
        errorLabel->setText(QString());
        okButton->setText(QApplication::translate("ExportDialog", "OK", 0));
        cancelButton->setText(QApplication::translate("ExportDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class ExportDialog: public Ui_ExportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTDIALOG_H
