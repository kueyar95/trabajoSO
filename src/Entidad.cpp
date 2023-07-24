#include"../include/Entidad.h"

Entidad::Entidad(int ID, string nombre, bool estado, string IP) {
	this->IP = IP;
	this->nombre = nombre;
	this->estado = estado;
}
// Getters
int Entidad::getID() {
	return ID;
}
string Entidad::getIP() {
	return IP;
}

std::vector<Sistema*> Entidad::getSistemas() {
	return sistemas;
}

std::vector<Usuario*> Entidad::getUsuarios() {
	return usuarios;
}

string Entidad::getNombre() {
	return nombre;
}

bool Entidad::getEstado() {
	return estado;
}

// Setters
void Entidad::setID(int ID) {
	this->ID = ID;
}
void Entidad::setIP(string IP) {
	this->IP = IP;
}

void Entidad::setSistemas(std::vector<Sistema*> sistemas) {
	this->sistemas = sistemas;
}

void Entidad::setUsuarios(std::vector<Usuario*> usuarios) {
	this->usuarios = usuarios;
}

void Entidad::setNombre(string nombre) {
	this->nombre = nombre;
}

void Entidad::setEstado(bool estado) {
	this->estado = estado;
}