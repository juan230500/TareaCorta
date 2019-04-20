#include "ejecutor.h"

Ejecutor::Ejecutor(MainWindow *w, QLabel **ArrayL, QProgressBar **ArrayB)
{
    this->w=w;
    this->ArrayL=ArrayL;
    this->ArrayB=ArrayB;
}


void Ejecutor::GenerarBarras()
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

    for (int i=0;i<7;i++){
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
    int PorcentajeProceso;
    int Proceso;
    string Letras="ABCDEF";

    for (int i=0;i<7;i++){
        PorcentajeProceso = rand() % 100;
        Proceso = rand() % 6;

        ArrayB[i]->setValue(PorcentajeProceso);
        ArrayL[i]->setText(QChar(Letras[Proceso]));

        usleep(50*1000);
    }
}

void Ejecutor::CicloActualizar()
{
    unsigned int msWait=1000;
    int limit=20;

    for (int i=0;i<limit;i++){
        qDebug()<<"#"<<i;

        LabelSec->setText("Tiempo total: "+QString::number(i)+"s");
        List->addItem("V"+QString::number(i));

        if (i%5==0){
            delete List->item(0);
        }

        usleep(50*1000);

        Actualizar();

        usleep(msWait*1000);

    }

    return;
}


