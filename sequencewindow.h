#ifndef SEQUENCEWINDOW_H
#define SEQUENCEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QPoint>
#include <QTime>
#include <QMouseEvent>
#include <QWidget>
#include <iostream>
#include <vector>
#include "data.h"

class SequenceWindow : public QWidget
{
    Q_OBJECT
private:
    // Work variable
    int nbSeq;
    int currentNbSeq;
    double pFitts1, pFitts2;
    bool mouseStartMove;

    // Data
    std::vector<Data> data;

    // Widgets
    QPushButton *btn;
    QTime *chrono;

public:
    explicit SequenceWindow(int nS, QWidget *parent = 0, double paraFitts1=0, double paraFitts2=0);
    void mouseMoveEvent(QMouseEvent *);

signals:
    void endSequence(std::vector<Data>);
    void changeLabMW(int, int);

public slots:
    void changePosBtn();
    
};

#endif // SEQUENCEWINDOW_H
