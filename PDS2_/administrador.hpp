#ifndef CADMIN
#define CADMIN

#include <map>
#include <string>
#include <iostream>

class Administrador {

    int id;
    std::string nome;
    std::map<std::string, user*> users;

    protected:

    public:
    int get_id();
    std::string get_nome();
    void incluiUsuario(user& user);
    void criarListaUsers();
    void pesquisarUsers();
    void acessarMetodosClasses(); //Qual a funcionalidade desse método?


};

#endif