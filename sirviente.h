#pragma once
#include <string>
#include "robot.h"

class sirviente : public robot{
  protected:
  	int oxido = 0;
  public:
	sirviente(string,double,string,double);
	virtual ~sirviente();
	virtual string toString() const;
	void funcionRobots(double&,double&);
	void setOxido(int);
	int getOxido();
};