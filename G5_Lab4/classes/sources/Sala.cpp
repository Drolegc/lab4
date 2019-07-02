#include "../headers/Sala.h"


Sala::Sala(int numero, int capacidad)
{
    this->numero = numero;
    this->capacidad = capacidad;
    this->dicFunciones = new OrderedDictionary();
}

ICollection *Sala::getDtFuncion(Pelicula *p)
{
    //BUSCAR LA PELICULA
    IDictionary *funciones = this->getDicFunciones();
    IIterator *it = funciones->getIterator();
    ICollection* col_funciones = new List();

    while (it->hasCurrent())
    {
        Funcion *f = dynamic_cast<Funcion *>(it->getCurrent());
        //Fecha actual para calcular las funciones antes de la fecha determinada
        
        ISistema *controladorSistema = Fabrica::getISistema();

        DtFecha *fecha = controladorSistema->getSystemDate();
        DtHora *hora = controladorSistema->getSystemHour();
        //this->anio + this->mes*100 + this->dia;
        int fecha_actual = fecha->getAnio() + fecha->getMes() * 100 + fecha->getDia();
        DtFecha fechaFuncion = f->getFecha();
        int fecha_funcion = fechaFuncion.getAnio() + fechaFuncion.getMes() * 100 + fechaFuncion.getDia();

        int hora_actual = hora->getHora()*100 + hora->getMinutos();
        DtHora horaFuncion = f->getHora();
        int hora_funcion = horaFuncion.getHora()*100 + horaFuncion.getMinutos();


        if (fecha_actual*1000+hora_actual < fecha_funcion*1000+hora_funcion)
        {
            if (f->tienePeli(p))
            {
                DtFuncion *dtf = new DtFuncion(f->getNumero(), f->getFecha(), f->getHora(), p->getTitulo());
                col_funciones->add(dtf);
            }
        }
        it->next();
    }

    return col_funciones;
}

Funcion *Sala::getFuncion(int id)
{
    //Chequear si tenemos esa funcion, si no devolver NULL
    IntKey *k = new IntKey(id);
    ICollectible *f = dicFunciones->find(k);
    if (f != NULL)
    {
        return dynamic_cast<Funcion *>(f);
    }
    else
    {
        return NULL;
    }
}

int Sala::getNumero()
{
    return this->numero;
}

int Sala::getCapacidad()
{
    return this->capacidad;
}

IDictionary *Sala::getDicFunciones()
{
    return this->dicFunciones;
}

void Sala::setNumero(int numero)
{
    this->numero = numero;
}

void Sala::setCapacidad(int capacidad)
{
    this->capacidad = capacidad;
}
Sala::~Sala()
{
}
void Sala::listarSalas(IDictionary *salas)
{
    IIterator *it = salas->getIterator();
    while (it->hasCurrent())
    {
        Sala *currentSala = dynamic_cast<Sala *>(it->getCurrent());
        std::cout << "                      " << new DtSala(currentSala->getCapacidad(), currentSala->getNumero()) << std::endl;
        it->next();
    }
    delete it;
}
