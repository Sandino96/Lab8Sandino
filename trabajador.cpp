#include "trabajador.h"
#include "robot.h"
#include <string>
#include <sstream>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

trabajador::trabajador(string numeroSerie, double amperios, string material, double precio):robot(numeroSerie,amperios,material,precio){
}

trabajador::~trabajador(){
}

string trabajador::toString() const{
	stringstream ss;
	ss << "Trabajador " << robot::toString();
	return ss.str();
}

void trabajador::funcionRobots(double& amperiosUsuario,double& precioUsuario){
	double uso = (amperiosUsuario*0.1) + amperiosUsuario;
	if(amperiosUsuario < uso){
		precioUsuario += 200.00;
		amperiosUsuario -= uso;
	} else {
		cout << "No hay suficientes amperios" << endl;
	}
}
