#include "administrador.hpp"

int Administrador::get_id(){
    return id;
}

std::string Administrador::get_nome(){
    return nome;
}

void Administrador::incluiUsuario(user& user){
    users.insert(std::pair<std::string, user> (user._nome, user));
}

void Administrador::pesquisarUsers(std::string nome){
    std::map<std::string, user*>::iterator it;
    it = users.find(nome);
}



