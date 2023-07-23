#include"../include/Proceso.h"

Proceso::Proceso(int id, string nombre, vector<string> recursos, function<void()> funcion, int nivelPrivilegioRequerido)
    : id(id), nombre(nombre), recursos(recursos), funcion(funcion), nivelPrivilegioRequerido(nivelPrivilegioRequerido) {
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

string Proceso::getEstado() {
    return this->estado;
}

vector<string> Proceso::getRecursos() {
    return this->recursos;
}

function<void()> Proceso::getFuncion() {
    return this->funcion;
}

int Proceso::getNivelPrivilegioRequerido() {
    return this->nivelPrivilegioRequerido;
}


// Setters
void Proceso::setId(int id) {
    this->id = id;
}

void Proceso::setNombre(string nombre) {
    this->nombre = nombre;
}

void Proceso::setEstado(string estado) {
    this->estado = estado;
}

void Proceso::setRecursos(vector<string> recursos) {
    this->recursos = recursos;
}
void Proceso::setFuncion(function<void()> funcion) {
    this->funcion = funcion;
}
void Proceso::setNivelPrivilegioRequerido(int nivelPrivilegioRequerido) {
    this->nivelPrivilegioRequerido = nivelPrivilegioRequerido;
}