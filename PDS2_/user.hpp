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
    void criarUsuario(std::string, std::string);
    void inserirPermissoes();
    std::string get_Nome();
    std::string get_Senha();
    Area& get_Area();
    void set_Nome(std::string);

};

#endif
