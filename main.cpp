/** @file production.txt
 *  @brief A program that tracks products at a warehouse
 *  @author Jose Silvestre-Bautista
 *  @bug no known bugs
 */

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <string>

// these are prototypes
/**
 * @brief  Is the main menu display for employees.
 */
void menu();

/**
 * @brief Process the user's main menu selection and prevents improper selection.
 * @param Takes the user's number input for main menu selection: userMenuSelection.
 */
void processing(int);

/**
 * @brief  Function that records products made using serial numbers.
 * The result of choosing produce items from main menu.
 */
int produceItems();

/**
 * @brief Item type menu from produceItems function.
 */
void itemTypeMenu(); // item display menu. it was created to display several times if user has invalid selection

int main() {  // drives the entire program by calling other functions.

    std::cout << "Hello User!\n" << std::endl; // user greeting
    menu(); // call to the main menu to display
    int userMenuSelection; // call to the main menu
    do { // ask user to select from the main menu and prevents them from choosing invalid selections
        std::cin
                >> userMenuSelection;// the loop should be removed to its own function to keep main clean and efficient.
        processing(userMenuSelection);
    } while (userMenuSelection > 6 || userMenuSelection < 1);
    return 0;
}

void menu() { // main menu display
    std::cout << "Production Line Tracker\n" << std::endl;
    std::cout << "1. Produce Items" << std::endl;
    std::cout << "2. Add Employee Account" << std::endl;
    std::cout << "3. Add Music Player" << std::endl;
    std::cout << "4. Add Movie Player" << std::endl;
    std::cout << "5. Display Production Statistics" << std::endl;
    std::cout << "6. Exit" << std::endl;
}

void stub() { // dummy function used as a temporary call for future function not yet built.
    std::cout << "I am the stub" << std::endl;
}

void processing(int userMenuSelection) { // main menu decision function. passes user to next submenu and
    if (userMenuSelection == 1) {       // keeps the user from choosing an invalid menu selection.
        produceItems(); // takes to submenu called produceItems
    } else if (userMenuSelection == 2) {
        stub();
    } else if (userMenuSelection == 3) {
        stub();
    } else if (userMenuSelection == 4) {
        stub();
    } else if (userMenuSelection == 5) {
        stub();
    } else if (userMenuSelection == 6) {
        std::cout << "Exit" << std::endl;
    } else { // may fail if user types letters. Fix this issue
        std::cout << "Not a valid selection" << std::endl;
        menu();
    }
}

int produceItems() { // submenu from selecting 1. Produce Items from main menu
    // Eventually the user will be able to choose the item to produce.
    // For now, just have them input the information.
    std::cout << "Enter the Manufacturer\n";
    std::string manufacturer; // Ask for the companies name
    std::cin >> manufacturer;
    std::cout << "Enter the Product Name\n";
    std::string prodName;
    std::cin >> prodName;
    itemTypeMenu(); // a display menu for item type
    int itemTypeChoice;
    std::cin >> itemTypeChoice;
    std::string itemTypeCode;

    do { // keeps the user from choosing invalid selection
        if (itemTypeChoice == 1) {
            itemTypeCode = "MM";
        } else if (itemTypeChoice == 2) {
            itemTypeCode = "VI";
        } else if (itemTypeChoice == 3) {
            itemTypeCode = "AM";
        } else if (itemTypeChoice == 4) {
            itemTypeCode = "VM";
        } else { // falls to produce ItemTypeChoice if user selects invalid choice the first time. Fix issue.
            std::cout << "Invalid Input\n" << std::endl;
            itemTypeMenu();
            std::cin >> itemTypeChoice;
        }
    } while (itemTypeChoice > 4 || itemTypeChoice < 1);

    std::cout << "Enter the number of items that were produced\n";
    int numProduced;
    std::cin >> numProduced;
    // add a loop to record production, for now simply by
    // outputting production number and serial number
    // produces the serial number products
    int productNumber;
    std::ofstream myfile("Production.txt", std::ios::app); // This create the file Production.txt and appends data.
    myfile.is_open();// opens the file

    for (productNumber = 0; productNumber < numProduced;) {
        ++productNumber;
        std::cout << "Production Number: " << productNumber << " Serial Number: " << manufacturer.substr(0, 3)
                  << itemTypeCode << std::setfill('0') << std::setw(5) << productNumber
                  << std::endl;

        myfile << "Production Number: " << productNumber << " Serial Number: " << manufacturer.substr(0, 3)
               << itemTypeCode << std::setfill('0') << std::setw(5) << productNumber
               << std::endl; // this code chunk  writes the serial number to the Production.txt file.

    }
    myfile.close();// closes the Production.txt file

    return 0;
}

void itemTypeMenu() { //  itemTypeMenu from produce items
    std::cout << "Enter the item type\n";
    std::cout << "1. Audio\n" <<
              "2. Visual\n" <<
              "3. AudioMobile\n" <<
              "4. VisualMobile\n";
}


