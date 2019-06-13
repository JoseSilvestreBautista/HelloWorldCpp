/** @file production.txt
 *  @brief A program that tracks products at a warehouse
 *  @author Jose Silvestre-Bautista
 *  @bug no known bugs
 */

#include "prototypes.h"


std::vector<int> Audio;
std::vector<int> Visual;
std::vector<int> AudioMobile;
std::vector<int> VisualMobile;


int main() {  // drives the entire program by calling other functions.
    std::vector<std::string> productLineManufacturer;
    std::vector<std::string> productLineName;
    std::vector<std::string> productLineItemType;
    std::vector<std::string> serialsSeries;
    std::vector<int> productNumber;

    productInfoLoad(productLineManufacturer, productLineItemType, productLineName);
    productSerialInfoLoad(serialsSeries, productNumber);
    processing(productLineManufacturer, productLineName, productLineItemType, productNumber, Audio, Visual, AudioMobile,
               VisualMobile);
    return 0;
}

void menu() { // main menu display

    std::cout << "1. Produce Items" << std::endl;
    std::cout << "2. Add Employee Account" << std::endl;
    std::cout << "3. Add To Product Line" << std::endl;
    std::cout << "4. Display Production Statistics" << std::endl;
    std::cout << "5. Exit" << std::endl;
}


void processing(std::vector<std::string> &productLineManufacturer, std::vector<std::string> &productLineName,
                std::vector<std::string> &productLineItemType, std::vector<int> &productNumber, std::vector<int> &Audio,
                std::vector<int> &Visual, std::vector<int> &AudioMobile, std::vector<int> &VisualMobile) {

    std::cout << "Hello User!\n" << std::endl; // user greeting
    std::cout << "Production Line Tracker\n" << std::endl;

    // main menu decision function. passes user to next submenu and
    bool repeat = true;
    while (repeat) {
        menu();
        std::cout << std::endl;
        int ask;
        std::cin >> ask;
        switch (ask) {
            case 1 :
                produceItems(productLineManufacturer, productLineName, productLineItemType, productNumber, Audio,
                             Visual, AudioMobile, VisualMobile);
                break;
            case 2 :
                AddEmployeeAccount();
                break;
            case 3 :
                addToProductLine(productLineManufacturer, productLineName, productLineItemType);
                break;
            case 4 :
                break;
            case 5 :
                std::cout << "exit" << std::endl;
                repeat = false;
                break;
            default:
                std::cout << "Not A Valid Selection\n" << std::endl;
                std::cin.clear();
                std::cin.ignore();
                break;
        }

    }
}

int produceItems(std::vector<std::string> &productLineManufacturer,
                 std::vector<std::string> &productLineName,
                 std::vector<std::string> &productLineItemType,
                 std::vector<int> &productNumber, std::vector<int> &Audio,
                 std::vector<int> &Visual, std::vector<int> &AudioMobile,
                 std::vector<int> &VisualMobile) { // submenu from selecting 1. Produce Items from main menu

    ReadAvailableDetailedProductsInFile(productLineManufacturer, productLineName, productLineItemType);

    int choice;
    std::cin >> choice;
    std::string threeLetterManufacturer;
    productLineManufacturer[choice];
    threeLetterManufacturer = productLineManufacturer[choice];
    productLineName[choice];
    std::string itemType;
    productLineItemType[choice];
    itemType = productLineItemType[choice];

    int holder;

    if (itemType.compare("AM")) {
        if (AudioMobile.empty()) {
            AudioMobile.push_back(0);
        }
        holder = AudioMobile.back();
    } else if (itemType.compare("VM")) {
        if (VisualMobile.empty()) {
            VisualMobile.push_back(0);
        }
        holder = VisualMobile.back();
    } else if (itemType.compare("VI")) {
        if (Visual.empty()) {
            Visual.push_back(0);
        }
        holder = Visual.back();
    } else if (itemType.compare("MM")) {
        if (Audio.empty()) {
            Audio.push_back(0);
        }
        holder = Audio.back();
    } else {
        std::cout << "Something went wrong." << std::endl;
    }

    std::cout << "Enter the number of items that were produced\n";


    int amountProduced;
    std::cin >> amountProduced;

    if (productNumber.empty()) {
        productNumber.push_back(0);
    }


    std::stringstream ss;

    int i;
    for (i = 1; i < amountProduced + 1; i++) {

        ss << productNumber.back() + i << ". " << threeLetterManufacturer.substr(0, 3) << itemType << std::setfill('0')
           << std::setw(5)
           << holder + i << std::endl;

        std::ofstream myfile("Production.txt", std::ios::app); // This create the file Production.txt and appends data.
        myfile.is_open();// opens the file

        myfile << productNumber.back() + i << ". " << threeLetterManufacturer.substr(0, 3) << itemType
               << std::setfill('0')
               << std::setw(5)
               << holder + i << std::endl;

        myfile.close();// closes the Production.txt fil

    }
    int temp = productNumber.back() + i - 1;
    productNumber.push_back(temp);


    if (itemType.compare("AM")) {
        AudioMobile.back() += i - 1;
    } else if (itemType.compare("VM")) {
        VisualMobile.back() += i - 1;
    } else if (itemType.compare("VI")) {
        Visual.back() += i - 1;
    } else if (itemType.compare("MM")) {
        Audio.back() += i - 1;
    } else {
        std::cout << "Something went wrong." << std::endl;
    }
    std::cout << ss.str() << std::endl;

    return 0;

}


