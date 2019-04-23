#include "vehiculo.h"

vehiculo::vehiculo(int id)
{
    this->id=id;
    if (id==0){
        this->ordenDeProcesos[0]={'A'};
        this->ordenDeProcesos[1]={'B'};
        this->ordenDeProcesos[2]={'C'};
        this->ordenDeProcesos[3]={'D'};
        this->ordenDeProcesos[4]={'E'};
        this->ordenDeProcesos[5]={'F'};
        this->tiempoDeProcesos[0]={2};
        this->tiempoDeProcesos[1]={2};
        this->tiempoDeProcesos[2]={4};
        this->tiempoDeProcesos[3]={1};
        this->tiempoDeProcesos[4]={3};
        this->tiempoDeProcesos[5]={1};

    }
    if (id==1){
        this->ordenDeProcesos[0]={'C'};
        this->ordenDeProcesos[1]={'A'};
        this->ordenDeProcesos[2]={'B'};
        this->ordenDeProcesos[3]={'E'};
        this->ordenDeProcesos[4]={'D'};
        this->ordenDeProcesos[5]={'F'};
        this->tiempoDeProcesos[0]={2};
        this->tiempoDeProcesos[1]={1};
        this->tiempoDeProcesos[2]={1};
        this->tiempoDeProcesos[3]={2};
        this->tiempoDeProcesos[4]={3};
        this->tiempoDeProcesos[5]={1};

    }
    if (id==2){
        this->ordenDeProcesos[0]={'D'};
        this->ordenDeProcesos[1]={'E'};
        this->ordenDeProcesos[2]={'A'};
        this->ordenDeProcesos[3]={'C'};
        this->ordenDeProcesos[4]={'B'};
        this->ordenDeProcesos[5]={'F'};
        this->tiempoDeProcesos[0]={1};
        this->tiempoDeProcesos[1]={4};
        this->tiempoDeProcesos[2]={3};
        this->tiempoDeProcesos[3]={2};
        this->tiempoDeProcesos[4]={1};
        this->tiempoDeProcesos[5]={1};

    }
    if (id==3){
        this->ordenDeProcesos[0]={'B'};
        this->ordenDeProcesos[1]={'C'};
        this->ordenDeProcesos[2]={'D'};
        this->ordenDeProcesos[3]={'A'};
        this->ordenDeProcesos[4]={'F'};
        this->ordenDeProcesos[5]={'E'};
        this->tiempoDeProcesos[0]={2};
        this->tiempoDeProcesos[1]={1};
        this->tiempoDeProcesos[2]={4};
        this->tiempoDeProcesos[3]={3};
        this->tiempoDeProcesos[4]={2};
        this->tiempoDeProcesos[5]={1};

    }
    if (id==4){
        this->ordenDeProcesos[0]={'E'};
        this->ordenDeProcesos[1]={'F'};
        this->ordenDeProcesos[2]={'B'};
        this->ordenDeProcesos[3]={'C'};
        this->ordenDeProcesos[4]={'A'};
        this->ordenDeProcesos[5]={'D'};
        this->tiempoDeProcesos[0]={4};
        this->tiempoDeProcesos[1]={1};
        this->tiempoDeProcesos[2]={2};
        this->tiempoDeProcesos[3]={4};
        this->tiempoDeProcesos[4]={1};
        this->tiempoDeProcesos[5]={3};

    }
    if (id==5){
        this->ordenDeProcesos[0]={'F'};
        this->ordenDeProcesos[1]={'D'};
        this->ordenDeProcesos[2]={'C'};
        this->ordenDeProcesos[3]={'B'};
        this->ordenDeProcesos[4]={'E'};
        this->ordenDeProcesos[5]={'A'};
        this->tiempoDeProcesos[0]={1};
        this->tiempoDeProcesos[1]={1};
        this->tiempoDeProcesos[2]={2};
        this->tiempoDeProcesos[3]={4};
        this->tiempoDeProcesos[4]={3};
        this->tiempoDeProcesos[5]={4};

    }
}

void vehiculo::avanzar()
{     AgendaGeneral Agenda=AgendaGeneral::getInstance();
      //qDebug()<<"SOY: "<<id<<"ESTOY EN: "<<estadoActual;
      if (estadoActual==6){
          mensaje='R';
          return;
      }



      if(tiempoTranscurrido==0){
          Agenda.meter(ordenDeProcesos[estadoActual],this->id);
          tiempoTranscurrido++;
      }
      else if (tiempoTranscurrido==tiempoDeProcesos[estadoActual]) {
          Agenda.sacar(ordenDeProcesos[estadoActual],this->id);
          estadoActual++;
          tiempoTranscurrido=0;
          Agenda.meter(ordenDeProcesos[estadoActual],this->id);
      }
      else {
          bool nopausa=Agenda.consultar(ordenDeProcesos[estadoActual],id);
          if(!nopausa){
              mensaje='P';
              return;
          }
          tiempoTranscurrido++;

      }
       mensaje=ordenDeProcesos[estadoActual];

}

void vehiculo::avanzarForzado()
{
    AgendaGeneral *Agenda=&AgendaGeneral::getInstance();
    Agenda->meter(ordenDeProcesos[estadoActual],this->id);
    tiempoTranscurrido++;
    mensaje=ordenDeProcesos[estadoActual];
}

char vehiculo::dameProcesoActual()
{
    return mensaje;
}

int vehiculo::dameEstadoActual()
{
    float t1=tiempoTranscurrido;
    float t2=tiempoDeProcesos[estadoActual];
    return (t1/t2)*100;
}

int vehiculo::getEstadoActual() const
{
    return estadoActual;
}

void vehiculo::setEstadoActual(int value)
{
    estadoActual = value;
}

