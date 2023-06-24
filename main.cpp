#include <string>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include "Hardware.h"
#include<vector>
#include <limits>
#include<fstream>
#include "AdministradorHardware.h"
#include "AdministradorUsuario.h"
using namespace std;

void menuGeneral();
void menuGeneralSuperUsuario();
void menuGeneralAdministrador();
void menuGeneralUsuario();
void menuGeneralVisita();
void menuEntidades();
void menuSistemas();
void menuHardware();
void menuUsuarios();
void reiniciar();
void imprimirLog();
int iniciarSesion();
void mostrarPanelControl();

int main()
{
	menuGeneral();
	return 0;
}

int iniciarSesion() {
    AdministradorUsuario adminUsuario;
    adminUsuario.cargarUsuarios();

    while (true) {
        cout << "Por favor, ingrese su nombre de usuario (presione enter para continuar como invitado): ";
        string nombreUsuario;
        getline(cin, nombreUsuario);

        Usuario* usuario;
        if (nombreUsuario.empty()) {
            usuario = new Usuario(0, "Invitado", "Usuario", 0);
            return usuario->getNivelAcceso();
        } else {
            usuario = adminUsuario.buscarUsuario(nombreUsuario);
            if (usuario == nullptr) {
                cout << "Usuario no encontrado." << endl;
                cout << "1. Intentar de nuevo" << endl;
                cout << "2. Continuar como invitado" << endl;
                cout << "3. Salir" << endl;
                cout << "Opcion: ";
                int opcion;
                cin >> opcion;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada

                switch (opcion) {
                    case 1:
                        continue;
                    case 2:
                        usuario = new Usuario(0, "Invitado", "Usuario", 0);
                        return usuario->getNivelAcceso();
                    case 3:
                        exit(1);
                    default:
                        cout << "Opcion no reconocida. Saliendo del programa." << endl;
                        exit(1);
                }
            } else {
                return usuario->getNivelAcceso();
            }
        }
    }
}

