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
  std::string monitoramento, cap;
public:
  Permission();
  int area = Area.areaID;
  int dia = Schedule.WeekDay;
  int periodo = Schedule.PeriodDay;
  std::string cap = User.capacity;
  bool acessoCedido(bool acesso, int area, int dia, int periodo, std::string capacity, std::string& monitoramento);
}

//pensei na string capacity como um atributo da classe user, que quando for criar um usuario, associá-lo a uma capacidade de acesso a
//casa. Ja areaID, recebeu valores arbitrarios, que cabe ao administrador do programa os associar a areas da casa. 
#endif
