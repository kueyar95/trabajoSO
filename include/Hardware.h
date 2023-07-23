#pragma once
#include <string>
using namespace std;

class Hardware {
	public:
		Hardware(int id, string tipo, string marca, string modelo, int capacidad, int velocidad);
		int getCapacidad();
		void setCapacidad(int capacidad);
		int getVelocidad();
		void setVelocidad(int velocidad);
		string getTipo();
		void setTipo(string tipo);
		void setModelo(string modelo);
		string getModelo();
		void setMarca(string marca);
		string getMarca();
		int getId();
		void setId(int id);
	private:
		string tipo;
		string modelo;
		string marca;
		int id;
		int capacidad;
		int almacenamiento;
		int velocidad;
};