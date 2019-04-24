#include "agendageneral.h"

AgendaGeneral::AgendaGeneral()
{

}



void AgendaGeneral::sacar(int procesoactual,int vehiculo)
{
    for (int i=0;i<3;i++){
        if (procesos[procesoactual][i]==vehiculo){
            procesos[procesoactual][i]=8;
            return;
        }
    }
}

void AgendaGeneral::meter(int procesoactual, int vehiculo)
{
    for (int i=0;i<3;i++){
        if (procesos[procesoactual][i]==8){
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
    char c;
    for (int i=0;i<6;i++){
        c=i+65;
        cout<<"Proceso "<<c<<":";
        for (int j=0;j<3;j++){
            if (procesos[i][j]==8){
                cout<<"#"<<"-";
            }
            else{
                cout<<procesos[i][j]+1<<"-";
            }

        }
        cout<<endl;
    }
    cout<<"Fin del reporte"<<"==============\n";
}