void menuGeneral(){
	int nivelAcceso = iniciarSesion();
	switch (nivelAcceso) {
		case 0:
			menuGeneralVisita();
			break;
		case 1:
			menuGeneralUsuario();
			break;
		case 2:
			menuGeneralAdministrador();
			break;
		case 3:
			menuGeneralSuperUsuario();
			break;
		default:
			cout << "Nivel de acceso no reconocido. Saliendo del programa." << endl;
			exit(1);
	}
}
void menuGeneralSuperUsuario(){
	int opcion, dato, contador = 0;
	char rpt;
	do
	{
		cout<<"\n\t.:MENU GENERAL:. \n";
		cout<<"1. Administrar Entidades"<<endl;
		cout<<"2. Administrar Sistemas"<<endl;
		cout<<"3. Administrar Hardware"<<endl;
		cout<<"4. Administrar Usuarios"<<endl;
		cout<<"5. Reiniciar"<<endl;
		cout<<"6. Log"<<endl;
		cout<<"7. Inicio Rápido"<<endl;
		cout<<"8. Visualizar Panel de Control"<<endl;
		cout<<"9. Salir"<<endl;
		cout<<"Opcion: "<<endl;
		cin>>opcion;

		switch (opcion)
		{
			case 1:
				// menuEntidades();
				// system("pause");
				break;
			 case 2:
				// menuSistemas();
			 	// system("pause");
			 	break;
			 case 3:
			 	menuHardware();
				system("pause");
			 	break;
			case 4:
				// menuUsuarios();
				// system("pause");
				break;
			 case 5:
			 	// reiniciar();
				// system("pause");
			 	break;
			 case 6:
			 	// imprimirLog();
				// system("pause");
			 	break;
			 case 7:
			 	// inicioJuego();
				// system("pause");
			 	break;
			case 8:
				// mostrarPanelControl();
				// system("pause");
			break;
		}
		// system("cls");
	} while (opcion < 9);
}
void menuGeneralAdministrador(){
	int opcion, dato, contador = 0;
	char rpt;
	do
	{
		cout<<"\n\t.:MENU GENERAL:. \n";
		cout<<"1. Administrar Entidad"<<endl;
		cout<<"2. Administrar Sistema"<<endl;
		cout<<"3. Administrar Hardware"<<endl;
		cout<<"4. Administrar Usuarios"<<endl;
		cout<<"5. Programar Eventos"<<endl;
		cout<<"6. Salir"<<endl;
		cout<<"Opcion: "<<endl;
		cin>>opcion;

		switch (opcion)
		{
			case 1:
				// menuEntidades();
				// system("pause");
				break;
			 case 2:
				// menuSistemas();
			 	// system("pause");
			 	break;
			 case 3:
			 	menuHardware();
				system("pause");
			 	break;
			case 4:
				// menuUsuarios();
				// system("pause");
				break;
			case 5:
			 	// reiniciar();
				// system("pause");
			 	break;
			case 6:	break;
		}
		// system("cls");
	} while (opcion < 6);
}
void menuGeneralUsuario(){
	int opcion;
    do
    {
        cout<<"\n\t.:MENU USUARIO:. \n";
        cout<<"1. Acceder a Sistema de Pagos"<<endl;
        cout<<"2. Acceder a Sistema de Recaudación de Impuestos"<<endl;
        cout<<"3. Acceder a Sistema de Banca"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"Opcion: "<<endl;
        cin>>opcion;
        // Aquí va el código para manejar las opciones
    } while (opcion != 4);
}
void menuGeneralVisita(){}
void menuEntidades(){
	int opcion;
	do
	{
		// cout<<"\n\t.:MENU ENTIDADES:. \n";
		// cout<<"1. Creacion rapida de entidad"<<endl;
		// cout<<"2. Crear nueva entidad"<<endl;
		// cout<<"3. Ver todas las entidades"<<endl;
		// cout<<"4. Ver entidad"<<endl;
		// cout<<"5. Eliminar todas las entidades"<<endl;
		// cout<<"6. Eliminar entidad"<<endl;
		// cout<<"7. Modificar entidad"<<endl;
		// cout<<"8. Atras"<<endl;
		// cout<<"9. Salir"<<endl;
		// cout<<"Opcion: "<<endl;
		// cin>>opcion;

		// switch (opcion)
		// {
		// 	case 1:
		// 		creacionRapidoEntidad();
		// 		system("pause");
		// 		break;
		// 	 case 2:
		// 		crearEntidad();
		// 	 	system("pause");
		// 	 	break;
		// 	 case 3:
		// 	 	verEntidades();
		// 		system("pause");
		// 	 	break;
		// 	case 4:
		// 		verEntidad();
		// 		system("pause");
		// 		break;
		// 	 case 5:
		// 	 	eliminarEntidades();
		// 		system("pause");
		// 	 	break;
		// 	 case 6:
		// 	 	eliminarEntidad();
		// 		system("pause");
		// 	 	break;
		// 	 case 7:
		// 	 	modificarEntidad();
		// 		system("pause");
		// 	 	break;
		// 	case 8:
		// 		menuGeneral();
		// 		system("pause");
		// 	break;
		// 	case 9:	break;
		// }
		// system("cls");
	} while (opcion < 9);
}
void menuSistemas(){
	int opcion;
	do
	{
		// cout<<"\n\t.:MENU SISTEMAS:. \n";
		// cout<<"1. Creacion rapida de sistema"<<endl;
		// cout<<"2. Crear nuevo sistema"<<endl;
		// cout<<"3. Ver todos los sistemas"<<endl;
		// cout<<"4. Ver sistema"<<endl;
		// cout<<"5. Eliminar todos los sistemas"<<endl;
		// cout<<"6. Eliminar sistema"<<endl;
		// cout<<"7. Modificar sistema"<<endl;
		// cout<<"8. Atras"<<endl;
		// cout<<"9. Salir"<<endl;
		// cout<<"Opcion: "<<endl;
		// cin>>opcion;

		// switch (opcion)
		// {
		// 	case 1:
		// 		creacionRapidoSistema();
		// 		system("pause");
		// 		break;
		// 	 case 2:
		// 		crearSistema();
		// 	 	system("pause");
		// 	 	break;
		// 	 case 3:
		// 	 	verSistemas();
		// 		system("pause");
		// 	 	break;
		// 	case 4:
		// 		verSistema();
		// 		system("pause");
		// 		break;
		// 	 case 5:
		// 	 	eliminarSistemas();
		// 		system("pause");
		// 	 	break;
		// 	 case 6:
		// 	 	eliminarSistema();
		// 		system("pause");
		// 	 	break;
		// 	 case 7:
		// 	 	modificarSistema();
		// 		system("pause");
		// 	 	break;
		// 	case 8:
		// 		menuGeneral();
		// 		system("pause");
		// 	break;
		// 	case 9:	break;
		// }
		// system("cls");
	} while (opcion < 9);
}
void menuHardware(){
	AdministradorHardware administradorHard;
	string tipo, modelo, marca;
    int id, capacidad, almacenamiento, velocidad, opcion;
	Hardware* nuevoHardware = nullptr;
	do
	{
		cout<<"\n\t.:MENU HARDWARE:. \n";
		cout<<"1. Crear nuevo hardware"<<endl;
		cout<<"2. Cargar hardware creado"<<endl;
		cout<<"3. Ver todo el hardware"<<endl;
		cout<<"4. Eliminar hardware"<<endl;
		cout<<"5. Eliminar todo el hardware"<<endl;
		cout<<"6. Modificar hardware"<<endl;
		cout<<"7. Atras"<<endl;
		cout<<"8. Salir"<<endl;
		cout<<"Opcion: "<<endl;
		cin>>opcion;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta el salto de línea en el búfer de entrada

		switch (opcion)
		{
			case 1:
                cout << "Ingrese el tipo de hardware: ";
				getline(cin, tipo);
                cout << "Ingrese la marca del hardware: ";
				getline(cin, marca);
				cout << "Ingrese el nombre del hardware: ";
				getline(cin, modelo);
                cout << "Ingrese la capacidad del hardware: ";
				cin >> capacidad;
				cout << "Ingrese la velocidad del hardware: ";
                cin >> velocidad;
                nuevoHardware = administradorHard.agregarHardware(tipo, marca, modelo, capacidad, velocidad, false);
    			administradorHard.guardarHardware(nuevoHardware);
				system("pause");
				break;
			 case 2:
				administradorHard.cargarHardware();
			 	system("pause");
			 	break;
			 case 3:
			 	administradorHard.verHardware();
				system("pause");
			 	break;
			case 4:
				cout << "Ingrese el id del hardware que desea eliminar: ";
				cin >> id;
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta el salto de línea en el búfer de entrada
			 	administradorHard.eliminarHardware(id);
				system("pause");
				break;
			 case 5:
			 	cout << "Eliminando hardware...\n";
			 	administradorHard.eliminarTodoHardware();
				system("pause");
			 	break;
			 case 6:
			 	cout << "Ingrese el id del hardware que desea modificar: ";
				cin >> id;
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta el salto de línea en el búfer de entrada
			 	administradorHard.modificarHardware(id);
				system("pause");
			 	break;
			 case 7:
			 	menuGeneral();
				system("pause");
			 	break;
			case 8:	break;
		}
		system("cls");
	} while (opcion < 8);
}
void menuUsuarios(){
	int opcion;
	do
	{
		// cout<<"\n\t.:MENU USUARIOS:. \n";
		// cout<<"1. Creacion rapida de usuario"<<endl;
		// cout<<"2. Crear nuevo usuario"<<endl;
		// cout<<"3. Ver todos los usuarios"<<endl;
		// cout<<"4. Ver usuario"<<endl;
		// cout<<"5. Eliminar todos los usuarios"<<endl;
		// cout<<"6. Eliminar usuario"<<endl;
		// cout<<"7. Modificar usuario"<<endl;
		// cout<<"8. Atras"<<endl;
		// cout<<"9. Salir"<<endl;
		// cout<<"Opcion: "<<endl;
		// cin>>opcion;

		// switch (opcion)
		// {
		// 	case 1:
		// 		creacionRapidoUsuario();
		// 		system("pause");
		// 		break;
		// 	 case 2:
		// 		crearUsuario();
		// 	 	system("pause");
		// 	 	break;
		// 	 case 3:
		// 	 	verUsuarios();
		// 		system("pause");
		// 	 	break;
		// 	case 4:
		// 		verUsuario();
		// 		system("pause");
		// 		break;
		// 	 case 5:
		// 	 	eliminarUsuarios();
		// 		system("pause");
		// 	 	break;
		// 	 case 6:
		// 	 	eliminarUsuario();
		// 		system("pause");
		// 	 	break;
		// 	 case 7:
		// 	 	modificarUsuario();
		// 		system("pause");
		// 	 	break;
		// 	case 8:
		// 		menuGeneral();
		// 		system("pause");
		// 	break;
		// 	case 9:	break;
		// }
		// system("cls");
	} while (opcion < 9);
}