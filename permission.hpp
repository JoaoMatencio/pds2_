#ifndef PERMISSION_HPP
#define PERMISSION_HPP

#include <sstream>
#include <vector>
#include <string>

class Permission{
private:
  bool acesso;
  std::string monitoramento;
public:
  Permission();
  alterarAtributos();
  bool acessoCedido(bool, int, int, std::string, std::string);
  std::string monitamentoPermission(std:: string, int, int, std::string, std::string);
}

#endif
