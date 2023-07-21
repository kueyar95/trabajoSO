#pragma once
#include <string>
#include "Usuario.h"
#include "Sistema.h"
#include <vector>
using namespace std;

class AdministradorSistema {
	private:
		vector<Sistema*> sistemasList; // Lista de todos los sistemas
		int ultimoId; // El último ID que se ha asignado a un sistema

	public:
		// Constructor
		AdministradorSistema();

		// Métodos
		Sistema* agregarSistema(string nombre, string tipo, bool cargadoDesdeArchivo); // Crea un nuevo sistema y lo agrega a la lista
		void eliminarSistema(int id); // Elimina un sistema de la lista
		void eliminarTodosSistemas();
		void modificarSistema(int id);
		Sistema* buscarSistema(string nombreSistema); // Busca un sistema por su nombre
		void listarSistemas(); // Muestra todos los sistemas
		void cargarSistemas(); // Carga los sistemas desde un archivo
		Sistema* cargarSistema(string nombre, string tipo, int id);
		void guardarSistema(Sistema* sistema); // Guarda un sistema en un archivo
		void guardarUltimoId(); // Guarda el último ID en un archivo
		void cargarUltimoId(); // Carga el último ID desde un archivo
		void depositar(Sistema* sistema, double cantidad); // Deposita dinero en un sistema
		void retirar(Sistema* sistema, double cantidad); // Retira dinero de un sistema
};