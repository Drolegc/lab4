#ifndef DTPELICULA_H
#define DTPELICULA_H

#include <string>
#include <iostream>
#include "../../ICollection/interfaces/ICollectible.h"

class DtPelicula : public ICollectible {
    private:
        std::string titulo;
        std::string urlPoster;
        std::string sinopsis;
        int puntajePromedio;
    public:
        DtPelicula(std::string titulo, std::string urlPoster, std::string sinopsis, int puntajePromedio);

        std::string getTitulo();
        std::string getUrlPoster();
        std::string getSinopsis();
        int getPuntajePromedio();

        void setTitulo(std::string titulo);
        void setUrlPoster(std::string urlPoster);
        void setSinopsis(std::string sinopsis);
        void setPuntajePromedio(int puntajePromedio);
        
        friend std::ostream& operator<<(std::ostream &o, DtPelicula* dtP);

        virtual ~DtPelicula();
};

#endif /* DTPELICULA_H */



