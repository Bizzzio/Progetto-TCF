#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "GermanInfantry.h"

GermanInfantry::GermanInfantry() {
	name = "GermanInfantry";
}
void GermanInfantry::move() {
	cout << " si muove";
}
void GermanInfantry::fight() {
	cout << " e spara con il fucile";
}
string GermanInfantry::getName() {
	return "La fanteria tedesca";
}

