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
using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Fábrica de autos");

    w.setGeometry(500,200,400,400);

    QLabel* ArrayL[7]={};
    QProgressBar* ArrayB[7]={};

    Ejecutor* E=new Ejecutor(&w,ArrayL,ArrayB);
    E->GenerarBarras();
    thread t(&Ejecutor::CicloActualizar,E);

    w.show();
    return a.exec();
}
