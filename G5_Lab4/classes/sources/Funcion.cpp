#include "../headers/Funcion.h"
#include "Reserva.h"

Funcion::Funcion(int numero, DtFecha fecha, DtHora hora) {
    this->numero = numero;
    this->fecha = fecha;
    this->hora = hora;
}

int Funcion::getNumero() {
    return this->numero;
}

DtFecha Funcion::getFecha() {
    return this->fecha;
}

DtHora Funcion::getHora() {
    return this->hora;
}

void Funcion::setNumero(int numero) {
    this->numero = numero;
}

void Funcion::setFecha(DtFecha fecha) {
    this->fecha = fecha;
}

void Funcion::setHora(DtHora hora) {
    this->hora = hora;
}

void Funcion::eliminarFunciones() {
    IIterator* it = Funcion->getIterator();
    ICollectible* funcion;
    while(it->hasCurrent()) {
        funcion = it->getCurrent();
        Reserva::eliminarReservas();
        it->remove(funcion);
        delete funcion;
    }
    delete it;
    delete Funcion;
}

ICollection* Funcion::obtenerFunciones() {
    ICollection* listaFunciones = new list();
    IIterator* it = Funcion->getIterator();
    while(it->hasCurrent()) {
        Funcion* funcion = (Funcion*) it->getCurrent();
        listaFunciones->add(funcion);
        it->next();
    }
    delete it;
    return listaFunciones;
}

//ICollectible* Funcion::obtenerFuncion(int numero) {
//    
//}

Funcion::~Funcion() {

}



