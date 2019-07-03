#include "../headers/Reserva.h"

Reserva::Reserva(int asientos, int costoTotal,Funcion* f) {
    this->asientos = asientos;
    this->costoTotal = costoTotal;
    this->f=f;
}

int Reserva::getAsientos() {
    return this->asientos;
}

int Reserva::getCostoTotal() {
    return this->costoTotal;
}

Funcion* Reserva::getF() {
    return this->f;
}

void Reserva::setAsientos(int asientos) {
    this->asientos = asientos;
}

void Reserva::setCostoTotal(int costoTotal) {
    this->costoTotal = costoTotal;
}

Reserva::~Reserva() {
    
}