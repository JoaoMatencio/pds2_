#include "usuario.hpp"

// Métodos
user::user(int id, std::string nome) : userID(id), _nome(nome) {}

void user::adicionarArea(area* novaArea) {
    areas.insert(std::make_pair(novaArea->get_id(), novaArea));
}