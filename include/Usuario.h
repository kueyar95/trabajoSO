#ifndef USUARIO_H
#define USUARIO_H
#include <string>
using namespace std;

class Usuario {
    private:
        int id; // ID del usuario
        string nombre; // Nombre del usuario
        string tipo; // Tipo de usuario (por ejemplo, humano, sistema, etc.)
        int nivelAcceso; // Nivel de acceso o privilegios del usuario
        double saldo;

    public:
        Usuario(int id, string nombre, string tipo, int nivelAcceso)
                : id(id), nombre(nombre), tipo(tipo), nivelAcceso(nivelAcceso) {}
        int getId();
        string getNombre();
        void setNombre(string nombre);
        string getTipo();
        double getSaldo();
        void setTipo(string tipo);
        int getNivelAcceso();
        void setNivelAcceso(int nivelAcceso);
        void setEstado(bool estado);
        void setSaldo(double saldo);
};

#endif
