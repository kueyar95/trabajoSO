#include "Proceso.h"

Proceso::Proceso(int id, string nombre, int idSistema, vector<string> recursos) {
    this->id = id;
    this->nombre = nombre;
    this->idSistema = idSistema;
    this->recursos = recursos;
    this->estado = "Detenido"; // Por defecto, los procesos se crean en estado "Detenido"
}

// Getters
int Proceso::getId() {
    return this->id;
}

string Proceso::getNombre() {
    return this->nombre;
}

int Proceso::getIdSistema() {
    return this->idSistema;
}

string Proceso::getEstado() {
    return this->estado;
}

vector<string> Proceso::getRecursos() {
    return this->recursos;
}

// Setters
void Proceso::setId(int id) {
    this->id = id;
}

void Proceso::setNombre(string nombre) {
    this->nombre = nombre;
}

void Proceso::setIdSistema(int idSistema) {
    this->idSistema = idSistema;
}

void Proceso::setEstado(string estado) {
    this->estado = estado;
}

void Proceso::setRecursos(vector<string> recursos) {
    this->recursos = recursos;
}
