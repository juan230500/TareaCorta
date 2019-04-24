#ifndef VEHICULO_H
#define VEHICULO_H
#include "agendageneral.h"
#include <queue>
#include "iostream"

using namespace std;
class vehiculo
{
public:

    vehiculo(int id);
    void avanzar();
    void iniciar();

    char dameProcesoActual();
    int dameEstadoActual();
    int getEstadoActual() const;
    void setEstadoActual(int value);


private:
    int id;
    char ordenDeProcesos[6];
    char mensaje=0;
    int tiempoDeProcesos [6];
    int  estadoActual=0;
    int  tiempoTranscurrido=0;
};

#endif // VEHICULO_H
