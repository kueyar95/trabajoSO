#include<Usuario.h>

class Proceso {
	public:
		Proceso(Usuario* usuario, int sistemaId, int recursosRequeridos);
		void ejecutar();
		// Otros métodos según sea necesario
	private:
		Usuario* usuario; // El usuario que inició el proceso
		int sistemaId; // ID del sistema en el que se está ejecutando el proceso
		int recursosRequeridos; // La cantidad de recursos que el proceso necesita para ejecutarse
};