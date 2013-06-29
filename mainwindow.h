#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QStatusBar>
#include <vector>
#include <iostream>
#include "parametersdialog.h"
#include "sequencewindow.h"
#include "dataviewwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    // Menu Bar
    QMenu *menuFile;
    QAction *actionNew;
    QAction *actionClose;

    //Start button
    QPushButton *btnStart;

    //Restart button
    QPushButton *btnRestart;

    // Dialog box
    ParametersDialog *paramDiag;

    // Status bar
    QStatusBar *statusBar;
    QLabel *labNbIter;

    // Data view window
    DataViewWindow *dataViewWin;

public:
    explicit MainWindow(QWidget *parent = 0);
    QLabel *getLabNbIter();
    
public slots:
    void showParametersDialog();
    void changeDataView(std::vector<Data> data);
    void changeLabNbIter(int x, int y);

};

#endif // MAINWINDOW_H
