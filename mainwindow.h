#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
using namespace std;

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent * event);
    void pic();
    void add();
    void finish();
    void best();
    static int arr[4][4];
    static int mark;
    static int smark;
    static int sarr[4][4];
    static int bestmark;
};

#endif // MAINWINDOW_H
