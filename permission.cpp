#include "permission.hpp"
#include "user.hpp"
#include "area.hpp"
#include "date.hpp"

Permission::Permission() acesso(false), monitoramento("") {}


alterarAtributos(){

}

bool permission::acessoCedido(bool acesso, int userID, int areaID, std::string diaSemana, std::string periodoDia){
  
}

std::string permission::monitamentoPermission(std::string monitoramento, int userID, int areaID, std::string diaSemana, std::string periodoDia){
  std::ostringstream aux;
  aux << "UserID: " << userID << "AreaID: " << areaID << "Dia :" << diaSemana << "Horario :" << periodoDia;
  monitoramento = aux;
  return monitoramento;
}
