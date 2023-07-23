#include<string>
#include"../include/Hardware.h"
#include<vector>
#include<fstream>

using namespace std;

Hardware::Hardware(int id, string tipo, string marca, string modelo, int capacidad, int velocidad)
    : id(id), tipo(tipo), modelo(modelo), marca(marca), capacidad(capacidad), velocidad(velocidad) {}

int Hardware::getCapacidad() {
    return capacidad;
}

void Hardware::setCapacidad(int capacidad) {
    this->capacidad = capacidad;
}

int Hardware::getVelocidad() {
    return velocidad;
}

void Hardware::setVelocidad(int velocidad) {
    this->velocidad = velocidad;
}

string Hardware::getTipo() {
    return tipo;
}

void Hardware::setTipo(string tipo) {
    this->tipo = tipo;
}

string Hardware::getModelo() {
    return modelo;
}

void Hardware::setModelo(string modelo) {
    this->modelo = modelo;
}

string Hardware::getMarca() {
    return marca;
}

void Hardware::setMarca(string marca) {
    this->marca = marca;
}

int Hardware::getId(){
	return id;
}
void Hardware::setId(int id){
	this->id = id;
}