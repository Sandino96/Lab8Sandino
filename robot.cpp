#include "robot.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

robot::robot(string numeroSerie, double amperios, string material, double precio):numeroSerie(numeroSerie),amperios(amperios),material(material),precio(precio){

}

robot::~robot(){

}

string robot::toString() const{
	stringstream ss;
	ss << "Numero de serie: " << numeroSerie << ", amperios: " << amperios << ", material hecho: " << material << " y su precio es: " << precio << "$";
	return ss.str();
}

void robot::setPrecio(double precio){
	this -> precio = precio;
}

void robot::setAmperios(double amperios){
	this -> amperios = amperios;
}

double robot::getPrecio(){
	return precio;
}

double robot::getAmperios(){
	return amperios;
}