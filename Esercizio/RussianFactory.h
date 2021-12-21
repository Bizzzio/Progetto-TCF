#ifndef RussianFactory_h
#define RussianFactory_h
#include <vector>
using std::vector;
#include "Unit.h"
#include "ArmyFactory.h"

class RussianFactory : public ArmyFactory {

public:
	RussianFactory();
	~RussianFactory();
	int sizeUnit() const;
	vector<Unit*>::const_iterator beginUnit() const;
	vector<Unit*>::const_iterator endUnit() const;
	vector<Unit*> getArmy() const;
private:
	vector<Unit*> unit;

};
#endif
