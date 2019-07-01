#include "ControladorSistema.h"
#include "../../ICollection/StringKey.h"
//#include "auxiliar.cpp"


ControladorSistema::ControladorSistema() {
    colReserva = new List();
    dicUsuario = new OrderedDictionary();
    dicPelicula = new OrderedDictionary();
    dicCines = new OrderedDictionary();
    //hay que iniciar con algo
    sesion = NULL;
}
void ControladorSistema::altaUsuario(std::string nickname, std::string urlimagen, std::string password){
    IKey* key = new StringKey(nickname);
    bool isAdmin;
    if(dicUsuario->getSize()==0){
        isAdmin = true;
    }else{
        isAdmin = false;
    }
    Usuario* user = new Usuario(nickname, urlimagen,password, isAdmin);
    dicUsuario->add(key, user);
}
void ControladorSistema::altaFuncion(std::string titulo, int numeroCine, int numeroSala, DtFecha fecha, DtHora hora)
{    /********************* Obtengo la película específica *********************/


    IKey *keyPelicula = new StringKey(titulo);
    if(dicPelicula->find(keyPelicula) == nullptr) {
        throw std::invalid_argument("No existe la película seleccionada");
    }
    Pelicula *pelicula = (Pelicula *)dicPelicula->find(keyPelicula);
    delete keyPelicula;
    /*********************** Obtengo el cine específico ***********************/
    IKey *keyCine = new IntKey(numeroCine);
    if(dicCines->find(keyCine) == nullptr) {
        throw std::invalid_argument("No existe el cine seleccionado");
    }
    Cine *cine = (Cine *)dicCines->find(keyCine);
    delete keyCine;

    /*********************** Obtengo la sala específica ***********************/

    IKey* keySala = new IntKey(numeroSala);
    IDictionary* dicSalas = cine->getSalas();
    if(dicSalas->find(keySala) == nullptr) {
        throw std::invalid_argument("No existe la sala seleccionada");
    }
    Sala* sala = (Sala*) dicSalas->find(keySala);
    delete keySala;

    /**************************** Agrego la función ****************************/

    IDictionary* dicFunciones = sala->getDicFunciones();
    IIterator* it = dicFunciones->getIterator();
    int numeroFuncion = 0;

    while (it->hasCurrent())
    {
        numeroFuncion++;
        it->next();
    }
    numeroFuncion++;
    ICollectible *funcion = new Funcion(numeroFuncion, fecha, hora, pelicula);
    IKey *keyFuncion = new IntKey(numeroFuncion);
    dicFunciones->add(keyFuncion, funcion);
    //Falta que la pelicula se sume al diccionario de peliculas de cine
    //Ahora que se creo la funcion con la pelicula...
    cine->addPelicula(pelicula);
    delete it;
}

Usuario *ControladorSistema::getUsuarioLogeado()
{
    return this->sesion;
}

bool ControladorSistema::getAdminStatus() {
    return this->sesion->getIsAdmin();
}

