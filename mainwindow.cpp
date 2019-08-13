#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "functions.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QTimer>

quint8 numOfLaps = 1;
quint8 countDown = 3;
QTimer *timer1 = new QTimer();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showFullScreen();
    this->setWindowTitle("Car Track Timer");
    ui->label_setNumOfLaps->setProperty("text", numOfLaps);
    connect(timer1,SIGNAL(timeout()),this,SLOT(countDownToStart()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Quit_clicked()
{
    qDebug() << "Closing application!";
    qApp->quit();
}

void MainWindow::on_pushButton_addLapNumber_clicked()
{
    addNumOfLaps(&numOfLaps);
    ui->label_setNumOfLaps->setProperty("text", numOfLaps);
}

void MainWindow::on_pushButton_subLapNumber_clicked()
{
    subNumOfLaps(&numOfLaps);
    ui->label_setNumOfLaps->setProperty("text", numOfLaps);
}

void MainWindow::on_pushButton_numOfLaps_reset_clicked()
{
    resNumOfLaps(&numOfLaps);
    ui->label_setNumOfLaps->setProperty("text", numOfLaps);
}

void MainWindow::on_pushButton_numOfLaps_ok_clicked()
{
    ui->carTrackTimerPages->setCurrentIndex(1);
}

void MainWindow::on_pushButton_lapTime_back_clicked()
{
    ui->carTrackTimerPages->setCurrentIndex(0);
}

void MainWindow::on_pushButton_laptIme_start_clicked()
{
    ui->carTrackTimerPages->setCurrentIndex(2);
    timer1->start(1000);
}

void addNumOfLaps(quint8 *numOfLaps)
{
    quint8 maxLaps = 25;

    if(*numOfLaps != maxLaps)
        (*numOfLaps)++;
}

void subNumOfLaps(quint8 *numOfLaps)
{
    quint8 minLaps = 1;

    if(*numOfLaps != minLaps)
        (*numOfLaps)--;
}

void resNumOfLaps(quint8 *numOfLaps)
{
    (*numOfLaps) = 1;
}

void MainWindow::countDownToStart()
{
    if(countDown)
    {
        ui->label_startAnimation->setProperty("text", countDown);
        countDown--;
    }
    else
    {
        timer1->stop();
    }
}

