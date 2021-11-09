#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <assert.h>

#include <stack.h>

int main(int argc, char *argv[])
{
    Stack stack;
    assert(stack.isEmpty());

    Plate plate{100, 1, 0, 0, 10};
    stack.push(plate);
    assert(stack.top().index() == 1);

    Paper paper{10, 10, 1, 0, 0, 10};
    stack.push(paper);
    assert(stack.top().index() == 0);

    assert(stack.getLen() == 2);
    assert(stack.isBalance());

    stack.pop();
    assert(stack.getLen() == 1);
    assert(stack.isBalance());

    stack.clear();
    assert(stack.getLen() == 0);

    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "lab1-3_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
