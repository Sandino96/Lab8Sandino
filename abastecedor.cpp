#include "abastecedor.h"
#include "robot.h"
#include <string>
#include <sstream>
#include <iostream>

using std::string;
using std::stringstream;
using std::cout;
using std::endl;

abastecedor::abastecedor(string numeroSerie, double amperios, string material, double precio):robot(numeroSerie,amperios,material,precio){
}

abastecedor::~abastecedor(){
}

string abastecedor::toString() const{
	stringstream ss;
	ss << "Abastecedor " << robot::toString();
	return ss.str();
}

void abastecedor::funcionRobots(double& robots,double& precioUsuario){
	double dineroUsado = robots * 100;
	if (dineroUsado < precioUsuario){
		precioUsuario -= dineroUsado;
	} else {
		cout << "No tiene dinero suficiente" << endl;
	}
}