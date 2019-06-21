#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <cctype>
#include <cstdio>
#include <cstring>


//Structures that hold variables

struct Item_Type_Serial {
    int audio_count = 0;
    int visual_count = 0;
    int audio_mobile_count = 0;
    int visual_mobile_count = 0;
};

struct Product_Info {
    std::string product_Line_Manufacturer;
    std::string product_Line_Name;
    std::string product_Line_Item_Type;
};


// these are prototypes

/**
 * @brief The main menu display with the options: produce items, add products, add employee account, stats, and exit.
 */
void Display_Main_Menu();

/**
 * @brief Process the user's main menu selection and prevents improper selection.
 * @param my_Product_Info handles three single pieces of info for individual products.
 * @param product_Number_Count holds the most recent product number recorded.
 * @param my_Item_Type_Serial holds the most recent serial number by item type.
 * @param catalog holds all product info together to be printed.
 * @param new_Product_Info holds new added products and displays them only.
 */
void
Process_Main_Menu_Selection(Product_Info &my_Product_Info, int &product_Number_Count,
                            Item_Type_Serial &my_Item_Type_Serial, std::vector<Product_Info> &catalog,
                            std::vector<Product_Info> &new_Product_Info);

/**
 * @brief Produces serial numbers for products that exit in file and saves the serial numbers to another file.
 * @param product_Number_Count Holds the most recent product number recorded.
 * @param product_Number_Count Holds the most recent product number recorded.
 * @param catalog Holds all product info together to be printed.
 */
int Produce_Items(int &product_Number_Count, Item_Type_Serial &my_Item_Type_Serial,
                  std::vector<Product_Info> &catalog);

/**
 * @brief Where new products are created and stored to a file for manufacturing.
 * @param my_Product Stores the pieces of info about the new product.
 * @param new_Product_Info Holds all the info about new products and only the new products.
 */

void Add_To_Product_Line(Product_Info &my_Product, std::vector<Product_Info> &new_Product_Info);

/**
 * @brief The user adds new products to the line by entering manufacturer, product name, and item type.
 * @param my_Product Stores the pieces of info about the new product.
 * @param new_Product_Info Holds all the info about new products and only the new products.
 */

void Assemble_New_Product_Info(Product_Info &my_Product, std::vector<Product_Info> &new_Product_Info);

/**
 * @brief Displays newly added products to the user.
 * @param my_Product Stores the pieces of info about the new product.
 * @param new_Product_Info Holds all the info about new products and only the new products.
 */
void Display_New_Added_Products(const Product_Info &my_Product, std::vector<Product_Info> &new_Product_Info);

/**
 * @brief Saves the newly added products to a file for later use.
 * @param my_Product Stores the pieces of info about the new product.
 * @param new_Product_Info Holds all the info about new products and only the new products.
 */
void Store_New_Products_To_File(const Product_Info &my_Product, std::vector<Product_Info> &new_Product_Info);

/**
 * @brief Loads the productline files to the catalog for production.
 * @param catalog Holds all product info from the productline file to be printed and manipulated.
 * @param my_Product Stores the pieces of info about the new product.
 * */

void Loads_Products_From_ProductLine_File(Product_Info &my_Product, std::vector<Product_Info> &catalog);

/**
 * @brief Loads the saved product numbers and serial numbers into the program.
 * @param my_Item_Type_Serial holds the most recent serial number by item type.
 * @param product_Number_Count Holds the most recent product number recorded.
 */
void Loads_Product_And_Serial_Numbers_From_ProductionLog(int &product_Number_Count,
                                                         Item_Type_Serial &my_Item_Type_Serial);

/**
 * @brief The user creates an employee user name with first name and last name.
 */
void Add_Employee_Account();

/**
 * @brief The user creates a password with certain requirements such as lowercase and uppercase letters and an integer. The password is then stored in the Users file.
 */
void Create_Employee_Password();


/**
 * @brief Retrieves the created, valid password and then encrypts.
 * @param productLineManufacturer
 */
std::string Encrypt_Password(std::string password_Being_Encrypted);

/**
 * @brief Displays the total amount products by item type and the total products created by product Number.
 * @param product_Number_Count Holds the most recent product number recorded.
 * @param my_Item_Type_Serial holds the most recent serial number by item type.
 */
void Display_Production_Statistics(int &product_Number_Count, Item_Type_Serial &my_Item_Type_Serial);

#endif //HELLOWORLD_PROTOTYPES_H
