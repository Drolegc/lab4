#include "../headers/DtCine.h"

DtCine::DtCine(DtDireccion direccion, int numero){
    this->direccion = direccion;
    this->numero = numero;
}
DtDireccion DtCine::getDireccion(){
    return this->direccion;
}
int DtCine::getNumero(){
    return this->numero;
}
std::ostream& operator<<(std::ostream &o, DtCine *df){
    o<<std::string("Cine: ") <<
    df->getNumero() <<
    std::string(" - Direccion: ") <<
    df->getDireccion().getCalle() <<
    std::string(" ") <<
    df->getDireccion().getNumero() <<
    std::string(", ") <<
    df->getDireccion().getCiudad()<<std::endl;
    return o;
}
