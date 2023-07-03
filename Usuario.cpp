// Usuario.cpp
#include "Usuario.h"
using namespace std;


int Usuario::getId() {
    return id;
}

string Usuario::getNombre() {
    return nombre;
}

void Usuario::setNombre(string nombre) {
    this->nombre = nombre;
}

string Usuario::getTipo() {
    return tipo;
}

void Usuario::setTipo(string tipo) {
    this->tipo = tipo;
}

int Usuario::getNivelAcceso() {
    return nivelAcceso;
}

void Usuario::setNivelAcceso(int nivelAcceso) {
    this->nivelAcceso = nivelAcceso;
}