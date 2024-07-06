#include "administrator.hpp"
#include "area.hpp"
#include "login.hpp"
#include "user.hpp"
#include <map>
#include <iostream>
#include <string>

int main() {
    bool stop = false;
    std::map<std::string, User> usuariosConfigurados;

    while (!stop) {
        std::string nomeUsuario = getUser();
        std::string senhaUsuario = getSenha();
        if (isAdmin(nomeUsuario, senhaUsuario)) {
            Administrator admin;
            admin.switchCaseAdmin(getOption(), usuariosConfigurados);
        } else {
            // Implementação do código para conferencia de autorizações e acessos efetivos.
        }
    }
    return 0;
}
