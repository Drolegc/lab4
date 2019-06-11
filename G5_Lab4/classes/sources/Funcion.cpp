#include "../headers/Funcion.h"

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

Funcion::~Funcion() {

}



