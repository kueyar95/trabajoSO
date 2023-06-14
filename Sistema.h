#include <vector>
#include "Hardware.h"


class Sistema {
	public:
		Sistema();
		void agregarHardware(Hardware* hardware);
		void eliminarHardware(Hardware* hardware);
		// Otros métodos para realizar operaciones en el hardware
	private:
		std::vector<Hardware*> hardware;
};