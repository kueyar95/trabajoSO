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
		void atacar(Entidad* objetivo, Sistema* sistemaObjetivo);
    	void defender(Entidad* atacante, Sistema* sistemaAtacante);
		// Otros métodos para realizar operaciones en los sistemas y usuarios
	private:
		std::vector<Sistema*> sistemas;
		std::vector<Usuario*> usuarios;
};