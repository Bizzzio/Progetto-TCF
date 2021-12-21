#include <vector>
using std::vector;
#include "RussianFactory.h"
#include "T34.h"
#include "RussianInfantry.h"

RussianFactory::RussianFactory() {

	unit.push_back(new T34());
	unit.push_back(new T34());

	unit.push_back(new RussianInfantry());
	unit.push_back(new RussianInfantry());
}
RussianFactory::~RussianFactory() {

	vector<Unit*>::iterator i;
	for (i = unit.begin(); i != unit.end(); i++)
		delete* i;

}
int RussianFactory::sizeUnit() const {
	return unit.size();
}
vector<Unit*>::const_iterator RussianFactory::beginUnit() const {
	return unit.begin();
}
vector<Unit*>::const_iterator RussianFactory::endUnit() const {
	return unit.end();
}
vector<Unit*> RussianFactory::getArmy() const {
	return unit;
}
