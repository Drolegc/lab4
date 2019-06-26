#include "../headers/DtFuncion.h"

DtFuncion::DtFuncion(int numero, DtFecha fecha, DtHora hora, std::string tituloPelicula) : fecha(fecha), hora(hora) {
    this->numero = numero;
    this->fecha = fecha;
    this->hora = hora;
    this->tituloPelicula = tituloPelicula;
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

//Pelicula* DtFuncion::getPelicula() {
//    return this->pelicula;
//}

std::string DtFuncion::getTituloPelicula() {
    return this->tituloPelicula;
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

//void DtFuncion::setPelicula(Pelicula* pelicula) {
//    this->pelicula = pelicula;
//}

void DtFuncion::setTituloPelicula(std::string tituloPelicula) {
    this->tituloPelicula = tituloPelicula;
}

std::ostream& operator<<(std::ostream &o, DtFuncion* dtF) {
    o<<std::string("Funcion: ") << dtF->getNumero() << std::string(" - Pelicula: ") << dtF->getTituloPelicula()
            << std::string(" - Fecha: ") << dtF->getFecha().getDia() << std::string("/") << dtF->getFecha().getMes()
            << std::string("/") << dtF->getFecha().getAnio() << std::string(" - Hora: ") << dtF->getHora().getHora()
            << std::string(":") << dtF->getHora().getMinutos() << std::endl << std::endl;
    return o;
}