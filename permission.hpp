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
  bool acessoCedido(int, int, int, std::string);
}

//pensei na string capacity como um atributo da classe user, que quando for criar um usuario, associá-lo a uma capacidade de acesso a
//casa. Ja areaID, recebeu valores arbitrarios, que cabe ao administrador do programa os associar a areas da casa. 
#endif
