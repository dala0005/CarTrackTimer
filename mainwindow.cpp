#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "functions.h"
#include <QDebug>
#include <QDesktopWidget>


quint8 numOfLaps = 1;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showFullScreen();
    this->setWindowTitle("Car Track Timer");
    ui->label_setNumOfLaps->setProperty("text", numOfLaps);
    /*QDesktopWidget* widget = qApp->desktop();
    QRect screenSize = widget->availableGeometry(widget->primaryScreen());
    this->setProperty("Width", screenSize.width());
    qDebug() << "MainWindow Width: " << this->property("Width");
    this->setProperty("Height", screenSize.height());
    ui->centralWidget->setProperty("Width", screenSize.width());
    ui->centralWidget->setProperty("Height", screenSize.height()-39);
    ui->mainTitle->setProperty("Point Size", 20);
    qDebug() << "MainWindow Height: " << this->property("Height");
    */
    //ui->mainLine_top->setProperty("Width", 800);
   /* ui->stackedWidget->setProperty("Width", screenSize.width());
    ui->stackedWidget->setProperty("Height", screenSize.height()-100);
    ui->stackedWidget->setProperty("X", 0);
    ui->stackedWidget->setProperty("Y", 100);
    ui->page_1_setNumOfLaps->setProperty("Width", screenSize.width());
    qDebug() << "page_1_setNumOfLaps Width: " << ui->page_1_setNumOfLaps->property("Width");
    ui->page_1_setNumOfLaps->setProperty("Height", screenSize.height()-100);
    qDebug() << "page_1_setNumOfLaps Height: " << ui->page_1_setNumOfLaps->property("Height");
    ui->page_1_setNumOfLaps->setProperty("X", 0);
    qDebug() << "page_1_setNumOfLaps X: " << ui->page_1_setNumOfLaps->property("X");
    ui->page_1_setNumOfLaps->setProperty("Y", 100);
    qDebug() << "page_1_setNumOfLaps Y: " << ui->page_1_setNumOfLaps->property("Y");
    */
    //ui->pushButton_Quit->setProperty("x", "700");
  /*  qDebug() << "Height: " << screenSize.height() << "Width: " << screenSize.width();
    ui->pushButton_Quit->setProperty("X", 0);
    qDebug() << "pushButton_Quit X: " << ui->pushButton_Quit->property("X");
    ui->pushButton_Quit->setProperty("Y", 0);
    qDebug() << "pushButton_Quit Y: " << ui->pushButton_Quit->property("Y"); */
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


void MainWindow::on_pushButton_numOfLaps_ok_clicked()
{
    ui->carTrackTimerPages->setCurrentIndex(1);
}

void MainWindow::on_pushButton_lapTime_back_clicked()
{
    ui->carTrackTimerPages->setCurrentIndex(0);
}
