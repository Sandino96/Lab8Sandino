#pragma once
#include <string>
#include "robot.h"

class trabajador : public robot{
  public:
  	trabajador(string,double,string,double);
  	virtual ~trabajador();
  	virtual string toString() const;
  	void funcionRobots(double&,double&);
};