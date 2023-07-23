// AdministradorUsuario.cpp
#include "AdministradorUsuario.h"
#include <iomanip>
#include<vector>
#include<fstream>
#include<iostream>
#include<sstream>
#include <random>
using namespace std;

AdministradorUsuario::AdministradorUsuario() {
    cargarUltimoId();
    cargarUsuarios();
}

void AdministradorUsuario::guardarUltimoId() {
    vector<string> lines;
    string line, tipo;
    int id;

    // Leer el archivo y guardar todas las líneas en un vector
    ifstream fileRead("ultimoId.txt");
    while (getline(fileRead, line)) {
        stringstream ss(line);
        getline(ss, tipo, ',');
        ss >> id;
        if (tipo == "Usuario") {
            // Reemplazar la línea que corresponde al tipo de ID que estás actualizando
            line = "Usuario," + to_string(ultimoId);
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
Usuario* AdministradorUsuario::agregarUsuario(string nombre, string tipo, int nivelAcceso, bool cargadoDesdeArchivo = false) {
    int id;
    if (cargadoDesdeArchivo) {
        // Si el usuario está siendo cargado desde un archivo, usa el último ID que ya has leído
        id = ultimoId;
    } else {
        // Si el usuario no está siendo cargado desde un archivo, incrementa el último ID y guárdalo
        ultimoId++;
        id = ultimoId;
        guardarUltimoId();
    }
    // Crear el nuevo usuario con el ID correcto
    Usuario* nuevoUsuario = new Usuario(id, nombre, tipo, nivelAcceso);
    usuariosList.push_back(nuevoUsuario);

    // Guardar el usuario en el archivo
    if (!cargadoDesdeArchivo) {
        guardarUsuario(nuevoUsuario);
    }

    return nuevoUsuario;
}

void AdministradorUsuario::guardarUsuario(Usuario* usuario) {
    // Primero, abre el archivo en modo de escritura para sobrescribirlo
    ofstream file("usuarios.txt", ios::out);

    // Luego, escribe todos los usuarios en el archivo
    for (Usuario* u : usuariosList) {
        file << u->getId() << "," << u->getNombre() << "," << u->getTipo() << "," << u->getNivelAcceso() << "\n";
    }

    file.close();
}

Usuario* AdministradorUsuario::cargarUsuario(string nombre, string tipo, int nivelAcceso, int id) {
    // Crear el nuevo usuario con el ID correcto
    Usuario* nuevoUsuario = new Usuario(id, nombre, tipo, nivelAcceso);
    usuariosList.push_back(nuevoUsuario);
    return nuevoUsuario;
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
        cargarUsuario(nombre, tipo, nivelAcceso, id);
        if (id > ultimoId) {
            ultimoId = id;
        }
    }

    file.close();
}

void AdministradorUsuario::verUsuarios() {
    cout<< left << setw(5) << "ID" << setw(15) << "Nombre" << setw(15) << "Tipo" << setw(15) << "Nivel de Acceso" << "\n";
    cout<< "------------------------------------------------------------------------\n";
    for (Usuario* usuario : usuariosList) {
        cout << left << setw(5) << usuario->getId() << setw(15) << usuario->getNombre() << setw(15) << usuario->getTipo() << setw(15) << usuario->getNivelAcceso() << "\n";
    }
}

Usuario* AdministradorUsuario::buscarUsuario(string nombreUsuario){
    for (Usuario* usuario : usuariosList) {
        if (usuario->getNombre() == nombreUsuario) {
            return usuario;
        }
    }
    return nullptr;  // Devuelve nullptr si no se encuentra el usuario
}

void AdministradorUsuario::eliminarUsuario(int id) {
    for (auto it = usuariosList.begin(); it != usuariosList.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            usuariosList.erase(it);
            break;
        }
    }
}

void AdministradorUsuario::eliminarTodosUsuarios() {
    // Eliminar todos los elementos del vector
    for (Usuario* U : usuariosList) {
        delete U;
    }
    usuariosList.clear();

    // Eliminar todo el contenido del archivo
    ofstream file;
    file.open("usuarios.txt", ofstream::out | ofstream::trunc);
    file.close();

    cout<<"Todos los usuarios han sido eliminados exitosamente"<<endl;
}

void AdministradorUsuario::modificarUsuario(int id) {
    for (Usuario* usuario : usuariosList) {
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


string AdministradorUsuario::generarNombreAleatorio() {
    static const char alphanumerico[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    uniform_int_distribution<> dis(0, sizeof(alphanumerico) - 2);
    string nombre;
    for (int i = 0; i < 10; ++i) {
        nombre += alphanumerico[dis(gen)];
    }

    return nombre;
}

void AdministradorUsuario::creacionRapidoUsuario(int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        string nombre = generarNombreAleatorio(); // Genera un nombre de 10 caracteres
        string tipo = i % 2 == 0 ? "humano" : "maquina";
        int nivelAcceso = i % 3; // Genera niveles de acceso aleatorios
        agregarUsuario(nombre, tipo, nivelAcceso, false);
    }
}

void AdministradorUsuario::depositar(Usuario* sistema, double cantidad) {
    if (sistema != nullptr && cantidad > 0) {
        double nuevoSaldo = sistema->getSaldo() + cantidad;
        sistema->setSaldo(nuevoSaldo);
        cout << "Se han depositado " << cantidad << " al sistema " << sistema->getNombre() << ". Nuevo saldo: " << nuevoSaldo << endl;
    } else {
        cout << "Error: Sistema no encontrado o cantidad inválida." << endl;
    }
}

void AdministradorUsuario::retirar(Usuario* sistema, double cantidad) {
    if (sistema != nullptr && cantidad > 0 && cantidad <= sistema->getSaldo()) {
        double nuevoSaldo = sistema->getSaldo() - cantidad;
        sistema->setSaldo(nuevoSaldo);
        cout << "Se han retirado " << cantidad << " del sistema " << sistema->getNombre() << ". Nuevo saldo: " << nuevoSaldo << endl;
    } else {
        cout << "Error: Sistema no encontrado, cantidad inválida o saldo insuficiente." << endl;
    }
}
