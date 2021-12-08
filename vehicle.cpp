#include <iostream>
#include <iomanip>

#include "vehicle.h"

vehicle::vehicle(std::string StName, int power) {
	name = StName;
	horsepower = power;
	rented = false;
}
vehicle::vehicle(vehicle& original) {
	this->name = original.name;
	this->horsepower = original.horsepower;

	this->loansCounter = 0;
	original.loansCounter++;
	original.rented = true;
}
std::string vehicle::getName() {
	return this->name;
}
int vehicle::getPower() {
	return this->horsepower;
}
int vehicle::getLoans() {
	return this->loansCounter;
}
std::string vehicle::isAvailable() {
	std::string container;
	if (this->rented) {
		container = "NO";
	}
	else {
		container = "YES";
	}
	return container;
}

std::string car::displayType() {
	std::string container = "car";
	return container;
}
std::string car::getAC() {
	std::string container;
	if (this->airCond) {
		container = "YES";
	}
	else {
		container = "NO";
	}
	return container;
}
std::string car::getEngines() {
	std::string container = "na";
	return container;
}

std::string boat::displayType() {
	std::string container = "boat";
	return container;
}
std::string boat::getAC() {
	std::string container = "na";
	return container;
}
std::string boat::getEngines() {
	std::string container = std::to_string(this->numOfEngines);
	return container;
}
