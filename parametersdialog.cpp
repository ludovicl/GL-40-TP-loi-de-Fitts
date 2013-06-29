#include "parametersdialog.h"
#include <iostream>

ParametersDialog::ParametersDialog(QWidget *parent) :
    QDialog(parent)
{
    //color
    // this->setStyleSheet(" background-color: #E0E1D5 ;");

    // ###################### Size ######################
    this->setFixedSize(400,200);

    // ##################### Layout #####################
    //mainLayout = new QVBoxLayout;
    layout = new QGridLayout;
    btnLayout = new QHBoxLayout;

    //#####################Labels#######################
    lblFitts1 = new QLabel;
    lblIteration = new QLabel;
    lblFitts2 = new QLabel;
    lblFitts3 = new QLabel;

    //##################### Spinners##################
    spinFitts1 = new QDoubleSpinBox;
    spinFitts2 = new QDoubleSpinBox;
    spinIter = new QSpinBox;

    //################## Init Labes###################
    lblFitts1->setText("T = ");
    lblFitts2->setText("+");
    lblFitts3->setText(" * log(D/L + 0.5 ) ");
    lblIteration->setText("Sélectionnez le nombre de cliques : ");

    // ################# Init Spin Box ##################
    spinFitts1->setToolTip("constante pouvant être déterminé empiriquement par régression linéaire");
    spinFitts1->setMinimum(0);
    spinFitts1->setMaximum(10);
    spinFitts1->setSingleStep(0.1);
    spinFitts1->setValue(0.2);

    spinFitts2->setToolTip("constante pouvant être déterminé empiriquement par régression linéaire");
    spinFitts2->setMinimum(0.01);
    spinFitts2->setMaximum(10);
    spinFitts2->setSingleStep(0.1);
    spinFitts2->setValue(0.1);


    spinIter->setMinimum(0);
    spinIter->setMaximum(1000);
    spinIter->setSingleStep(10);
    spinIter->setValue(10);



    // ################## Init button ###################
    btnStart = new QPushButton("Valider");
    btnCancel = new QPushButton("Annuler");


    // ############## Put item into layout ##############

    layout->addWidget(lblFitts1,0,0);
    layout->addWidget(spinFitts1,0,1);
    layout->addWidget(lblFitts2,0,2);
    layout->addWidget(spinFitts2,0,3);
    layout->addWidget(lblFitts3,0,4);
    layout->addWidget(lblIteration, 1, 0, 1, 4);
    layout->addWidget(spinIter,1,4);
    layout->addLayout(btnLayout,2,0,1,4);
    btnLayout->addWidget(btnStart);
    btnLayout->addWidget(btnCancel);

    this->setLayout(layout);

    // ################### Connection ###################
    connect(btnStart, SIGNAL(clicked()), this, SLOT(accept()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(close()));

}

int ParametersDialog::getNbSeq()
{
    return spinIter->value();
}
double ParametersDialog::getParaFitts1()
{
    return spinFitts1->value();
}

double ParametersDialog::getParaFitts2()
{
    return spinFitts2->value();
}

