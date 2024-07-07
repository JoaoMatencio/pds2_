#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <string>
#include <map>
#include "user.hpp"

std::string getUser();
std::string getSenha();
int getOption();
int getOptionUser();
bool noFindAdmin(const std::string& nomeUsuario, std::map<std::string, User>& usuariosConfigurados);
bool findUser(const std::string& nomeUsuario, const std::string& senhaUsuario, std::map<std::string, User>& usuariosConfigurados);
User& returnUser(std::string nomeUsuario, std::map<std::string, User> usuariosConfigurados);
bool stopOrRepeat();

#endif // LOGIN_HPP