void ControladorSistema::verComentariosypuntajedepelicula(std::string _titulo){
    StringKey *key = new StringKey(_titulo);
    Pelicula *pelicula = dynamic_cast<Pelicula*>(dicPelicula->find(key));
    int puntaje=pelicula->getPuntajePromedio();
    int cantidadVecesPuntuada = pelicula->getCantidadVecesPuntuada();
    std::cout << "           ═══════════════════════════════════════════════════════════          " << std::endl;
    std::cout << "                PELICULA:" << std::endl;
    std::cout <<"                            Titulo: "<<pelicula->getTitulo() << std::endl;
    std::cout <<"                  Puntaje promedio: "<< puntaje <<"(" <<cantidadVecesPuntuada << " Usuarios)"<< std::endl;
    std::cout << "           ───────────────────────────────────────────────────────────          " << std::endl;
    std::cout << "                COMENTARIOS:" << std::endl;
    IDictionary* comentarios =  pelicula->getComentarios();
    Comentarios::listaComentarios(comentarios);
    std::cout << " " << std::endl;
    std::cout << "           ───────────────────────────────────────────────────────────          " << std::endl;
    std::cout << "                PUNTAJES " << std::endl;
    std::cout <<"                          USUARIOX: 5 Puntos"<<  std::endl;
    std::cout <<"                          USUARIOB: 2 Puntos"<< std::endl;
    std::cout << " " << std::endl;
    std::cout << "           ═══════════════════════════════════════════════════════════          " << std::endl;
    std::cout << "                                   Presione enter  para continuar..";
std::getchar();
std::getchar();





}
void ControladorSistema::puntuarPelicula(){
    std::string nombrePelicula;
    std::cout << "\n\n          \033[1;31m>>>>>>>>>>\033[0m             PUNTUAR PELICULA           \033[1;31m<<<<<<<<<<\033[0m                   " << std::endl;
    Pelicula::listarPeliculas(dicPelicula);

    std::cout <<"\n\n                   Ingrese el nombre de la pelicula: ";
    std::cin >> nombrePelicula;
    StringKey * key = new StringKey(nombrePelicula);
    int puntajePelicula;
    Pelicula *p =  dynamic_cast <Pelicula*> (dicPelicula->find(key));
    IIterator *it = p->getPuntajes()->getIterator();
    ICollection *puntaje = p->getPuntajes();
    int modificarPuntaje;
    while(it->hasCurrent()){
        Puntajes *punt = dynamic_cast<Puntajes*>(it->getCurrent());
        if(punt->getUsuario()->getNickname() == sesion->getNickname()){
            std::cout <<"Puntaje anterior:" << punt->getPuntaje();
            std::cout <<"Para modificar el puntaje presione 1 para salir presione 0?"<<std::endl;
            std::cin >>modificarPuntaje;
            if(modificarPuntaje == 1){
                puntaje->remove(it->getCurrent());
                delete punt;
            }
        }
        it->next();
    }
    std::cout <<"                   Que puntaje le pondras a la pelicula (0 a 100): ";
    std::cin >>puntajePelicula;
    Puntajes *puntajeTemporal = new Puntajes(puntajePelicula,sesion);
    p->setPuntaje(puntajeTemporal);
    std::getchar();
}


void ControladorSistema::altaCine(DtDireccion direccion) {
    int numero = dicCines->getSize();
    Cine *nuevocine = new Cine(new DtCine(direccion, numero));
    int agregarmas = 1;
    int capacidadSala;
    int numeroSala;
    int confirmarCine;
    std::cout << "\n                   AGREGAR SALAS "<< std::endl;
     int contador = 0;
    while(agregarmas!=0){

        std::cout << "           ═══════════════════════════════════════════════════════════          " << std::endl;
        std::cout <<"                     CAPACIDAD:";
        std::cin >>capacidadSala;
        numeroSala = contador;
        contador++ ;
        IntKey* keysala = new IntKey {numeroSala};
        Sala* sala = new Sala(capacidadSala,numeroSala);
        nuevocine->getSalas()->add(keysala,sala);
        std::cout << " "<< std::endl;
        std::cout <<"        Para continuar agregando salas ingrese 1,"<< std::endl;//wtf, por que no
        std::cout <<"        Para terminar de agregar salas ingrese 0: ";//wtf, por que no
        std::cin >>agregarmas;
        if(agregarmas == 0){
            break;
        }
    }
    IntKey *keyCine = new IntKey(numero);
    std::cout <<"Para guardar el cine presione 1, para salir presione 0:";
    std::cin >> confirmarCine;
    if(confirmarCine != 1){
        return;
    }
    dicCines->add(keyCine, nuevocine);
}

void ControladorSistema::comentarPelicula(){
    std::string nombrePelicula;
    std::string comentario;
    Pelicula::listarPeliculas(dicPelicula);
    std::cout << "                  Elija que pelicula va a comentar:";
    std::cin >> nombrePelicula;
    StringKey *key = new StringKey(nombrePelicula);
    Pelicula *pelicula = dynamic_cast<Pelicula*>(dicPelicula->find(key));
    IDictionary* comentarios =  pelicula->getComentarios();
    int agregarComentarios = 1;
    while(agregarComentarios == 1){
        Comentarios::listaComentarios(comentarios);
        int accion;
        std::cout <<"\n                     Para agregar un nuevo comentario Ingrese 1.";
        if(comentarios->getSize() != 0){
        std::cout <<"\n                     Para comentar otro comentario ingrese 2.";
        }
        std::cout <<"Para salir ingrese 0"<<std::endl;
        std::cin >>accion;
        if(accion==1){
            std::cout <<"\n                     Escriba su comentario:"<<std::endl;
            std::cin >>comentario;
            pelicula->setComentario(comentario, sesion);
        }
        if(comentarios->getSize() != 0){
            if (accion == 2){
                int numeroComentario;
                std::cout <<"Ingrese que comentario desea comentar"<<std::endl;
                std::cin >>numeroComentario;
                IntKey *key = new IntKey(numeroComentario);
                Comentarios * comentarioAcomentar =  dynamic_cast<Comentarios*>(comentarios->find(key));
                std::cout <<"\n                     Escriba su comentario"<<std::endl;
                std::cin >>comentario;
                comentarioAcomentar->setComentarios("   " + comentario, sesion);
            }
        }
        std::cout <<"Para agregar otro comentario a la pelicula ingrese 1, para salir, ingrese 0:"<<std::endl;
        std::cin>> agregarComentarios;
    }

}


