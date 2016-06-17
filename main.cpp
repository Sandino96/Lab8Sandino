#include "sirviente.h"
#include "trabajador.h"
#include "abastecedor.h"
#include "robot.h"
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(int argc, char*argv[]){
	int opcion,dias = 0;
	double amperios = 20000,dinero = 15000;
	vector<robot*> usuario;
	vector<robot*> creados;
	while (opcion != 7){
		cout << "Dias: " << dias << endl;
		cout << "Dinero: " << dinero << endl;
		cout << "Amperios: " << amperios << endl;
		cout << "MENU\n1.-Agregar Robots\n2.-Modificar Robots\n3.-Eliminar Robots\n4.-Comprar Robots\n5.-Usar funcion Robots\n6.-Botar Robots\n7.-Salir\nOpcion: ";	
		cin >> opcion;
		if(opcion == 1){
			int opcionRobots;
			while(opcionRobots != 4){
				cout << "\tRobots\n\t1.-Trabajador\n\t2.-Sirviente\n\t3.-Abastecedor\n\t4.-Salir\n\tOpcion: ";
				cin >> opcionRobots;
				if(opcionRobots == 1){
					string numeroSerie,material;
					double amperios,precio;
					cout << "\tNumero de serie: ";
					cin.ignore();
					getline(cin,numeroSerie);
					cout << "\tMaterial: ";
					cin.ignore();
					getline(cin,material);
					cout << "\tAmperios: ";
					cin >> amperios;
					cout << "\tPrecio: ";
					cin >> precio;
					creados.push_back(new trabajador(numeroSerie,amperios,material,precio));
					cout << "Agregado :3" << endl;
					cout << creados.at(creados.size() - 1) -> toString() << endl;
				} else if(opcionRobots == 2){
					string numeroSerie,material;
					double amperios,precio;
					cout << "\tNumero de serie: ";
					cin.ignore();
					getline(cin,numeroSerie);
					cout << "\tMaterial: ";
					cin.ignore();
					getline(cin,material);
					cout << "\tAmperios: ";
					cin >> amperios;
					cout << "\tPrecio: ";
					cin >> precio;
					creados.push_back(new sirviente(numeroSerie,amperios,material,precio));
					cout << "Agregado :3" << endl;
					cout << creados.at(creados.size() - 1) -> toString() << endl;
				} else if(opcionRobots == 3){
					string numeroSerie,material;
					double amperios,precio;
					cout << "\tNumero de serie: ";
					cin.ignore();
					getline(cin,numeroSerie);
					cout << "\tMaterial: ";
					cin.ignore();
					getline(cin,material);
					cout << "\tAmperios: ";
					cin >> amperios;
					cout << "\tPrecio: ";
					cin >> precio;
					creados.push_back(new abastecedor(numeroSerie,amperios,material,precio));
					cout << "Agregado :3" << endl;
					cout << creados.at(creados.size() - 1) -> toString() << endl;
				}
			}
		} else if (opcion == 2){
			for (int i = 0; i < creados.size(); i++){
				cout << i << " " << creados.at(i) -> toString() << endl;
			}
			int modificar;
			cout << "Posicion del robot que desea modificar: ";
			cin >> modificar;
			double precioNuevo, amperiosNuevo;
			cout << "Precio nuevo: ";
			cin >> precioNuevo;
			creados.at(modificar) -> setPrecio(precioNuevo);
			cout << "Amperios nuevos: ";
			cin >> amperiosNuevo;
			creados.at(modificar) -> setAmperios(amperiosNuevo);
			cout << creados.at(modificar) -> toString() << endl;
			cout << "Modificado :3" << endl;
		} else if (opcion == 3){
			for (int i = 0; i < creados.size(); i++){
				cout << i << " " << creados.at(i) -> toString() << endl;
			}
			int eliminar;
			cout << "Posicion del robot que quiere eliminar: ";
			cin >> eliminar;
			cout << "Eliminado :3" << endl;
			creados.erase(creados.begin() + eliminar);
		} else if(opcion == 4){
			if(creados.empty()){
				cout << "No hay robots para comprar" << endl;
			} else {
				for (int i = 0; i < creados.size(); i++)
					cout << i << " " << creados.at(i) -> toString() << endl;
				int comprar;
				cout << "Posicion del robot que desea comprar: ";
				cin >> comprar;
				if (creados.at(comprar) -> getPrecio() < dinero){
					if(creados.at(comprar) -> getAmperios() < amperios){
						dinero -= creados.at(comprar) -> getPrecio();
						amperios -= creados.at(comprar) -> getAmperios();
						usuario.push_back(creados.at(comprar));
						creados.erase(creados.begin() + comprar);
						cout << "Comprado :3" << endl;
					} else {
						cout << "No tiene suficientes amperios" << endl;
					}
				} else {
					cout << "No tiene suficiente dinero" << endl;
				}
			}
		} else if(opcion == 5){
			if(usuario.empty()){
				cout << "No tiene robots" << endl;
			} else {
				for (int i = 0; i < usuario.size(); i++)
				cout << i << " " << usuario.at(i) -> toString() << endl;
				int darFuncion;
				cout << "Posicion del robot que desea dar funcion: ";
				cin >> darFuncion;
				double robots = usuario.size();
				if(typeid(*usuario.at(darFuncion)) == typeid(abastecedor))
					usuario.at(darFuncion) -> funcionRobots(robots,dinero);
				else
					usuario.at(darFuncion) -> funcionRobots(amperios,dinero);
				dias++;
			}
		} else if(opcion == 6){
			for (int i = 0; i < usuario.size(); i++)
				cout << i << " " << usuario.at(i) -> toString() << endl;
			int eliminar;
			cout << "Posicion del robot que quiere eliminar: ";
			cin >> eliminar;
			usuario.erase(usuario.begin() + eliminar);
			cout << "Botado :3" << endl;
		} else if (opcion > 7)
			cout << "Esta opcion no existe" << endl;
	}
	for (int i = 0; i < creados.size(); i++)
		delete creados.at(i);
	for (int i = 0; i < usuario.size(); ++i){
		delete usuario.at(i);
	}
	return 0;
}