#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA() {}


void HumanA::attack() {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
