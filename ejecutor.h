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
using namespace std;

class Ejecutor
{
private:
    MainWindow* w;
    QLabel** ArrayL;
    QProgressBar** ArrayB;
    QLabel* LabelSec;
    QListWidget* List;
public:
    /**
     * @brief Ejecutor
     * @param w ventana principal
     * @param ArrayL array con los Labels
     * @param ArrayB array con las ProgressBar
     */
    Ejecutor(MainWindow *w, QLabel **ArrayL, QProgressBar **ArrayB);
    /**
     * @brief GenerarBarras Dibuja y agrupa los Labels y PrograssBar
     * @param i
     */
    void GenerarBarras(int i=0);
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
