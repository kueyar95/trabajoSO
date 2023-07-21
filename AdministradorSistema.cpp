// AdministradorSistema.cpp
#include "AdministradorSistema.h"
#include <iomanip>
#include<vector>
#include<fstream>
#include<iostream>
#include<sstream>
#include <random>
using namespace std;
random_device rd;
mt19937 gen(rd());

AdministradorSistema::AdministradorSistema() {
    cargarUltimoId();
    cargarSistemas();
}

void AdministradorSistema::guardarUltimoId() {
    vector<string> lines;
    string line, tipo;
    int id;

    // Leer el archivo y guardar todas las líneas en un vector
    ifstream fileRead("ultimoId.txt");
    while (getline(fileRead, line)) {
        stringstream ss(line);
        getline(ss, tipo, ',');
        ss >> id;
        if (tipo == "Sistema") {
            // Reemplazar la línea que corresponde al tipo de ID que estás actualizando
            line = "Sistema," + to_string(ultimoId);
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

void AdministradorSistema::cargarUltimoId() {
    ifstream file("ultimoId.txt");
    string line, tipo;
    int id;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, tipo, ',');
        ss >> id;
        if (tipo == "Sistema") {
            ultimoId = id;
        }
    }
    file.close();
}

Sistema* AdministradorSistema::agregarSistema(string nombre, string tipo, bool cargadoDesdeArchivo = false) {
    int id;
    if (cargadoDesdeArchivo) {
        // Si el sistema está siendo cargado desde un archivo, usa el último ID que ya has leído
        id = ultimoId;
    } else {
        // Si el sistema no está siendo cargado desde un archivo, incrementa el último ID y guárdalo
        ultimoId++;
        id = ultimoId;
        guardarUltimoId();
    }
    // Crear el nuevo sistema con el ID correcto
    Sistema* nuevoSistema = new Sistema(id, nombre, tipo);
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
        file << s->getId() << "," << s->getNombre() << "," << s->getTipo() << "\n";
    }

    file.close();
}

Sistema* AdministradorSistema::cargarSistema(string nombre, string tipo, int id) {
    // Crear el nuevo sistema con el ID correcto
    Sistema* nuevoSistema = new Sistema(id, nombre, tipo);
    sistemasList.push_back(nuevoSistema);
    return nuevoSistema;
}

void AdministradorSistema::cargarSistemas() {
    ifstream file("sistemas.txt");
    int id;
    string nombre, tipo;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        ss >> id;
        ss.ignore(1, ',');
        getline(ss, nombre, ',');
        getline(ss, tipo, ',');
        cargarSistema(nombre, tipo, id);
        if (id > ultimoId) {
            ultimoId = id;
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

Sistema* AdministradorSistema::buscarSistema(string nombreSistema){
    for (Sistema* sistema : sistemasList) {
        if (sistema->getNombre() == nombreSistema) {
            return sistema;
        }
    }
    return nullptr;  // Devuelve nullptr si no se encuentra el sistema
}

void AdministradorSistema::eliminarSistema(int id) {
    for (auto it = sistemasList.begin(); it != sistemasList.end(); ++it) {
        if ((*it)->getId() == id) {
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

void AdministradorSistema::modificarSistema(int id) {
    for (Sistema* sistema : sistemasList) {
        if (sistema->getId() == id) {
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

void AdministradorSistema::depositar(Sistema* sistema, double cantidad) {
    if (sistema != nullptr && cantidad > 0) {
        double nuevoSaldo = sistema->getSaldo() + cantidad;
        sistema->setSaldo(nuevoSaldo);
        cout << "Se han depositado " << cantidad << " al sistema " << sistema->getNombre() << ". Nuevo saldo: " << nuevoSaldo << endl;
    } else {
        cout << "Error: Sistema no encontrado o cantidad inválida." << endl;
    }
}

void AdministradorSistema::retirar(Sistema* sistema, double cantidad) {
    if (sistema != nullptr && cantidad > 0 && cantidad <= sistema->getSaldo()) {
        double nuevoSaldo = sistema->getSaldo() - cantidad;
        sistema->setSaldo(nuevoSaldo);
        cout << "Se han retirado " << cantidad << " del sistema " << sistema->getNombre() << ". Nuevo saldo: " << nuevoSaldo << endl;
    } else {
        cout << "Error: Sistema no encontrado, cantidad inválida o saldo insuficiente." << endl;
    }
}
