#pragma once
#include<string>
#include<vector>
#include"Proceso.h"
using namespace std;

class AdministradorProcesos {
    private:
        vector<Proceso*> procesosList;
        int ultimoId;

    public:
        AdministradorProcesos();

        Proceso* agregarProceso(string nombre, int idSistema, vector<string> recursos);
        void eliminarProceso(int id);
        Proceso* buscarProceso(string nombre);
        void listarProcesos();
        void cargarProcesos();
        void guardarProceso(Proceso* proceso);
        void guardarUltimoId();
        void cargarUltimoId();
        void iniciarProceso(int id);
        void detenerProceso(int id);
};