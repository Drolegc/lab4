#include "../headers/DtSala.h"
DtSala::DtSala(int numero, int capacidad) {
    this->numero = numero;
    this->capacidad = capacidad;
}

int DtSala::getNumero() {
    return this->numero;
}

int DtSala::getCapacidad() {
    return this->capacidad;
}
std::ostream& operator<<(std::ostream &o, DtSala *df){
    o<<std::string("sala: ") << df->getNumero()<<std::string("- Capacidad: ")<< df->getCapacidad();
    return o;
}
