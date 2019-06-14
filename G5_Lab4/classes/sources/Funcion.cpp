#include <stdlib.h>

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

Funcion Funcion::altaFuncion(DtHora hora, DtFecha fecha) {
    int aux = 0;
    IKey* numero = new Integer();
    Funcion* funcion = new Funcion();
    IDictionary* listaFunciones = new list(funciones);
    IIterator* it = listaFunciones->getIterator();
    while(it->hasCurrent()) {
        aux = Funcion->getNumero();
    }
    numero = aux + 1;
    funcion->setNumero(numero);
    funcion->setFecha(fecha);
    funcion->setHora(hora);
    return funcion;
}

void Funcion::eliminarFunciones(ICollection* funciones) {
    IDictionary* listaFunciones = new list(funciones);
    IIterator* it = listaFunciones->getIterator();
    ICollectible* funcion;
    while(it->hasCurrent()) {
        funcion = it->getCurrent();
        Reserva::eliminarReservas();
        listaFunciones->remove(funcion);
        delete funcion;
    }
    delete it;
    delete Funcion;
}

ICollection* Funcion::obtenerFunciones() {
    ICollection* listaFunciones = new list();
    IIterator* it = listaFunciones->getIterator();
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



