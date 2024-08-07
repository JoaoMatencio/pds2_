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
    void criarUsuario(std::string nomeUsuario, std::string senhaUsuario);
    void inserirPermissoes();
    std::string get_Nome();
    std::string get_Senha();
    Area& get_Area();
    void set_Nome(std::string);
    void switchCaseUser(int);
};

#endif // USUARIO_HPP
