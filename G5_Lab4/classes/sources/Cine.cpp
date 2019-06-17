#include "../headers/Cine.h"

Cine::Cine(int numero, DtDireccion direccion) : direccion(direccion) {
    this->numero = numero;
    this->direccion = direccion;
}

DtDireccion Cine::getDireccion() {
    return this->direccion;
}

int Cine::getNumero() {
    return this->numero;
}

void Cine::setDireccion(DtDireccion direccion) {
    this->direccion = direccion;
}

void Cine::setNumero(int numero) {
    this->numero = numero;
}

Cine::~Cine() {
    
}