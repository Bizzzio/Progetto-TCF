#include <vector>
using std::vector;
#include "GermanFactory.h"
#include "Tiger.h"
#include "GermanInfantry.h"

GermanFactory::GermanFactory() {

	unit.push_back(new Tiger());
	unit.push_back(new Tiger());

	unit.push_back(new GermanInfantry());
	unit.push_back(new GermanInfantry());
}
GermanFactory::~GermanFactory() {
	vector<Unit*>::iterator i;
	for (i = unit.begin(); i != unit.end(); i++)
		delete* i;
}
int GermanFactory::sizeUnit() const {
	return unit.size();
}
vector<Unit*>::const_iterator GermanFactory::beginUnit() const {
	return unit.begin();
}
vector<Unit*>::const_iterator GermanFactory::endUnit() const {
	return unit.end();
}
vector<Unit*> GermanFactory::getArmy() const {
	return unit;
}