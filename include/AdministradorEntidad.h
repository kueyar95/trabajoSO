#ifndef ADMINISTRADORENTIDAD_H
#define ADMINISTRADORENTIDAD_H
#pragma once
#include <vector>
#include "Entidad.h"
#include "Usuario.h"
#include "Sistema.h"

class AdministradorEntidad {
    private:
        vector<Entidad*> entidadesList;
		int ultimoId; // El último ID que se ha asignado a una entidad
		string ultimoIP; // El último IP que se ha asignado a una entidad

    public:
        AdministradorEntidad();
        ~AdministradorEntidad();
        Entidad* agregarEntidad(string nombre, bool cargadoDesdeArchivo);
        void eliminarEntidad(string nombre);
        void modificarEntidad(string nombre);
        void listarEntidades();
        void guardarUltimoId();
        void cargarUltimoId();
        void guardarUltimoIp();
        void cargarUltimoIp();
        void cargarEntidades();
        void guardarEntidad(Entidad* entidad);
        Entidad* cargarEntidad(int ID, string nombre, bool estado, string IP);
        Entidad* buscarEntidad(int idEntidad);
        void asignarUsuarioAEntidad(int idUsuario, int idEntidad);
        void eliminarUsuarioDeEntidad(int idUsuario, int idEntidad);
        void listarUsuariosDeEntidad(int idEntidad);
        void agregarSistemaAEntidad(int idEntidad, int idSistema);
        void eliminarSistemaDeEntidad(int idEntidad, int idSistema);
        void listarSistemasDeEntidad(int idEntidad);
        Sistema* buscarSistemaEnEntidad(string nombreEntidad, string nombreSistema);
};

#endif