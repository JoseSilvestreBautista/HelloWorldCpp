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
#include <vector>
#include <algorithm>

#include "prototypes.h"

int main() {  // drives the entire program by calling other functions.

    std::cout << "Hello User!\n" << std::endl; // user greeting
    std::cout << "Production Line Tracker\n" << std::endl;
    menu(); // call to the main menu to display
    int userMenuSelection;
    std::vector<std::string> productLineManufacturer = {"Apple", "Microsoft", "Apple"};
    std::vector<std::string> productLineName = {"iPod", "Surface Laptop 2", "iPad"};
    std::vector<std::string> productLineItemType = {"AM", "VM", "VM"};
    std::vector<int> productNumber = {0};
    do {
        userMenuSelection = menuSelection();
        processing(userMenuSelection, productLineManufacturer, productLineName, productLineItemType, productNumber);
    } while (userMenuSelection > 6 || userMenuSelection < 1);
    return 0;

}

void menu() { // main menu display

    std::cout << "1. Produce Items" << std::endl;
    std::cout << "2. Add Employee Account" << std::endl;
    std::cout << "3. Add To Product Line" << std::endl;
    std::cout << "4. Display Production Statistics" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

int menuSelection() {
    int input;
    std::cin >> input;
    return input;
}

void stub() { // dummy function used as a temporary call for future function not yet built.
    std::cout << "I am the stub" << std::endl;
}

void processing(int userMenuSelection, std::vector<std::string> &productLineManufacturer,
                std::vector<std::string> &productLineName,
                std::vector<std::string> &productLineItemType,
                std::vector<int> &productNumber) { // main menu decision function. passes user to next submenu and

    switch (userMenuSelection) {
        case 1 :
            produceItems(productLineManufacturer, productLineName, productLineItemType, productNumber);
            break;
        case 2 :
            stub();
            break;
        case 3 :
            addToProductLine(productLineManufacturer, productLineName, productLineItemType);
            break;
        case 4 :
            stub();
            break;
        case 5 :
            std::cout << "exit" << std::endl;
            break;
        default:
            std::cout << "Not A Valid Selection\n" << std::endl;
            menu();
            break;
    }

}

int produceItems(std::vector<std::string> &productLineManufacturer,
                 std::vector<std::string> &productLineName,
                 std::vector<std::string> &productLineItemType,
                 std::vector<int> &productNumber) { // submenu from selecting 1. Produce Items from main menu
    // Eventually the user will be able to choose the item to produce.
    // For now, just have them input the information.
    output_sorted_product_names(productLineName);
    int productChoice;
    std::cin >> productChoice;
    std::cout << "How many products will be produced?" << std::endl;
    int productAmount;
    std::cin >> productAmount;
    int index;


    std::ofstream myfile("Production.txt", std::ios::app); // This create the file Production.txt and appends data.
    myfile.is_open();// opens the file

    for (index = 0; index < productAmount;) {
        ++index;
        std::cout << index << ". " << productLineManufacturer[productChoice].substr(0, 3)
                  << productLineItemType[productChoice] << std::setfill('0') << std::setw(5) << index
                  << std::endl;
        myfile << index << ". " << productLineManufacturer[productChoice].substr(0, 3)
               << productLineItemType[productChoice] << std::setfill('0') << std::setw(5) << index
               << std::endl;

    }
    myfile.close();// closes the Production.txt file

    return 0;
}


void addToProductLine(std::vector<std::string> &productLineManufacturer,
                      std::vector<std::string> &productLineName,
                      std::vector<std::string> &productLineItemType) {

    // Add three new products to the product line
    processingNewProductInfo(productLineManufacturer, productLineName, productLineItemType);
    processingNewProductInfo(productLineManufacturer, productLineName, productLineItemType);
    processingNewProductInfo(productLineManufacturer, productLineName, productLineItemType);

    // Output the products in the product line
    newAvailableDetailedProducts(productLineManufacturer, productLineName, productLineItemType);


}

void processingNewProductInfo(std::vector<std::string> &productLineManufacturer,
                              std::vector<std::string> &productLineName,
                              std::vector<std::string> &productLineItemType) {
    std::cout << "Adding a new product to the product line\n";

    std::cout << "Enter the Manufacturer\n";
    std::string manufacturer;
    std::cin >> manufacturer;
    // add manufacturer to the vector here
    productLineManufacturer.push_back(manufacturer);

    std::cout << "Enter the Product Name\n";
    std::string prodName;
    std::cin >> prodName;
    // add prodName to the vector
    productLineName.push_back(prodName);

    std::cout << "Enter the item type\n";
    std::cout << "1. Audio\n" <<
              "2. Visual\n" <<
              "3. AudioMobile\n" <<
              "4. VisualMobile\n";
    int itemTypeChoice;
    std::cin >> itemTypeChoice;
    std::string itemTypeCode;
    switch (itemTypeChoice) {
        case 1:
            itemTypeCode = "MM";
            break;
        case 2:
            itemTypeCode = "VI";
            break;
        case 3:
            itemTypeCode = "AM";
            break;
        case 4:
            itemTypeCode = "VM";
            break;
        default:
            std::cout << "Not a valid selection\n";
            std::cout << "Setting type to 'NA'\n";
            itemTypeCode = "NA";
            break;
    }
    // add itemTypeCode to the vector
    productLineItemType.push_back(itemTypeCode);

}

void output_sorted_product_names(std::vector<std::string> &productLineName) {
    std::cout << "Enter the product to Produce product :\n";
    for (int productLineItemNum = 0; productLineItemNum < productLineName.size(); productLineItemNum++) {
        std::cout << productLineItemNum << ". " << std::flush;
        std::cout << productLineName[productLineItemNum] << std::endl;
    }

    sort(productLineName.begin(), productLineName.end());

    for (const auto &x : productLineName) {
        std::cout << x << std::endl;
    }
}

void newAvailableDetailedProducts(std::vector<std::string> &productLineManufacturer,
                                  std::vector<std::string> &productLineName,
                                  std::vector<std::string> &productLineItemType) {
    std::cout << "The products in the Product Line are:\n";
    for (int productLineItemNum = 0; productLineItemNum < productLineItemType.size(); productLineItemNum++) {
        std::cout << productLineItemNum << ". " << std::flush;
        std::cout << productLineManufacturer[productLineItemNum] << ", ";
        std::cout << productLineName[productLineItemNum] << ", ";
        std::cout << productLineItemType[productLineItemNum] << "\n";
    }

}
