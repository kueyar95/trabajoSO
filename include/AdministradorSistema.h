#pragma once
#include <random>
#include <string>
#include "Sistema.h"
#include <vector>
using namespace std;
extern random_device rd;  // Declaración
extern mt19937 gen;  // Declaración

class AdministradorSistema {
	private:
		vector<Sistema*> sistemasList; // Lista de todos los sistemas
		int ultimoId; // El último ID que se ha asignado a un sistema
		string ultimoIP; // El último IP que se ha asignado a un sistema

	public:
		// Constructor
		AdministradorSistema();

		// Métodos
		Sistema* agregarSistema(string nombre, string tipo, bool cargadoDesdeArchivo); // Crea un nuevo sistema y lo agrega a la lista
		void eliminarSistema(int ID); // Elimina un sistema de la lista
		void eliminarTodosSistemas();
		void modificarSistema(int ID);
		Sistema* verSistema(int ID); // Busca un sistema por su ID
		void listarSistemas(); // Muestra todos los sistemas
		void cargarSistemas(); // Carga los sistemas desde un archivo
		Sistema* cargarSistema(int ID, string nombre, string tipo, string IP);
		void guardarSistema(Sistema* sistema); // Guarda un sistema en un archivo
		void guardarUltimoId(); // Guarda el último ID en un archivo
		void cargarUltimoId(); // Carga el último ID desde un archivo
		void guardarUltimoIp(); // Carga el último IP desde un archivo
		void cargarUltimoIp(); // Carga el último IP desde un archivo
		void depositar(int idSistema, double cantidad); // Deposita dinero en un sistema
		void retirar(int idSistema, double cantidad); // Retira dinero de un sistema
		Sistema* buscarSistemaPorId(int idSistema);
		string generarIpUnica();
		void asignarIp(Sistema* sistema);
        void cambiarIp(Sistema* sistema, string nuevaIp);
        string getIp(Sistema* sistema);
        Sistema* buscarSistemaPorIp(string IP);
};