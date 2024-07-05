#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>

#include "area.hpp"
#include "permission.hpp"
#include "date.hpp"


class User {
private:
    
    std::string usuario;
    std::string senha;
    Area _area;

public:
    User& criarUsuario(std::string, std::string, std::string, Permission&);
    std::string get_Usuario();
    std::string get_Senha();
    Area& get_Area();
    User& inserirPermissoes();

};

#endif
