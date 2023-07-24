#include <vector>
#include "Sistema.h"
#include "Usuario.h"

class Entidad {
	private:
		int ID;
		string IP;
		std::vector<Sistema*> sistemas;
		std::vector<Usuario*> usuarios;
		string nombre;
		bool estado;
	public:
		Entidad(int ID, string nombre, bool estado, string IP);
		~Entidad();

		// Getters
		int getID();
		string getIP();
		std::vector<Sistema*> getSistemas();
		std::vector<Usuario*> getUsuarios();
		string getNombre();
		bool getEstado();

		// Setters
		void setID(int ID);
		void setIP(string IP);
		void setSistemas(std::vector<Sistema*> sistemas);
		void setUsuarios(std::vector<Usuario*> usuarios);
		void setNombre(string nombre);
		void setEstado(bool estado);
};