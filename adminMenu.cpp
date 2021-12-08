#include <iostream>
#include <iomanip>
#include <vector>

#include "Menu.h"
#include "vehicle.h"

void adminMenu::MenuDisplay() {
    using namespace std;
    cout << setw(33) << setfill('-') << "" << endl;
    cout << left << setw(32) << setfill(' ') << "| Admin menu:" << "|" << endl;
    cout << left << setw(32) << "| 1.Add a vehicle" << "|" << endl;
    cout << left << setw(32) << "| 2.Delete a vehicle" << "|" << endl;
    cout << left << setw(32) << "| 3.Display database" << "|" << endl;
    cout << left << setw(32) << "| 4.Change account" << "|" << endl;
    cout << setw(33) << setfill('-') << "" << endl;
}

void adminMenu::choice(std::vector<vehicle*>& database, int& menuChoice) {

    int optionChoice;

    std::cin >> optionChoice;
    switch (optionChoice) {
    case 1:
        adminMenu::vehicleAdd(database);
        break;
    case 2:
        adminMenu::vehicleDelete(database);
        break;
    case 3:
        adminMenu::databaseDisplay(database);
        break;
    case 4:
        menuChoice = 0;
        Menu::MenuDisplay();
        break;
    }
}

void adminMenu::vehicleAdd(std::vector<vehicle*>& database) {

    int vehicleTypeChoice;
    int vehicleHorsepower;
    int boatEngines;
    bool vehicleAirCond;
    std::string vehicleName;
    car* carPtr;
    boat* boatPtr;

    std::cout << "1.Car\n"
              << "2.Boat\n";
    std::cin >> vehicleTypeChoice;
    switch (vehicleTypeChoice) {
    case 1:
        std::cout << "NAME: " << std::endl;
        std::cin >> vehicleName;
        std::cout << "POWER: " << std::endl;
        std::cin >> vehicleHorsepower;
        std::cout << "A/C (1/0): " << std::endl;
        std::cin >> vehicleAirCond;
        carPtr = new car(vehicleName, vehicleHorsepower, vehicleAirCond);
        database.push_back(carPtr);

        break;
    case 2:
        std::cout << "NAME: " << std::endl;
        std::cin >> vehicleName;
        std::cout << "POWER: " << std::endl;
        std::cin >> vehicleHorsepower;
        std::cout << "NUMBER OF ENGINES: " << std::endl;
        std::cin >> boatEngines;
        boatPtr = new boat(vehicleName, vehicleHorsepower, boatEngines);
        database.push_back(boatPtr);
        
        break;
    }
    std::cout << std::endl;
}

void adminMenu::vehicleDelete(std::vector<vehicle*>& database) {

    int optionChoice;

    adminMenu::databaseDisplay(database);
    std::cout << "Choose vehicle:" << std::endl;
    std::cin >> optionChoice;
    
    try {
        database.at(optionChoice);  //throw exception if out of range
        if (database[optionChoice]->rented == true) {
            std::cout << "You can't delete rented vehicle" << std::endl;
        }
        else {
            database.erase(database.begin() + optionChoice);
        }
    }
    catch (const std::out_of_range) {
        std::cerr << "Non-existing vehicle has been chosen\n";
    }
}

void adminMenu::databaseDisplay(std::vector<vehicle*>& database) {
    using namespace std;

    cout << endl;
    cout << setfill(' ') << "|" << setw(3) << left << "NO" << "|" <<
        setw(8) << left << "TYPE" << "|" << setw(14) << left << "NAME" << "|" <<
        setw(8) << left << "POWER" << "|" << setw(5) << left << "A/C" << "|" <<
        setw(5) << left << "ENG." << "|" << setw(5) << left << "LOANS" << "|" << endl;
    cout << setfill('-') << setw(56) << "" << endl;
    
    for (int j = 0; j < database.size(); j++) {
        cout << setfill(' ') << "|" << setw(3) << left << j << "|" <<
            setw(8) << left << database[j]->displayType() << "|" << setw(14) << left << database[j]->getName() << "|" <<
            setw(8) << left << database[j]->getPower() << "|" << setw(5) << left << database[j]->getAC() << "|" <<
            setw(5) << left << database[j]->getEngines() << "|" << setw(5) << left << database[j]->getLoans() << "|" << endl;
    }

    cout << "\n\n";
}
