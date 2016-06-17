#pragma once
#include "robot.h"
#include <string>

using std::string;

class abastecedor : public robot{
  public:
  	abastecedor(string,double,string,double);
  	virtual ~abastecedor();
  	virtual string toString() const;
  	void funcionRobots(double&,double&);
};