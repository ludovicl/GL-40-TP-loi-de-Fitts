#ifndef PARAMETERSDIALOG_H
#define PARAMETERSDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QBoxLayout>

class ParametersDialog : public QDialog
{
    Q_OBJECT
private:
    // Spin box
    QSpinBox *spinIter;
    QDoubleSpinBox *spinFitts1;
    QDoubleSpinBox *spinFitts2;

    //Labels
    QLabel *lblFitts1;
    QLabel *lblIteration ;
    QLabel *lblFitts2;
    QLabel *lblFitts3 ;
    // Button
    QPushButton *btnStart;
    QPushButton *btnCancel;

    //Layout
     QGridLayout *layout;
     QHBoxLayout *btnLayout;

     //Values Fitts
    double paraFitts1, paraFitts2;

public:
    explicit ParametersDialog(QWidget *parent = 0);
    int getNbSeq();
    double getParaFitts1();
    double getParaFitts2();

};

#endif // PARAMETERSDIALOG_H
