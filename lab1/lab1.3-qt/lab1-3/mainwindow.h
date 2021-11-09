#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "stack.h"
#include "paper.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void addPaper();
    void addPlate();
    void printStack();
    void delTop();
    void clear();
    void btnIsBalance();
    void createStackFromFile();
    void serialise();
private:
    Stack* _stack;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
