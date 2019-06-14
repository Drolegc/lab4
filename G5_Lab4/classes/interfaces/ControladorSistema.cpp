#include "ControladorSistema.h"

ControladorSistema::ControladorSistema() {
    
}

ICollection* ControladorSistema::listarPeliculas() {
    ICollection* lisPeliculas = new list();
    IIterator *it = Pelicula->getIterator();    
    while(it->hasCurrent()){
        Pelicula* pelicula = (Pelicula*) it->getCurrent();
        std::string titulo = pelicula->getTitulo();
        lisPeliculas->add(titulo);   
        it->next();
    }
    delete it;
    return lisPeliculas;
}

ICollection* ControladorSistema::listarCines() {
    ICollection listaCines = new list();
    IIterator *it = Cine->getIterator();    
    while(it->hasCurrent()){
        Cine* cine = (Cine*) it->getCurrent();
        int numero = cine->getNumero();
        listaCines->add(numero);   
        it->next();
    }
    delete it;
    return listaCines;
}

//void ControladorSistema::eliminarPelicula(string titulo){
    // Corresponde al caso de uso eliminar pelicula
//    IKey clave = new KeyString(titulo);
//    Pelicula *p;
//    p = (Pelicula *) Pelicula->find(clave);
//    Pelicula->remove(p);
//    delete p;
//    delete clave;       
//}

//DtPelicula ControladorSistema::seleccionarPelicula(string titulo){
    //Corresponde al caso de uso Ver informacion de pelicula
//    IKey clave = new KeyString(titulo);
//    DtPelicula *p;
//    p = (DtPelicula *) Pelicula->find(clave);
//
//    return p;
//}