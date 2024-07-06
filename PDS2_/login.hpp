#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <string>

std::string getUser();
std::string getSenha();
bool isAdmin(const std::string& nomeUsuario, const std::string& senhaUsuario);
bool isUser(const std::string& nomeUsuario, const std::string& senhaUsuario);
int getOption();

#endif // LOGIN_HPP
