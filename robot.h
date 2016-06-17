#pragma once
#include <string>

using std::string;

class robot{
  protected:
	string numeroSerie;
	string material;
	double precio,amperios;
  public:
	robot(string,double,string,double);
	virtual ~robot();
	virtual string toString() const;
	virtual void funcionRobots(double&, double&) = 0;
	virtual void setPrecio(double);
	virtual void setAmperios(double);
	virtual double getPrecio();
	virtual double getAmperios();
};