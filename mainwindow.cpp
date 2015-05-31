#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <QString>
#include <fstream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->framee->setPixmap(QPixmap(":/pic/frame.png"));
    add();
    add();
    best();
    ui->label_2->setText(QString::number(mark));
    pic();
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::arr[4][4]={0};
int MainWindow::sarr[4][4]={0};
int MainWindow::mark=0;
int MainWindow::smark=0;
int MainWindow::bestmark=0;

//the best score
void MainWindow::best(){
    ifstream inFile("best_score.txt",ios::in);
    inFile>>bestmark;
    ui->label_4->setText(QString::number(bestmark));

    if(mark>=bestmark){
        bestmark = mark;
        ui->label_4->setText(QString::number(bestmark));
        ofstream outFile("best_score.txt",ios::out);
        outFile<<bestmark;
    }
}

//judge finish
void MainWindow::finish(){
    int checkrc=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]!=arr[i][j+1] && arr[i][j]!=0 && arr[i][j+1]!=0){
                checkrc++;
                //cout<<"checkrow="<<checkrc<<endl;
            }
            if(arr[j][i]!=arr[j+1][i] && arr[j][i]!=0 && arr[j+1][i]!=0){
                checkrc++;
                //cout<<"checkcol="<<checkrc<<endl;
            }
            if(checkrc==24){
                cout<<"game over!!!!!!!!!!!!!!"<<endl;
                ui->label_5->setPixmap(QPixmap(":/pic/gameover.png"));
            }
        }
    }
    checkrc=0;
}

//add a random number
void MainWindow::add(){
    int aa=0,bb=0,c=0;
    int choose[10] = {2,2,2,2,2,2,2,2,4,4};
    srand(time(0));
    there:
    c = rand()%10;
    aa = rand()%4;
    bb = rand()%4;

    if(arr[aa][bb]==0)
        arr[aa][bb]=choose[c];
    else
        goto there;
    for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cout<<arr[i][j]<<" ";
            }
        cout<<endl;
    }
    cout<<"MARK="<<mark<<endl;
}

