#ifndef PERMISSION_HPP
#define PERMISSION_HPP

#include <sstream>
#include <vector>
#include <string>
#include "user.hpp"
#include "area.hpp"
#include "date.hpp"

class Permission{
private:
  bool acesso;
  int area, dia, periodo;
  std::string monitoramento, cap;
public:
  Permission();
  bool acessoCedido(bool, int, int, int, std::string, std::string);
}

//pensei na string capacity como um atributo da classe user, que quando for criar um usuario, associá-lo a uma capacidade de acesso a
//casa. Ja areaID, recebeu valores arbitrarios, que cabe ao administrador do programa os associar a areas da casa. 
#endif
