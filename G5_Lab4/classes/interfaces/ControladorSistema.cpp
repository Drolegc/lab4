#include "ControladorSistema.h"

ControladorSistema::ControladorSistema() {
    colReserva = new List();
    dicUsuario = new OrderedDictionary();
    dicPelicula = new OrderedDictionary();
    Cines = new OrderedDictionary();
}

void ControladorSistema::altaFuncion(std::string titulo, int numeroCine, int numeroSala, DtFecha fecha, DtHora hora) {
    
    /********************* Obtengo la película específica *********************/
    
    IKey* keyPelicula = new StringKey(titulo);
    Pelicula* pelicula = (Pelicula*) dicPelicula->find(keyPelicula);
    delete keyPelicula;
    
    /*********************** Obtengo el cine específico ***********************/
    
    IKey* keyCine = new IntKey(numeroCine);
    Cine* cine = (Cine*) Cines->find(keyCine);
    delete keyCine;
    
    /*********************** Obtengo la sala específica ***********************/
    
    IKey* keySala = new IntKey(numeroSala);
    IDictionary* dicSalas = cine->getSalas();
    Sala* sala = (Sala*) dicSalas->find(keySala);
    delete keySala;
    
    /**************************** Agrego la función ****************************/
    
    IDictionary* dicFunciones = sala->getDicFunciones();
    IIterator* it = dicFunciones->getIterator();
    int numeroFuncion = 0;
    while(it->hasCurrent()) {
        numeroFuncion++;
        it->next();
    }
    numeroFuncion++;
    ICollectible* funcion = new Funcion(numeroFuncion, fecha, hora, pelicula);
    IKey* keyFuncion = new IntKey(numeroFuncion);
    dicFunciones->add(keyFuncion, funcion);
    delete it;
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

void ControladorSistema::comentarPelicula() {
    int numpelicula;
    std::string comentario;
    Pelicula::listarPeliculas(dicPelicula);
    std::cout << "Elija que pelicula va a comentar:";
    std::cin >> numpelicula;
    IntKey *key = new IntKey(numpelicula);
    Pelicula *pelicula = dynamic_cast<Pelicula*>(dicPelicula->find(key));
    std::cout <<"Escriba su comentario"<<std::endl;
    std::cin >>comentario;
    pelicula->setComentario(comentario);
}

void ControladorSistema::altaPelicula(DtPelicula datos) {
    IKey* key = new StringKey(datos.getTitulo());
//    key = datos.getTitulo();
    Pelicula* pelicula = new Pelicula();
    pelicula->setTitulo(datos.getTitulo());
    pelicula->setUrlPoster(datos.getUrlPoster());
    pelicula->setSinopsis(datos.getSinopsis());
    pelicula->setPuntajePromedio(datos.getPuntajePromedio());
    dicPelicula->add(key, pelicula);
}

void ControladorSistema::listarCines() {
    Cine::listarCines(Cines);
}

void ControladorSistema::eliminarPelicula(std::string titulo) {
    
    IIterator* iteratorCine = Cines->getIterator();
    while(iteratorCine->hasCurrent()){
        Cine* cine =  dynamic_cast<Cine*>(iteratorCine->getCurrent());
        IDictionary* sala = cine->getSalas();
        IIterator* SalaIterator = sala->getIterator();
        while(SalaIterator->hasCurrent()){
            Sala* sala =  dynamic_cast<Sala*>(SalaIterator->getCurrent());
            IDictionary* funciones = sala->getDicFunciones();
            IIterator* ItFunciones = funciones->getIterator();
            while(ItFunciones->hasCurrent()){
                Funcion* f = dynamic_cast<Funcion*>(ItFunciones->getCurrent());
                Pelicula* peliculaFuncion = f->getPelicula();
                if(titulo == peliculaFuncion->getTitulo()) {
                    ICollection* colReserva = f->getColReserva();
                    IIterator* itColReserva = colReserva->getIterator();
                    while(itColReserva->hasCurrent()) {
                        ICollectible* reserva = dynamic_cast<Reserva*> (itColReserva->getCurrent());
                        delete reserva;
                        itColReserva->next();
                    }
                    delete peliculaFuncion;
                    delete f;
                }
                ItFunciones->next();
            }
            SalaIterator->next();
        }
        iteratorCine->next();
    }
    IKey* tituloPelicula = new StringKey(titulo);
    ICollectible* pelicula = dicPelicula->find(tituloPelicula);
    dicPelicula->remove(tituloPelicula);
    delete tituloPelicula;
    delete pelicula;
}

//void ControladorSistema::listarFunciones() {
//    IIterator* iteratorCine = Cines->getIterator();
//    while(iteratorCine->hasCurrent()){
//        Cine* cine =  dynamic_cast<Cine*>(iteratorCine->getCurrent());
//        IDictionary* sala = cine->getSalas();
//        IIterator* SalaIterator = sala->getIterator();
//        while(SalaIterator->hasCurrent()){
//            Sala* sala =  dynamic_cast<Sala*>(SalaIterator->getCurrent());
//            IDictionary* funciones = sala->getDicFunciones();
//            IIterator* ItFunciones = funciones->getIterator();
//            while(ItFunciones->hasCurrent()){
//                Funcion* f = dynamic_cast<Funcion*>(ItFunciones->getCurrent());
//                f->listarFunciones(funciones);
//                ItFunciones->next();
//            }
//            SalaIterator->next();
//        }
//        iteratorCine->next();
//    }
//}

void ControladorSistema::listarPeliculas() {
    Pelicula::listarPeliculas(dicPelicula);
}

ControladorSistema::~ControladorSistema() {

}