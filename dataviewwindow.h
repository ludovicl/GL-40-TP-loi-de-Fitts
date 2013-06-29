#ifndef DATAVIEWWINDOW_H
#define DATAVIEWWINDOW_H

#include <QWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <vector>
#include <QPushButton>
#include <QFileDialog>
#include <QTextDocument>
#include <fstream>
#include <iostream>
#include "data.h"

class DataViewWindow : public QWidget
{
    Q_OBJECT
private:
    QTableView *table;
    QStandardItemModel *model;
    QPushButton *btnSave;
    QPushButton *btnRestart;
    std::vector<Data> dataEnregistre;
    double tpsRealTot;
    double tpsFittTot;

public:
    explicit DataViewWindow(QWidget *parent = 0);
    DataViewWindow(std::vector<Data> data, QWidget *parent = 0);
    QPushButton *getBtnRestart();

signals:
    
public slots:
    void saveSequence();

};

#endif // DATAVIEWWINDOW_H
