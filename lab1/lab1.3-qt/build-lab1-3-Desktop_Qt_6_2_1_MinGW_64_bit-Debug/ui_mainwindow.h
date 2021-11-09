/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_1;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLineEdit *edtYPlate;
    QLineEdit *edtXPaper;
    QPushButton *btnWriteFile;
    QPushButton *btnIsBalance;
    QLabel *label_10;
    QLineEdit *edtHPaper;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *edtHPlate;
    QLineEdit *edtLPaper;
    QTextEdit *txtStack;
    QLabel *label_7;
    QLabel *label_11;
    QLabel *label_2;
    QLineEdit *edtXPlate;
    QLineEdit *edtWPaper;
    QLineEdit *edtMassPaper;
    QPushButton *btnAddPaper;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_9;
    QLineEdit *edtRPlate;
    QLineEdit *edtYPaper;
    QPushButton *btnReadFile;
    QPushButton *btnAddPlate;
    QPushButton *btnDelTop;
    QPushButton *btnClear;
    QLineEdit *edtMassPlate;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(882, 548);
        MainWindow->setMinimumSize(QSize(882, 548));
        MainWindow->setMaximumSize(QSize(3000, 3000));
        action_1 = new QAction(MainWindow);
        action_1->setObjectName(QString::fromUtf8("action_1"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font;
        font.setPointSize(12);
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 8, 0, 1, 1);

        edtYPlate = new QLineEdit(centralwidget);
        edtYPlate->setObjectName(QString::fromUtf8("edtYPlate"));

        gridLayout->addWidget(edtYPlate, 3, 1, 1, 1);

        edtXPaper = new QLineEdit(centralwidget);
        edtXPaper->setObjectName(QString::fromUtf8("edtXPaper"));

        gridLayout->addWidget(edtXPaper, 9, 1, 1, 1);

        btnWriteFile = new QPushButton(centralwidget);
        btnWriteFile->setObjectName(QString::fromUtf8("btnWriteFile"));

        gridLayout->addWidget(btnWriteFile, 13, 3, 1, 1);

        btnIsBalance = new QPushButton(centralwidget);
        btnIsBalance->setObjectName(QString::fromUtf8("btnIsBalance"));

        gridLayout->addWidget(btnIsBalance, 7, 3, 1, 1);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        gridLayout->addWidget(label_10, 11, 0, 1, 1);

        edtHPaper = new QLineEdit(centralwidget);
        edtHPaper->setObjectName(QString::fromUtf8("edtHPaper"));

        gridLayout->addWidget(edtHPaper, 13, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 9, 0, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        edtHPlate = new QLineEdit(centralwidget);
        edtHPlate->setObjectName(QString::fromUtf8("edtHPlate"));

        gridLayout->addWidget(edtHPlate, 5, 1, 1, 1);

        edtLPaper = new QLineEdit(centralwidget);
        edtLPaper->setObjectName(QString::fromUtf8("edtLPaper"));

        gridLayout->addWidget(edtLPaper, 11, 1, 1, 1);

        txtStack = new QTextEdit(centralwidget);
        txtStack->setObjectName(QString::fromUtf8("txtStack"));
        txtStack->setReadOnly(true);

        gridLayout->addWidget(txtStack, 1, 2, 14, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 12, 0, 1, 1);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        gridLayout->addWidget(label_11, 13, 0, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        edtXPlate = new QLineEdit(centralwidget);
        edtXPlate->setObjectName(QString::fromUtf8("edtXPlate"));

        gridLayout->addWidget(edtXPlate, 2, 1, 1, 1);

        edtWPaper = new QLineEdit(centralwidget);
        edtWPaper->setObjectName(QString::fromUtf8("edtWPaper"));

        gridLayout->addWidget(edtWPaper, 12, 1, 1, 1);

        edtMassPaper = new QLineEdit(centralwidget);
        edtMassPaper->setObjectName(QString::fromUtf8("edtMassPaper"));

        gridLayout->addWidget(edtMassPaper, 8, 1, 1, 1);

        btnAddPaper = new QPushButton(centralwidget);
        btnAddPaper->setObjectName(QString::fromUtf8("btnAddPaper"));

        gridLayout->addWidget(btnAddPaper, 14, 0, 1, 2);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        gridLayout->addWidget(label_9, 10, 0, 1, 1);

        edtRPlate = new QLineEdit(centralwidget);
        edtRPlate->setObjectName(QString::fromUtf8("edtRPlate"));

        gridLayout->addWidget(edtRPlate, 4, 1, 1, 1);

        edtYPaper = new QLineEdit(centralwidget);
        edtYPaper->setObjectName(QString::fromUtf8("edtYPaper"));

        gridLayout->addWidget(edtYPaper, 10, 1, 1, 1);

        btnReadFile = new QPushButton(centralwidget);
        btnReadFile->setObjectName(QString::fromUtf8("btnReadFile"));

        gridLayout->addWidget(btnReadFile, 14, 3, 1, 1);

        btnAddPlate = new QPushButton(centralwidget);
        btnAddPlate->setObjectName(QString::fromUtf8("btnAddPlate"));

        gridLayout->addWidget(btnAddPlate, 6, 0, 1, 2);

        btnDelTop = new QPushButton(centralwidget);
        btnDelTop->setObjectName(QString::fromUtf8("btnDelTop"));

        gridLayout->addWidget(btnDelTop, 1, 3, 1, 1);

        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));

        gridLayout->addWidget(btnClear, 2, 3, 1, 1);

        edtMassPlate = new QLineEdit(centralwidget);
        edtMassPlate->setObjectName(QString::fromUtf8("edtMassPlate"));

        gridLayout->addWidget(edtMassPlate, 1, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "lab1-3", nullptr));
        action_1->setText(QCoreApplication::translate("MainWindow", "\320\255\320\272\321\201\320\277\320\276\321\200\321\202", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\320\277\320\276\321\200\321\202", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\201\321\202\320\276\320\277\320\272\321\203", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "mass:", nullptr));
        btnWriteFile->setText(QCoreApplication::translate("MainWindow", "serialise", nullptr));
        btnIsBalance->setText(QCoreApplication::translate("MainWindow", "is balance", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "l:", nullptr));
        edtHPaper->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "x:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "radius:", nullptr));
        edtHPlate->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "w:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "h:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "x:", nullptr));
        edtWPaper->setText(QString());
        btnAddPaper->setText(QCoreApplication::translate("MainWindow", "add paper", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "y:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "h:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "y:", nullptr));
        btnReadFile->setText(QCoreApplication::translate("MainWindow", "create from file", nullptr));
        btnAddPlate->setText(QCoreApplication::translate("MainWindow", "add plate", nullptr));
        btnDelTop->setText(QCoreApplication::translate("MainWindow", "del top", nullptr));
        btnClear->setText(QCoreApplication::translate("MainWindow", "clear stack", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "mass:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
