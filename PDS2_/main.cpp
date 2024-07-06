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
            stop = stopOrRepeat();
        }
    }
    return 0;
}
