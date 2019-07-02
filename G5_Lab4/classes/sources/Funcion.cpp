#include <stdlib.h>

#include "../headers/Funcion.h"

Funcion::Funcion(int numero, DtFecha fecha, DtHora hora, Pelicula* pelicula) : fecha(fecha), hora(hora){
    this->numero = numero;
    this->fecha = fecha;
    this->hora = hora;
    this->pelicula = pelicula;
    this->colReserva = new List();
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

ICollection* Funcion::getColReserva() {
    return this->colReserva;
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

bool Funcion::tienePeli(Pelicula* p){
    if (this->pelicula == p){
        return true;
    }else{
        return false;
    }
}

//Funcion Funcion::altaFuncion(DtHora hora, DtFecha fecha) {
//    int aux = 0;
//    IKey* numero = new Integer();
//    Funcion* funcion = new Funcion();
//    IDictionary* listaFunciones = new list(funciones);
//    IIterator* it = listaFunciones->getIterator();
//    while(it->hasCurrent()) {
//        aux = Funcion->getNumero();
//    }
//    numero = aux + 1;
//    funcion->setNumero(numero);
//    funcion->setFecha(fecha);
//    funcion->setHora(hora);
//    return funcion;
//}
//
//void Funcion::eliminarFunciones(ICollection* funciones) {
//    IDictionary* listaFunciones = new list(funciones);
//    IIterator* it = listaFunciones->getIterator();
//    ICollectible* funcion;
//    while(it->hasCurrent()) {
//        funcion = it->getCurrent();
//        Reserva::eliminarReservas();
//        listaFunciones->remove(funcion);
//        delete funcion;
//    }
//    delete it;
//    delete Funcion;
//}
//
//ICollection* Funcion::obtenerFunciones() {
//    ICollection* listaFunciones = new list();
//    IIterator* it = listaFunciones->getIterator();
//    while(it->hasCurrent()) {
//        Funcion* funcion = (Funcion*) it->getCurrent();
//        listaFunciones->add(funcion);
//        it->next();
//    }
//    delete it;
//    return listaFunciones;
//}

//ICollectible* Funcion::obtenerFuncion(int numero) {
//    
//}
void Funcion::setPelicula(Pelicula* pelicula) {
    this->pelicula = pelicula;
}

void Funcion::listarFunciones(IDictionary* funciones){
    IIterator* it = funciones->getIterator();
    while (it->hasCurrent()) {
        Funcion* currentFuncion = dynamic_cast<Funcion*>(it->getCurrent());
        std::cout << new DtFuncion(currentFuncion->getNumero(), currentFuncion->getFecha(),
                currentFuncion->getHora(), currentFuncion->getPelicula()->getTitulo());
        it->next();
    }
    
}

void Funcion::setReserva(ICollectible* c){
    colReserva->add(c);
}

void Funcion::FuncionesConPeli(ICollection *c)
{
    IIterator *it = c->getIterator();
    if (!it->hasCurrent())
    {
        std::cout << "Sin funciones para esa pelicula, vuelve pronto" << std::endl;
        throw std::invalid_argument("");
    }
    while (it->hasCurrent())
    {
        DtFuncion *f = dynamic_cast<DtFuncion *>(it->getCurrent());
        std::cout << f;
        it->next();
    }
}

Funcion::~Funcion() {

}



