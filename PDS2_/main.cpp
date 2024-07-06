#include "administrator.hpp"
#include "login.hpp"
#include "user.hpp"

int main() {
    bool stop = false;
    std::map<std::string, User> usuariosConfigurados;

    while (!stop) {
        std::string nomeUsuario = getUser();
        std::string senhaUsuario = getSenha();
        if (isAdmin(nomeUsuario, senhaUsuario)) {
            Administrator admin;
            admin.switchCaseAdmin(getOption(), usuariosConfigurados);
        } 
        else if (usuariosConfigurados.find(nomeUsuario) != usuariosConfigurados.end()) 
        {   
            // Implementação do código para conferencia de autorizações e acessos efetivos.
        }
        else {
            std::cout << "Usuário não cadastrado." << std::endl;
        }
    }
    return 0;
}
