/** @file production.txt
 *  @brief A program that tracks products at a warehouse
 *  @author Jose Silvestre-Bautista
 *  @bug infinite loop at produce items if wrong input
 */

#include "prototypes.h"

int main() {  // drives the entire program by calling other functions.
    Product_Info my_Product_Info;
    Item_Type_Serial my_Item_Type_Serial{};
    my_Item_Type_Serial.audio_count = 0;
    my_Item_Type_Serial.visual_count = 0;
    my_Item_Type_Serial.visual_mobile_count = 0;
    my_Item_Type_Serial.audio_mobile_count = 0;
    int product_Number_Count = 0;
    std::vector<Product_Info> catalog;
    std::vector<Product_Info> new_Product_Info;
    Loads_Product_And_Serial_Numbers_From_ProductionLog(product_Number_Count, my_Item_Type_Serial);
    Process_Main_Menu_Selection(my_Product_Info, product_Number_Count, my_Item_Type_Serial, catalog, new_Product_Info);
    return 0;
}

void Display_Main_Menu() { // main menu display

    std::cout << "1. Produce Items" << std::endl;
    std::cout << "2. Add Employee Account" << std::endl;
    std::cout << "3. Add To Product Line" << std::endl;
    std::cout << "4. Display Production Statistics" << std::endl;
    std::cout << "5. Exit" << std::endl;
}


void Process_Main_Menu_Selection(Product_Info &my_Product_Info, int &product_Number_Count,
                                 Item_Type_Serial &my_Item_Type_Serial, std::vector<Product_Info> &catalog,
                                 std::vector<Product_Info> &new_Product_Info) {

    std::cout << "Production Line Tracker\n" << std::endl;

    bool repeat = true;// the user controls this variable with exit selection
    while (repeat) { // allows the user to return to main menu after choosing a selection, other than exit.
        Display_Main_Menu();
        int users_Selection;
        std::cin >> users_Selection;
        switch (users_Selection) { // the switch choice follows the menu
            case 1 :
                Loads_Products_From_ProductLine_File(my_Product_Info, catalog);
                if (catalog.empty()) {
                    std::cout << "The product line is empty, please create a product." << std::endl;
                    Add_To_Product_Line(my_Product_Info, new_Product_Info);
                } else {
                    Produce_Items(product_Number_Count, my_Item_Type_Serial, catalog);
                }
                break;
            case 2 :
                Add_Employee_Account();
                break;
            case 3 :
                Add_To_Product_Line(my_Product_Info, new_Product_Info);
                break;
            case 4 :
                Display_Production_Statistics(product_Number_Count, my_Item_Type_Serial);
                break;
            case 5 :
                std::cout << "exit" << std::endl;
                repeat = false;
                break;
            default: // this keeps the program from crashing if user makes a wrong selection
                std::cout << "Not A Valid Selection\n" << std::endl;
                std::cin.clear();
                std::cin.ignore();
                break;
        }

    }
}

int
Produce_Items(int &product_Number_Count, Item_Type_Serial &my_Item_Type_Serial, std::vector<Product_Info> &catalog) {

    std::cout << "Which product is to be created. Select by the number.\n" << std::endl; // user greeting

    for (int product = 0; product < catalog.size(); product++) {
        std::cout << product << ". " << catalog[product].product_Line_Manufacturer << ", "
                  << catalog[product].product_Line_Name
                  << ", " << catalog[product].product_Line_Item_Type << std::endl;
    }

    int users_Product_Choice = 0;
    std::cin >> users_Product_Choice;


    std::string three_Letter_Manufacturer;
    three_Letter_Manufacturer = catalog[users_Product_Choice].product_Line_Manufacturer; //hold the manufacturer
    std::string item_Type;
    item_Type = catalog[users_Product_Choice].product_Line_Item_Type;

    int holds_Products_Item_Type_Serial_Num = 0;

    if (item_Type == "AM") { // depending on the users product choice the recent serial number of that product is picked
        holds_Products_Item_Type_Serial_Num = my_Item_Type_Serial.audio_mobile_count;
    } else if (item_Type == "VM") {
        holds_Products_Item_Type_Serial_Num = my_Item_Type_Serial.visual_mobile_count;
    } else if (item_Type == "VI") {
        holds_Products_Item_Type_Serial_Num = my_Item_Type_Serial.visual_count;
    } else if (item_Type == "MM") {
        holds_Products_Item_Type_Serial_Num = my_Item_Type_Serial.audio_count;
    } else {
        std::cout << "Something went wrong." << std::endl;
    }

    std::cout << "Enter the number of items that were produced\n";

    int amount_Produced;
    std::cin >> amount_Produced;

    if (item_Type == "AM") { // increments the serial number by the amount produced
        my_Item_Type_Serial.audio_mobile_count += amount_Produced;
    } else if (item_Type == "VM") {
        my_Item_Type_Serial.visual_mobile_count += amount_Produced;
    } else if (item_Type == "VI") {
        my_Item_Type_Serial.visual_count += amount_Produced;
    } else if (item_Type == "MM") {
        my_Item_Type_Serial.audio_count += amount_Produced;
    } else {
        std::cout << "Something went wrong." << std::endl;
    }

    std::stringstream serial_Number;

    int i;
    for (i = 1; i < amount_Produced + 1; i++) {
        product_Number_Count++;
        //displays the serial numbers
        holds_Products_Item_Type_Serial_Num++;
        serial_Number << product_Number_Count << ". " << three_Letter_Manufacturer.substr(0, 3) << item_Type
                      << std::setfill('0')
                      << std::setw(5) << holds_Products_Item_Type_Serial_Num << std::endl;

        // This create the file Production.txt and appends data.
        std::ofstream myfile("ProductionLog.csv ", std::ios::app);
        myfile.is_open();// opens the file
        // saves the serial number to the file opned
        myfile << product_Number_Count << ", " << three_Letter_Manufacturer.substr(0, 3) << item_Type
               << std::setfill('0')
               << std::setw(5) << holds_Products_Item_Type_Serial_Num << std::endl;
        myfile.close();// closes the Production.txt fil

    }

    std::cout << serial_Number.str() << std::endl;

    return 0;

}

