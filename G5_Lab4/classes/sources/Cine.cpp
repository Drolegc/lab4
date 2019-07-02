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

void Cine::CinesConPeli(ICollection *c)
{
    IIterator *it = c->getIterator();
    if (!it->hasCurrent())
    {
        std::cout << "No tenemos cines :/" << std::endl;
        throw std::invalid_argument("");
    }
    while (it->hasCurrent())
    {
        Cine *cine = dynamic_cast<Cine *>(it->getCurrent());
        std::cout << "Id del cine: " << cine->getNumero() << std::endl;
        
        it->next();
    }
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
    IIterator *it = dicSalas->getIterator();

    while (it->hasCurrent())
    {
        Sala *S = dynamic_cast<Sala *>(it->getCurrent());

        ICollection *col_funciones = S->getDtFuncion(p);
        IIterator* f_it = col_funciones->getIterator();
        while(f_it->hasCurrent()){
            
            funciones->add(f_it->getCurrent());
            f_it->next();
            
        }
        
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

        Sala *S = dynamic_cast<Sala *>(it->getCurrent());

        f = S->getFuncion(id_funcion);

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
    return dicSalas;
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