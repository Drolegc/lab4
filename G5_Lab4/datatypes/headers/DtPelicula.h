#ifndef DTPELICULA_H
#define DTPELICULA_H

#include <string>

class DtPelicula {
    private:
        std::string titulo;
        std::string urlPoster;
        std::string sinopsis;
        int puntajePromedio;
    public:
        DtPelicula(std::string titulo, std::string urlPoster, std::string sinopsis);

        std::string getTitulo();
        std::string getUrlPoster();
        std::string getSinopsis();
        int getPuntajePromedio();

        void setTitulo(std::string titulo);
        void setUrlPoster(std::string urlPoster);
        void setSinopsis(std::string sinopsis);
        void setPuntajePromedio(int puntajePromedio);

        virtual ~DtPelicula();
};

#endif /* DTPELICULA_H */



