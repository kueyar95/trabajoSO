#pragma once
#include <string>
#include "Usuario.h"
#include "Sistema.h"
#include <vector>
using namespace std;

class AdministradorSistemas {
	private:
		vector<Sistema*> sistemasList; // Lista de todos los sistemas
		int ultimoId; // El último ID que se ha asignado a un sistema

	public:
		// Constructor
		AdministradorSistemas();

		// Métodos
		Sistema* agregarSistema(string nombre, string tipo); // Crea un nuevo sistema y lo agrega a la lista
		void eliminarSistema(int id); // Elimina un sistema de la lista
		Sistema* buscarSistema(string nombreSistema); // Busca un sistema por su nombre
		void listarSistemas(); // Muestra todos los sistemas
		void cargarSistemas(); // Carga los sistemas desde un archivo
		void guardarSistema(Sistema* sistema); // Guarda un sistema en un archivo
		void guardarUltimoId(); // Guarda el último ID en un archivo
		void cargarUltimoId(); // Carga el último ID desde un archivo
};