void ControladorSistema::iniciarSesion(std::string nickname, std::string password){
    if(sesion!=NULL){
        std::__throw_invalid_argument("La sesion ya esta iniciada");
    }
    StringKey *userKey = new StringKey(nickname);
    Usuario* user = dynamic_cast <Usuario*>(dicUsuario->find(userKey));
    int preguntarContrasenia = 1;
    while(preguntarContrasenia == 1){
        if(user != NULL){
            if (user->getContrasenia() == password){
                this->sesion = user;

                std::cout <<"\n\n                                       Bienvenido "<< user->getNickname() <<std::endl;
                std::cout <<"                                       Presione enter para seguir.."<<std::endl;
                preguntarContrasenia = 0;
                std::getchar();
                std::getchar();
            }else{
                std::cout <<"\n\n                                       Password incorrecta"<<std::endl;
                std::cout <<"                                       Presione enter para seguir.."<<std::endl;
                std::getchar();
                std::getchar();
                preguntarContrasenia = 0;
                std::cout <<"Para ingresar una nueva contrasenia presione 1, para salir presione 0:";
                std::cin >> preguntarContrasenia;
                std::cout <<"Ingrese nuevamente la contrasenia:";
                std::cin >> password;
            }
        }else{
            std::cout <<"\n\n                                       El usuario no existe"<<std::endl;
            std::cout <<"                                       Presione enter para seguir.."<<std::endl;
            preguntarContrasenia = 0;
            std::getchar();
            std::getchar();
        }
    }

}
void ControladorSistema::altaPelicula(DtPelicula datos) {
    IKey* key = new StringKey(datos.getTitulo());
//    key = datos.getTitulo();
    Pelicula* pelicula = new Pelicula();
    pelicula->setTitulo(datos.getTitulo());
    pelicula->setUrlPoster(datos.getUrlPoster());
    pelicula->setSinopsis(datos.getSinopsis());
    dicPelicula->add(key, pelicula);
}
void ControladorSistema::infoPeliculas(){
    std::string nombrePelicula;
    int verInfoPeliculas = 1;
    int verCines;
    IIterator *it = dicPelicula->getIterator();
    while(verInfoPeliculas==1){

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
            int seleccionarCine, numeroCine;
            std::cout <<"Ingrese 1 para seleccionar un cine o 0 para salir:";
            Cine::listarCines(dicCines);
            std::cin >>seleccionarCine;
            if(seleccionarCine!=1){
                return;
            }
            std::cout << "Ingrese el numero del cine:";
            std::cin >> numeroCine;
            IntKey *keyCine = new IntKey(numeroCine);
            Cine* cine =  dynamic_cast<Cine*> (dicCines->find(keyCine));
            if(cine == nullptr){
                std::__throw_invalid_argument("El cine no existe");
            }
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
                            std::cout << new DtFuncion(
                                f->getNumero(),
                                f->getFecha(),
                                f->getHora(),
                                f->getPelicula()->getTitulo()
                            )<<std::endl;
                        }
                        ItFunciones->next();
                    }
                    SalaIterator->next();
                }
        }
    }
    std::cout << "Para ver informacion de otra pelicula ingrese 1, para salir, ingrese 0:";
    std::cin >> verInfoPeliculas;
    }
}
void ControladorSistema::listarCines(){
    if (dicCines->getSize() == 0){
        throw std::invalid_argument("No hay cines ni salas agregadas.");
    }
    Cine::listarCines(dicCines);
}

