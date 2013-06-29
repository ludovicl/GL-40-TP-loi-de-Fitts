#ifndef DATA_H
#define DATA_H

#include <QTime>
#include <QPointF>
#include <math.h>
#include <iostream>

class Data
{
private:
    // Initial position
    QPointF posInit;

    // Button position
    QPointF posBtn;

    // Distance calculate
    double distance;

    // Width button
    int widthBtn;

    // Time to move mouse until target
    int tpsReal;

    //Constants in fitts equation
    double paraFitts1;
    double paraFitts2;

    // Fitts time
    double tpsFitts;

public:
    // Constructor
    Data();
    Data(QPointF pI, QPointF pB, int wB, int tps, double pFitts1, double pFitts2);

    // Calcul
    void calculDistance();
    void calculTpsFitts();

    //Getters
    QPointF getPosInit();
    QPointF getPosBtn();
    double getDistance();
    int getWidthBtn();
    int getTpsReal();
    double getTpsFitts();
    double getParaFitts1();
    double getParaFitts2();
};

#endif // DATA_H
