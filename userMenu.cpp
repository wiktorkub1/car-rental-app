#include <iostream>
#include <iomanip>
#include <vector>

#include "Menu.h"
#include "vehicle.h"

void userMenu::MenuDisplay() {
    using namespace std;
    cout << setw(33) << setfill('-') << "" << endl;
    cout << left << setw(32) << setfill(' ') << "| User menu:" << "|" << endl;
    cout << left << setw(32) << "| 1.Show available vehicles" << "|" << endl;
    cout << left << setw(32) << "| 2.Rent a vehicle" << "|" << endl;
    cout << left << setw(32) << "| 3.Return a vehicle" << "|" << endl;
    cout << left << setw(32) << "| 4.Your rentals" << "|" << endl;
    cout << left << setw(32) << "| 5.Change account" << "|" << endl;
    cout << setw(33) << setfill('-') << "" << endl;

}

void userMenu::choice(std::vector<vehicle*>& database, std::vector<vehicle*>& databaseUser, int& menuChoice) {
    int optionChoice;
    
    std::cin >> optionChoice;
    switch (optionChoice) {
    case 1:
        userMenu::databaseDisplay(database);
        break;
    case 2:
        userMenu::vehicleRent(database, databaseUser);
        break;
    case 3:
        userMenu::vehicleReturn(databaseUser);
        break;
    case 4:
        userMenu::rentsDisplay(databaseUser);
        break;
    case 5:
        menuChoice = 3;
        Menu::MenuDisplay();
        break;
    }
}

void userMenu::vehicleRent(std::vector<vehicle*>& database, std::vector<vehicle*>& databaseUser) {
    int optionChoice;
    
    userMenu::databaseDisplay(database);
    std::cout << "Choose vehicle:" << std::endl;
    std::cin >> optionChoice;
    try {
        vehicle* Ptr = new vehicle(*database.at(optionChoice));
        databaseUser.push_back(Ptr);
    }
    catch (const std::out_of_range) {
        std::cerr << "Non-existing vehicle has been chosen\n";
    }
}

void userMenu::vehicleReturn(std::vector<vehicle*>& databaseUser) {

    int optionChoice;

    userMenu::databaseDisplay(databaseUser);
    std::cout << "Choose vehicle:" << std::endl;
    std::cin >> optionChoice;
    try {
        databaseUser.at(optionChoice);
        databaseUser.erase(databaseUser.begin() + optionChoice);
    }
    catch (const std::out_of_range) {
        std::cerr << "Non-existing vehicle has been chosen\n";
    }
}

void userMenu::rentsDisplay(std::vector<vehicle*> databaseUser) {
    std::cout << "Your rentals:\n";
    for (int j = 0; j < databaseUser.size(); j++) {
        std::cout << databaseUser[0]->getName() << "\n";
    }
}

void userMenu::databaseDisplay(std::vector<vehicle*> database) {
    using namespace std;

    cout << endl;
    cout << setfill(' ') << "|" << setw(3) << left << "NO" << "|" <<
        setw(8) << left << "TYPE" << "|" << setw(14) << left << "NAME" << "|" <<
        setw(8) << left << "POWER" << "|" << setw(5) << left << "A/C" << "|" <<
        setw(5) << left << "ENG." << "|" << setw(10) << left << "AVAILABLE" << "|" << endl;
    cout << setfill('-') << setw(61) << "" << endl;

    for (int j = 0; j < database.size(); j++) {
        cout << setfill(' ') << "|" << setw(3) << left << j << "|" <<
            setw(8) << left << database[j]->displayType() << "|" << setw(14) << left << database[j]->getName() << "|" <<
            setw(8) << left << database[j]->getPower() << "|" << setw(5) << left << database[j]->getAC() << "|" <<
            setw(5) << left << database[j]->getEngines() << "|" << setw(10) << left << database[j]->isAvailable() << "|" << endl;
    }

    cout << "\n\n";
}
