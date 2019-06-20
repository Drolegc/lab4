#include "../headers/Cine.h"
#include <stdexcept>

Cine::Cine(DtCine *datacine) {
    this->numero = datacine->getNumero();
    this->direccion = datacine->getDireccion();
    this->dicSalas = new OrderedDictionary();
    this->dicPeliculas = new OrderedDictionary();
}

Cine::Cine(std::string calle,int num,std::string ciudad,int id):direccion(calle,num,ciudad){
    this->numero=id;
}

void Cine::listarCines(IDictionary* cines){
    IIterator* it = cines->getIterator();
    while (it->hasCurrent()) {
        Cine * currentCine = dynamic_cast<Cine*>(it->getCurrent());
        std::cout << new DtCine(currentCine->getDireccion(),currentCine->getNumero());
        IDictionary *salas = currentCine->getSalas();
        Sala::listarSalas(salas);
        it->next();
    }
    delete it;
}

ICollection* Cine::getFunciones(Pelicula* p){
    //CREO UNA COLLECCION DE FUNCIONES QUE TIENEN LA PELICULA DESEADA
    ICollection* funciones = new List();
    IIterator* it = this->dicSalas->getIterator();
    while(it->hasCurrent()){
        Sala* S = dynamic_cast<Sala*>(it->getCurrent());
        funciones->add(S->getDtFuncion(p));
        it->next();
    }
    return funciones;
}

Funcion* Cine::getFuncion(int id_funcion){
    Funcion* f;
    IIterator* it = this->dicSalas->getIterator();
    while(it->hasCurrent()){
        Sala* S = dynamic_cast<Sala*>(it->getCurrent());
        f = S->getFuncion();
        if(f->getNumero() == id_funcion){
            return f;
        }
        it->next();
    }
    return NULL;
}

DtDireccion Cine::getDireccion() {
    return this->direccion;
}
IDictionary *Cine::getSalas(){
    return this->dicSalas;
}
int Cine::getNumero() {
    return this->numero;
}

void Cine::setDireccion(DtDireccion direccion) {
    this->direccion = direccion;
}

void Cine::setNumero(int numero) {
    this->numero = numero;
}

bool Cine::tienePeli(StringKey* k){
    return dicPeliculas->member(k);
}

Cine::~Cine() {

}