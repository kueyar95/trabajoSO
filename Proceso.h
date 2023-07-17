#pragma once
#include <string>
#include <vector>
using namespace std;

class Proceso {
    private:
        int id;
        string nombre;
        int idSistema;
        string estado;
        vector<string> recursos;

    public:
        Proceso(int id, string nombre, int idSistema, vector<string> recursos);

        // Getters
        int getId();
        string getNombre();
        int getIdSistema();
        string getEstado();
        vector<string> getRecursos();

        // Setters
        void setId(int id);
        void setNombre(string nombre);
        void setIdSistema(int idSistema);
        void setEstado(string estado);
        void setRecursos(vector<string> recursos);
};