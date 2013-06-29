#include "mainwindow.h"
#include <QGridLayout>
#include <QBoxLayout>
#include <QWidget>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    // ################### Set style ####################
    //this->setStyleSheet("border: 2px solid #262526; border-radius: 4px;margin: 0px ; background-color: #D3D3B7 ;");

    // ###################### Size ######################
    this->setMinimumSize(600,400);

    // Main Layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QWidget *central = new QWidget;
    central->setLayout(mainLayout);
    this->setCentralWidget(central);

    // ##################### Label ######################
    QLabel *label = new QLabel("Test de la loi de Fitts");
    label->setFont(QFont("Arial Black", 46));
    label->setAlignment(Qt::AlignCenter);

    mainLayout->addWidget(label);

    QLabel *label2 = new QLabel("Ce programme réalisé à l'aide de Qt permet de mettre en oeuvre la loi de Fitts et comparer ses résultats avec des tests réels. Vous pouvez sélectionner le nombre de séquence que vous souhaitez réaliser ainsi que les constantes de l’équation. Plus vous ferez de séquences et plus les résultats seront précis.");
    label2->setWordWrap(true);
    label2->setAlignment(Qt::AlignCenter);

    mainLayout->addWidget(label2);

    // ################ Start button ####################
    btnStart =  new QPushButton("Démarrer une séquence");
    mainLayout->addWidget(btnStart);

    // ################## Status bar ####################
    statusBar = new QStatusBar;
    this->setStatusBar(statusBar);
    QLabel *labIter = new QLabel("Iteration: ");

    labNbIter = new QLabel("");

    statusBar->addWidget(labIter);
    statusBar->addWidget(labNbIter);
    statusBar->setStyleSheet("background-color: #D0D0D0;");

    statusBar->setHidden(true);

    // ################## Init menu bar #################
    menuFile = menuBar()->addMenu("Fichier");

    actionNew = new QAction("Nouveau", this);
    actionClose = new QAction("Quitter", this);

    menuFile->addAction(actionNew);
    menuFile->addAction(actionClose);


    // ################# Init dialog box ################
    paramDiag = new ParametersDialog;

    // ################### Connection ###################
    connect(actionNew, SIGNAL(triggered()), this, SLOT(showParametersDialog()));
    connect(btnStart, SIGNAL(clicked()), this, SLOT(showParametersDialog()));

}

void MainWindow::showParametersDialog()
{
    paramDiag->setModal(true);

    if(paramDiag->exec() == QDialog::Accepted)
    {

        this->setCentralWidget(new SequenceWindow(paramDiag->getNbSeq(), this, paramDiag->getParaFitts1(),paramDiag->getParaFitts2()));

        // Change label status bar
        labNbIter->setText("0/"+QString::number(paramDiag->getNbSeq()));
        // Show status bar
        statusBar->setHidden(false);
    }

}

// SLOT
void MainWindow::changeDataView(std::vector<Data> data)
{
    // Hide status bar
    statusBar->setHidden(true);

    dataViewWin = new DataViewWindow(data);

    //connect button restart in class DataViewWindow
    connect(dataViewWin->getBtnRestart(), SIGNAL(clicked()), this, SLOT(showParametersDialog()));

    this->setCentralWidget(dataViewWin);
}

// SLOT
void MainWindow::changeLabNbIter(int x, int y)
{
    labNbIter->setText(QString::number(x)+"/"+QString::number(y));
}

