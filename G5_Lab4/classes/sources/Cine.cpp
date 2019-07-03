#include "../headers/Cine.h"
#include <stdexcept>

Cine::Cine(DtCine *datacine)
{
    this->numero = datacine->getNumero();
    this->direccion = datacine->getDireccion();
    this->dicSalas = new OrderedDictionary();
    this->dicPeliculas = new OrderedDictionary();
}

Cine::Cine(std::string calle, int num, std::string ciudad, int id) : direccion(calle, num, ciudad)
{
    this->numero = id;
}

void Cine::addPelicula(Pelicula *p)
{
    StringKey *k = new StringKey(p->getTitulo());
    dicPeliculas->add(k, p);
}

void Cine::listarCines(IDictionary *cines)
{
    IIterator *it = cines->getIterator();
    while (it->hasCurrent())
    {
        Cine *currentCine = dynamic_cast<Cine *>(it->getCurrent());
        std::cout <<"              " << new DtCine(currentCine->getDireccion(), currentCine->getNumero());
        IDictionary *salas = currentCine->getSalas();
        Sala::listarSalas(salas);
        it->next();
    }
    delete it;
}

ICollection *Cine::getFunciones(Pelicula *p)
{
    //CREO UNA COLLECCION DE FUNCIONES QUE TIENEN LA PELICULA DESEADA
    ICollection *funciones = new List();
    IIterator *it = this->dicSalas->getIterator();
    while (it->hasCurrent())
    {
        Sala *S = dynamic_cast<Sala *>(it->getCurrent());
        DtFuncion *dtf = S->getDtFuncion(p);
        funciones->add(dynamic_cast<ICollectible *>(dtf));
        it->next();
    }
    return funciones;
}

Funcion *Cine::getFuncion(int id_funcion)
{
    /* Obetener la funcion deseada  */
    Funcion *f;
    IIterator *it = dicSalas->getIterator();

    while (it->hasCurrent())
    {
        //std::cout << "Pasad444as" << std::endl;
        Sala *S = dynamic_cast<Sala *>(it->getCurrent());
        //std::cout << "Obrengo sala";
        //Si casteo como Cine logra pasar, o al menos mostrar el mensaje anterior
        f = S->getFuncion(id_funcion);
        //std::cout << "Obtengo la funcion";
        if (f != NULL)
        {
            return f;
        }
        std::cout << S->getNumero();

        it->next();
    }
    return NULL;
}

DtDireccion Cine::getDireccion()
{
    return this->direccion;
}
IDictionary *Cine::getSalas()
{
    return this->dicSalas;
}
int Cine::getNumero()
{
    return this->numero;
}

void Cine::setDireccion(DtDireccion direccion)
{
    this->direccion = direccion;
}

void Cine::setNumero(int numero)
{
    this->numero = numero;
}

bool Cine::tienePeli(StringKey *k)
{
    return dicPeliculas->member(k);
}

Cine::~Cine()
{
}