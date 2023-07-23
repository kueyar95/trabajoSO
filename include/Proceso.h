#pragma once
#include <string>
#include <functional>
#include <vector>
using namespace std;

class Proceso {
    private:
        int id;
        string nombre;
        int idSistema;
        string estado;
        function<void()> funcion;
        int nivelPrivilegioRequerido;
        vector<string> recursos;

    public:
        Proceso(int id, string nombre, vector<string> recursos, function<void()> funcion, int nivelPrivilegioRequerido);
        // Getters
        int getId();
        string getNombre();
        string getEstado();
        vector<string> getRecursos();
        function<void()> getFuncion();
        int getNivelPrivilegioRequerido();

        // Setters
        void setId(int id);
        void setNombre(string nombre);
        void setEstado(string estado);
        void setRecursos(vector<string> recursos);
        void setFuncion(function<void()> funcParam);
        void setNivelPrivilegioRequerido(int nivelPrivilegioRequerido);
};