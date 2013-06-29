#include "sequencewindow.h"
#include <QLayout>

SequenceWindow::SequenceWindow(int nS, QWidget *parent, double paraFitts1, double paraFitts2) :
    QWidget(parent)
{
    // ################## Init button ###################
    btn = new QPushButton("Click me to start", this);
    btn->setGeometry( (parent->size().width())/2 - 250/2, (parent->size().height())/2 - 100/2, 250, 100);

    // ############### Init work variable ###############
    pFitts1 = paraFitts1;
    pFitts2 = paraFitts2;
    nbSeq = nS;
    currentNbSeq = 0;
    mouseStartMove = false;

    // #################### Init chrono ##################
    chrono = new QTime;

    // Enable mouse tracking
    this->setMouseTracking(true);

    // ##################### Connect ####################
    connect(btn, SIGNAL(clicked()), this, SLOT(changePosBtn()));
    connect(this, SIGNAL(endSequence(std::vector<Data>)), this->parent(), SLOT(changeDataView(std::vector<Data>)));
    connect(this, SIGNAL(changeLabMW(int,int)), this->parent(), SLOT(changeLabNbIter(int,int)));

}

void SequenceWindow::mouseMoveEvent(QMouseEvent *)
{
    if(mouseStartMove == false)
        chrono->start();

    mouseStartMove = true;
}

void SequenceWindow::changePosBtn()
{
    // Set text btn
    btn->setText("Click Me!");

    // Initialize random speed
    QTime now = QTime::currentTime();
    qsrand(now.msec());

    // Generate random size
    int wBtn = qrand()%300+30;
    int hBtn = wBtn;

    // Get size of widget
    int wScreen = this->size().width();
    int hScreen = this->size().height();

    // Generate random position
    int x = 0;
    int xTemp = (qrand()%wScreen) - wBtn;
    if(xTemp >= 0)
        x = xTemp;

    int y = 0;
    int yTemp = (qrand()%hScreen) - hBtn;
    if( yTemp >= 0)
        y = yTemp;

    // Set property
    btn->setGeometry(x, y, wBtn, hBtn);

    // Set visual effects
    QString str="border-radius: ";
    str += QString::number(rand()%(hBtn/2));
    str += "px; background-color: #";
    str += QString::number(rand()%10);
    str += QString::number(rand()%10);
    str += QString::number(rand()%10);
    str += QString::number(rand()%10);
    str += QString::number(rand()%10);
    str += QString::number(rand()%10);
    str+=";";
    btn->setStyleSheet(str);

    // Increment currentNbSeq
    currentNbSeq++;

    // =-=-=-=- DEBUG -=-=-=-=
    // Position absolute
    //std::cout << QCursor::pos().x() << "-" << QCursor::pos().y() << std::endl;
    // Position widget
    //std::cout << this->mapFromGlobal(QCursor::pos()).x() << "-" << this->mapFromGlobal(QCursor::pos()).y() << std::endl;
    // Tps exec
    //std::cout << "Temps exec: " << chrono->elapsed() << std::endl;
    // =-=-=- END DEBUG -=-=-=

    QPoint posInit = this->mapFromGlobal(QCursor::pos());

    if(currentNbSeq>=2)//the first click is not saved
        data.push_back(Data(posInit, QPoint(x,y), wBtn, chrono->elapsed(), pFitts1, pFitts2));

    // Send signal change lab iter
    emit changeLabMW(currentNbSeq-1, nbSeq);

    // Stop if end of sequence
    if(currentNbSeq-1 == nbSeq)//-1 the first click doesn't count
    {
        for(unsigned int i=0; i<data.size(); i++)
        {
            data[i].calculDistance();
            data[i].calculTpsFitts();
        }

        // Send signal end of sequence
        emit endSequence(data);
    }

    // Reset mouseMoveStart
    mouseStartMove = false;
}
