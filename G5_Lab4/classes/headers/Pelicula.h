#ifndef PELICULA_H
#define PELICULA_H

#include <string>
#include <iostream>
#include "../../ICollection/interfaces/ICollectible.h"
#include "../../ICollection/interfaces/IDictionary.h"
#include "../../datatypes/headers/DtPelicula.h"
#include "../../ICollection/IntKey.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../ICollection/interfaces/IIterator.h"
#include "../../classes/headers/Comentarios.h"
#include "../../classes/headers/Puntajes.h"
class Pelicula : public ICollectible {
    private:
        std::string titulo;
        std::string urlPoster;
        std::string sinopsis;
        int puntajePromedio;
        ICollection* puntajes;
        IDictionary *comentarios;
    public:
        Pelicula();
        Pelicula(std::string titulo, std::string urlPoster, std::string sinopsis, int puntajePromedio);

        std::string getTitulo();
        std::string getUrlPoster();
        std::string getSinopsis();
        void setPuntaje(Puntajes *puntaje);
        ICollection * getPuntajes();
        void setComentario(std::string comentario, Usuario* usuario);
        void setTitulo(std::string titulo);
        void setUrlPoster(std::string urlPoster);
        void setSinopsis(std::string sinopsis);
        int getPuntajePromedio();
        int getCantidadVecesPuntuada();
        IDictionary * getComentarios();
        DtPelicula* obtenerDtPelicula();
        static void listarPeliculas(IDictionary* peliculas);

        ~Pelicula();
};

#endif /* PELICULA_H */

