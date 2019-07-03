#ifndef COMENTARIOS_H
#define COMENTARIOS_H
#include <iostream>
#include "../../ICollection/IntKey.h"
#include "../../ICollection/interfaces/IDictionary.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../ICollection/interfaces/ICollectible.h"

#include "Usuario.h"
class Comentarios :public ICollectible{
    private:
        std::string comentario;
        IDictionary* comentarios;
        Usuario* usuario;
        int numero;
    public:
        Comentarios(int numero, std::string comentario, Usuario *usuario);
        int getNumero();
        std::string getComentario();
        IDictionary *getComentarios();
        Usuario *getUsuario();
        static Comentarios * buscarComentario(IDictionary * comentarios, std::string idComentario);
        void setComentarios(std::string comentario, Usuario *usuario);
        void setComentario(std::string comentario);
        static void listaComentarios(IDictionary * comentarios, int nivel);
        ~Comentarios();
};

#endif /* COMENTARIOS_H */

