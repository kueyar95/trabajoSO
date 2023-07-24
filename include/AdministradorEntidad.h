#pragma once
#include <vector>
#include "Entidad.h"
#include "Usuario.h"
#include "Sistema.h"

class AdministradorEntidad {
    public:
        AdministradorEntidad();
        ~AdministradorEntidad();
        Entidad* agregarEntidad(string nombre, bool cargadoDesdeArchivo);
        void eliminarEntidad(string nombre);
        void modificarEntidad(string nombre);
        void listarEntidades();
        void guardarUltimoId();
        void cargarUltimoId();
        void cargarEntidades();
        void guardarEntidad(Entidad* entidad);
        Entidad* cargarEntidad(int ID, string nombre, bool estado, string IP);
        Entidad* buscarEntidad(string nombre);
        void asignarUsuarioAEntidad(string nombreUsuario, string nombreEntidad);
        void eliminarUsuarioDeEntidad(string nombreUsuario, string nombreEntidad);
        void listarUsuariosDeEntidad(string nombreEntidad);
        void agregarSistemaAEntidad(string nombreEntidad, Sistema* sistema);
        void eliminarSistemaDeEntidad(string nombreEntidad, Sistema* sistema);
        void listarSistemasDeEntidad(string nombreEntidad);
        Sistema* buscarSistemaEnEntidad(string nombreEntidad, string nombreSistema);
    private:
        vector<Entidad*> entidadesList;
		int ultimoId; // El último ID que se ha asignado a una entidad
		string ultimoIP; // El último IP que se ha asignado a una entidad
};