#include "ejecutor.h"

Ejecutor::Ejecutor(MainWindow *w, QLabel **ArrayL, QProgressBar **ArrayB)
{
    this->w=w;
    this->ArrayL=ArrayL;
    this->ArrayB=ArrayB;
    for (int i=0;i<6;i++){
        vehiculos[i]=new vehiculo(i);

    }
}

void Ejecutor::actualizarVehiculos()
{
    for (int i=0;i<6;i++){
        vehiculos[i]->avanzar();

    }
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

    for (int i=0;i<6;i++){
        h=40*i+20;

        Ltmp=new QLabel(w);
        Ltmp->setGeometry(20,h,20,20);
        Ltmp->setText("V"+QString::number(i+1));
        usleep(50*1000);

        L=new QLabel(w);
        L->setGeometry(160,h,100,20);
        L->setText(QString::number(i+1));
        usleep(50*1000);

        B=new QProgressBar (w);
        B->setGeometry(50,h,100,20);
        B->setValue(10*i);
        usleep(50*1000);

        ArrayL[i]=L;
        ArrayB[i]=B;
    }
    usleep(1000*1000);
}

void Ejecutor::Actualizar(){
    int PorcentajeProceso;
    int Proceso;
    int v=6;
    for (int i=0;i<v;i++){
        PorcentajeProceso = vehiculos[i]->dameEstadoActual();
        Proceso = vehiculos[i]->dameProcesoActual();
        vehiculos[i]->avanzar();

        ArrayB[i]->setValue(PorcentajeProceso);
        ArrayL[i]->setText(QChar(Proceso));

        if(Proceso=='P' && !arrayDeCola[i]){
            arrayDeCola[i]=1;
            colaVehiculos.push(i);
            colaProcesos.push(vehiculos[i]->getEstadoActual());
            List->addItem("V"+QString::number(i+1));
        }

        usleep(50*1000);
    }
}

void Ejecutor::CicloActualizar()
{
    unsigned int msWait=2000;
    int limit=30;

    for (int i=0;i<limit;i++){
        //qDebug()<<"#"<<i;

        LabelSec->setText("Tiempo total: "+QString::number(i)+"s");
        usleep(50*1000);

        if (i%5==0 && colaProcesos.size()!=0){
            AgendaGeneral *Agenda=&AgendaGeneral::getInstance();
            Agenda->meter(colaProcesos.back(),colaVehiculos.back());
            qDebug()<<"DATA"<<colaProcesos.back()<<" "<<colaVehiculos.back();
            colaProcesos.pop();
            colaVehiculos.pop();
            Agenda->print();
            delete List->item(0);
        }

        usleep(50*1000);

        Actualizar();

        usleep(msWait*1000);

    }

    return;
}


