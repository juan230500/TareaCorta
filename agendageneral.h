#ifndef AGENDAGENERAL_H
#define AGENDAGENERAL_H
#include "qdebug.h"

class AgendaGeneral
{
private:
    int procesos[6][3]={}; //[LetraProceso][campo]
public:
    static AgendaGeneral& getInstance()
            {
                static AgendaGeneral    instance; // Guaranteed to be destroyed.
                                      // Instantiated on first use.
                return instance;
            }
    AgendaGeneral();
    /**
     * @brief sacar saca un vehiculo de un proceso
     * @param proceso
     * @param vehiculo
     */
    void sacar(int proceso,int vehiculo);
    /**
     * @brief meter mete un vehiculo a un proceso
     * @param proceso
     * @param vehiculo
     */
    void meter(int proceso, int vehiculo);
    /**
     * @brief consultar consulta si un vehiculo está en un proceso
     * @param proceso
     * @param vehiculo
     * @return
     */
    bool consultar(int proceso, int vehiculo);
    /**
     * @brief print imprime el estado de los procesos
     */
    void print();
};

#endif // AGENDAGENERAL_H
