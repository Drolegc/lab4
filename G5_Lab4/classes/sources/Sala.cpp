#include "../headers/Sala.h"

Sala::Sala(int numero, int capacidad) {
    this->numero = numero;
    this->capacidad = capacidad;
    this->funcion = NULL;
}

Funcion* Sala::getFuncion(){
    return this->funcion;
}

DtFuncion* Sala::getDtFuncion(Pelicula* p){
    if(this->funcion){
        if(this->funcion->tienePeli(p)){
            int num = this->funcion->getNumero();
            DtFecha dtf = this->funcion->getFecha();
            DtHora dth = this->funcion->getHora();
            DtFuncion * dtfuncion = new DtFuncion(num,dtf,dth);
            return dtfuncion;
        }
    }
    return NULL;

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
void Sala::listarSalas(IDictionary* salas){
    IIterator* it = salas->getIterator();
    while (it->hasCurrent()) {
        Sala* currentSala = dynamic_cast<Sala*>(it->getCurrent());
        std::cout << new DtSala(currentSala->getCapacidad(), currentSala->getNumero()) <<std::endl;
        it->next();
    }
    delete it;
}