//display picture
void MainWindow::pic(){
            if(arr[0][0]==0)
                ui->label1->setPixmap(QPixmap(":/pic/0.png"));
            if(arr[0][0]==2)
                ui->label1->setPixmap(QPixmap(":/pic/2.png"));
            if(arr[0][0]==4)
                ui->label1->setPixmap(QPixmap(":/pic/4.png"));
            if(arr[0][0]==8)
                ui->label1->setPixmap(QPixmap(":/pic/8.png"));
            if(arr[0][0]==16)
                ui->label1->setPixmap(QPixmap(":/pic/16.png"));
            if(arr[0][0]==32)
                ui->label1->setPixmap(QPixmap(":/pic/32.png"));
            if(arr[0][0]==64)
                ui->label1->setPixmap(QPixmap(":/pic/64.png"));
            if(arr[0][0]==128)
                ui->label1->setPixmap(QPixmap(":/pic/128.png"));
            if(arr[0][0]==256)
                ui->label1->setPixmap(QPixmap(":/pic/256.png"));
            if(arr[0][0]==1024)
                ui->label1->setPixmap(QPixmap(":/pic/1024.png"));
            if(arr[0][0]==2048)
                ui->label1->setPixmap(QPixmap(":/pic/2048.png"));

            if(arr[0][1]==0)
                ui->label2->setPixmap(QPixmap(":/pic/0.png"));
            if(arr[0][1]==2)
                ui->label2->setPixmap(QPixmap(":/pic/2.png"));
            if(arr[0][1]==4)
                ui->label2->setPixmap(QPixmap(":/pic/4.png"));
            if(arr[0][1]==8)
                ui->label2->setPixmap(QPixmap(":/pic/8.png"));
            if(arr[0][1]==16)
                ui->label2->setPixmap(QPixmap(":/pic/16.png"));
            if(arr[0][1]==32)
                ui->label2->setPixmap(QPixmap(":/pic/32.png"));
            if(arr[0][1]==64)
                ui->label2->setPixmap(QPixmap(":/pic/64.png"));
            if(arr[0][1]==128)
                ui->label2->setPixmap(QPixmap(":/pic/128.png"));
            if(arr[0][1]==256)
                ui->label2->setPixmap(QPixmap(":/pic/256.png"));
            if(arr[0][1]==1024)
                ui->label2->setPixmap(QPixmap(":/pic/1024.png"));
            if(arr[0][1]==2048)
                ui->label2->setPixmap(QPixmap(":/pic/2048.png"));

            if(arr[0][2]==0)
                ui->label3->setPixmap(QPixmap(":/pic/0.png"));
            if(arr[0][2]==2)
                ui->label3->setPixmap(QPixmap(":/pic/2.png"));
            if(arr[0][2]==4)
                ui->label3->setPixmap(QPixmap(":/pic/4.png"));
            if(arr[0][2]==8)
                ui->label3->setPixmap(QPixmap(":/pic/8.png"));
            if(arr[0][2]==16)
                ui->label3->setPixmap(QPixmap(":/pic/16.png"));
            if(arr[0][2]==32)
                ui->label3->setPixmap(QPixmap(":/pic/32.png"));
            if(arr[0][2]==64)
                ui->label3->setPixmap(QPixmap(":/pic/64.png"));
            if(arr[0][2]==128)
                ui->label3->setPixmap(QPixmap(":/pic/128.png"));
            if(arr[0][2]==256)
                ui->label3->setPixmap(QPixmap(":/pic/256.png"));
            if(arr[0][2]==1024)
                ui->label3->setPixmap(QPixmap(":/pic/1024.png"));
            if(arr[0][2]==2048)
                ui->label3->setPixmap(QPixmap(":/pic/2048.png"));

            if(arr[0][3]==0)
                ui->label4->setPixmap(QPixmap(":/pic/0.png"));
            if(arr[0][3]==2)
                ui->label4->setPixmap(QPixmap(":/pic/2.png"));
            if(arr[0][3]==4)
                ui->label4->setPixmap(QPixmap(":/pic/4.png"));
            if(arr[0][3]==8)
                ui->label4->setPixmap(QPixmap(":/pic/8.png"));
            if(arr[0][3]==16)
                ui->label4->setPixmap(QPixmap(":/pic/16.png"));
            if(arr[0][3]==32)
                ui->label4->setPixmap(QPixmap(":/pic/32.png"));
            if(arr[0][3]==64)
                ui->label4->setPixmap(QPixmap(":/pic/64.png"));
            if(arr[0][3]==128)
                ui->label4->setPixmap(QPixmap(":/pic/128.png"));
            if(arr[0][3]==256)
                ui->label4->setPixmap(QPixmap(":/pic/256.png"));
            if(arr[0][3]==1024)
                ui->label4->setPixmap(QPixmap(":/pic/1024.png"));
            if(arr[0][3]==2048)
                ui->label4->setPixmap(QPixmap(":/pic/2048.png"));

            if(arr[1][0]==0)
                ui->label5->setPixmap(QPixmap(":/pic/0.png"));
            if(arr[1][0]==2)
                ui->label5->setPixmap(QPixmap(":/pic/2.png"));
            if(arr[1][0]==4)
                ui->label5->setPixmap(QPixmap(":/pic/4.png"));
            if(arr[1][0]==8)
                ui->label5->setPixmap(QPixmap(":/pic/8.png"));
            if(arr[1][0]==16)
                ui->label5->setPixmap(QPixmap(":/pic/16.png"));
            if(arr[1][0]==32)
                ui->label5->setPixmap(QPixmap(":/pic/32.png"));
            if(arr[1][0]==64)
                ui->label5->setPixmap(QPixmap(":/pic/64.png"));
            if(arr[1][0]==128)
                ui->label5->setPixmap(QPixmap(":/pic/128.png"));
            if(arr[1][0]==256)
                ui->label5->setPixmap(QPixmap(":/pic/256.png"));
            if(arr[1][0]==1024)
                ui->label5->setPixmap(QPixmap(":/pic/1024.png"));
            if(arr[1][0]==2048)
                ui->label5->setPixmap(QPixmap(":/pic/2048.png"));

            if(arr[1][1]==0)
                ui->label6->setPixmap(QPixmap(":/pic/0.png"));
            if(arr[1][1]==2)
                ui->label6->setPixmap(QPixmap(":/pic/2.png"));
            if(arr[1][1]==4)
                ui->label6->setPixmap(QPixmap(":/pic/4.png"));
            if(arr[1][1]==8)
                ui->label6->setPixmap(QPixmap(":/pic/8.png"));
            if(arr[1][1]==16)
                ui->label6->setPixmap(QPixmap(":/pic/16.png"));
            if(arr[1][1]==32)
                ui->label6->setPixmap(QPixmap(":/pic/32.png"));
            if(arr[1][1]==64)
                ui->label6->setPixmap(QPixmap(":/pic/64.png"));
            if(arr[1][1]==128)
                ui->label6->setPixmap(QPixmap(":/pic/128.png"));
            if(arr[1][1]==256)
                ui->label6->setPixmap(QPixmap(":/pic/256.png"));
            if(arr[1][1]==1024)
                ui->label6->setPixmap(QPixmap(":/pic/1024.png"));
            if(arr[1][1]==2048)
                ui->label6->setPixmap(QPixmap(":/pic/2048.png"));

            if(arr[1][2]==0)
                ui->label7->setPixmap(QPixmap(":/pic/0.png"));
            if(arr[1][2]==2)
                ui->label7->setPixmap(QPixmap(":/pic/2.png"));
            if(arr[1][2]==4)
                ui->label7->setPixmap(QPixmap(":/pic/4.png"));
            if(arr[1][2]==8)
                ui->label7->setPixmap(QPixmap(":/pic/8.png"));
            if(arr[1][2]==16)
                ui->label7->setPixmap(QPixmap(":/pic/16.png"));
            if(arr[1][2]==32)
                ui->label7->setPixmap(QPixmap(":/pic/32.png"));
            if(arr[1][2]==64)
                ui->label7->setPixmap(QPixmap(":/pic/64.png"));
            if(arr[1][2]==128)
                ui->label7->setPixmap(QPixmap(":/pic/128.png"));
            if(arr[1][2]==256)
                ui->label7->setPixmap(QPixmap(":/pic/256.png"));
            if(arr[1][2]==1024)
                ui->label7->setPixmap(QPixmap(":/pic/1024.png"));
            if(arr[1][2]==2048)
                ui->label7->setPixmap(QPixmap(":/pic/2048.png"));

            if(arr[1][3]==0)
                ui->label8->setPixmap(QPixmap(":/pic/0.png"));
            if(arr[1][3]==2)
                ui->label8->setPixmap(QPixmap(":/pic/2.png"));
            if(arr[1][3]==4)
                ui->label8->setPixmap(QPixmap(":/pic/4.png"));
            if(arr[1][3]==8)
                ui->label8->setPixmap(QPixmap(":/pic/8.png"));
            if(arr[1][3]==16)
                ui->label8->setPixmap(QPixmap(":/pic/16.png"));
            if(arr[1][3]==32)
                ui->label8->setPixmap(QPixmap(":/pic/32.png"));
            if(arr[1][3]==64)
                ui->label8->setPixmap(QPixmap(":/pic/64.png"));
            if(arr[1][3]==128)
                ui->label8->setPixmap(QPixmap(":/pic/128.png"));
            if(arr[1][3]==256)
                ui->label8->setPixmap(QPixmap(":/pic/256.png"));
            if(arr[1][3]==1024)
                ui->label8->setPixmap(QPixmap(":/pic/1024.png"));
            if(arr[1][3]==2048)
                ui->label8->setPixmap(QPixmap(":/pic/2048.png"));

            if(arr[2][0]==0)
                ui->label9->setPixmap(QPixmap(":/pic/0.png"));
            if(arr[2][0]==2)
                ui->label9->setPixmap(QPixmap(":/pic/2.png"));
            if(arr[2][0]==4)
                ui->label9->setPixmap(QPixmap(":/pic/4.png"));
            if(arr[2][0]==8)
                ui->label9->setPixmap(QPixmap(":/pic/8.png"));
            if(arr[2][0]==16)
                ui->label9->setPixmap(QPixmap(":/pic/16.png"));
            if(arr[2][0]==32)
                ui->label9->setPixmap(QPixmap(":/pic/32.png"));
            if(arr[2][0]==64)
                ui->label9->setPixmap(QPixmap(":/pic/64.png"));
            if(arr[2][0]==128)
                ui->label9->setPixmap(QPixmap(":/pic/128.png"));
            if(arr[2][0]==256)
                ui->label9->setPixmap(QPixmap(":/pic/256.png"));
            if(arr[2][0]==1024)
                ui->label9->setPixmap(QPixmap(":/pic/1024.png"));
            if(arr[2][0]==2048)
                ui->label9->setPixmap(QPixmap(":/pic/2048.png"));

            if(arr[2][1]==0)
                ui->label10->setPixmap(QPixmap(":/pic/0.png"));
            if(arr[2][1]==2)
                ui->label10->setPixmap(QPixmap(":/pic/2.png"));
            if(arr[2][1]==4)
                ui->label10->setPixmap(QPixmap(":/pic/4.png"));
            if(arr[2][1]==8)
                ui->label10->setPixmap(QPixmap(":/pic/8.png"));
            if(arr[2][1]==16)
                ui->label10->setPixmap(QPixmap(":/pic/16.png"));
            if(arr[2][1]==32)
                ui->label10->setPixmap(QPixmap(":/pic/32.png"));
            if(arr[2][1]==64)
                ui->label10->setPixmap(QPixmap(":/pic/64.png"));
            if(arr[2][1]==128)
                ui->label10->setPixmap(QPixmap(":/pic/128.png"));
            if(arr[2][1]==256)
                ui->label10->setPixmap(QPixmap(":/pic/256.png"));
            if(arr[2][1]==1024)
                ui->label10->setPixmap(QPixmap(":/pic/1024.png"));
            if(arr[2][1]==2048)
                ui->label10->setPixmap(QPixmap(":/pic/2048.png"));

            if(arr[2][2]==0)
                ui->label11->setPixmap(QPixmap(":/pic/0.png"));
            if(arr[2][2]==2)
                ui->label11->setPixmap(QPixmap(":/pic/2.png"));
            if(arr[2][2]==4)
                ui->label11->setPixmap(QPixmap(":/pic/4.png"));
            if(arr[2][2]==8)
                ui->label11->setPixmap(QPixmap(":/pic/8.png"));
            if(arr[2][2]==16)
                ui->label11->setPixmap(QPixmap(":/pic/16.png"));
            if(arr[2][2]==32)
                ui->label11->setPixmap(QPixmap(":/pic/32.png"));
            if(arr[2][2]==64)
                ui->label11->setPixmap(QPixmap(":/pic/64.png"));
            if(arr[2][2]==128)
                ui->label11->setPixmap(QPixmap(":/pic/128.png"));
            if(arr[2][2]==256)
                ui->label11->setPixmap(QPixmap(":/pic/256.png"));
            if(arr[2][2]==1024)
                ui->label11->setPixmap(QPixmap(":/pic/1024.png"));
            if(arr[2][2]==2048)
                ui->label11->setPixmap(QPixmap(":/pic/2048.png"));

            if(arr[2][3]==0)
                ui->label12->setPixmap(QPixmap(":/pic/0.png"));
            if(arr[2][3]==2)
                ui->label12->setPixmap(QPixmap(":/pic/2.png"));
            if(arr[2][3]==4)
                ui->label12->setPixmap(QPixmap(":/pic/4.png"));
            if(arr[2][3]==8)
                ui->label12->setPixmap(QPixmap(":/pic/8.png"));
            if(arr[2][3]==16)
                ui->label12->setPixmap(QPixmap(":/pic/16.png"));
            if(arr[2][3]==32)
                ui->label12->setPixmap(QPixmap(":/pic/32.png"));
            if(arr[2][3]==64)
                ui->label12->setPixmap(QPixmap(":/pic/64.png"));
            if(arr[2][3]==128)
                ui->label12->setPixmap(QPixmap(":/pic/128.png"));
            if(arr[2][3]==256)
                ui->label12->setPixmap(QPixmap(":/pic/256.png"));
            if(arr[2][3]==1024)
                ui->label12->setPixmap(QPixmap(":/pic/1024.png"));
            if(arr[2][3]==2048)
                ui->label12->setPixmap(QPixmap(":/pic/2048.png"));

            if(arr[3][0]==0)
                ui->label13->setPixmap(QPixmap(":/pic/0.png"));
            if(arr[3][0]==2)
                ui->label13->setPixmap(QPixmap(":/pic/2.png"));
            if(arr[3][0]==4)
                ui->label13->setPixmap(QPixmap(":/pic/4.png"));
            if(arr[3][0]==8)
                ui->label13->setPixmap(QPixmap(":/pic/8.png"));
            if(arr[3][0]==16)
                ui->label13->setPixmap(QPixmap(":/pic/16.png"));
            if(arr[3][0]==32)
                ui->label13->setPixmap(QPixmap(":/pic/32.png"));
            if(arr[3][0]==64)
                ui->label13->setPixmap(QPixmap(":/pic/64.png"));
            if(arr[3][0]==128)
                ui->label13->setPixmap(QPixmap(":/pic/128.png"));
            if(arr[3][0]==256)
                ui->label13->setPixmap(QPixmap(":/pic/256.png"));
            if(arr[3][0]==1024)
                ui->label13->setPixmap(QPixmap(":/pic/1024.png"));
            if(arr[3][0]==2048)
                ui->label13->setPixmap(QPixmap(":/pic/2048.png"));

            if(arr[3][1]==0)
                ui->label14->setPixmap(QPixmap(":/pic/0.png"));
            if(arr[3][1]==2)
                ui->label14->setPixmap(QPixmap(":/pic/2.png"));
            if(arr[3][1]==4)
                ui->label14->setPixmap(QPixmap(":/pic/4.png"));
            if(arr[3][1]==8)
                ui->label14->setPixmap(QPixmap(":/pic/8.png"));
            if(arr[3][1]==16)
                ui->label14->setPixmap(QPixmap(":/pic/16.png"));
            if(arr[3][1]==32)
                ui->label14->setPixmap(QPixmap(":/pic/32.png"));
            if(arr[3][1]==64)
                ui->label14->setPixmap(QPixmap(":/pic/64.png"));
            if(arr[3][1]==128)
                ui->label14->setPixmap(QPixmap(":/pic/128.png"));
            if(arr[3][1]==256)
                ui->label14->setPixmap(QPixmap(":/pic/256.png"));
            if(arr[3][1]==1024)
                ui->label14->setPixmap(QPixmap(":/pic/1024.png"));
            if(arr[3][1]==2048)
                ui->label14->setPixmap(QPixmap(":/pic/2048.png"));

            if(arr[3][2]==0)
                ui->label15->setPixmap(QPixmap(":/pic/0.png"));
            if(arr[3][2]==2)
                ui->label15->setPixmap(QPixmap(":/pic/2.png"));
            if(arr[3][2]==4)
                ui->label15->setPixmap(QPixmap(":/pic/4.png"));
            if(arr[3][2]==8)
                ui->label15->setPixmap(QPixmap(":/pic/8.png"));
            if(arr[3][2]==16)
                ui->label15->setPixmap(QPixmap(":/pic/16.png"));
            if(arr[3][2]==32)
                ui->label15->setPixmap(QPixmap(":/pic/32.png"));
            if(arr[3][2]==64)
                ui->label15->setPixmap(QPixmap(":/pic/64.png"));
            if(arr[3][2]==128)
                ui->label15->setPixmap(QPixmap(":/pic/128.png"));
            if(arr[3][2]==256)
                ui->label15->setPixmap(QPixmap(":/pic/256.png"));
            if(arr[3][2]==1024)
                ui->label15->setPixmap(QPixmap(":/pic/1024.png"));
            if(arr[3][2]==2048)
                ui->label15->setPixmap(QPixmap(":/pic/2048.png"));

            if(arr[3][3]==0)
                ui->label16->setPixmap(QPixmap(":/pic/0.png"));
            if(arr[3][3]==2)
                ui->label16->setPixmap(QPixmap(":/pic/2.png"));
            if(arr[3][3]==4)
                ui->label16->setPixmap(QPixmap(":/pic/4.png"));
            if(arr[3][3]==8)
                ui->label16->setPixmap(QPixmap(":/pic/8.png"));
            if(arr[3][3]==16)
                ui->label16->setPixmap(QPixmap(":/pic/16.png"));
            if(arr[3][3]==32)
                ui->label16->setPixmap(QPixmap(":/pic/32.png"));
            if(arr[3][3]==64)
                ui->label16->setPixmap(QPixmap(":/pic/64.png"));
            if(arr[3][3]==128)
                ui->label16->setPixmap(QPixmap(":/pic/128.png"));
            if(arr[3][3]==256)
                ui->label16->setPixmap(QPixmap(":/pic/256.png"));
            if(arr[3][3]==1024)
                ui->label16->setPixmap(QPixmap(":/pic/1024.png"));
            if(arr[3][3]==2048)
                ui->label16->setPixmap(QPixmap(":/pic/2048.png"));
}

