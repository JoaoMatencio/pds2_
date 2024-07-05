#ifndef ADMIN_HPP
#define ADMIN_HPP

#include <map>
#include <string>
#include <iostream>
#include "user.hpp"
#include "area.hpp"
#include "permission.hpp"

class Administrator {

    std::string nomeAdmin;
    std::string senhaAdmin;
    std::map<std::string, Area&> usuariosPermissoes;

    public:

    void inserirUsuario(User&);
    void imprimirUsuarios();
    void editarPermissoes();
    std::string get_Senha();
    std::string get_Nome();
    void set_Senha(std::string);
    void set_Nome(std::string);
    
};

#endif