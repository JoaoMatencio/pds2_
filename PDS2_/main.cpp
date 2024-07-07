#include "administrator.hpp"
#include "login.hpp"
#include "user.hpp"




int main() {
    bool stop = false;
    
    std::map<std::string, User> usuariosConfigurados;
    Administrator admin;

    while (!stop) {
        std::string nomeUsuario = " ";
        std::string senhaUsuario = " ";
        nomeUsuario = getUser();
        senhaUsuario = getSenha();
        

        if (noFindAdmin(nomeUsuario, usuariosConfigurados) && admin.isAdmin(nomeUsuario, senhaUsuario)) {
            
            admin.switchCaseAdmin(getOption(), usuariosConfigurados);

        }

        else if (findUser(nomeUsuario, senhaUsuario, usuariosConfigurados)) {

            returnUser(nomeUsuario, usuariosConfigurados).switchCaseUser(getOptionUser());

        }
        
        else {

            stop = stopOrRepeat();
            std::cin.ignore();
            
        }
    }
    return 0;
}
