#ifndef EJECUTOR_H
#define EJECUTOR_H

#include "mainwindow.h"
#include <unistd.h>
#include <iostream>
#include <string>
#include <QApplication>
#include <QProgressBar>
#include <QLabel>
#include <QString>
#include <QDebug>
#include <thread>
#include <QListWidget>
#include"vehiculo.h"
#include <queue>
#include "iostream"

using namespace std;

class Ejecutor
{
private:
    queue <int> colaVehiculos;
    queue <int> colaProcesos;
    MainWindow* w;
    QLabel** ArrayL;
    QProgressBar** ArrayB;
    QLabel* LabelSec;
    QListWidget* List;
    vehiculo* vehiculos[6]={};
    bool arrayDeCola[6]={};
public:
    /**
     * @brief Ejecutor
     * @param w ventana principal
     * @param ArrayL array con los Labels
     * @param ArrayB array con las ProgressBar
     */
    Ejecutor(MainWindow *w, QLabel **ArrayL, QProgressBar **ArrayB);
    /**
     * @brief actualiza todos los vehiculos del array
     */
    void actualizarVehiculos();
    /**
     * @brief GenerarBarras Dibuja y agrupa los Labels y PrograssBar
     */
    void GenerarBarras();
    /**
     * @brief Actualizar Modifica los Labels y PrograssBar según la info del vehículo
     */
    void Actualizar();
    /**
     * @brief CicloActualizar cantidad de iteraciones para finalizar
     */
    void CicloActualizar();
};

#endif // EJECUTOR_H
