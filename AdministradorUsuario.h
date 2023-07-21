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
        Usuario* cargarUsuario(string nombre, string tipo, int nivelAcceso, int id);
        void verUsuarios();
        Usuario* buscarUsuario(string nombreUsuario);
        void eliminarUsuario(int id);
        void eliminarTodosUsuarios();
        void modificarUsuario(int id);
        void guardarUltimoId();
        void cargarUltimoId();
        string generarNombreAleatorio();
        void creacionRapidoUsuario(int cantidad);
        void depositar(Usuario* usuario, double cantidad); // Deposita dinero en un sistema
		void retirar(Usuario* usuario, double cantidad); // Retira dinero de un sistema

    private:
        vector<Usuario*> usuariosList;
        int ultimoId;
};