#pragma once

#include <string>

class vehicle {
public:
	vehicle(std::string StName, int power);
	vehicle(vehicle& original);

	std::string getName();
	int getPower();
	int getLoans();
	virtual std::string displayType() { return {}; };
	virtual std::string getAC()	{ return {}; };
	virtual std::string getEngines() { return {}; };
	std::string isAvailable();

	std::string name;
	int			horsepower;
	int			loansCounter{0};
	bool		rented;
};

class car : public vehicle {
public:
	car(std::string StName, int power, bool AC) : vehicle(StName, power) {
		airCond = AC;
	};

	std::string displayType();
	std::string getAC();
	std::string getEngines();
private:
	bool		airCond;
};

class boat : public vehicle {
public:
	boat(std::string StName, int power, int engines) : vehicle(StName, power) {
		numOfEngines = engines;
	};

	std::string displayType();
	std::string getAC();
	std::string getEngines();
private:
	int			numOfEngines;
};