#include "ControladorSistema.h"
#include "../../ICollection/StringKey.h"

ControladorSistema::ControladorSistema()
{
    colReserva = new OrderedDictionary();
    dicUsuario = new OrderedDictionary();
    dicPelicula = new OrderedDictionary();
    dicCines = new OrderedDictionary();
    //usuario predeterminado
    U = new Usuario("Pepe","LinkImg","alfanumerica",false);
}

void ControladorSistema::altaFuncion(std::string titulo, int numeroCine, int numeroSala, DtFecha fecha, DtHora hora)
{

    /********************* Obtengo la película específica *********************/

    IKey *keyPelicula = new StringKey(titulo);
    Pelicula *pelicula = (Pelicula *)dicPelicula->find(keyPelicula);
    delete keyPelicula;

    /*********************** Obtengo el cine específico ***********************/

    IKey *keyCine = new IntKey(numeroCine);
    Cine *cine = (Cine *)dicCines->find(keyCine);
    delete keyCine;

    /*********************** Obtengo la sala específica ***********************/

    IKey *keySala = new IntKey(numeroSala);
    IDictionary *dicSalas = cine->getSalas();
    Sala *sala = (Sala *)dicSalas->find(keySala);
    delete keySala;

    /**************************** Agrego la función ****************************/

    IDictionary *dicFunciones = sala->getDicFunciones();
    IIterator *it = dicFunciones->getIterator();
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
    return this->U;
}

void ControladorSistema::altaCine(DtDireccion direccion)
{
    int numero;
    std::cout << "Ingrese el numero del cine:";
    std::cin >> numero;
    Cine *nuevocine = new Cine(new DtCine(direccion, numero));
    int agregarmas = 1;
    int capacidadSala;
    int numeroSala;
    while (agregarmas != 0)
    {
        std::cout << "Ingrese la capacidad:";
        std::cin >> capacidadSala;
        std::cout << "Ingrese el numero de sala:";
        std::cin >> numeroSala;
        IntKey *keysala = new IntKey{numeroSala};
        Sala *sala = new Sala(capacidadSala, numeroSala);
        nuevocine->getSalas()->add(keysala, sala);
        std::cout << "Para salir presione 0:";
        std::cin >> agregarmas;
        if (agregarmas == 0)
        {
            break;
        }
    }
    IntKey *keyCine = new IntKey(numero);
    dicCines->add(keyCine, nuevocine);
}

void ControladorSistema::comentarPelicula()
{
    int numpelicula;
    std::string comentario;
    Pelicula::listarPeliculas(dicPelicula);
    std::cout << "Elija que pelicula va a comentar:";
    std::cin >> numpelicula;
    IntKey *key = new IntKey(numpelicula);
    Pelicula *pelicula = dynamic_cast<Pelicula *>(dicPelicula->find(key));
    std::cout << "Escriba su comentario" << std::endl;
    std::cin >> comentario;
    pelicula->setComentario(comentario);
}

void ControladorSistema::altaPelicula(DtPelicula datos)
{
    IKey *key = new StringKey(datos.getTitulo());
    //    key = datos.getTitulo();
    Pelicula *pelicula = new Pelicula();
    pelicula->setTitulo(datos.getTitulo());
    pelicula->setUrlPoster(datos.getUrlPoster());
    pelicula->setSinopsis(datos.getSinopsis());
    pelicula->setPuntajePromedio(datos.getPuntajePromedio());
    dicPelicula->add(key, pelicula);
}

void ControladorSistema::listarCines()
{
    Cine::listarCines(dicCines);
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
            std::cout << "Tiene peli" << std::endl;
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
    std::cout << "El total es: $" << total << std::endl;
    std::cout << "¿Confirmar? Y/N" << std::endl;
    char YN;
    std::cin >> YN;
    if (YN == 'Y')
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
        
        Usuario *U = this->U;

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

        std::cout << "Reserva mediante debito lista! Que disfrutes la pelicula! " << std::endl;
    }
}

void ControladorSistema::pagoCredito(int asientos, std::string financiera, int funcion)
{
    //MOMENTANEAMENTE COMO NO TENEMOS UN MONTO PARA EL TOTAL, DIREMOS QUE EL PRECIO ESTA A 250 PESOS
    int total = (asientos * 250) * 0.75; //Asumimos %15 porciento de descuentopor financiera
    std::cout << "El total es: $" << total << std::endl;
    std::cout << "¿Confirmar? Y/N" << std::endl;
    char YN;
    std::cin >> YN;
    if (YN == 'Y')
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

        std::cout << "Reserva mediante credito lista! Que disfrutes la pelicula! " << std::endl;
    }
    else
    {
        throw std::invalid_argument("Reserva cancelada");
    }
}

void ControladorSistema::MostrarReservas(){
    ICollection* c = U->getReservas();
    IIterator* it = c->getIterator();
    
    while (it->hasCurrent())
    {
        if(dynamic_cast<Debito*>(it->getCurrent())){
            Debito* d = dynamic_cast<Debito*>(it->getCurrent());
            std::cout<<"Asientos debito: "<<d->getAsientos()<<std::endl;
        }else{
            Credito* cr = dynamic_cast<Credito*>(it->getCurrent());
            std::cout<<"Asientos credito: "<<cr->getAsientos()<<std::endl;
        }
        it->next();
    }
    
}

ControladorSistema::~ControladorSistema()
{
}