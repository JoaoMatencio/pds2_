#ifndef CADMIN
#define CADMIN


class administrador {

    int id;
    std::string nome;
    std::vector<user*> users;

    protected:

    public:
    int get_id();
    std::string get_nome();
    void set_vector(user& user);
    void criarListaUsers;
    user* pesquisarUsers;
    void acessarMetodosClasses(); //Qual a funcionalidade desse método?


};

#endif