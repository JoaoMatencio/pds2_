#include "administrator.hpp"
#include "login.hpp"
#include "user.hpp"


int main() {
    bool stop = false;

    while (!stop) {
        std::string nomeUsuario = getUser();
        std::string senhaUsuario = getSenha();
        std::map<std::string, User> usuariosConfigurados;
        if (isAdmin(nomeUsuario, senhaUsuario)) {
            Administrator admin;
            admin.switchCaseAdmin(getOption(), usuariosConfigurados);
        } 
        else if (isUser(nomeUsuario, senhaUsuario)) {
            std::cout << "Usuário cadastrado." << std::endl;
        }
        else {
            std::cout << "Usuário não cadastrado." << std::endl;
        }
    }
    return 0;
}
