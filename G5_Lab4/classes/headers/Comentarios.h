#ifndef COMENTARIOS_H
#define COMENTARIOS_H
#include <iostream>
#include "../../ICollection/IntKey.h"
#include "../../ICollection/interfaces/IDictionary.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../ICollection/interfaces/ICollectible.h"
class Comentarios :public ICollectible{
    private:
        std::string comentario;
        IDictionary* comentarios;
        int numero;
    public:
        Comentarios(int numero, std::string comentario);
        int getNumero();
        std::string getComentario();
        IDictionary *getComentarios();
        void setComentarios(std::string comentario);
        void setComentario(std::string comentario);
        static void listaComentarios(IDictionary * comentarios);
        ~Comentarios();
};

#endif /* COMENTARIOS_H */

