// AdministradorSistema.cpp
#include "AdministradorSistema.h"
#include <iomanip>
#include<vector>
#include<fstream>
#include<iostream>
#include<sstream>
#include <random>
using namespace std;
AdministradorSistema::AdministradorSistema() {
    ultimoId = 0;  // Inicializa ultimoId con 0
    ultimoIP = "0.0.0.0";  // Inicializa ultimoIP con "0.0.0.0"
    cargarSistemas();
    cargarUltimoId();
    cargarUltimoIp();
}

void AdministradorSistema::guardarUltimoId() {
    bool idFound = false;
    vector<string> lines;
    string line, tipo;
    int ID;

    // Leer el archivo y guardar todas las líneas en un vector
    ifstream fileRead("ultimoId.txt");
    while (getline(fileRead, line)) {
        stringstream ss(line);
        getline(ss, tipo, ',');
        ss >> ID;
        if (tipo == "SistemaID") {
            // Reemplazar la línea que corresponde al tipo de ID que estás actualizando
            line = "SistemaID," + to_string(ultimoId);
            idFound = true;
        }
        lines.push_back(line);
    }
    fileRead.close();

    // Si no se encontró el ID, añadirlo al final
    if (!idFound) {
        lines.push_back("SistemaID," + to_string(ultimoId));
    }

    // Sobrescribir el archivo con las líneas actualizadas
    ofstream fileWrite("ultimoId.txt", ios::out);
    for (const string& line : lines) {
        fileWrite << line << "\n";
    }
    fileWrite.close();
}

void AdministradorSistema::cargarUltimoId() {
    ifstream file("ultimoId.txt");
    string line, tipo;
    int ID;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, tipo, ',');
        ss >> ID;
        if (tipo == "SistemaID") {
            ultimoId = ID;
        }
    }
    file.close();
}
void AdministradorSistema::guardarUltimoIp(){
    vector<string> lines;
    string line, tipo;
    string IP;

    // Leer el archivo y guardar todas las líneas en un vector
    ifstream fileRead("ultimoId.txt");
    while (getline(fileRead, line)) {
        stringstream ss(line);
        getline(ss, tipo, ',');
        getline(ss, IP);
        if (tipo == "SistemaIP") {
            // Reemplazar la línea que corresponde al tipo de IP que estás actualizando
            line = "SistemaIP," + ultimoIP;
        }
        lines.push_back(line);
    }
    fileRead.close();

    // Sobrescribir el archivo con las líneas actualizadas
    ofstream fileWrite("ultimoId.txt", ios::out);
    for (const string& line : lines) {
        fileWrite << line << "\n";
    }
    fileWrite.close();
}

void AdministradorSistema::cargarUltimoIp(){
    ifstream file("ultimoId.txt");
    string line, tipo;
    string IP;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, tipo, ',');
        getline(ss, IP);
        if (tipo == "SistemaIP") {
            ultimoIP = IP;
        }
    }
    file.close();
}

Sistema* AdministradorSistema::agregarSistema(string nombre, string tipo, bool cargadoDesdeArchivo = false) {
    int ID;
    string IP;
    if (cargadoDesdeArchivo) {
        // Si el sistema está siendo cargado desde un archivo, usa el último ID que ya has leído
        ID = ultimoId;
        IP = ultimoIP;

    } else {
        // Si el sistema no está siendo cargado desde un archivo, incrementa el último ID y IP y guárdalos
        ultimoId++;
        ID = ultimoId;
        guardarUltimoId();
        IP = generarIpUnica();
        ultimoIP = IP;
        guardarUltimoIp();
    }
    // Crear el nuevo sistema con el ID correcto
    Sistema* nuevoSistema = new Sistema(ID, nombre, tipo, IP);
    sistemasList.push_back(nuevoSistema);

    // Guardar el sistema en el archivo
    if (!cargadoDesdeArchivo) {
        guardarSistema(nuevoSistema);
    }

    return nuevoSistema;
}

void AdministradorSistema::guardarSistema(Sistema* sistema) {
    // Primero, abre el archivo en modo de escritura para sobrescribirlo
    ofstream file("sistemas.txt", ios::out);

    // Luego, escribe todos los sistemas en el archivo
    for (Sistema* s : sistemasList) {
        file << s->getId() << "," << s->getNombre() << "," << s->getTipo() << "," << s->getIp() << "\n";
    }

    file.close();
}

Sistema* AdministradorSistema::cargarSistema(int ID, string nombre, string tipo, string IP) {
    // Crear el nuevo sistema con el ID y IP correctos
    Sistema* nuevoSistema = new Sistema(ID, nombre, tipo, IP);
    sistemasList.push_back(nuevoSistema);
    return nuevoSistema;
}

