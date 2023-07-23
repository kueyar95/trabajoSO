#include <vector>
#include "Hardware.h"
#include "Proceso.h"

class Sistema {
    private:
        int ID; // Identificador único del sistema
        string nombre; // Nombre del sistema
        string tipo; // Tipo de sistema (Banca, Recaudación de impuestos, Sistemas de pago, Sistemas de minado, etc.)
        bool estado; // Estado del sistema (activo o inactivo)
        vector<Proceso*> procesos; // Lista de procesos que se están ejecutando en el sistema
        double saldo;
        string IP;

    public:
        // Constructor
        Sistema(int ID, string nombre, string tipo, string IP) : ID(ID), nombre(nombre), tipo(tipo), estado(true), saldo(0.0), IP(IP) {}

        // Getters
        int getId();
        string getNombre();
        string getTipo();
        bool getEstado();
        double getSaldo();
        string getIp();
        // Setters
        void setId(int ID);
        void setTipo(string tipo);
        void setNombre(string nombre);
        void setEstado(bool estado);
        void setSaldo(double saldo);
        void setIp(string IP);
        // Métodos
        void agregarProceso(Proceso* proceso); // Agrega un proceso a la lista de procesos
        void eliminarProceso(int idProceso); // Elimina un proceso de la lista de procesos
        void listarProcesos(); // Muestra todos los procesos que se están ejecutando en el sistema
};