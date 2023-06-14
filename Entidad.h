#include <vector>
#include "Sistema.h"
#include "Usuario.h"

class Entidad {
	public:
		Entidad();
		void agregarSistema(Sistema* sistema);
		void eliminarSistema(Sistema* sistema);
		void agregarUsuario(Usuario* usuario);
		void eliminarUsuario(Usuario* usuario);
		// Otros métodos para realizar operaciones en los sistemas y usuarios
	private:
		std::vector<Sistema*> sistemas;
		std::vector<Usuario*> usuarios;
};