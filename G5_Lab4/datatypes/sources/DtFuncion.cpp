#include "../headers/DtFuncion.h"

DtFuncion::DtFuncion(int numero, DtFecha fecha, DtHora hora, Pelicula* pelicula) : fecha(fecha), hora(hora) {
    this->numero = numero;
    this->fecha = fecha;
    this->hora = hora;
    this->pelicula = pelicula;
}

DtFecha DtFuncion::getFecha() {
    return this->fecha;
}

DtHora DtFuncion::getHora() {
    return this->hora;
}

int DtFuncion::getNumero() {
    return this->numero;
}

Pelicula* DtFuncion::getPelicula() {
    return this->pelicula;
}

void DtFuncion::setFecha(DtFecha fecha) {
    this->fecha = fecha;
}

void DtFuncion::setHora(DtHora hora) {
    this->hora = hora;
}

void DtFuncion::setNumero(int numero) {
    this->numero = numero;
}

void DtFuncion::setPelicula(Pelicula* pelicula) {
    this->pelicula = pelicula;
}

std::ostream& operator<<(std::ostream &o, DtFuncion* dtF) {
    o<<std::string("Funcion: ") << dtF->getNumero() << std::string(" - Pelicula: ") << dtF->getPelicula()
            << std::string(" - Fecha: ") << dtF->getFecha().getDia() << std::string("/") << dtF->getFecha().getMes()
            << std::string("/") << dtF->getFecha().getAnio() << std::string(" - Hora: ") << dtF->getHora().getHora()
            << std::string(":") << dtF->getHora().getMinutos();
    return o;
}
