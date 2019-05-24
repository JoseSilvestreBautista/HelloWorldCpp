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
void menu(); // display main menu

void processing(int); // prevents user from invalid choice in main menu

int produceItems(); // next menu from choosing 1. from main menu also serial number for products

void saveToFile(); // creates a file

void writeToFile(); // writes and reads file

void writeAppend();

void itemTypeMenu(); // item display menu. it was created to display several times if user has invalid selection

int main() {  // drives the entire program by calling other functions.
    saveToFile();
    writeToFile();

    std::cout << "Hello User!\n" << std::endl; // user greeting
    menu(); // call to the main menu to display
    int userMenuSelection; // call to the main menu
    do { // ask user to select from the main menu and prevents them from choosing invalid selections
        std::cin >> userMenuSelection;
        processing(userMenuSelection);
    } while (userMenuSelection > 6 || userMenuSelection < 1);
    writeAppend();
    return 0;
}

void saveToFile() { //opens a file, then writes in file, then closes.
    std::ofstream myfile;
    myfile.open("Production.txt");
    myfile << "produceItems\n";
    myfile.close();
}

void writeToFile() {
    std::ofstream myfile;
    if (myfile.is_open()) {
        myfile << "This is a line.\n";
        myfile << "This is another line.\n";
        myfile.close();
    } else std::cout << "Unable to open file";
}

void writeAppend() {
    std::ofstream myFile;
    myFile.open("Production.txt", std::ios_base::app);
    myFile << "writeAppend called. Writing this to example.txt" << "\n";
    myFile.close();
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

void stub() { // dummy function used as a temporary call for future function not built
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
    } else {
        std::cout << "Not a valid selection" << std::endl;
        menu();
    }
}

int produceItems() { // submenu from selecting 1. Produce Items from main menu
    // Eventually the user will be able to choose the item to produce.
    // For now, just have them input the information.
    std::cout << "Enter the Manufacturer\n";
    std::string manufacturer;
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
        } else {
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
    for (int productNumber = 1; productNumber <= numProduced; ++productNumber) {
        std::cout << "Production Number: " << productNumber << " Serial Number: " << manufacturer.substr(0, 3)
                  << itemTypeCode
                  << std::flush;
        printf("%05d\n", productNumber);
    }
    return 0;
}

void itemTypeMenu() { //  itemTypeMenu from produce items
    std::cout << "Enter the item type\n";
    std::cout << "1. Audio\n" <<
              "2. Visual\n" <<
              "3. AudioMobile\n" <<
              "4. VisualMobile\n";
}