void Add_To_Product_Line(Product_Info &my_Product, std::vector<Product_Info> &new_Product_Info) {

    // Add three new products to the product line
    Assemble_New_Product_Info(my_Product, new_Product_Info);
    Assemble_New_Product_Info(my_Product, new_Product_Info);
    Assemble_New_Product_Info(my_Product, new_Product_Info);
    // Output the products in the product line
    Display_New_Added_Products(my_Product, new_Product_Info);
    Store_New_Products_To_File(my_Product, new_Product_Info);

}

void Assemble_New_Product_Info(Product_Info &my_Product, std::vector<Product_Info> &new_Product_Info) {

    std::cout << "Adding a new product to the product line\n";
    std::cout << "Enter the Manufacturer\n";
    std::cin.ignore();
    std::string entered_Manufacturer;
    getline(std::cin, entered_Manufacturer);
    my_Product.product_Line_Manufacturer = entered_Manufacturer;
    std::cout << "Enter the Product Name\n";
    std::string entered_product_Name;
    getline(std::cin, entered_product_Name);
    my_Product.product_Line_Name = entered_product_Name;

    std::cout << "Enter the item type\n";
    std::cout << "1. Audio\n" <<
              "2. Visual\n" <<
              "3. AudioMobile\n" <<
              "4. VisualMobile\n";
    int item_Type_Choice;
    std::cin >> item_Type_Choice;
    std::string entered_item_Type_Code;
    switch (item_Type_Choice) {
        case 1:
            entered_item_Type_Code = "MM";
            break;
        case 2:
            entered_item_Type_Code = "VI";
            break;
        case 3:
            entered_item_Type_Code = "AM";
            break;
        case 4:
            entered_item_Type_Code = "VM";
            break;
        default:
            std::cout << "Not a valid selection\n";
            std::cout << "Setting type to 'NA'\n";
            entered_item_Type_Code = "NA";
            break;
    }
    // add itemTypeCode to the vector
    my_Product.product_Line_Item_Type = entered_item_Type_Code;
    new_Product_Info.push_back(my_Product);

}


void Display_New_Added_Products(const Product_Info &my_Product, std::vector<Product_Info> &new_Product_Info) {
    std::cout << "These products have been added to the Product Line:\n";
    for (auto &product_Line_Item_Num : new_Product_Info) {
        // displays the what is in the vector new_Product_Info
        std::cout << product_Line_Item_Num.product_Line_Manufacturer << ",";
        std::cout << product_Line_Item_Num.product_Line_Name << ",";
        std::cout << product_Line_Item_Num.product_Line_Item_Type << "\n";

    }

    std::cout << std::endl;
}

void Store_New_Products_To_File(const Product_Info &my_Product, std::vector<Product_Info> &new_Product_Info) {
    for (auto &product_Line_Item_Num : new_Product_Info) {
        std::ofstream catalog_file("ProductLine.csv", std::ios::app);
        if (catalog_file.is_open()) {
            //prints what is inside the vector new_Product_Info
            catalog_file << product_Line_Item_Num.product_Line_Manufacturer << ",";
            catalog_file << product_Line_Item_Num.product_Line_Name << ",";
            catalog_file << product_Line_Item_Num.product_Line_Item_Type << "\n";
            catalog_file.close();
        } else {
            std::cout << "Unable to open file" << std::endl;
        }
    }

    std::cout << std::endl;
}


void Loads_Products_From_ProductLine_File(Product_Info &my_Product, std::vector<Product_Info> &catalog) {
    std::string manufacturer_In_File, product_Name_In_File, item_Type_In_File, line_In_File;
    std::ifstream catalog_file("ProductLine.csv");

    while (getline(catalog_file, line_In_File)) {
        std::stringstream ss(line_In_File);
        if (line_In_File.empty()) { //skips lines that are empty in the ProductLine file
            continue;
        } else {
            getline(ss, manufacturer_In_File, ',');
            getline(ss, product_Name_In_File, ',');
            getline(ss, item_Type_In_File);
            my_Product.product_Line_Manufacturer = manufacturer_In_File;
            my_Product.product_Line_Name = product_Name_In_File;
            my_Product.product_Line_Item_Type = item_Type_In_File;
            catalog.push_back(my_Product);
        }
    }

}

