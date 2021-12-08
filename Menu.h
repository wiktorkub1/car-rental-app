#pragma once

#include "vehicle.h"

class Menu {
public:
	Menu() {};
	static void MenuDisplay();
	virtual void databaseDisplay(std::vector<vehicle*> database) {};
	virtual void choice(std::vector<vehicle*>& database, int& menuChoice) {};
private:

protected:

};

class adminMenu : public Menu {
public:
	adminMenu() {};
	static void MenuDisplay();
	void choice(std::vector<vehicle*>& database, int& menuChoice);
	void vehicleAdd(std::vector<vehicle*>& database);
	void vehicleDelete(std::vector<vehicle*>& database);
	void databaseDisplay(std::vector<vehicle*>& database);
private:

protected:

};

class userMenu : public Menu {
public:
	userMenu() {};
	static void MenuDisplay();
	void choice(std::vector<vehicle*>& database, std::vector<vehicle*>& databaseUser, int& menuChoice);
	void databaseDisplay(std::vector<vehicle*> database);
	void vehicleRent(std::vector<vehicle*>& database, std::vector<vehicle*>& databaseUser);
	void vehicleReturn(std::vector<vehicle*>& databaseUser);
	void rentsDisplay(std::vector<vehicle*> databaseUser);
private:

protected:

};