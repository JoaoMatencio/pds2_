#include "administrator.hpp"
#include "user.hpp"


Administrator::Administrator(){
    nomeAdmin = "admin";
    senhaAdmin = "admin";
}

std::string Administrator::get_Nome(){
    return nomeAdmin;
}

std::string Administrator::get_Senha(){
    return senhaAdmin;
}

void Administrator::set_Nome(std::string novoNome){
    this -> nomeAdmin = novoNome;
}

void Administrator::set_Senha(std::string novaSenha){
    this -> senhaAdmin = novaSenha;
}

void Administrator::inserirUsuario(User& user){
    usuariosPermissoes.insert(std::pair<std::string, Area&> (user.get_Usuario(), user.get_Area()));
}

void Administrator::imprimirUsuarios(){
    int idUsuario = 1;
    std::map<std::string, Area&>::iterator it;
    for(it = usuariosPermissoes.begin(); it != usuariosPermissoes.end(); it++){
        std::cout << idUsuario << " - " << it -> first << std::endl;
        idUsuario += 1;
    }
}

void Administrator::editarPermissoes(){
    std::map<std::string, Area&>::iterator it;
    int idUsuario = 0;
    std::string nomeUsuario;

    std::cout << "Escolha um usuário para editar as permissões: " << std::endl;
    imprimirUsuarios();
    std::cin >> idUsuario;
    std::advance(it, idUsuario - 1);
    it -> second.editarAutorizacoesArea();
}


