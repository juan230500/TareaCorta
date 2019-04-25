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
#include "elemento.h"
#include"cola.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Fábrica de autos");

    w.setGeometry(500,200,400,400);

    QLabel* ArrayL[6]={};
    QProgressBar* ArrayB[6]={};


    Ejecutor* E=new Ejecutor(&w,ArrayL,ArrayB);
    E->GenerarBarras();

    w.show();

    thread t(&Ejecutor::CicloActualizar,E);
    return a.exec();
}
