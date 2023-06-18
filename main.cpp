#include <string>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include "Hardware.h"
#include<vector>
#include <limits>
#include<fstream>
#include "AdministradorHardware.h"
using namespace std;

void menuGeneral();
void menuEntidades();
void menuSistemas();
void menuHardware();
void menuUsuarios();
void reiniciar();
void imprimirLog();
void inicioRapido();
void mostrarPanelControl();

int main()
{
	menuGeneral();
	return 0;
}
void menuGeneral(){
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
		cout<<"4. Ver hardware"<<endl;
		cout<<"5. Eliminar todo el hardware"<<endl;
		cout<<"6. Eliminar hardware"<<endl;
		cout<<"7. Modificar hardware"<<endl;
		cout<<"8. Atras"<<endl;
		cout<<"9. Salir"<<endl;
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
                nuevoHardware = administradorHard.agregarHardware(tipo, marca, modelo, capacidad, velocidad);
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
				// verDetalleHardware();
				// system("pause");
				break;
			 case 5:
			 	cout << "Ingrese el id del hardware que desea eliminar: ";
				cin >> id;
			 	administradorHard.eliminarHardware(id);
				system("pause");
			 	break;
			 case 6:
			 	// eliminarDetalleHardware();
				// system("pause");
			 	break;
			 case 7:
			 	// modificarHardware();
				// system("pause");
			 	break;
			case 8:
				menuGeneral();
				system("pause");
			break;
			case 9:	break;
		}
		system("cls");
	} while (opcion < 9);
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