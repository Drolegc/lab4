/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../../datatypes/headers/DtFuncion.h"

DtFuncion::DtFuncion(int numero, DtFecha fecha, DtHora hora) : fecha(fecha), hora(hora){
    this->numero = numero;
}

int DtFuncion::getNumero() {
    return this->numero;
}

DtFecha DtFuncion::getFecha() {
    return this->fecha;
}

DtHora DtFuncion::getHora() {
    return this->hora;
}
