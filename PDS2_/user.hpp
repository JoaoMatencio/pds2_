#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include "area.hpp"

class User {
private:
    
    std::string usuario;
    std::string senha;
    Area _area;

public:
    User();
    void criarUsuario(std::string, std::string);
    void inserirPermissoes();
    std::string getNome();
    std::string getSenha();
    Area& getArea();
    void setNome(std::string);

};

#endif
