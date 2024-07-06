#ifndef ADMIN_HPP
#define ADMIN_HPP

#include <map>
#include <string>
#include <iostream>


class Administrator {

    std::string nomeAdmin;
    std::string senhaAdmin;

    public:
    
    Administrator();
    std::string getSenha();
    std::string getNome();
    void setSenha(std::string, std::string);
    void setNome(std::string);
    
};

#endif