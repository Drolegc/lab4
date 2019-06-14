#ifndef DTPELICULA_H
#define DTPELICULA_H
using namespace std;
class DtPelicula {
    public:
        DtPelicula(string titulo, string urlPoster, string sinopsis, int puntajePromedio);

        string getTitulo();
        string urpPoster();
        string sinopsis();
        int puntajePromedio();

        void setTitulo(std::string titulo);
        void setUrlPoster(std::string urlPoster);
        void setSinopsis(std::string sinopsis);
        void setPuntajePromedio(int puntajePromedio);

        virtual ~DtPelicula();
        
    private:
    string titulo;
    string urlPoster;
    string sinopsis;
    int puntajePromedio;

};

#endif /* DTPELICULA_H */