void addToProductLine(std::vector<std::string> &productLineManufacturer, std::vector<std::string> &productLineName,
                      std::vector<std::string> &productLineItemType) {

    // Add three new products to the product line
    processingNewProductInfo(productLineManufacturer, productLineName, productLineItemType);
    processingNewProductInfo(productLineManufacturer, productLineName, productLineItemType);
    processingNewProductInfo(productLineManufacturer, productLineName, productLineItemType);

    // Output the products in the product line
    newAvailableDetailedProducts(productLineManufacturer, productLineName, productLineItemType);
    newAvailableDetailedProductsToFile(productLineManufacturer, productLineName, productLineItemType);


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

    std::cout << std::endl;
}

void newAvailableDetailedProductsToFile(std::vector<std::string> &productLineManufacturer,
                                        std::vector<std::string> &productLineName,
                                        std::vector<std::string> &productLineItemType) {
    for (int productLineItemNum = 0; productLineItemNum < productLineItemType.size(); productLineItemNum++) {
        std::ofstream catalogfile("productcatalog.txt", std::ios::app);
        if (catalogfile.is_open()) {

            catalogfile << productLineManufacturer[productLineItemNum] << ", ";
            catalogfile << productLineName[productLineItemNum] << ", ";
            catalogfile << productLineItemType[productLineItemNum] << "\n";
            catalogfile.close();
        } else {
            std::cout << "Unable to open file" << std::endl;
        }
    }

    std::cout << std::endl;
}

void ReadAvailableDetailedProductsInFile(std::vector<std::string> &productLineManufacturer,
                                         std::vector<std::string> &productLineName,
                                         std::vector<std::string> &productLineItemType) {
    std::cout << "The products in the Product Line are:\n";
    std::string line;
    int counter = 0;
    std::ifstream catalogfile("productcatalog.txt");
    if (catalogfile.is_open()) {
        while (getline(catalogfile, line)) {
            std::cout << counter++ << ". " << line << '\n';
        }
        catalogfile.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }
    std::cout << std::endl;

}

void productInfoLoad(std::vector<std::string> &productLineManufacturer, std::vector<std::string> &productLineName,
                     std::vector<std::string> &productLineItemType) {
    std::string manu, prodnam, type, line;
    std::ifstream catalogfile("productcatalog.txt");

    while (getline(catalogfile, line)) {
        std::stringstream ss(line);
        getline(ss, manu, ',');
        getline(ss, type, ',');
        getline(ss, prodnam, ',');
        productLineManufacturer.push_back(manu);
        productLineName.push_back(prodnam);
        productLineItemType.push_back(type);
    }


}

void productSerialInfoLoad(std::vector<std::string> &serialsSeries, std::vector<int> &productNumber) {
    std::string serial, line, firstNum, itemType, secondNum;
    int proNum, lastNums;
    std::ifstream myfile("Production.txt");

    while (getline(myfile, line)) {
        std::stringstream ss(line);
        ss >> firstNum;
        ss >> serial;
        proNum = std::stoi(firstNum);
        itemType = serial.substr(3, 2);
        secondNum = serial.substr(5, 6);
        lastNums = std::stoi(secondNum);

        productNumber.push_back(proNum);

        if (itemType.compare("AM")) {
            AudioMobile.push_back(lastNums);
        } else if (itemType.compare("VM")) {
            VisualMobile.push_back(lastNums);
        } else if (itemType.compare("VI")) {
            Visual.push_back(lastNums);
        } else if (itemType.compare("MM")) {
            Audio.push_back(lastNums);
        } else {
            std::cout << "Something went wrong." << std::endl;
        }

    }

}

void AddEmployeeAccount() {
    std::cout << "Enter employee's first name" << std::endl;
    std::string first_name;
    std::cin >> first_name;
    std::transform(first_name.begin(), first_name.end(), first_name.begin(), ::tolower);
    std::cout << "Enter employee's first last name" << std::endl;
    std::string last_name;
    std::cin >> last_name;
    std::transform(last_name.begin(), last_name.end(), last_name.begin(), ::tolower);
    std::string user_name;
    // create user name in proper format
    user_name = first_name.substr(0, 1) + last_name;

    std::cout << "User name: " + user_name + "\n" << std::endl;

    std::ofstream UserInfo("Users.txt", std::ios::app);
    if (UserInfo.is_open()) {
        UserInfo << user_name;
        UserInfo.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }


    CreateEmployeePassword();
}

void CreateEmployeePassword() {
    bool again = true;
    char password[30];
    while (again) {
        std::cout << "Enter employee's password." << std::endl;
        std::cout << "Must contain a number and lowercase and uppercase letters." << std::endl;


        std::cin >> password;
        int i = 0;
        int j = 0;
        int k = 0;

        for (int count = 0; count < strlen(password); ++count) {
            if (isupper(password[count])) {
                i++;
            }
            if (islower(password[count])) {
                j++;
            }
            if (isdigit(password[count])) {
                k++;
            }
        }
        bool valid = false;
        if (i > 0 && j > 0 && k > 0) {
            valid = true;
        }

        if (valid) {
            std::cout << "valid" << std::endl;
            again = false;
        } else {
            std::cout << "invalid" << std::endl;
        }
    }

    std::string encrypted_str = encrypt_string(password);

    std::ofstream UserInfo("Users.txt", std::ios::app);
    if (UserInfo.is_open()) {
        UserInfo << " " << encrypted_str << std::endl;
        UserInfo.close();
    } else {
        std::cout << "Unable to open file";
    }
}


std::string encrypt_string(std::string str) {
    if (str.length() == 1) {
        return str;
    } else {
        return char((int) str[0] + 3) + encrypt_string(str.substr(1, str.length() - 1));
    }
}