//keypress
void MainWindow::keyPressEvent(QKeyEvent * event){
    int checkmove=0;
    if (event->key() == Qt::Key_Up){
        //record for back
        smark=mark;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                sarr[i][j]=arr[i][j];
            }
        }
        //吃掉
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(arr[j][i]==arr[j+1][i] && arr[j][i]!=0){
                    arr[j][i]=arr[j][i]*2;
                    mark = mark + arr[j][i];
                    arr[j+1][i]=0;
                    break;
                }
                if((j==0 || j==1 ) && arr[j][i]==arr[j+2][i] && arr[j+1][i]==0 && arr[j][i]!=0){
                    arr[j][i]=arr[j][i]*2;
                    mark = mark + arr[j][i];
                    arr[j+2][i]=0;
                    break;
                }
                if(j==0 && arr[j][i]==arr[j+3][i] && arr[j+1][i]==0 && arr[j+2][i]==0 && arr[j][i]!=0){
                    arr[j][i]=arr[j][i]*2;
                    mark = mark + arr[j][i];
                    arr[j+3][i]=0;
                    break;
                }
            }
        }
        //向上
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(arr[j][i]==0 && arr[j+1][i]!=0){
                    arr[j][i]=arr[j+1][i];
                    arr[j+1][i]=0;
                    checkmove++;
                }
                if((j==0 || j==1) && arr[j][i]==0 && arr[j+1][i]==0 && arr[j+2][i]!=0){
                    arr[j][i]=arr[j+2][i];
                    arr[j+2][i]=0;
                    checkmove++;
                }
                if(j==0 && arr[j][i]==0 && arr[j+1][i]==0 && arr[j+2][i]==0 && arr[j+3][i]!=0){
                    arr[j][i]=arr[j+3][i];
                    arr[j+3][i]=0;
                    checkmove++;
                }
            }
        }
        if(checkmove!=0){
            add();
            checkmove=0;
        }

        pic();
        ui->label_2->setText(QString::number(mark));
        finish();
        best();
    }

    if (event->key() == Qt::Key_Down){
        //record for back
        smark=mark;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                sarr[i][j]=arr[i][j];
            }
        }
      //吃掉
        for(int i=0;i<4;i++){
            for(int j=3;j>0;j--){
                if(arr[j][i]==arr[j-1][i] && arr[j][i]!=0){
                    arr[j][i]=arr[j][i]*2;
                    mark = mark + arr[j][i];
                    arr[j-1][i]=0;
                    break;
                }
                if((j==3 || j==2 ) && arr[j][i] == arr[j-2][i] && arr[j-1][i]==0 && arr[j][i]!=0){
                    arr[j][i]=arr[j][i]*2;
                    mark = mark + arr[j][i];
                    arr[j-2][i]=0;
                    break;
                }
                if(j==3 && arr[j][i] == arr[j-3][i] && arr[j-1][i]==0 && arr[j-2][i]==0 && arr[j][i]!=0){
                    arr[j][i]=arr[j][i]*2;
                    mark = mark + arr[j][i];
                    arr[j-3][i]=0;
                    break;
                }
            }
        }
        //向下
        for(int i=0;i<4;i++){
            for(int j=3;j>0;j--){
                if(arr[j][i]==0 && arr[j-1][i]!=0){
                    arr[j][i]=arr[j-1][i];
                    arr[j-1][i]=0;
                    checkmove++;
                }
                if((j==3 || j==2) && arr[j][i]==0 && arr[j-1][i]==0 && arr[j-2][i]!=0){
                    arr[j][i]=arr[j-2][i];
                    arr[j-2][i]=0;
                    checkmove++;
                }
                if(j==3 && arr[j][i]==0 && arr[j-1][i]==0 && arr[j-2][i]==0 && arr[j-3][i]!=0){
                    arr[j][i]=arr[j-3][i];
                    arr[j-3][i]=0;
                    checkmove++;
                }
            }
        }
        if(checkmove!=0){
            add();
            checkmove=0;
        }
        pic();
        ui->label_2->setText(QString::number(mark));
        finish();
        best();
    }

    if(event->key() == Qt::Key_Right){
        //record for back
        smark=mark;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                sarr[i][j]=arr[i][j];
            }
        }
        //吃掉
        for(int i=0;i<4;i++){
            for(int j=3;j>0;j--){
                if(arr[i][j]==arr[i][j-1] && arr[i][j]!=0){
                    arr[i][j]=arr[i][j]*2;
                    mark = mark + arr[i][j];
                    arr[i][j-1]=0;
                    break;
                }
                if((j==3 || j==2 ) && arr[i][j]==arr[i][j-2] && arr[i][j-1]==0 && arr[i][j]!=0){
                    arr[i][j]=arr[i][j]*2;
                    mark = mark + arr[i][j];
                    arr[i][j-2]=0;
                    break;
                }
                if(j==3 && arr[i][j]==arr[i][j-3] && arr[i][j-1]==0 && arr[i][j-2]==0 && arr[i][j]!=0){
                    arr[i][j]=arr[i][j]*2;
                    mark = mark + arr[i][j];
                    arr[i][j-3]=0;
                    break;
                }
            }
        }
        //向右
        for(int i=0;i<4;i++){
            for(int j=3;j>0;j--){
                if(arr[i][j]==0 && arr[i][j-1]!=0){
                    arr[i][j]=arr[i][j-1];
                    arr[i][j-1]=0;
                    checkmove++;
                }
                if((j==3 || j==2) && arr[i][j]==0 && arr[i][j-1]==0 && arr[i][j-2]!=0){
                    arr[i][j]=arr[i][j-2];
                    arr[i][j-2]=0;
                    checkmove++;
                }
                if(j==3 && arr[i][j]==0 && arr[i][j-1]==0 && arr[i][j-2]==0 && arr[i][j-3]!=0){
                    arr[i][j]=arr[i][j-3];
                    arr[i][j-3]=0;
                    checkmove++;
                }
            }
        }
        if(checkmove!=0){
            add();
            checkmove=0;
        }
        pic();
        ui->label_2->setText(QString::number(mark));
        finish();
        best();
    }

    if (event->key() == Qt::Key_Left){
        //record for back
        smark=mark;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                sarr[i][j]=arr[i][j];
            }
        }
        //吃掉
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(arr[i][j]==arr[i][j+1] && arr[i][j]!=0){
                    arr[i][j]=arr[i][j]*2;
                    mark = mark + arr[i][j];
                    arr[i][j+1]=0;
                    break;
                }
                if((j==0 || j==1 ) && arr[i][j]==arr[i][j+2] && arr[i][j+1]==0 && arr[i][j]!=0){
                    arr[i][j]=arr[i][j]*2;
                    mark = mark + arr[i][j];
                    arr[i][j+2]=0;
                    break;
                }
                if(j==0 && arr[i][j]==arr[i][j+3] && arr[i][j+1]==0 && arr[i][j+2]==0 && arr[i][j]!=0){
                    arr[i][j]=arr[i][j]*2;
                    mark = mark + arr[i][j];
                    arr[i][j+3]=0;
                    break;
                }
            }
        }
        //向左
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(arr[i][j]==0 && arr[i][j+1]!=0){
                    arr[i][j]=arr[i][j+1];
                    arr[i][j+1]=0;
                    checkmove++;
                }
                if((j==0 || j==1) && arr[i][j]==0 && arr[i][j+1]==0 && arr[i][j+2]!=0){
                    arr[i][j]=arr[i][j+2];
                    arr[i][j+2]=0;
                    checkmove++;
                }
                if(j==0 && arr[i][j]==0 && arr[i][j+1]==0 && arr[i][j+2]==0 && arr[i][j+3]!=0){
                    arr[i][j]=arr[i][j+3];
                    arr[i][j+3]=0;
                    checkmove++;
                }
            }
        }
        if(checkmove!=0){
            add();
            checkmove=0;
        }
        pic();
        ui->label_2->setText(QString::number(mark));
        finish();
        best();
    }
}

//new
void MainWindow::on_pushButton_clicked()
{
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            arr[i][j]=0;
            sarr[i][j]=0;
        }
    }
    add();
    add();
    pic();
    mark = 0;
    smark = 0;
    ui->label_2->setText(QString::number(mark));
    ui->label_5->setPixmap(QPixmap(""));
}

//back
void MainWindow::on_pushButton_2_clicked()
{
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            arr[i][j]=sarr[i][j];
        }
    }
    pic();
    ui->label_2->setText(QString::number(smark));
    mark = mark - (mark-smark);
    ui->label_5->setPixmap(QPixmap(""));
}