void ControladorSistema::eliminarPelicula() {
    std::string titulo;
    std::cout << "\n          \033[1;31m>>>>>>>>>>\033[0m             ELIMINAR PELÌCULA           \033[1;31m<<<<<<<<<<\033[0m                   \n " << std::endl;
    Pelicula::listarPeliculas(dicPelicula);
    std::cout << "\n                        Seleccione pelicula a eliminar: ";
    std::cin >> titulo;
    std::string confirmar;
    std::cout <<"Esta seguro que desea eliminar esta pelicula? (Y/N):";
    std::cin >> confirmar;
    if(confirmar == "n" || confirmar=="N"){
        return;
    }
    IIterator* iteratorCine = dicCines->getIterator();
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
                        colReserva->remove(reserva);
                        delete reserva;
                        itColReserva->next();
                    }
                    IKey* tituloPelicula = new StringKey(titulo);
                    dicPelicula->remove(tituloPelicula);
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
    if(pelicula != NULL) {
        dicPelicula->remove(tituloPelicula);
        delete tituloPelicula;
        delete pelicula;
    }

    //logo();
    //ver cuando no hay peliculas para eliminar o la pelicula no existe?
    std::cout << "\n        \033[1;31m>>>>>>>>>>\033[0m             PELICULA ELIMINADA             \033[1;31m<<<<<<<<<<\033[0m                   " << std::endl;
    std::cout << "\n                                    Presione enter  para continuar..." << std::endl;
    std::getchar();
    std::getchar();
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

void ControladorSistema::listarPeliculas()
{
    Pelicula::listarPeliculas(dicPelicula);
}

DtPelicula ControladorSistema::seleccionarPelicula(std::string titulo)
{
    //Corresponde al caso de uso Ver informacion de pelicula
    //IKey clave = new String(titulo);
    StringKey *clave = new StringKey(titulo);
    Pelicula *p = dynamic_cast<Pelicula *>(dicPelicula->find(clave));
    if (p != NULL)
    {
        DtPelicula peli = DtPelicula(p->getTitulo(), p->getUrlPoster(), p->getSinopsis(), p->getPuntajePromedio());
        return peli;
    }
    else
    {
        throw std::invalid_argument("Disculpa, no tenemos esa pelicula pr el momento :/");
    }
}

ICollection *ControladorSistema::verInfoAdicional(DtPelicula p)
{
    //Primero obtener el objeto pelicula
    //clave y coleccionable
    StringKey *clave = new StringKey(p.getTitulo());
    //ICollectible * peli = dicPelicula->find(clave);
    //Crear una coleccion vacia para agregar los cines
    ICollection *CinesConPeli = new List();
    //Obtenemos el iterador del diccionario de Cines
    IIterator *it = dicCines->getIterator();

    while (it->hasCurrent())
    {
        Cine *c = dynamic_cast<Cine *>(it->getCurrent());
        if (c->tienePeli(clave))
        {
           // std::cout << "                   Tiene peli" << std::endl;
            CinesConPeli->add(it->getCurrent());
        }
        it->next();
    }

    return CinesConPeli;
}

ICollection *ControladorSistema::SeleccionarCine(int numCine, std::string titulo)
{
    IntKey *k = new IntKey(numCine);
    Cine *c = dynamic_cast<Cine *>(this->dicCines->find(k));

    StringKey *tituloKey = new StringKey(titulo);
    Pelicula *peliAux = dynamic_cast<Pelicula *>(this->dicPelicula->find(tituloKey));

    ICollection *funciones = c->getFunciones(peliAux);
    return funciones;
}

