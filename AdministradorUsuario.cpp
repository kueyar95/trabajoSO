// AdministradorUsuario.cpp
#include "AdministradorUsuario.h"
#include <iomanip>
#include<vector>
#include<fstream>
#include<iostream>
#include<sstream>
using namespace std;

AdministradorUsuario::AdministradorUsuario() {
    cargarUltimoId();
}

void AdministradorUsuario::guardarUltimoId() {
    ofstream file("ultimoId.txt", ios::app);
    file << "Usuario," << ultimoId << "\n";
    file.close();
}

void AdministradorUsuario::cargarUltimoId() {
    ifstream file("ultimoId.txt");
    string line, tipo;
    int id;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, tipo, ',');
        ss >> id;
        if (tipo == "Usuario") {
            ultimoId = id;
        }
    }
    file.close();
}
Usuario* AdministradorUsuario::agregarUsuario(string nombre, string tipo, int nivelAcceso) {
    ultimoId++;
    Usuario* nuevoUsuario = new Usuario(ultimoId, nombre, tipo, nivelAcceso);
    usuarios.push_back(nuevoUsuario);
    return nuevoUsuario;
}

void AdministradorUsuario::guardarUsuario(Usuario* usuario) {
    ofstream file("usuarios.txt", ios::app);
    file << usuario->getId() << "," << usuario->getNombre() << "," << usuario->getTipo() << "," << usuario->getNivelAcceso() << "\n";
    file.close();
}

void AdministradorUsuario::cargarUsuarios() {
    ifstream file("usuarios.txt");
    int id, nivelAcceso;
    string nombre, tipo;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        ss >> id;
        ss.ignore(1, ',');
        getline(ss, nombre, ',');
        getline(ss, tipo, ',');
        ss >> nivelAcceso;
        agregarUsuario(nombre, tipo, nivelAcceso);
        if (id > ultimoId) {
            ultimoId = id;
        }
    }

    file.close();
}

void AdministradorUsuario::verUsuarios() {
    cout<< left << setw(5) << "ID" << setw(15) << "Nombre" << setw(15) << "Tipo" << setw(15) << "Nivel de Acceso" << "\n";
    cout<< "------------------------------------------------------------------------\n";
    for (Usuario* usuario : usuarios) {
        cout << left << setw(5) << usuario->getId() << setw(15) << usuario->getNombre() << setw(15) << usuario->getTipo() << setw(15) << usuario->getNivelAcceso() << "\n";
    }
}

void AdministradorUsuario::eliminarUsuario(int id) {
    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            usuarios.erase(it);
            break;
        }
    }
}

void AdministradorUsuario::modificarUsuario(int id) {
    for (Usuario* usuario : usuarios) {
        if (usuario->getId() == id) {
            string nuevoNombre, nuevoTipo;
            int nuevoNivelAcceso;
            cout << "Ingrese el nuevo nombre (deje en blanco para no cambiar): ";
            getline(cin, nuevoNombre);
            if (!nuevoNombre.empty()) {
                usuario->setNombre(nuevoNombre);
            }
            cout << "Ingrese el nuevo tipo (deje en blanco para no cambiar): ";
            getline(cin, nuevoTipo);
            if (!nuevoTipo.empty()) {
                usuario->setTipo(nuevoTipo);
            }
            cout << "Ingrese el nuevo nivel de acceso (ingrese -1 para no cambiar): ";
            cin >> nuevoNivelAcceso;
            if (nuevoNivelAcceso != -1) {
                usuario->setNivelAcceso(nuevoNivelAcceso);
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta el salto de línea en el búfer de entrada
            break;
        }
    }
}