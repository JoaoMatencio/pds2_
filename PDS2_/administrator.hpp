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
    std::string get_Senha();
    std::string get_Nome();
    void set_Senha(std::string, std::string);
    void set_Nome(std::string);
    
};

#endif