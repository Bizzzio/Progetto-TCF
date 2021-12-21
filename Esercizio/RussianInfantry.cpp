#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "RussianInfantry.h"

RussianInfantry::RussianInfantry() {
	name = "RussianInfantry";
}
void RussianInfantry::move() {
	cout << " si muove";
}
void RussianInfantry::fight() {
	cout << " e spara con il fucile ";
}
string RussianInfantry::getName() {
	return "La fanteria russa";
}
