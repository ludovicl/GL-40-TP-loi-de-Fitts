#include "data.h"

//  ######################## Constructor ########################
Data::Data() { }

Data::Data(QPointF pI, QPointF pB, int wB, int tps, double pFitts1, double pFitts2)
    : posInit(pI), posBtn(pB), widthBtn(wB), tpsReal(tps), paraFitts1(pFitts1),paraFitts2(pFitts2) { }

// ########################### Calcul ############################
void Data::calculDistance()
{
    distance = sqrt( pow( (posBtn.x() - posInit.x()), 2 ) + pow( (posBtn.y() - posInit.y()), 2) );
}

void Data::calculTpsFitts()
{
    tpsFitts =  paraFitts1 + paraFitts2*log2( (distance/(double)widthBtn + 0.5 ) );
}

// ########################### Getters ############################
QPointF Data::getPosInit()
{
    return posInit;
}

QPointF Data::getPosBtn()
{
    return posBtn;
}

double Data::getDistance()
{
    return distance;
}

int Data::getWidthBtn()
{
    return widthBtn;
}

int Data::getTpsReal()
{
    return tpsReal;
}

double Data::getTpsFitts()
{
    return tpsFitts;
}

double Data::getParaFitts1()
{
    return paraFitts1;
}

double Data::getParaFitts2()
{
    return paraFitts2;

}


