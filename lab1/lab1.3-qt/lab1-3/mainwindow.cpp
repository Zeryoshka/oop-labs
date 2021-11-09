#include <variant>
#include <QMessageBox>
#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnAddPaper, &QPushButton::clicked, this, &MainWindow::addPaper);
    connect(ui->btnAddPlate, &QPushButton::clicked, this, &MainWindow::addPlate);
    connect(ui->btnClear, &QPushButton::clicked, this, &MainWindow::clear);
    connect(ui->btnDelTop, &QPushButton::clicked, this, &MainWindow::delTop);
    connect(ui->btnIsBalance, &QPushButton::clicked, this, &MainWindow::btnIsBalance);
    connect(ui->btnReadFile, &QPushButton::clicked, this, &MainWindow::createStackFromFile);
    connect(ui->btnWriteFile, &QPushButton::clicked, this, &MainWindow::serialise);
    _stack = new Stack();
    ui->btnClear->setVisible(false);
    ui->btnDelTop->setVisible(false);
}

void MainWindow::addPaper() {
    QString m_str = ui->edtMassPaper->text();
    bool ok;
    int m = m_str.toInt(&ok, 10);
    if (!ok or m <= 0) {
        QMessageBox::about(this, "Error", "Масса невалидна");
        return;
    }

    QString l_str = ui->edtLPaper->text();
    int l = l_str.toInt(&ok, 10);
    if (!ok or l <= 0) {
        QMessageBox::about(this, "Error", "Длина невалидна");
        return;
    }

    QString w_str = ui->edtWPaper->text();
    int w = w_str.toInt(&ok, 10);
    if (!ok or l <= 0) {
        QMessageBox::about(this, "Error", "Ширина невалидна");
        return;
    }

    QString x_str = ui->edtXPaper->text();
    int x = x_str.toInt(&ok, 10);
    if (!ok) {
        QMessageBox::about(this, "Error", "X невалиден");
        return;
    }

    QString y_str = ui->edtYPaper->text();
    int y = y_str.toInt(&ok, 10);
    if (!ok) {
        QMessageBox::about(this, "Error", "Y невалиден");
        return;
    }

    QString h_str = ui->edtHPaper->text();
    int h = h_str.toInt(&ok, 10);
    if (!ok or h <= 0) {
        QMessageBox::about(this, "Error", "Высота невалиден");
        return;
    }

    _stack->push(Paper(l, w, h, x, y, m));
    printStack();

    ui->btnClear->setVisible(true);
    ui->btnDelTop->setVisible(true);
}

void MainWindow::addPlate() {
    QString m_str = ui->edtMassPlate->text();
    bool ok;
    int m = m_str.toInt(&ok, 10);
    if (!ok or m <= 0) {
        QMessageBox::about(this, "Error", "Масса невалидна");
        return;
    }

    QString r_str = ui->edtRPlate->text();
    int r = r_str.toInt(&ok, 10);
    if (!ok or r <= 0) {
        QMessageBox::about(this, "Error", "Радиус невалиден");
        return;
    }

    QString x_str = ui->edtXPlate->text();
    int x = x_str.toInt(&ok, 10);
    if (!ok) {
        QMessageBox::about(this, "Error", "X невалиден");
        return;
    }

    QString y_str = ui->edtYPlate->text();
    int y = y_str.toInt(&ok, 10);
    if (!ok) {
        QMessageBox::about(this, "Error", "Y невалиден");
        return;
    }

    QString h_str = ui->edtHPlate->text();
    int h = h_str.toInt(&ok, 10);
    if (!ok or h <= 0) {
        QMessageBox::about(this, "Error", "Высота невалиден");
        return;
    }

    _stack->push(Plate(r, h, x, y, m));
    printStack();

    ui->btnClear->setVisible(true);
    ui->btnDelTop->setVisible(true);
}

void MainWindow::clear() {
    _stack->clear();
    printStack();
    ui->btnClear->setVisible(false);
    ui->btnDelTop->setVisible(false);
}

void MainWindow::delTop() {
    if (_stack->isEmpty()) {
        QMessageBox::about(this, "Error", "Стек пустой, удалять нечего");
        return;
    }
    _stack->pop();
    if (_stack->getLen() == 0) {
        ui->btnClear->setVisible(false);
        ui->btnDelTop->setVisible(false);
    }
    printStack();
}

void MainWindow::btnIsBalance() {
    if (_stack->isBalance()) {
        QMessageBox::about(this, "Error", "Стопка сбалансирована");
        return;
    }
    QMessageBox::about(this, "Error", "Стопка не сбалансирована");
    return;
}

void MainWindow::printStack() {
    ui->txtStack->clear();
    if (_stack->isEmpty())
        return;
    Iterat iter = _stack->getIterator();
    while (!iter.isLast()) {
        ui->txtStack->append(
            QString::fromStdString(
                std::visit(CallToString{}, iter.value())
            )
        );
        iter.next();
    }
    ui->txtStack->append(
        QString::fromStdString(
            std::visit(CallToString{}, iter.value())
        )
    );
}

void MainWindow::serialise() {
    QString f_name = QFileDialog::getSaveFileName(this, "Write to...");
    QFile file(f_name);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::about(this, "Error", "Невозможно открыть файл на запись");
        return;
    }
    QTextStream out(&file);
    _stack->serialise(out);
    file.close();

}

void MainWindow::createStackFromFile() {
    QString f_name = QFileDialog::getOpenFileName(this, "Read from...");
    QFile file(f_name);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::about(this, "Error", "Невозможно открыть файл на запись");
        return;
    }
    QTextStream inp(&file);
    delete _stack;
    _stack = new Stack(inp);
    file.close();
    ui->btnClear->setVisible(_stack->getLen() != 0);
    ui->btnDelTop->setVisible(_stack->getLen() != 0);
    printStack();
}

MainWindow::~MainWindow() {
    delete ui;
    delete _stack;
}
