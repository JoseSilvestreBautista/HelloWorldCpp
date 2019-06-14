/** @file production.txt
 *  @brief A program that tracks products at a warehouse
 *  @author Jose Silvestre-Bautista
 *  @bug no known bugs
 */

#include "prototypes.h"

int main() {  // drives the entire program by calling other functions.
    ProductInfo myProduct;
    ItemTypeSerial productSerial{};
    productSerial.audio_count = 0;
    productSerial.visual_count = 0;
    productSerial.visual_mobile_count = 0;
    productSerial.audio_mobile_count = 0;
    int productNumber = 0;
    std::vector<ProductInfo> Catalog;

    productInfoLoad(myProduct, Catalog);
    productSerialInfoLoad(productNumber, productSerial);
    processing(myProduct, productNumber, productSerial, Catalog);
    return 0;
}

void menu() { // main menu display

    std::cout << "1. Produce Items" << std::endl;
    std::cout << "2. Add Employee Account" << std::endl;
    std::cout << "3. Add To Product Line" << std::endl;
    std::cout << "4. Display Production Statistics" << std::endl;
    std::cout << "5. Exit" << std::endl;
}


void processing(ProductInfo &myProduct, int &productNumber,
                ItemTypeSerial &productSerial, std::vector<ProductInfo> &Catalog) {

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
                produceItems(myProduct, productNumber, productSerial, Catalog);
                break;
            case 2 :
                AddEmployeeAccount();
                break;
            case 3 :
                addToProductLine(myProduct);
                break;
            case 4 :
                DisplayProductionStatistics(productNumber, productSerial);
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

int produceItems(const ProductInfo &myProduct,
                 int &productNumber,
                 ItemTypeSerial &productSerial,
                 std::vector<ProductInfo> &Catalog) { // submenu from selecting 1. Produce Items from main menu

    std::cout << "Which product is to be created. Select by the number.\n" << std::endl; // user greeting

    for (int index = 0; index < Catalog.size(); index++) {
        std::cout << index << ". " << Catalog[index].productLineManufacturer << ", " << Catalog[index].productLineName
                  << ", " << Catalog[index].productLineItemType << std::endl;
    }

    int choice;
    std::cin >> choice;
    std::string threeLetterManufacturer;
    threeLetterManufacturer = Catalog[choice].productLineManufacturer;
    std::string itemType;
    itemType = Catalog[choice].productLineItemType;

    int holder = 0;

    if (itemType == "AM") {
        holder = productSerial.audio_mobile_count;
    } else if (itemType == "VM") {
        holder = productSerial.visual_mobile_count;
    } else if (itemType == "VI") {
        holder = productSerial.visual_count;
    } else if (itemType == "MM") {
        holder = productSerial.audio_count;
    } else {
        std::cout << "Something went wrong." << std::endl;
    }


    std::cout << "Enter the number of items that were produced\n";


    int amountProduced;
    std::cin >> amountProduced;

    if (itemType == "AM") {
        productSerial.audio_mobile_count += amountProduced;
    } else if (itemType == "VM") {
        productSerial.visual_mobile_count += amountProduced;
    } else if (itemType == "VI") {
        productSerial.visual_count += amountProduced;
    } else if (itemType == "MM") {
        productSerial.audio_count += amountProduced;
    } else {
        std::cout << "Something went wrong." << std::endl;
    }

    std::stringstream ss;

    int i;
    for (i = 1; i < amountProduced + 1; i++) {
        productNumber++;

        holder++;
        ss << productNumber << ". " << threeLetterManufacturer.substr(0, 3) << itemType << std::setfill('0')
           << std::setw(5) << holder << std::endl;

        // This create the file Production.txt and appends data.
        std::ofstream myfile("ProductionLog.csv ", std::ios::app);

        myfile.is_open();// opens the file

        myfile << productNumber << ", " << threeLetterManufacturer.substr(0, 3) << itemType << std::setfill('0')
               << std::setw(5) << holder << std::endl;

        myfile.close();// closes the Production.txt fil

    }

    std::cout << ss.str() << std::endl;

    return 0;

}

void addToProductLine(ProductInfo &myProduct) {

    // Add three new products to the product line
    processingNewProductInfo(myProduct);
    processingNewProductInfo(myProduct);
    processingNewProductInfo(myProduct);

    // Output the products in the product line
    newAvailableDetailedProducts(myProduct);
    newAvailableDetailedProductsToFile(myProduct);


}

void processingNewProductInfo(ProductInfo &myProduct) {

    std::cout << "Adding a new product to the product line\n";
    std::cout << "Enter the Manufacturer\n";
    std::string manufacturer;
    std::cin >> manufacturer;
    // add manufacturer to the vector here
    myProduct.productLineManufacturer = manufacturer;
    std::cout << "Enter the Product Name\n";
    std::string prodName;
    std::cin >> prodName;
    // add prodName to the vector
    myProduct.productLineName = prodName;

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
    myProduct.productLineItemType = itemTypeCode;

}


void newAvailableDetailedProducts(const ProductInfo &myProduct) {
    std::cout << "The products in the Product Line are:\n";
    for (int productLineItemNum = 0; productLineItemNum < myProduct.productLineItemType.size(); productLineItemNum++) {

        std::cout << productLineItemNum << ". " << std::flush;
        std::cout << myProduct.productLineManufacturer[productLineItemNum] << ",";
        std::cout << myProduct.productLineName[productLineItemNum] << ",";
        std::cout << myProduct.productLineItemType[productLineItemNum] << "\n";

    }

    std::cout << std::endl;
}

void newAvailableDetailedProductsToFile(const ProductInfo &myProduct) {
    for (int productLineItemNum = 0; productLineItemNum < myProduct.productLineItemType.size(); productLineItemNum++) {
        std::ofstream catalog_file("ProductLine.csv", std::ios::app);
        if (catalog_file.is_open()) {

            catalog_file << myProduct.productLineManufacturer[productLineItemNum] << ",";
            catalog_file << myProduct.productLineName[productLineItemNum] << ",";
            catalog_file << myProduct.productLineItemType[productLineItemNum] << "\n";
            catalog_file.close();
        } else {
            std::cout << "Unable to open file" << std::endl;
        }
    }

    std::cout << std::endl;
}


void productInfoLoad(ProductInfo &myProduct, std::vector<ProductInfo> &Catalog) {
    std::string manu, prodnam, type, line;
    std::ifstream catalog_file("ProductLine.csv");

    while (getline(catalog_file, line)) {
        std::stringstream ss(line);
        getline(ss, manu, ',');
        getline(ss, prodnam, ',');
        getline(ss, type);
        myProduct.productLineManufacturer = manu;
        myProduct.productLineName = prodnam;
        myProduct.productLineItemType = type;
        Catalog.push_back(myProduct);
    }

}

void productSerialInfoLoad(int &productNumber, ItemTypeSerial &productSerial) {
    std::string serial, line, firstNum, itemType, secondNum;
    int proNum;
    std::ifstream myfile("ProductionLog.csv ");

    while (getline(myfile, line)) {
        int lastNums;
        std::stringstream ss(line);
        ss >> firstNum;
        ss >> serial;
        proNum = std::stoi(firstNum);
        itemType = serial.substr(3, 2);
        secondNum = serial.substr(5, 6);
        lastNums = std::stoi(secondNum);

        productNumber = proNum;

        if (itemType == "AM") {
            productSerial.audio_mobile_count = lastNums;
        } else if (itemType == "VM") {
            productSerial.visual_mobile_count = lastNums;
        } else if (itemType == "VI") {
            productSerial.visual_count = lastNums;
        } else if (itemType == "MM") {
            productSerial.audio_count = lastNums;
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

void DisplayProductionStatistics(int &productNumber, ItemTypeSerial &productSerial) {


    std::cout << "Total Product Created: " << productNumber << std::endl;
    std::cout << "Total Audio Products: " << productSerial.audio_count << std::endl;
    std::cout << "Total AudioMobile Products: " << productSerial.audio_mobile_count << std::endl;
    std::cout << "Total Visual Products: " << productSerial.visual_count << std::endl;
    std::cout << "Total VisualMobile Products: " << productSerial.visual_mobile_count << std::endl;

    std::cout << std::endl;
}
