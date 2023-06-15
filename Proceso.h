#include<Usuario.h>
#include<Sistema.h>

class Proceso {
	public:
		Proceso(Usuario* usuario, Sistema* sistema, int recursosRequeridos);
		void ejecutar();
		// Otros métodos según sea necesario
	private:
		Usuario* usuario; // El usuario que inició el proceso
		Sistema* sistema; // El sistema en el que se está ejecutando el proceso
		int recursosRequeridos; // La cantidad de recursos que el proceso necesita para ejecutarse
};