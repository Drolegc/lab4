#include "ControladorSistema.h"

ControladorSistema::ControladorSistema() {
    Pelicula = new OrderedDictionary();
    Cines = new OrderedDictionary();
    Usuario = new OrderedDictionary();
    Reserva = new List();
}

void ControladorSistema::altaCine(DtDireccion direccion) {
    int numero;
    std::cout << "Ingrese el numero del cine:";
    std::cin >> numero;
    Cine* nuevocine = new Cine(new DtCine(direccion,numero));
    int agregarmas = 1;
    int capacidadSala;
    int numeroSala;
    while(agregarmas!=0){
        std::cout <<"Ingrese la capacidad:";
        std::cin >>capacidadSala;
        std::cout <<"Ingrese el numero de sala:";
        std::cin>>numeroSala;
        IntKey* keysala = new IntKey {numeroSala};
        Sala* sala = new Sala(capacidadSala,numeroSala);
        nuevocine->getSalas()->add(keysala,sala);
        std::cout <<"Para salir presione 0:";
        std::cin >>agregarmas;
        if(agregarmas == 0){
            break;
        }
    }
    IntKey* keyCine = new IntKey (numero);
    Cines->add(keyCine,nuevocine);
}
void ControladorSistema::listarCines(){
    Cine::listarCines(Cines);
}

//void ControladorSistema::eliminarPelicula(std::string titulo) {
//    // Corresponde al caso de uso eliminar pelicula
//    IKey* clave = new String(titulo);
//    ICollectible* (Pelicula *) p;
//    p = (Pelicula *) Pelicula->find(clave);
//    Pelicula->remove(p);
//    delete p;
//    delete clave;
//}

//ICollection* ControladorSistema::listarCines() {
//    ICollection* listaCines = new list();
//    IIterator* it = Cine->getIterator();
//    while(it->hasCurrent()){
//        Cine* cine = (Cine*) it->getCurrent();
//        int numero = cine->getNumero();
//        listaCines->add(numero);
//        it->next();
//    }
//    delete it;
//    return listaCines;
//}

//ICollection* ControladorSistema::listarPeliculas() {
//    ICollection* lisPeliculas = new list();
//    IIterator *it = Pelicula->getIterator();
//    while(it->hasCurrent()){
//        Pelicula* pelicula = (Pelicula*) it->getCurrent();
//        std::string titulo = pelicula->getTitulo();
//        lisPeliculas->add(titulo);
//        it->next();
//    }
//    delete it;
//    return lisPeliculas;
//}

//DtPelicula ControladorSistema::seleccionarPelicula(std::string titulo) {
//    //Corresponde al caso de uso Ver informacion de pelicula
//    IKey clave = new String(titulo);
//    DtPelicula *p;
//    p = (DtPelicula *) Pelicula->find(clave);
//
//    return p;
//}

ControladorSistema::~ControladorSistema() {

}