#include "../headers/Cine.h"
#include <stdexcept>

Cine::Cine(DtCine *datacine) {
    this->numero = datacine->getNumero();
    this->direccion = datacine->getDireccion();
    this->salas = new OrderedDictionary();
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
DtDireccion Cine::getDireccion() {
    return this->direccion;
}
IDictionary *Cine::getSalas(){
    return this->salas;
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

Cine::~Cine() {

}