#include "../headers/Sala.h"

Sala::Sala(int numero, int capacidad) {
    this->numero = numero;
    this->capacidad = capacidad;
}

int Sala::getNumero() {
    return this->numero;
}

int Sala::getCapacidad() {
    return this->capacidad;
}

void Sala::setNumero(int numero) {
    this->numero = numero;
}

void Sala::setCapacidad(int capacidad) {
    this->capacidad = capacidad;
}

Sala::~Sala() {
    
}
