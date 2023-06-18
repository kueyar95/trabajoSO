#include <string>
#include "Hardware.h"
#include "AdministradorHardware.h"
#include 	<iomanip>
#include<vector>
#include<fstream>
#include<iostream>
#include<sstream>


using namespace std;
AdministradorHardware::AdministradorHardware() : ultimoId(0) {}
Hardware* AdministradorHardware::agregarHardware(string tipo, string nombre, string marca, int capacidad, int velocidad) {
	ultimoId++;
    Hardware* nuevoHardware = new Hardware(ultimoId, tipo, nombre, marca, capacidad, velocidad);
    hardwareList.push_back(nuevoHardware);
	return nuevoHardware;
}
void AdministradorHardware::guardarHardware(Hardware* hardware) {
    ofstream file("hardware.txt", ios::app);
    file << hardware->getId() << "," << hardware->getTipo() << "," << hardware->getMarca() << "," << hardware->getModelo() << "," << hardware->getCapacidad() << "," << hardware->getVelocidad() << "\n";
    file.close();
}

void AdministradorHardware::cargarHardware() {
    ifstream file("hardware.txt");
    int id;
    string tipo, modelo, marca;
    int capacidad, velocidad;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        ss >> id;
        ss.ignore(1, ',');
        getline(ss, tipo, ',');
        getline(ss, modelo, ',');
        getline(ss, marca, ',');
        ss >> capacidad;
        ss.ignore(1, ',');
        ss >> velocidad;
        agregarHardware(tipo, modelo, marca, capacidad, velocidad);
        if (id > ultimoId) {
            ultimoId = id;
        }
    }

    file.close();
}

void AdministradorHardware::verHardware() {
    cout << left << setw(5) << "ID" << setw(15) << "Tipo" << setw(20) << "Modelo" << setw(15) << "Marca" << setw(10) << "Capacidad" << setw(10) << "Velocidad" << "\n";
    cout << "------------------------------------------------------------------------\n";
    for (Hardware* hardware : hardwareList) {
        cout << left << setw(5) << hardware->getId() << setw(15) << hardware->getTipo() << setw(20) << hardware->getModelo() << setw(15) << hardware->getMarca() << setw(10) << hardware->getCapacidad() << setw(10) << hardware->getVelocidad() << "\n";
    }
}

void AdministradorHardware::eliminarHardware(int id) {
    for (auto it = hardwareList.begin(); it != hardwareList.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            hardwareList.erase(it);
            break;
        }
    }
}

void AdministradorHardware::modificarHardware(int id) {
    for (Hardware* hardware : hardwareList) {
        if (hardware->getId() == id) {
            string nuevoModelo;
            cout << "Ingrese el nuevo modelo: ";
            cin >> nuevoModelo;
            hardware->setModelo(nuevoModelo);
            break;
        }
    }
}