void Loads_Product_And_Serial_Numbers_From_ProductionLog(int &product_Number_Count,
                                                         Item_Type_Serial &my_Item_Type_Serial) {
    std::string serial_Number_In_File, line_In_File, product_Number_In_File, item_Type_File, item_Type_Num_In_File;
    int integer_Form_of_Product_Number = 0;
    std::ifstream myfile("ProductionLog.csv ");

    while (getline(myfile, line_In_File)) {
        int item_Num_To_Be_Assigned = 0;
        std::stringstream ss(line_In_File);
        ss >> product_Number_In_File;
        ss >> serial_Number_In_File;
        integer_Form_of_Product_Number = std::stoi(product_Number_In_File);
        item_Type_File = serial_Number_In_File.substr(3, 2);
        item_Type_Num_In_File = serial_Number_In_File.substr(5, 6);
        item_Num_To_Be_Assigned = std::stoi(item_Type_Num_In_File); //turns string into numbers

        product_Number_Count = integer_Form_of_Product_Number;
        if (item_Type_File == "AM") { // depending on the item type, certain variables are populated
            my_Item_Type_Serial.audio_mobile_count = item_Num_To_Be_Assigned;
        } else if (item_Type_File == "VM") {
            my_Item_Type_Serial.visual_mobile_count = item_Num_To_Be_Assigned;
        } else if (item_Type_File == "VI") {
            my_Item_Type_Serial.visual_count = item_Num_To_Be_Assigned;
        } else if (item_Type_File == "MM") {
            my_Item_Type_Serial.audio_count = item_Num_To_Be_Assigned;
        } else {
            std::cout << "Something went wrong." << std::endl;
        }

    }

}

void Add_Employee_Account() {
    std::cout << "Enter employee's first name" << std::endl;
    std::string first_Name;
    std::cin >> first_Name;
    std::transform(first_Name.begin(), first_Name.end(), first_Name.begin(), ::tolower);
    std::cout << "Enter employee's first last name" << std::endl;
    std::string last_Name;
    std::cin >> last_Name;
    std::transform(last_Name.begin(), last_Name.end(), last_Name.begin(), ::tolower);
    std::string user_Name;
    // create user name in proper format
    user_Name = first_Name.substr(0, 1) + last_Name;

    std::cout << "User name: " + user_Name + "\n" << std::endl;

    std::ofstream UserInfo("Users.txt", std::ios::app); //saves the user name in a file
    if (UserInfo.is_open()) {
        UserInfo << user_Name;
        UserInfo.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }

    Create_Employee_Password();
}

void Create_Employee_Password() {
    bool repeat = true;
    char password[30]; // character limit
    while (repeat) {
        std::cout << "Enter employee's password." << std::endl;
        std::cout << "Must contain a number and lowercase and uppercase letters." << std::endl;

        std::cin >> password;
        int i = 0;
        int j = 0;
        int k = 0;
//if the statements are true a 1 is added, if false zero is added
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
        bool valid = false; // if all requirements are meet the loop ends
        if (i > 0 && j > 0 && k > 0) {
            valid = true;
        }

        if (valid) {
            std::cout << "valid" << std::endl;
            repeat = false;
        } else {
            std::cout << "invalid" << std::endl;
        }
    }

    std::string encrypted_str = Encrypt_Password(password);
// saves the the password but encrypted
    std::ofstream UserInfo("Users.txt", std::ios::app);
    if (UserInfo.is_open()) {
        UserInfo << " " << encrypted_str << std::endl;
        UserInfo.close();
    } else {
        std::cout << "Unable to open file";
    }
}


std::string Encrypt_Password(std::string password_Being_Encrypted) {
    if (password_Being_Encrypted.length() == 1) {
        return password_Being_Encrypted;
    } else {
        return char((int) password_Being_Encrypted[0] + 3) +
               Encrypt_Password(password_Being_Encrypted.substr(1, password_Being_Encrypted.length() - 1));
    }
}

void Display_Production_Statistics(int &product_Number_Count, Item_Type_Serial &my_Item_Type_Serial) {

    std::cout << "Total Product Created: " << product_Number_Count << std::endl;
    std::cout << "Total Audio Products: " << my_Item_Type_Serial.audio_count << std::endl;
    std::cout << "Total AudioMobile Products: " << my_Item_Type_Serial.audio_mobile_count << std::endl;
    std::cout << "Total Visual Products: " << my_Item_Type_Serial.visual_count << std::endl;
    std::cout << "Total VisualMobile Products: " << my_Item_Type_Serial.visual_mobile_count << std::endl;

    std::cout << std::endl;
}
