#include "cola.h"
Cola::Cola(void){
    delante=NULL;//inicializamos los punteros
    atras=NULL;
}

bool Cola::ColaVacia(){

    if(delante==NULL)
        return true;
    else return false;
}
void Cola::Encolar(int x){

     Puntero p_aux;

     p_aux=new(struct nodo);
     p_aux->nro=x;
     p_aux->sgte=NULL;

     if(delante==NULL)
        delante=p_aux;
     else atras->sgte=p_aux;

     atras=p_aux;
}

int Cola::Desencolar(void){

    int n;
    Puntero p_aux;

    p_aux=delante;
    n=p_aux->nro;
    delante=(delante)->sgte;
    delete(p_aux);
    return n;
}

void Cola::MostrarCola(void){
    Puntero p_aux;
     p_aux=delante;
     while(p_aux!=NULL){
        cout<<"\n\n\t"<<p_aux->nro;
        p_aux=p_aux->sgte;
     }

}

void Cola::VaciarCola(void){

     Puntero p_aux,r_aux;
     p_aux=delante;
     while(p_aux!=NULL){
        r_aux=p_aux;
        p_aux=p_aux->sgte;
        delete(r_aux);
     }
     delante=NULL;
     atras=NULL;
}
