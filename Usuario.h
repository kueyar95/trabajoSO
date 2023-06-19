#include <string>
using namespace std;

class Usuario {
public:
    Usuario(int id, string nombre, string tipo, int nivelAcceso);
    int getId();
    string getNombre();
    void setNombre(string nombre);
    string getTipo();
    void setTipo(string tipo);
    int getNivelAcceso();
    void setNivelAcceso(int nivelAcceso);

private:
    int id; // ID del usuario
    string nombre; // Nombre del usuario
    string tipo; // Tipo de usuario (por ejemplo, humano, sistema, etc.)
    int nivelAcceso; // Nivel de acceso o privilegios del usuario
};