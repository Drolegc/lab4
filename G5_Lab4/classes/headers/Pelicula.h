#ifndef PELICULA_H
#define PELICULA_H

#include <string>
#include "../../ICollection/interfaces/ICollectible.h"
#include "../../datatypes/headers/DtPelicula.h"

class Pelicula : public ICollectible {
    private:
        std::string titulo;
        std::string urlPoster;
        std::string sinopsis;
        int puntajePromedio;
    public:
        Pelicula(std::string titulo, std::string urlPoster, std::string sinopsis);
        
        std::string getTitulo();
        std::string getUrlPoster();
        std::string getSinopsis();
        int getPuntajePromedio();
        
        void setTitulo(std::string titulo);
        void setUrlPoster(std::string urlPoster);
        void setSinopsis(std::string sinopsis);
        void setPuntajePromedio(int puntajePromedio);
        
//        ICollection* listarPeliculas();
//        void eliminarPelicula(std::string titulo);
//        DtPelicula verInfoAdicional();
//        DtPelicula seleccionarPelicula(std::string titulo);
        
        ~Pelicula();
};

#endif /* PELICULA_H */

