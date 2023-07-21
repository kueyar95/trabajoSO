#include "Sistema.h"
using namespace std;

int Sistema::getId() {
	return id;
}
string Sistema::getNombre() {
	return nombre;
}
string Sistema::getTipo() {
	return tipo;
}
bool Sistema::getEstado() {
	return estado;
}
double Sistema::getSaldo() {
	return saldo;
}
void Sistema::setId(int id) {
	this->id = id;
}
void Sistema::setTipo(string tipo) {
	this->tipo = tipo;
}
void Sistema::setNombre(string nombre) {
	this->nombre = nombre;
}
void Sistema::setEstado(bool estado) {
	this->estado = estado;
}
void Sistema::setSaldo(double saldo){
	this->saldo = saldo;
}