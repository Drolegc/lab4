#include "ControladorSistema.h"
#include "../../ICollection/StringKey.h"

ControladorSistema::ControladorSistema()
{
    dicPelicula = new OrderedDictionary();
}

void ControladorSistema::altaCine(DtDireccion direccion)
{
    int asd;
    std::cout << "Llegamos a entrar a la función";
    std::cin >> asd;
    //    int numero = 0;
    //    IDictionary* listaCines = new list(Cine);
    //    IIterator* it = listaCines->getIterator();
    //    while(it->hasCurrent()) {
    //        Cine* cine = (Cine*) it->getCurrent();
    //        numero = cine->getNumero();
    //        it->next();
    //    }
    //    numero = numero + 1;
    //    Cine cine = new Cine();
    //    cine->setNumero(numero)
    //    cine->setDireccion(direccion);
    //    int seguirAgregandoSalas = 1;
    //    while(seguirAgregandoSalas != 0) {
    //
    //    }
    //    listaCines->add(numero, cine);
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

DtPelicula ControladorSistema::seleccionarPelicula(std::string titulo)
{
    //Corresponde al caso de uso Ver informacion de pelicula
    //IKey clave = new String(titulo);
    StringKey *clave = new StringKey(titulo);
    Pelicula *p = dynamic_cast<Pelicula *>(dicPelicula->find(clave));
    if (p != NULL)
    {
        DtPelicula peli = DtPelicula(p->getTitulo(), p->getUrlPoster(), p->getSinopsis());
        return peli;
    }else{
        throw std::invalid_argument("Disculpa, no tenemos esa pelicula pr el momento :/");
    }
}

ICollection* ControladorSistema::verInfoAdicional(DtPelicula p){
    //Primero obtener el objeto pelicula
    //clave y coleccionable
    StringKey *clave = new StringKey(p.getTitulo());
    //ICollectible * peli = dicPelicula->find(clave);
    //Crear una coleccion vacia para agregar los cines
    ICollection * CinesConPeli = new List();
    //Obtenemos el iterador del diccionario de Cines
    IIterator *it = dicCine->getIterator();
    
    while(it->hasCurrent()){
        Cine *c = dynamic_cast<Cine*>(it->getCurrent());
        if(c->tienePeli(clave)){
            CinesConPeli->add(it->getCurrent());
        }
    }

    return CinesConPeli;
}


ControladorSistema::~ControladorSistema()
{
}