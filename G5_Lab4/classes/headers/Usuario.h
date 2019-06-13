#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario : ICollectible{
    private:
        std::string nickname;
        std::string urlImagen;
        std::string contrasenia;
    public:
        Usuario(std::string nickname, std::string urlImagen, std::string contrasenia);
        
        std::string getNickname();
        std::string getUrlImagen();
        std::string getContrasenia();
        
        void setNickame(std::string nickname);
        void setUrlImagen(std::string urlImagen);
        void setContrasenia(std::string contrasenia);
        
        void iniciarSesion(std::string nickname, std::string contrasenia);
        
        ~Usuario();
};

#endif /* USUARIO_H */

