#include "sirviente.h"
#include "robot.h"
#include <string>
#include <sstream>
#include <iostream>

using std::string;
using std::stringstream;
using std::cout;
using std::endl;

sirviente::sirviente(string numeroSerie, double amperios, string material, double precio):robot(numeroSerie,amperios,material,precio){

}

sirviente::~sirviente(){

}

string sirviente::toString() const{
	stringstream ss;
	ss << "Sirviente" << robot::toString();
	return ss.str();
}

void sirviente::funcionRobots(double& amperiosUsuario,double& precioUsuario){
	setOxido(getOxido());
	if(getOxido() == 100){
		amperiosUsuario+=amperios;
	}
}

void sirviente::setOxido(int oxido){
	oxido+=5;
}

int sirviente::getOxido(){
	return oxido;
}
