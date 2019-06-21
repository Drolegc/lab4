#include <stdlib.h>

#include "../headers/Funcion.h"

Funcion::Funcion(int numero, DtFecha fecha, DtHora hora, Pelicula* pelicula) : fecha(fecha), hora(hora){
    this->numero = numero;
    this->fecha = fecha;
    this->hora = hora;
    this->pelicula = pelicula;
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

Pelicula* Funcion::getPelicula() {
    return this->pelicula;
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

void Funcion::setPelicula(Pelicula* pelicula) {
    this->pelicula = pelicula;
}

void Funcion::listarFunciones(IDictionary* funciones){
    IIterator* it = funciones->getIterator();
    while (it->hasCurrent()) {
        Funcion* currentFuncion = dynamic_cast<Funcion*>(it->getCurrent());
        std::cout << new DtFuncion(currentFuncion->getNumero(), currentFuncion->getFecha(), currentFuncion->getHora(), currentFuncion->getPelicula());
        it->next();
    }
    delete it;
}

Funcion::~Funcion() {

}



