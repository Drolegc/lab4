#include "../headers/Sala.h"

Sala::Sala(int numero, int capacidad) {
    this->numero = numero;
    this->capacidad = capacidad;
    this->dicFunciones = new OrderedDictionary();
}

DtFuncion* Sala::getDtFuncion(Pelicula* p){
    //BUSCAR LA PELICULA
    IDictionary* funciones = this->getDicFunciones();
    IIterator* it = funciones->getIterator();

    while(it->hasCurrent()){
        Funcion* f = dynamic_cast<Funcion*>(it->getCurrent());
        if(f->tienePeli(p)){
            DtFuncion* dtf = new DtFuncion(f->getNumero(),f->getFecha(),f->getHora(),p->getTitulo());
            return dtf;
        }
    }

    throw std::invalid_argument("");
}

Funcion* Sala::getFuncion(int id){
    //Chequear si tenemos esa funcion, si no devolver NULL
    IntKey* k = new IntKey(id);
    ICollectible* f = dicFunciones->find(k);
    if(f!=NULL){
        return dynamic_cast<Funcion*>(f);
    }else{
        return NULL;
    }
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
Sala::~Sala() {

}
void Sala::listarSalas(IDictionary* salas){
    IIterator* it = salas->getIterator();
    while (it->hasCurrent()) {
        Sala* currentSala = dynamic_cast<Sala*>(it->getCurrent());
        std::cout <<"                      "<< new DtSala(currentSala->getCapacidad(), currentSala->getNumero()) <<std::endl;
        it->next();
    }
    delete it;
}
