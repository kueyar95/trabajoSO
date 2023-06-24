// AdministradorUsuario.h
#pragma once
#include <string>
#include "Usuario.h"
#include <vector>
using namespace std;


class AdministradorUsuario {
public:
    AdministradorUsuario();
    Usuario* agregarUsuario(string nombre, string tipo, int nivelAcceso);
    void guardarUsuario(Usuario* usuario);
    void cargarUsuarios();
    void verUsuarios();
    Usuario* buscarUsuario(string nombreUsuario);
    void eliminarUsuario(int id);
    void modificarUsuario(int id);
	void guardarUltimoId();
	void cargarUltimoId();
    string generarNombreAleatorio(int longitud);
    void agregarUsuariosAleatorios(int cantidad);

private:
    vector<Usuario*> usuarios;
    int ultimoId;
};