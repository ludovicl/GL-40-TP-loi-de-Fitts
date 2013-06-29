#include <QApplication>
#include <QTextCodec>
#include <QDesktopWidget>
#include "mainwindow.h"
#include "sequencewindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Codec UTF8
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    // Main Window
    MainWindow *mainWin = new MainWindow;

    // Receive the screen size and put mainWin at the middle of screen
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-mainWin->width()) / 2;
    int y = (screenGeometry.height()-mainWin->height()) / 2;
    mainWin->move(x, y);

    // Show Main Window
    mainWin->show();

    return app.exec();
}

