#include <vector>
#include "Hardware.h"
#include "Proceso.h"

class Sistema {
    private:
        int id; // Identificador único del sistema
        string nombre; // Nombre del sistema
        string tipo; // Tipo de sistema (Banca, Recaudación de impuestos, Sistemas de pago, Sistemas de minado, etc.)
        bool estado; // Estado del sistema (activo o inactivo)
        vector<Proceso*> procesos; // Lista de procesos que se están ejecutando en el sistema

    public:
        // Constructor
        Sistema(int id, string nombre, string tipo) : id(id), nombre(nombre), tipo(tipo), estado(true) {}

        // Getters
        int getId();
        string getNombre();
        string getTipo();
        bool getEstado();

        // Setters
        void setId(int id);
        void setTipo(string tipo);
        void setNombre(string nombre);
        void setEstado(bool estado);

        // Métodos
        void agregarProceso(Proceso* proceso); // Agrega un proceso a la lista de procesos
        void eliminarProceso(int idProceso); // Elimina un proceso de la lista de procesos
        void listarProcesos(); // Muestra todos los procesos que se están ejecutando en el sistema
};