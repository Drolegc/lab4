#include "../headers/DtDireccion.h"

DtDireccion::DtDireccion(std::string calle, int numero, std::string ciudad) {
    this->calle = calle;
    this->numero = numero;
    this->ciudad = ciudad;
}
DtDireccion::DtDireccion(){

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
std::ostream& operator<<(std::ostream &o, DtDireccion df){
    o<<std::string("Cine: ") << df.getCalle() << df.getNumero()<<std::string(", ")<< df.getCiudad()<<std::endl;
    return o;
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