void ControladorSistema::pagoDebito(int asientos, std::string banco, int funcion, int cine)
{
    //MOMENTANEAMENTE COMO NO TENEMOS UN MONTO PARA EL TOTAL, DIREMOS QUE EL PRECIO ESTA A 250 PESOS
    int total = asientos * 250;
    std::cout << "                   El total es: $" << total << std::endl;
    std::cout << "                   ¿confirmar? Y/N: ";
    char YN;
    std::cin >> YN;
    if (YN == 'Y' or YN=='y')
    {
        std::getchar();
        //El usuario confirmo, por lo tanto hay que crear la reserva
        //1 - buscar la funcion
        //2 - obtener usuario logeado
        //3 - crear reserva con la funcion
        //4 - Linkear usuario con reserva

        //1
        /*

        Iterar entre la colleccion de cines para encontrar la funcion
        Corregir, ya deberia de tener el cine - Ademas diferentes cines pueden tener funciones con el mismo id

        */

        IntKey *k = new IntKey(cine);
        Cine *c = dynamic_cast<Cine *>(dicCines->find(k));

        Funcion *f = NULL;

        IDictionary *ds = c->getSalas();

        IIterator *it = ds->getIterator();

        while (it->hasCurrent())
        {
            Sala *s = dynamic_cast<Sala *>(it->getCurrent());
            f = s->getFuncion(funcion);
            if (f != NULL)
            {
                break;
            }
            it->next();
        }

        /*
       2
       Obtener usuario logeado suponemos que el controlador tiene un usuario loageado que se puede obtener con getUsuarioLogeado
       */

        Usuario *U = this->sesion;

        /*
        3 creamos la reserva con link a funcion
        "Me parece mas razonable que cuando un usuario quiere ver su reserva, que pueda ver a que funcion es"
        */

        Reserva *RDebito = new Debito(asientos, total, banco, f);
        /*
       4
       - Linkear usuario con reserva
       */
        //Creo un setter de reserva
        ICollectible* res = dynamic_cast<ICollectible*>(RDebito);
        U->setReserva(res);

        std::cout << "                   Reserva mediante debito lista! Que disfrutes la pelicula! " << std::endl;
        std::getchar();
        std::getchar();
    }
}

void ControladorSistema::pagoCredito(int asientos, std::string financiera, int funcion)
{
    //MOMENTANEAMENTE COMO NO TENEMOS UN MONTO PARA EL TOTAL, DIREMOS QUE EL PRECIO ESTA A 250 PESOS
    int total = (asientos * 250) * 0.75; //Asumimos %15 porciento de descuentopor financiera
    std::cout << "                   El total es: $" << total << std::endl;
    std::cout << "                   ¿confirmar? Y/N: ";
    char YN;
    std::cin >> YN;
    if (YN == 'Y' or YN == 'y')
    {
        //El usuario confirmo, por lo tanto hay que crear la reserva
        //1 - buscar la funcion
        //2 - obtener usuario logeado
        //3 - crear reserva con la funcion
        //4 - Linkear usuario con reserva

        //1
        /*
        Iterar entre la colleccion de cines para encontrar la funcion
        */
        IIterator *it = this->dicCines->getIterator();
        Funcion *f;
        while (it->hasCurrent())
        {
            Cine *c = dynamic_cast<Cine *>(it->getCurrent());
            if (c->getFuncion(funcion))
            {
                f = c->getFuncion(funcion);
                break;
            }
            it->next();
        }
        /*
       2
       Obtener usuario logeado suponemos que el controlador tiene un usuario loageado que se puede obtener con getUsuarioLogeado
       */

        Usuario *U = this->getUsuarioLogeado();

        /*
        3 creamos la reserva con link a funcion
        "Me parece mas razonable que cuando un usuario quiere ver su reserva, que pueda ver a que funcion es"
        */

        Reserva *RCredito = new Credito(asientos, total, 15, financiera, f);

        /*
       4
       - Linkear usuario con reserva
       */
        //Creo un setter de reserva
        //Recordar que las reserrvas que tiene el user es una coleccion,
        //por lo tanto lo que se pasapor parametros tiene que ser un coleccionable
        //para eso lo casteamos
        U->setReserva(dynamic_cast<ICollectible *>(RCredito));

        std::cout << "                   Reserva mediante credito lista! Que disfrutes la pelicula! " << std::endl;
        std::getchar();
        std::getchar();
    }
    else
    {
        throw std::invalid_argument(" Reserva cancelada");
    }
}

void ControladorSistema::MostrarReservas(){
    ICollection* c = sesion->getReservas();
    IIterator* it = c->getIterator();

    while (it->hasCurrent())
    {
        if(dynamic_cast<Debito*>(it->getCurrent())){
            Debito* d = dynamic_cast<Debito*>(it->getCurrent());
            std::cout<<"                   Asientos debito: "<<d->getAsientos()<<std::endl;
        }else{
            Credito* cr = dynamic_cast<Credito*>(it->getCurrent());
            std::cout<<"                   Asientos credito: "<<cr->getAsientos()<<std::endl;
        }
        it->next();
    }

}

ControladorSistema::~ControladorSistema()
{
}