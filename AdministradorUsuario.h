#pragma once
#include <string>
#include "Usuario.h"
#include <vector>
using namespace std;


class AdministradorUsuario {
public:
    AdministradorUsuario();
    Usuario* agregarUsuario(string nombre, string tipo, int nivelAcceso, bool cargadoDesdeArchivo);
    void guardarUsuario(Usuario* usuario);
    void cargarUsuarios();
    void verUsuarios();
    Usuario* buscarUsuario(string nombreUsuario);
    void eliminarUsuario(int id);
    void eliminarTodosUsuarios();
    void modificarUsuario(int id);
	void guardarUltimoId();
	void cargarUltimoId();
    string generarNombreAleatorio();
    void creacionRapidoUsuario(int cantidad);

private:
    vector<Usuario*> usuariosList;
    int ultimoId;
};