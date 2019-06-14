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