void AdministradorSistema::cargarSistemas() {
    ifstream file("sistemas.txt");
    int ID;
    string nombre, tipo, IP;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        ss >> ID;
        ss.ignore(1, ',');
        getline(ss, nombre, ',');
        getline(ss, tipo, ',');
        getline(ss, IP, ',');
        cargarSistema(ID, nombre, tipo, IP);
        if (ID > ultimoId) {
            ultimoId = ID;
            ultimoIP = IP;
        }
    }

    file.close();
}

void AdministradorSistema::listarSistemas() {
    cout<< left << setw(5) << "ID" << setw(15) << "Nombre" << setw(15) << "Tipo" << "\n";
    cout<< "------------------------------------------------------------------------\n";
    for (Sistema* sistema : sistemasList) {
        cout << left << setw(5) << sistema->getId() << setw(15) << sistema->getNombre() << setw(15) << sistema->getTipo() << "\n";
    }
}

Sistema* AdministradorSistema::verSistema(int ID){
    for (Sistema* sistema : sistemasList) {
        if (sistema->getId() == ID) {
            return sistema;
        }
    }
    return nullptr;  // Devuelve nullptr si no se encuentra el sistema
}

void AdministradorSistema::eliminarSistema(int ID) {
    for (auto it = sistemasList.begin(); it != sistemasList.end(); ++it) {
        if ((*it)->getId() == ID) {
            delete *it;
            sistemasList.erase(it);
            break;
        }
    }
}

void AdministradorSistema::eliminarTodosSistemas() {
    // Eliminar todos los elementos del vector
    for (Sistema* S : sistemasList) {
        delete S;
    }
    sistemasList.clear();

    // Eliminar todo el contenido del archivo
    ofstream file;
    file.open("sistemas.txt", ofstream::out | ofstream::trunc);
    file.close();

    cout<<"Todos los sistemas han sido eliminados exitosamente"<<endl;
}

void AdministradorSistema::modificarSistema(int ID) {
    for (Sistema* sistema : sistemasList) {
        if (sistema->getId() == ID) {
            string nuevoNombre, nuevoTipo;
            cout << "Ingrese el nuevo nombre (deje en blanco para no cambiar): ";
            getline(cin, nuevoNombre);
            if (!nuevoNombre.empty()) {
                sistema->setNombre(nuevoNombre);
            }
            cout << "Ingrese el nuevo tipo (deje en blanco para no cambiar): ";
            getline(cin, nuevoTipo);
            if (!nuevoTipo.empty()) {
                sistema->setTipo(nuevoTipo);
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta el salto de línea en el búfer de entrada
            break;
        }
    }
}

void AdministradorSistema::depositar(int idSistema, double cantidad) {
    Sistema* sistema = buscarSistemaPorId(idSistema);
    if (sistema != nullptr && cantidad > 0) {
        double nuevoSaldo = sistema->getSaldo() + cantidad;
        sistema->setSaldo(nuevoSaldo);
        cout << "Se han depositado " << cantidad << " al sistema " << sistema->getNombre() << ". Nuevo saldo: " << nuevoSaldo << endl;
    } else {
        cout << "Error: Sistema no encontrado o cantidad inválida." << endl;
    }
}

void AdministradorSistema::retirar(int idSistema, double cantidad) {
    Sistema* sistema = buscarSistemaPorId(idSistema);
    if (sistema != nullptr && cantidad > 0 && cantidad <= sistema->getSaldo()) {
        double nuevoSaldo = sistema->getSaldo() - cantidad;
        sistema->setSaldo(nuevoSaldo);
        cout << "Se han retirado " << cantidad << " del sistema " << sistema->getNombre() << ". Nuevo saldo: " << nuevoSaldo << endl;
    } else {
        cout << "Error: Sistema no encontrado, cantidad inválida o saldo insuficiente." << endl;
    }
}

string AdministradorSistema::generarIpUnica() {
    string IP;
    bool ipUnica = false;
    while (!ipUnica) {
        IP = to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256);
        ipUnica = true;
        for (Sistema* sistema : sistemasList) {
            if (sistema->getIp() == IP) {
                ipUnica = false;
                break;
            }
        }
    }
    return IP;
}

Sistema* AdministradorSistema::buscarSistemaPorId(int idSistema){
    for (Sistema* sistema : sistemasList) {
        if (sistema->getId() == idSistema) {
            return sistema;
        }
    }
    cout << "Error: No se encontró un sistema con el ID " << idSistema << ".\n";
    return nullptr;  // Devuelve nullptr si no se encuentra el sistema
}