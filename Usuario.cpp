// Usuario.cpp
#include "Usuario.h"
using namespace std;


Usuario::Usuario(int id, string nombre, string tipo, int nivelAcceso)
    : id(id), nombre(nombre), tipo(tipo), nivelAcceso(nivelAcceso) {}

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