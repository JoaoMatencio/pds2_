#ifndef USUARIOS_HPP
#define USUARIOS_HPP

#include <string>
#include <vector>
#include <map>

class user {
private:
    int userID;
    std::string _nome;
    std::map<int, area*> areas;

public:
    // Métodos
    user(int, std::string) : userID(id), _nome(nome){}
    void adicionarArea(&area);

};

#endif // USUARIO_HPP