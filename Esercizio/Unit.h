#ifndef Unit_h
#define Unit_h
#include <string>
using std::string;

class Unit {

public:
	virtual ~Unit() {};
	virtual void move() = 0;
	virtual void fight() = 0;
	virtual string getName() = 0;
};

#endif 
