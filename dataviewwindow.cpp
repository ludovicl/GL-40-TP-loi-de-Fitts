#include "dataviewwindow.h"
#include <QBoxLayout>
#include <QHeaderView>
#include <QAbstractItemView>

DataViewWindow::DataViewWindow(QWidget *parent) : QWidget(parent)
{

}

DataViewWindow::DataViewWindow(std::vector<Data> data, QWidget *parent) : QWidget(parent)
{
    dataEnregistre = data;

    // ###################### Size ######################
    //this->setFixedSize(1024, 680);

    // Main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Button layout
    QHBoxLayout *btnLayout = new QHBoxLayout;

    // Restart button
    btnRestart = new QPushButton("Redémarrer une séquence");
    btnLayout->addWidget(btnRestart);

    // Save button
    btnSave = new QPushButton("Enregister la séquence");
    btnLayout->addWidget(btnSave);

    // Init table
    table = new QTableView;
    table->setMinimumWidth(382);
    table->setMaximumWidth(382);

    table->verticalHeader()->setHidden(true);
    table->horizontalHeader()->setHidden(true);

    QHBoxLayout *tableLayout = new QHBoxLayout;
    tableLayout->addWidget(table);
    tableLayout->setAlignment(Qt::AlignCenter);

    mainLayout->addLayout(tableLayout);
    //mainLayout->addWidget(table);
    mainLayout->addLayout(btnLayout);

    //table->setGeometry(120, 120, 784, 440);
    table->setGeometry(1024/2-484/2, 100, 420, 340);

    model = new QStandardItemModel;
    table->setModel(model);

    // Title
    model->setItem(0, 0, new QStandardItem("Distance"));
    model->setItem(0, 1, new QStandardItem("Largeur bouton"));
    model->setItem(0, 2, new QStandardItem("Temps Fitts"));
    model->setItem(0, 3, new QStandardItem("Temps réel"));

    // Disable editing
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Set size
    table->setColumnWidth(0,80);
    table->setColumnWidth(1,120);
    table->setColumnWidth(2,90);
    table->setColumnWidth(3,90);
    // Work variable to calculate average time
    tpsRealTot=0;
    tpsFittTot=0;

    // To fill table
    for(unsigned int i=1; i<data.size()+1; i++)
    {
        model->setItem(i, 0, new QStandardItem(QString::number(data[i-1].getDistance())));
        model->setItem(i, 1, new QStandardItem(QString::number(data[i-1].getWidthBtn())));
        model->setItem(i, 2, new QStandardItem(QString::number(data[i-1].getTpsFitts())));
        model->setItem(i, 3, new QStandardItem(QString::number((double)data[i-1].getTpsReal()/1000)));

        // Calculate average times
        tpsRealTot += (double)data[i-1].getTpsReal()/1000;
        tpsFittTot += data[i-1].getTpsFitts();
    }

    model->setItem(data.size()+1, 1, new QStandardItem("Avg time:"));
    model->setItem(data.size()+1, 2, new QStandardItem(QString::number(tpsFittTot/data.size())));
    model->setItem(data.size()+1, 3, new QStandardItem(QString::number(tpsRealTot/data.size())));

    //Connection
    connect(btnSave, SIGNAL(clicked()), this, SLOT(saveSequence()));

}


void DataViewWindow::saveSequence()
{
    QString file = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Text files (*.txt)");

    //ouvre le fichier en eciture
    std::ofstream fileSave(file.toStdString().c_str(), std::ios::out | std::ios::trunc);

    for(unsigned int i=1; i<dataEnregistre.size()+1; ++i)
    {
        fileSave<<"Clique : "+ QString::number(i).toStdString()<<std::endl;
        fileSave<<"Distance : "+QString::number(dataEnregistre[i-1].getDistance()).toStdString()<<std::endl;
        fileSave<<"Largeur bouton : "+QString::number(dataEnregistre[i-1].getWidthBtn()).toStdString()<<std::endl;
        fileSave<<"Temps Fitts : "+QString::number(dataEnregistre[i-1].getTpsFitts()).toStdString()<<std::endl;
        fileSave<<"Temps réel : "+QString::number((double)dataEnregistre[i-1].getTpsReal()/1000).toStdString()<<std::endl;
        fileSave<<"----------------------------------"<<std::endl;

    }
    fileSave<<"#############################"<<std::endl;
    fileSave<<"Moyenne Fitts : "+ QString::number(tpsFittTot/dataEnregistre.size()).toStdString()<<std::endl;
    fileSave<<"Moyenne temps réel : "+ QString::number(tpsRealTot/dataEnregistre.size()).toStdString()<<std::endl;
    fileSave<<"Equation de Fitts :" +  QString::number(dataEnregistre[1].getParaFitts1()).toStdString()
            +" + "+QString::number(dataEnregistre[1].getParaFitts2()).toStdString()+"*log(D/L + 0.5)"<<std::endl;
    fileSave<<"#############################"<<std::endl;

    //std::cout<<dataEnregistre[1].getParaFitts2()<<std::endl;
    fileSave.close();
}

QPushButton *DataViewWindow::getBtnRestart()
{
    return btnRestart;
}
