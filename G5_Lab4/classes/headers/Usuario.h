#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "../../ICollection/interfaces/ICollectible.h"

class Usuario : public ICollectible {
    private:
        std::string nickname;
        std::string urlImagen;
        std::string contrasenia;
        bool isAdmin;
    public:
        Usuario(std::string nickname, std::string urlImagen, std::string contrasenia, bool isAdmin);
        
        std::string getNickname();
        std::string getUrlImagen();
        std::string getContrasenia();
        bool getIsAdmin();
        
        void setNickame(std::string nickname);
        void setUrlImagen(std::string urlImagen);
        void setContrasenia(std::string contrasenia);
        void setIsAdmin(bool estado);
        
        void iniciarSesion(std::string nickname, std::string contrasenia);
        
        ~Usuario();
};

#endif /* USUARIO_H */

