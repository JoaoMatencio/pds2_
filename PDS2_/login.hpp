#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <string>

std::string getUser();
std::string getSenha();
bool isUser(const std::string& nomeUsuario, const std::string& senhaUsuario);
int getOption();
int getOptionUser();
bool stopOrRepeat();

#endif // LOGIN_HPP
