#include "agendageneral.h"

AgendaGeneral::AgendaGeneral()
{

}



void AgendaGeneral::sacar(int procesoactual,int vehiculo)
{
    for (int i=0;i<3;i++){
        if (procesos[procesoactual][i]==vehiculo){
            procesos[procesoactual][i]=0;
            return;
        }
    }
}

void AgendaGeneral::meter(int procesoactual, int vehiculo)
{
    for (int i=0;i<3;i++){
        if (procesos[procesoactual][i]==0){
            procesos[procesoactual][i]=vehiculo;
            return;
        }
    }
    procesos[procesoactual][0]=vehiculo;
}

bool AgendaGeneral::consultar(int procesoactual, int vehiculo)
{
    for (int i=0;i<3;i++){
        if (procesos[procesoactual][i]==vehiculo){
            return true;
        }
    }
    return false;
}

void AgendaGeneral::print()
{
    for (int i=0;i<6;i++){
        cout<<"Proceso "<<i<<":";
        for (int j=0;j<3;j++){
            cout<<procesos[i][j]<<"-";
        }
        cout<<endl;
    }
    cout<<"Fin del reporte"<<"==============\n";
}
