#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Menu.h"
#include "vehicle.h"

Menu        Mainmenu = Menu();
adminMenu   Adminmenu = adminMenu();
userMenu    Usermenu = userMenu();
std::vector<Menu*> Menus = { &Mainmenu, &Adminmenu, &Usermenu };
std::vector<vehicle*> vehicleDatabase;
std::vector<vehicle*> rentedVehicles;

int main(){

    int menuChoice{ 0 };

    do {
        switch (menuChoice) {
        case 0:
            Menu::MenuDisplay();             //main menu
            break;
        case 1:
            while (menuChoice == 1) {
                adminMenu::MenuDisplay();    //admin menu
                Adminmenu.choice(vehicleDatabase, menuChoice);
            }
            break;
        case 2:
            while (menuChoice == 2) {
                userMenu::MenuDisplay();     //user menu
                Usermenu.choice(vehicleDatabase, rentedVehicles, menuChoice);
            }
            break;
        case 3:
            menuChoice = 3;
            break;
        }
        std::cin >> menuChoice;
    } while (menuChoice != 3);
}
