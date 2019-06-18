#include "../headers/DtCine.h"

DtCine::DtCine(int numero, DtDireccion direccion) : direccion(direccion) {
    this->numero = numero;
    this->direccion = direccion;
}

DtDireccion DtCine::getDireccion() {
    return this->direccion;
}

int DtCine::getNumero() {
    return this->numero;
}

DtCine::~DtCine() {
    
}