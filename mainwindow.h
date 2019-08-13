#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_Quit_clicked();

    void on_pushButton_addLapNumber_clicked();

    void on_pushButton_subLapNumber_clicked();

    void on_pushButton_numOfLaps_reset_clicked();

    void on_pushButton_numOfLaps_ok_clicked();

    void on_pushButton_lapTime_back_clicked();

    void on_pushButton_laptIme_start_clicked();

    void countDownToStart();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
