#include "ejecutor.h"

Ejecutor::Ejecutor(MainWindow *w, QLabel **ArrayL, QProgressBar **ArrayB)
{
    this->w=w;
    this->ArrayL=ArrayL;
    this->ArrayB=ArrayB;
}


void Ejecutor::GenerarBarras( int i)
{
    QProgressBar* B;
    QLabel* L;
    QLabel* Ltmp;
    int h;

    QLabel* Labeltmp=new QLabel(w);
    Labeltmp->setText("Cola de espera");
    Labeltmp->setGeometry(250,0,100,100);

    this->LabelSec=new QLabel(w);
    this->LabelSec->setGeometry(50,300,100,20);

    this->List=new QListWidget(w);
    this->List->setGeometry(250,70,100,250);

    for (;i<7;i++){
        h=40*i+20;

        Ltmp=new QLabel(w);
        Ltmp->setGeometry(20,h,20,20);
        Ltmp->setText("V"+QString::number(i+1));

        L=new QLabel(w);
        L->setGeometry(160,h,100,20);
        L->setText(QString::number(i+1));

        B=new QProgressBar (w);
        B->setGeometry(50,h,100,20);
        B->setValue(10*i);

        ArrayL[i]=L;
        ArrayB[i]=B;
    }
}

void Ejecutor::Actualizar(){
    int v1;
    int v2;
    string procesos="ABCDEF";

    for (int i=0;i<7;i++){
        v1 = rand() % 100;
        ArrayB[i]->setValue(v1);
        v2 = rand() % 6;
        ArrayL[i]->setText(QChar(procesos[v2]));
        usleep(50*1000);
    }

    return;
}

void Ejecutor::CicloActualizar()
{
    unsigned int msWait=1000;
    int limit=20;

    for (int i=0;i<limit;i++){
        qDebug()<<"#"<<i;

        LabelSec->setText("Tiempo total: "+QString::number(i)+"s");
        List->addItem("V"+QString::number(i));
        usleep(50*1000);

        Actualizar();
        usleep(msWait*1000);
    }

    return;
}


