#include "administrator.hpp"
#include "login.hpp"


int main() {
    bool stop = false;

    while (!stop) {
        std::string nomeUsuario = getUser();
        std::string senhaUsuario = getSenha();
        if (isAdmin(nomeUsuario, senhaUsuario)) {
            Administrator admin;
            admin.switchCaseAdmin(getOption());
        } 
        else if (isUser(nomeUsuario, senhaUsuario)) {
        }
        else {
            std::cout << "Usuário não cadastrado." << std::endl;
        }
    }
    return 0;
}
