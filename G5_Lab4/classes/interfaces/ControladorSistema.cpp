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

void ControladorSistema::verComentariosypuntajedepelicula(){
    std::string nombrePelicula;
    Pelicula::listarPeliculas(dicPelicula);
    std::cout << "Elija pelicula:";
    std::cin >> nombrePelicula;
    StringKey *key = new StringKey(nombrePelicula);
    Pelicula *pelicula = dynamic_cast<Pelicula*>(dicPelicula->find(key));
    int puntaje=pelicula->getPuntajePromedio();
    //logo();
    std::cout << "           ═══════════════════════════════════════════════════════════          " << std::endl;
    std::cout << "                PELICULA:" << std::endl;
    std::cout <<"                            Titulo: "<<pelicula->getTitulo() << std::endl;
    std::cout <<"                  Puntaje promedio: "<< puntaje <<"(x)usuarios\n"<< std::endl;
    std::cout << "           ───────────────────────────────────────────────────────────          " << std::endl;
    std::cout << "                COMENTARIOS:" << std::endl;
    std::cout <<"                         USUARIOX: "<< std::endl;
    IDictionary* comentarios =  pelicula->getComentarios();
    Comentarios::listaComentarios(comentarios);
    std::cout << " " << std::endl;
    std::cout << "           ───────────────────────────────────────────────────────────          " << std::endl;
    std::cout << "                PUNTAJES " << std::endl;
    std::cout <<"                          USUARIOX: 5 Puntos"<< std::endl;
    std::cout <<"                          USUARIOB: 2 Puntos"<< std::endl;
    std::cout << " " << std::endl;
    std::cout << "           ═══════════════════════════════════════════════════════════          " << std::endl;





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

void ControladorSistema::comentarPelicula(){
    std::string nombrePelicula;
    std::string comentario;
    Pelicula::listarPeliculas(dicPelicula);
    std::cout << "Elija que pelicula va a comentar:";
    std::cin >> nombrePelicula;
    StringKey *key = new StringKey(nombrePelicula);
    Pelicula *pelicula = dynamic_cast<Pelicula*>(dicPelicula->find(key));
    IDictionary* comentarios =  pelicula->getComentarios();
    Comentarios::listaComentarios(comentarios);
    std::cout <<"Escriba su comentario"<<std::endl;
    std::cin >>comentario;
    pelicula->setComentario(comentario);
    int accion;
    std::cout <<"Para agregar un nuevo comentario Ingrese 1, para comentar otro comentario ingrese 2, para salir ingrese 0"<<std::endl;
    std::cin >>accion;
    if(accion==1){
        std::cout <<"Escriba su comentario:"<<std::endl;
        std::cin >>comentario;
        pelicula->setComentario(comentario);
    }else if (accion == 2){
        IDictionary *comentarios = pelicula->getComentarios();
        Comentarios::listaComentarios(comentarios);
        int numeroComentario;
        std::cout <<"Ingrese que comentario desea comentar"<<std::endl;
        std::cin >>numeroComentario;
        IntKey *key = new IntKey(numeroComentario);
        Comentarios * comentarioAcomentar =  dynamic_cast<Comentarios*>(comentarios->find(key));
        std::cout <<"Escriba su comentario"<<std::endl;
        std::cin >>comentario;
        comentarioAcomentar->setComentarios("   " + comentario);
    }
}
void ControladorSistema::login(std::string nickname, std::string password){
    StringKey *userKey = new StringKey(nickname);
    Usuario* user = dynamic_cast <Usuario*>(dicUsuario->find(userKey));
    if(user != NULL){
        if (user->getContrasenia() == password){
            this->sesion = user;
        }else{
            std::cout <<"Password incorrecta"<<std::endl;
        }
    }else{
        std::cout <<"El usuario no existe"<<std::endl;
    }
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
void ControladorSistema::infoPeliculas(){
    std::string nombrePelicula;
    int verCines;
    IIterator *it = dicPelicula->getIterator();
    while(it->hasCurrent()){
        Pelicula* p =  dynamic_cast<Pelicula*>(it->getCurrent());
        std::cout <<p->getTitulo()<<std::endl;
        it->next();
    }

    std::cout <<"ingrese que pelicula desea buscar"<<std::endl;
    std::cin >>nombrePelicula;
    StringKey *key = new StringKey(nombrePelicula);
    Pelicula *p = dynamic_cast<Pelicula*>(dicPelicula->find(key));
    if(p!=NULL){
        std::cout << p->getUrlPoster()<<std::endl;
        std::cout << p->getSinopsis()<<std::endl;
        std::cout <<"Para ver los cines donde se proyecta la pelicula presione 1 "<<std::endl;
        std::cin >>verCines;
        if(verCines == 1){
            IIterator *iteratorCine = Cines->getIterator();
            while(iteratorCine->hasCurrent()){
                Cine* cine =  dynamic_cast<Cine*>(iteratorCine->getCurrent());
                IDictionary *sala = cine->getSalas();
                IIterator *SalaIterator = sala->getIterator();
                while(SalaIterator->hasCurrent()){
                    Sala* sala =  dynamic_cast<Sala*>(SalaIterator->getCurrent());
                    IDictionary *funciones = sala->getDicFunciones();
                    IIterator * ItFunciones = funciones->getIterator();
                    while(ItFunciones->hasCurrent()){
                        Funcion *f = dynamic_cast<Funcion*>(ItFunciones->getCurrent());
                        Pelicula* peliculas = f->getPelicula();
                        if(nombrePelicula == peliculas->getTitulo()){
                            std::cout << new DtCine(cine->getDireccion(),cine->getNumero())<<std::endl;
                        }
                    }
                }
            }
        }
    }
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