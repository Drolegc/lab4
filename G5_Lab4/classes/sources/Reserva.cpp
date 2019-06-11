#include "../headers/Reserva.h"

Reserva::Reserva(int asientos, int costoTotal) {
    this->asientos = asientos;
    this->costoTotal = costoTotal;
}

int Reserva::getAsientos() {
    return this->asientos;
}

int Reserva::getCostoTotal() {
    return this->costoTotal;
}

void Reserva::setAsientos(int asientos) {
    this->asientos = asientos;
}

void Reserva::setCostoTotal(int costoTotal) {
    this->costoTotal = costoTotal;
}

Reserva::~Reserva() {
    
}