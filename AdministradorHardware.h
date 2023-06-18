#pragma once
#include <string>
#include "Hardware.h"

#include<vector>

using namespace std;


class AdministradorHardware {
	public:
		AdministradorHardware();
		Hardware* agregarHardware(string tipo, string marca, string modelo, int capacidad, int velocidad);
		void guardarHardware(Hardware* hardware);
		void cargarHardware();
		void verHardware();
		void eliminarHardware(int id);
		void modificarHardware(int id);
		// Otros métodos según sea necesario
	private:
		vector<Hardware*> hardwareList;
		int ultimoId;
};