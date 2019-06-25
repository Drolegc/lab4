#include "ControladorSistema.h"

ControladorSistema::ControladorSistema() {
    colReserva = new OrderedDictionary();
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
    std::cout << "                  ID CINE(n°): ";
    std::cin >> numero;
    Cine* nuevocine = new Cine(new DtCine(direccion,numero));
    int agregarmas = 1;
    int capacidadSala;
    int numeroSala;
    while(agregarmas!=0){
        std::cout << "           ═══════ NUEVA SALA ════════════════════════════════════════          " << std::endl;
        std::cout <<"                     CAPACIDAD:";
        std::cin >>capacidadSala;
        std::cout <<"                    N° DE SALA:";
        std::cin>>numeroSala;
        IntKey* keysala = new IntKey {numeroSala};
        Sala* sala = new Sala(capacidadSala,numeroSala);
        nuevocine->getSalas()->add(keysala,sala);
        std::cout << " "<< std::endl;
        std::cout <<"                    Para terminar de ingresar salas ingrese 0:";//wtf, por que no 
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

//void ControladorSistema::eliminarPelicula(std::string titulo) {
//    // Corresponde al caso de uso eliminar pelicula
//    IKey* clave = new String(titulo);
//    ICollectible* (Pelicula *) p;
//    p = (Pelicula *) Pelicula->find(clave);
//    Pelicula->remove(p);
//    delete p;
//    delete clave;
//}

void ControladorSistema::listarPeliculas() {
    Pelicula::listarPeliculas(dicPelicula);
}

//DtPelicula ControladorSistema::seleccionarPelicula(std::string titulo) {
//    IKey clave = new String(titulo);
//    //Corresponde al caso de uso Ver informacion de pelicula
//    DtPelicula *p;
//    p = (DtPelicula *) Pelicula->find(clave);
//
//    return p;
//}

ControladorSistema::~ControladorSistema() {

}