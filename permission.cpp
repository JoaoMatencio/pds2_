#include "permission.hpp"
#include "user.hpp"
#include "area.hpp"
#include "date.hpp"

Permission::Permission() : acesso(0), monitoramento("") {}

bool permission::acessoCedido(bool acesso, int areaID, int WeekDay, int PeriodDay, std::string capacity, std::string *monitoramento){

  while(acesso == 0){
    switch(capacity){

      case "PARENT":
      acesso = 1;
      return acesso;
      break;

      case "TEEN":
      //coloquei um areaID arbitrario como 15, que seria o escritorio, por exemplo.
      if(areaID != 15){
        acesso = 1
        return acesso
      }
      else{
        return acesso;
      }
      break;

      case "CHILDREN":
        bool aux = 1;
        switch(areaID){

          // num possivel caso de sala de jogos
          case 5:
          if(PeriodDay == 1){
          aux = 0;
          }
          break;

          // casa de maquinas
          case 7:
          aux = 0;
          break;

          //exterior da casa
          case 10:
          if(PeriodDay == 1){
            aux = 0;
          }
          break;

          case 15:
          aux = 0;
          break;

          default:
          break;
       }

      acesso = aux;
      return acesso;
      break;

      case "HOUSEKEEPER":
      if(WeekDay == 3 && PeriodDay == 8){
        acesso = 1;
        return acesso;
      }
      else{
        return acesso;
      }
      break;

      default:
      break;
  }
}
  std::ostringstream aux;
  aux << "UserID: " << userID << "AreaID: " << areaID << "Dia :" << WeekDay << "Horario :" << PeriodDay << "Acesso" << acesso;
  monitoramento = aux;
}
