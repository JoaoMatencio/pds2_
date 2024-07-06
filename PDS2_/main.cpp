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
            User user;
            user.switchCaseUser(getOptionUser());
        }
        
        else {
            std::cout << "Usuário não cadastrado." << std::endl;
            std::cout << "Deseja tentar novamente? (s/n)" << std::endl;
            char resposta;
            std::cin >> resposta;
            if (resposta == 'n') {
                stop = true;
            }
        }
    }
    return 0;
}
