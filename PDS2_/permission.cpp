#include <ctime>
#include "permission.hpp"

class User;


void Permission::inserirAutorizacao(Date& d){

  std::map<int, Date&>::iterator it;
  d.configuraAutorizacao();                                                    
  it = autorizacaoSemanal.find(d.getAc().diaSemana);
  
  if(it == autorizacaoSemanal.end()){
    autorizacaoSemanal.insert(std::pair<int, Date&> (d.getAc().diaSemana, d));
  } else {
    std::cout << "Autorização já inserida.\n"
                "Escolha a opção \"Modificar autorização.\"" << std::endl; 
  }
}

void Permission::alterarAutorizacao(){
  std::map<int, Date&>::iterator it;
  int numeroEscolhido;
  std::cout << "Selecione o dia da semana que deseja alterar:\n"
              "1 = Domingo \n"
              "2 = Segunda-feira \n"
              "3 = Terça-feira \n"
              "4 = Quarta-feira \n"
              "5 = Quinta-feira \n"
              "6 = Sexta-feira \n"
              "7 = Sábado \n";
  std::cin >> numeroEscolhido;
  it = autorizacaoSemanal.find(numeroEscolhido);
  
  if(it != autorizacaoSemanal.end()){

    std::cout << "Selecione entre as opções para alterar as permissões:\n"
                "0 = Permissão Negada\n"
                "1 = Permissão Concedida\n";
    int autorizacao;
    std::cout << "Autorização atual no acesso na madrugada (00:00 às 05:59): " << it -> second.getAc().periodo.madrugada << std::endl;
    std::cout << "Qual a nova permissão para esse período?" << std::endl;
    std::cin >> autorizacao;
    it -> second.set_aC(autorizacao, 0);

    std::cout << "Autorização atual no acesso da manhã (06:00 às 11:59): " << it -> second.getAc().periodo.manha << std::endl;
    std::cout << "Qual a nova permissão para esse período?" << std::endl;
    std::cin >> autorizacao;
    it -> second.set_aC(autorizacao, 1);

    std::cout << "Autorização atual no acesso da tarde (12:00 às 17:59): " << it -> second.getAc().periodo.tarde << std::endl;
    std::cout << "Qual a nova permissão para esse período?" << std::endl;
    std::cin >> autorizacao;
    it -> second.set_aC(autorizacao, 2);

    std::cout << "Autorização atual no acesso da noite (18:00 às 23:59): " << it -> second.getAc().periodo.noite << std::endl;
    std::cout << "Qual a nova permissão para esse período?" << std::endl;
    std::cin >> autorizacao;
    it -> second.set_aC(autorizacao, 3);

  } else {
    
    std::cout << "Autorização ainda não inserida.\n"
                "Escolha a opção \"Inserir autorização.\"" << std::endl; 
  }
}

void Permission::imprimirAutorizacoes(){
  std::map<int, Date&>::iterator it;
  for(it = autorizacaoSemanal.begin(); it != autorizacaoSemanal.end(); it++){
    std::cout << it -> first << ": " << std::endl;
    std::cout << "Madrugada: " << retornaAutorizacao(it -> second.getAc().periodo.madrugada) << std::endl;
    std::cout << "Manha: " << retornaAutorizacao(it -> second.getAc().periodo.manha) << std::endl;
    std::cout << "Tarde: " << retornaAutorizacao(it -> second.getAc().periodo.tarde) << std::endl;
    std::cout << "Noite: " << retornaAutorizacao(it -> second.getAc().periodo.noite) << std::endl;
  }
}

std::string Permission::retornaAutorizacao(bool autorizacao){
  switch(autorizacao){
    case true:
      return "Autorizado.";
    case false:
      return "Não autorizado";
  }
}

void Permission::autorizaAcesso(){

    int diaSemana = 0;
    std::string mensagem = " ";
    std::time_t horaSistema = std::time(nullptr);
    std::tm* horaLocal = std::localtime(&horaSistema);

    diaSemana = horaLocal -> tm_wday;

    std::map<int, Date&>::iterator it;

    it = autorizacaoSemanal.find(diaSemana + 1);
    
    if(horaLocal -> tm_hour >= 00 && horaLocal -> tm_hour < 06) {
      mensagem = retornaAutorizacao(it -> second.getAc().periodo.madrugada);
      std::cout << mensagem << std::endl;

    } else if (horaLocal -> tm_hour >= 06 && horaLocal -> tm_hour < 12) {
      mensagem = retornaAutorizacao(it -> second.getAc().periodo.manha);
      std::cout << mensagem << std::endl;

    } else if (horaLocal -> tm_hour >= 12 && horaLocal -> tm_hour < 18) {
      mensagem = retornaAutorizacao(it -> second.getAc().periodo.madrugada);
      std::cout << mensagem << std::endl;

    } else if (horaLocal -> tm_hour >= 18 && horaLocal -> tm_hour < 00) {
      mensagem = retornaAutorizacao(it -> second.getAc().periodo.madrugada);
      std::cout << mensagem << std::endl;

    }

}
