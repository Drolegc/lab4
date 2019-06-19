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
#include "Comentarios.h"
class Pelicula : public ICollectible {
    private:
        std::string titulo;
        std::string urlPoster;
        std::string sinopsis;
        int puntajePromedio;
        IDictionary *comentarios;
    public:
        Pelicula();
        Pelicula(std::string titulo, std::string urlPoster, std::string sinopsis, int puntajePromedio);

        std::string getTitulo();
        std::string getUrlPoster();
        std::string getSinopsis();
        int getPuntajePromedio();
        void setComentario(std::string comentario);
        void setTitulo(std::string titulo);
        void setUrlPoster(std::string urlPoster);
        void setSinopsis(std::string sinopsis);
        void setPuntajePromedio(int puntajePromedio);
        IDictionary * getComentarios();
        DtPelicula* obtenerDtPelicula();
        static void listarPeliculas(IDictionary* peliculas);

//        void eliminarPelicula(std::string titulo);
//        DtPelicula verInfoAdicional();
//        DtPelicula seleccionarPelicula(std::string titulo);

        ~Pelicula();
};

#endif /* PELICULA_H */

