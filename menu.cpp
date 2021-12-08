#include <iostream>
#include <iomanip>
#include <vector>

#include "Menu.h"
#include "vehicle.h"

void Menu::MenuDisplay() {
    std::cout << "1. Admin" << std::endl;
    std::cout << "2. User" << std::endl;
    std::cout << "3. Exit" << std::endl;
}
