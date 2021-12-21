#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "T34.h"

T34::T34() {
	name = "T34";
}
void T34::move() {
	cout << " si muove";
}
void T34::fight() {
	cout << " e spara con il cannone e con la mitragliatrice ";
}
string T34::getName() {
	return "Il carro T34";
}