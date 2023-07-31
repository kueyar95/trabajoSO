#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include "Hardware.h"

class Sistema {
    private:
        int ID; // Identificador único del sistema
        string nombre; // Nombre del sistema
        string tipo; // Tipo de sistema (Banca, Recaudación de impuestos, Sistemas de pago, Sistemas de minado, etc.)
        bool estado; // Estado del sistema (activo o inactivo)
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
};

#endif