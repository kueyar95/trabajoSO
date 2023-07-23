#include "Sistema.h"
using namespace std;

int Sistema::getId() {
	return ID;
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
string Sistema::getIp() {
	return IP;
}
void Sistema::setId(int ID) {
	this->ID = ID;
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
void Sistema::setIp(string ip) {
	this->IP = IP;
}