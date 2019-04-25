#ifndef COLA_H
#define COLA_H
#include<iostream>
#include<cstdlib>
using namespace std;
struct nodo{
    int nro;
    struct nodo *sgte;
};
typedef struct nodo *Puntero;
class Cola
{
public:
        Cola(void);
        void Encolar(int );
        int Desencolar(void );
        bool ColaVacia(void);
        void MostrarCola(void);
        void VaciarCola(void);

    private:
        Puntero delante;//puntero al primer elemento de la cola
        Puntero atras;
};

#endif // COLA_H
