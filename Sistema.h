#include <vector>
#include "Hardware.h"
#include "Proceso.h"

class Sistema {
public:
    Sistema(std::string nombre, std::vector<Hardware*> hardware, std::vector<Usuario*> usuarios);
    std::string getNombre();
    void setNombre(std::string nombre);
    std::vector<Hardware*> getHardware();
    void setHardware(std::vector<Hardware*> hardware);
    std::vector<Usuario*> getUsuarios();
    void setUsuarios(std::vector<Usuario*> usuarios);
    void agregarHardware(Hardware* hardware);
    void eliminarHardware(Hardware* hardware);
    void agregarUsuario(Usuario* usuario);
    void eliminarUsuario(Usuario* usuario);
	void agregarProceso(Proceso* proceso);
    void eliminarProceso(Proceso* proceso);
    // Otros métodos según sea necesario
private:
    std::string nombre; // Nombre del sistema
    std::vector<Hardware*> hardware; // Lista de hardware asociado al sistema
    std::vector<Usuario*> usuarios; // Lista de usuarios asociados al sistema
};