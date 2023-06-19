#include <string>
#include "Hardware.h"
#include "AdministradorHardware.h"
#include 	<iomanip>
#include<vector>
#include<fstream>
#include<iostream>
#include<sstream>



using namespace std;

AdministradorHardware::AdministradorHardware() {
    cargarUltimoId();
}

void AdministradorHardware::guardarUltimoId() {
    ofstream file("ultimoId.txt", ios::app);
    file << "Hardware," << ultimoId << "\n";
    file.close();
}

void AdministradorHardware::cargarUltimoId() {
    ifstream file("ultimoId.txt");
    string line, tipo;
    int id;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, tipo, ',');
        ss >> id;
        if (tipo == "Hardware") {
            ultimoId = id;
        }
    }
    file.close();
}
Hardware* AdministradorHardware::agregarHardware(string tipo, string nombre, string marca, int capacidad, int velocidad, bool cargadoDesdeArchivo = false) {
    int id;
    if (cargadoDesdeArchivo) {
        // Si el hardware está siendo cargado desde un archivo, usa el último ID que ya has leído
        id = ultimoId;
    } else {
        // Si el hardware no está siendo cargado desde un archivo, incrementa el último ID y guárdalo
        ultimoId++;
        id = ultimoId;
        ofstream idOutFile("ultimoId.txt");
        idOutFile << ultimoId;
        idOutFile.close();
    }

    // Crear el nuevo hardware con el ID correcto
    Hardware* nuevoHardware = new Hardware(id, tipo, nombre, marca, capacidad, velocidad);
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
        getline(ss, marca, ',');
        getline(ss, modelo, ',');
        ss >> capacidad;
        ss.ignore(1, ',');
        ss >> velocidad;
        ultimoId = id; // Actualiza ultimoId al ID que acabas de leer
        agregarHardware(tipo, modelo, marca, capacidad, velocidad, true); // Indica que el hardware está siendo cargado desde un archivo
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
    // Paso 1: Eliminar el hardware del vector
    for (auto it = hardwareList.begin(); it != hardwareList.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            hardwareList.erase(it);
            break;
        }
    }

    // Paso 2: Reescribir el archivo con los datos del vector actualizado
    ofstream file("hardware.txt", ios::trunc); // Abre el archivo en modo trunc para eliminar todo su contenido
    for (Hardware* hardware : hardwareList) {
        file << hardware->getId() << "," << hardware->getTipo() << "," << hardware->getMarca() << "," << hardware->getModelo() << "," << hardware->getCapacidad() << "," << hardware->getVelocidad() << "\n";
    }
    file.close();
}

void AdministradorHardware::modificarHardware(int id) {
    for (Hardware* hardware : hardwareList) {
        if (hardware->getId() == id) {
            string nuevoTipo;
            cout << "Ingrese el nuevo tipo (deje en blanco para no cambiar): ";
            getline(cin, nuevoTipo);
            if (!nuevoTipo.empty()) {
                hardware->setTipo(nuevoTipo);
            }

            string nuevoMarca;
            cout<<"Ingrese el nueva marca (deje en blanco para no cambiar): ";
            getline(cin, nuevoMarca);
            if (!nuevoMarca.empty()) {
                hardware->setMarca(nuevoMarca);
            }

            string nuevoModelo;
            cout << "Ingrese el nuevo modelo (deje en blanco para no cambiar): ";
            getline(cin, nuevoModelo);
            if (!nuevoModelo.empty()) {
                hardware->setModelo(nuevoModelo);
            }

            string entrada;
            cout<<"Ingrese la nueva capacidad (deje en blanco para no cambiar): ";
            getline(cin, entrada);
            if (!entrada.empty()) {
                int nuevaCapacidad = stoi(entrada);
                hardware->setCapacidad(nuevaCapacidad);
            }

            cout<<"Ingrese la nueva velocidad (deje en blanco para no cambiar): ";
            getline(cin, entrada);
            if (!entrada.empty()) {
                int nuevaVelocidad = stoi(entrada);
                hardware->setVelocidad(nuevaVelocidad);
            }
        }
    }
    // Paso 2: Reescribir el archivo con los datos del vector actualizado
    ofstream file("hardware.txt", ios::trunc); // Abre el archivo en modo trunc para eliminar todo su contenido
    for (Hardware* hardware : hardwareList) {
        file << hardware->getId() << "," << hardware->getTipo() << "," << hardware->getMarca() << "," << hardware->getModelo() << "," << hardware->getCapacidad() << "," << hardware->getVelocidad() << "\n";
    }
    file.close();
}

void AdministradorHardware::eliminarTodoHardware() {
    // Eliminar todos los elementos del vector
    for (Hardware* h : hardwareList) {
        delete h;
    }
    hardwareList.clear();

    // Eliminar todo el contenido del archivo
    ofstream file;
    file.open("hardware.txt", ofstream::out | ofstream::trunc);
    file.close();

    cout<<"Todos los hardware han sido eliminados exitosamente"<<endl;
}