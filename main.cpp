#include "mainwindow.h"
#include "ejecutor.h"
#include <unistd.h>
#include <iostream>
#include <QApplication>
#include <QProgressBar>
#include <QLabel>
#include <QString>
#include <QDebug>
#include <thread>
#include "agendageneral.h"
using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Fábrica de autos");

    w.setGeometry(500,200,400,400);

    QLabel* ArrayL[7]={};
    QProgressBar* ArrayB[7]={};

    AgendaGeneral A=AgendaGeneral::getInstance();
    A.meter(5,6);
    A.meter(5,7);
    A.meter(5,8);
    A.print();
    A.sacar(5,7);
    A.print();
    qDebug()<<A.consultar(5,8);
//    Ejecutor* E=new Ejecutor(&w,ArrayL,ArrayB);
//    E->GenerarBarras();

//    w.show();

//    thread t(&Ejecutor::CicloActualizar,E);
    return a.exec();
}
