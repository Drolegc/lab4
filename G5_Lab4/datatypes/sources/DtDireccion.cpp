#include "../headers/DtDireccion.h"

DtDireccion::DtDireccion(std::string calle, int numero, std::string ciudad) {
    this->calle = calle;
    this->numero = numero;
    this->ciudad = ciudad;
}

std::string DtDireccion::getCalle() {
    return this->calle;
}

std::string DtDireccion::getCiudad() {
    return this->ciudad;
}

int DtDireccion::getNumero() {
    return this->numero;
}

void DtDireccion::setCalle(std::string calle) {
    this->calle = calle;
}

void DtDireccion::setNumero(int numero) {
    this->numero = numero;
}

void DtDireccion::setCiudad(std::string ciudad) {
    this->ciudad = ciudad;
}

DtDireccion::~DtDireccion() {
    
}