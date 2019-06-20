#include "ControladorSistema.h"
#include "../../ICollection/StringKey.h"

ControladorSistema::ControladorSistema()
{
    colReserva = new OrderedDictionary();
    dicUsuario = new OrderedDictionary();
    dicPelicula = new OrderedDictionary();
    dicCines = new OrderedDictionary();
}

void ControladorSistema::altaFuncion(DtFecha fecha, DtHora hora)
{
    //    std::string titulo;
    //    std::cout << "Seleccione una película de la siguiente lista: ";
    //    ControladorSistema::listarPeliculas();
    //    std::cin >> titulo;
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
            CinesConPeli->add(it->getCurrent());
        }
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

void ControladorSistema::pagoDebito(int asientos, std::string banco, int funcion)
{
    //MOMENTANEAMENTE COMO NO TENEMOS UN MONTO PARA EL TOTAL, DIREMOS QUE EL PRECIO ESTA A 250 PESOS
    int total = asientos * 250;
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
       
       Reserva* RDebito = new Debito(asientos,total,banco,f);

       /*
       4 
       - Linkear usuario con reserva
       */
      //Creo un setter de reserva
      U->setReserva(RDebito);

      std::cout<<"Reserva mediante debito lista! Que disfrutes la pelicula! "<<std::endl;

    }
}

ControladorSistema::~ControladorSistema()
{
}