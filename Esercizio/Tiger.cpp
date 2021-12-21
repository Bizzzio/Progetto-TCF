#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "Tiger.h"

Tiger::Tiger() {
	name = "Tiger";
}
void Tiger::move() {
	cout << " si muove";
}
void Tiger::fight() {
	cout << " e spara con il cannone e con la mitragliatrice ";
}
string Tiger::getName() {
	return "Il carro Tiger";
}
