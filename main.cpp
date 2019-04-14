#include "mainwindow.h"
#include <unistd.h>
#include <iostream>
#include <QApplication>
#include <QProgressBar>
#include <QLabel>
#include <QString>
#include <QDebug>
#include <QPushButton>
#include <thread>
using namespace std;

void Barras(MainWindow* w, QLabel** ArrayL,QProgressBar** ArrayB,int i=0){
    QProgressBar* B;
    QLabel* L;

    for (;i<7;i++){
        L=new QLabel(w);
        L->setGeometry(160,40*i+20,100,20);
        QString S=QString::number(i+1);
        L->setText(S);

        B=new QProgressBar (w);
        B->setGeometry(50,40*i+20,100,20);
        B->setValue(10*i);

        ArrayL[i]=L;
        ArrayB[i]=B;
    }
}

void Prueba(MainWindow* w,QLabel** ArrayL,QProgressBar** ArrayB){
    int i=0;
    while (true){
        sleep(1);
        qDebug()<<"s.c_str()"<<i;
        ArrayB[5]->setValue(i*10);
        i++;

    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setGeometry(500,200,400,400);

    QLabel* ArrayL[7]={};
    QProgressBar* ArrayB[7]={};
    Barras(&w,ArrayL,ArrayB);

    thread t(Prueba,&w,ArrayL,ArrayB);

    w.show();
    return a.exec();
}
