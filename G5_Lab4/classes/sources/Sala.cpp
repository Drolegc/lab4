#include "../headers/Sala.h"

Sala::Sala(int numero, int capacidad) {
    this->numero = numero;
    this->capacidad = capacidad;
    this->dicFunciones = new OrderedDictionary();
}

int Sala::getNumero() {
    return this->numero;
}

int Sala::getCapacidad() {
    return this->capacidad;
}

IDictionary* Sala::getDicFunciones() {
    return this->dicFunciones;
}

void Sala::setNumero(int numero) {
    this->numero = numero;
}

void Sala::setCapacidad(int capacidad) {
    this->capacidad = capacidad;
}
IDictionary* Sala::getDicFunciones() {
    return this->dicFunciones;
}

Sala::~Sala() {

}
void Sala::listarSalas(IDictionary* salas){
    IIterator* it = salas->getIterator();
    while (it->hasCurrent()) {
        Sala* currentSala = dynamic_cast<Sala*>(it->getCurrent());
        std::cout << new DtSala(currentSala->getCapacidad(), currentSala->getNumero()) <<std::endl;
        it->next();
    }
    delete it;
}
