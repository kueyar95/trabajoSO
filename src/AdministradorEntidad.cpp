#include"../include/AdministradorEntidad.h"
#include"../include/AdministradorSistema.h"
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include"../include/AdministradorUsuario.h"
using namespace std;
AdministradorUsuario admUsuario;
AdministradorSistema admSistema;
AdministradorEntidad::AdministradorEntidad() {
    cargarUltimoId();
    cargarEntidades();
}

void AdministradorEntidad::guardarUltimoId() {
    vector<string> lines;
    string line, tipo;
    int id;

    // Leer el archivo y guardar todas las líneas en un vector
    ifstream fileRead("ultimoId.txt");
    while (getline(fileRead, line)) {
        stringstream ss(line);
        getline(ss, tipo, ',');
        ss >> id;
        if (tipo == "EntidadID") {
            // Reemplazar la línea que corresponde al tipo de ID que estás actualizando
            line = "EntidadID," + to_string(ultimoId);
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

void AdministradorEntidad::cargarUltimoId() {
    ifstream file("ultimoId.txt");
    string line, tipo;
    int id;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, tipo, ',');
        ss >> id;
        if (tipo == "EntidadID") {
            ultimoId = id;
        }
    }
    file.close();
}

void AdministradorEntidad::guardarUltimoIp(){
    vector<string> lines;
    string line, tipo;
    string IP;

    // Leer el archivo y guardar todas las líneas en un vector
    ifstream fileRead("ultimoId.txt");
    while (getline(fileRead, line)) {
        stringstream ss(line);
        getline(ss, tipo, ',');
        getline(ss, IP);
        if (tipo == "EntidadIP") {
            // Reemplazar la línea que corresponde al tipo de IP que estás actualizando
            line = "EntidadIP," + ultimoIP;
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

void AdministradorEntidad::cargarUltimoIp(){
    ifstream file("ultimoId.txt");
    string line, tipo;
    string IP;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, tipo, ',');
        getline(ss, IP);
        if (tipo == "EntidadIP") {
            ultimoIP = IP;
        }
    }
    file.close();
}

Entidad* AdministradorEntidad::agregarEntidad(string nombre, bool cargadoDesdeArchivo = false) {
    int ID;
	string IP;
	AdministradorSistema admSistema;
    if (cargadoDesdeArchivo) {
        // Si la entidad está siendo cargada desde un archivo, usa el último ID que ya has leído
        ID = ultimoId;
    } else {
        // Si la entidad no está siendo cargada desde un archivo, incrementa el último ID y guárdalo
        ultimoId++;
        ID = ultimoId;
        guardarUltimoId();
    }
	IP = admSistema.generarIpUnica();
    // Crear la nueva entidad con el ID correcto
    Entidad* nuevaEntidad = new Entidad(ID, nombre, true, IP);
    entidadesList.push_back(nuevaEntidad);

    // Guardar la entidad en el archivo
    if (!cargadoDesdeArchivo) {
        guardarEntidad(nuevaEntidad);
    }

    return nuevaEntidad;
}

void AdministradorEntidad::guardarEntidad(Entidad* entidad) {
    // Primero, abre el archivo en modo de escritura para sobrescribirlo
    ofstream file("entidades.txt", ios::out);

    // Luego, escribe todas las entidades en el archivo
    for (Entidad* e : entidadesList) {
        file << e->getID() << "," << e->getNombre() << "\n";
    }

    file.close();
}

Entidad* AdministradorEntidad::cargarEntidad(int ID, string nombre, bool estado, string IP) {
    // Crear la nueva entidad con el ID correcto
    Entidad* nuevaEntidad = new Entidad(ID, nombre, estado, IP);
    entidadesList.push_back(nuevaEntidad);
    return nuevaEntidad;
}

void AdministradorEntidad::cargarEntidades() {
    ifstream file("entidades.txt");
    int ID;
    string nombre, IP;
	bool estado;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        ss >> ID;
        ss.ignore(1, ',');
        getline(ss, nombre, ',');
        cargarEntidad(ID, nombre, estado, IP);
        if (ID > ultimoId) {
            ultimoId = ID;
        }
    }

    file.close();
}

void AdministradorEntidad::listarEntidades() {
    cout<< left << setw(5) << "ID" << setw(15) << "Nombre" << "\n";
    cout<< "------------------------------------------------------------------------\n";
    for (Entidad* entidad : entidadesList) {
        cout << left << setw(5) << entidad->getID() << setw(15) << entidad->getNombre() << "\n";
    }
}

Entidad* AdministradorEntidad::buscarEntidad(int idEntidad){
    for (Entidad* entidad : entidadesList) {
        if (entidad->getID() == idEntidad) {
            return entidad;
        }
    }
    return nullptr;  // Devuelve nullptr si no se encuentra la entidad
}

void AdministradorEntidad::eliminarEntidad(string nombreEntidad) {
    for (auto it = entidadesList.begin(); it != entidadesList.end(); ++it) {
        if ((*it)->getNombre() == nombreEntidad) {
            delete *it;
            entidadesList.erase(it);
            break;
        }
    }
}

void AdministradorEntidad::asignarUsuarioAEntidad(int idUsuario, int idEntidad) {
    Usuario* usuario = admUsuario.buscarUsuario(idUsuario);
    Entidad* entidad = buscarEntidad(idEntidad);
    if (usuario != nullptr && entidad != nullptr) {
        vector<Usuario*> usuarios = entidad->getUsuarios();
        usuarios.push_back(usuario);
        entidad->setUsuarios(usuarios);
    }
}

void AdministradorEntidad::eliminarUsuarioDeEntidad(int idUsuario, int idEntidad) {
    Usuario* usuario = admUsuario.buscarUsuario(idUsuario);
    Entidad* entidad = buscarEntidad(idEntidad);
    if (usuario != nullptr && entidad != nullptr) {
        vector<Usuario*> usuarios = entidad->getUsuarios();
        usuarios.erase(remove(usuarios.begin(), usuarios.end(), usuario), usuarios.end());
        entidad->setUsuarios(usuarios);
    }
}

void AdministradorEntidad::listarUsuariosDeEntidad(int idEntidad) {
    Entidad* entidad = buscarEntidad(idEntidad);
    if (entidad != nullptr) {
        vector<Usuario*> usuarios = entidad->getUsuarios();
        for (Usuario* usuario : usuarios) {
            cout << usuario->getNombre() << endl;
        }
    }
}

void AdministradorEntidad::agregarSistemaAEntidad(int idEntidad, int idSistema) {
    Entidad* entidad = buscarEntidad(idEntidad);
    Sistema* sistema = admSistema.buscarSistemaPorId(idSistema);
    if (entidad != nullptr && sistema != nullptr) {
        vector<Sistema*> sistemas = entidad->getSistemas();
        sistemas.push_back(sistema);
        entidad->setSistemas(sistemas);
    }
}

void AdministradorEntidad::eliminarSistemaDeEntidad(int idEntidad, int idSistema) {
    Entidad* entidad = buscarEntidad(idEntidad);
    Sistema* sistema = admSistema.buscarSistemaPorId(idSistema);
    if (entidad != nullptr && sistema != nullptr) {
        vector<Sistema*> sistemas = entidad->getSistemas();
        sistemas.erase(remove(sistemas.begin(), sistemas.end(), sistema), sistemas.end());
        entidad->setSistemas(sistemas);
    }
}

void AdministradorEntidad::listarSistemasDeEntidad(int idEntidad) {
    Entidad* entidad = buscarEntidad(idEntidad);
    if (entidad != nullptr) {
        vector<Sistema*> sistemas = entidad->getSistemas();
        for (Sistema* sistema : sistemas) {
            cout << sistema->getId() << endl;
        }
    }
}
