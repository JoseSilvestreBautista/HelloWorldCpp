//
// Created by joses on 5/29/2019.
//

#ifndef HELLOWORLD_PROTOTYPES_H
#define HELLOWORLD_PROTOTYPES_H

#include <iostream>
#include <iomanip>
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

struct ItemTypeSerial {
    std::vector<int> Audio;
    std::vector<int> Visual;
    std::vector<int> AudioMobile;
    std::vector<int> VisualMobile;
};

struct ProductInfo {
    std::vector<std::string> productLineManufacturer;
    std::vector<std::string> productLineName;
    std::vector<std::string> productLineItemType;
};


// these are prototypes

/**
 * @brief  Is the main menu display for employees.
 */
void menu();

/**
 * @brief Process the user's main menu selection and prevents improper selection.
 * @param
 */
void processing(ProductInfo &myProduct, std::vector<int> &productNumber, ItemTypeSerial &);

/**
 * @brief  Function that records products made using serial numbers.
 * The result of choosing produce items from main menu.
 */
int produceItems(const ProductInfo &myProduct, std::vector<int> &productNumber, ItemTypeSerial &);


/**
 * @brief where new products are created and displayed
 * @param productLineManufacturer
 * @param productLineName
 * @param productLineItemType
 */

void addToProductLine(ProductInfo &myProduct);

/**
 * @brief the user creates an employee user name with first name and last name.
 */
void AddEmployeeAccount();

/**
 * @brief the user creates a password with certain requirements.
 */
void CreateEmployeePassword();

/**
 * @brief user adds new products by entering manufacturer, product name, and item type.
 * @param productLineManufacturer
 * @param productLineName
 * @param productLineItemType
 */

void processingNewProductInfo(ProductInfo &myProduct);

/**
 * @brief displays newly add products to the user
 * @param productLineManufacturer
 * @param productLineName
 * @param productLineItemType
 */
void newAvailableDetailedProducts(const ProductInfo &myProduct);

/**
 * @brief saves the newly added products to a file for safe keeping
 * @param productLineManufacturer
 * @param productLineName
 * @param productLineItemType
 */
void newAvailableDetailedProductsToFile(const ProductInfo &myProduct);

/**
 * @brief retrieves the products saved to a file and newly created products and displays them
 * @param productLineManufacturer
 * @param productLineName
 * @param productLineItemType
 */

void ReadAvailableDetailedProductsInFile();

/**
 * @brief retrieves saved product info to the program
 * @param productLineManufacturer
 * @param productLineName
 * @param productLineItemType
 */
void productInfoLoad(ProductInfo &myProduct);

/**
 * @brief loads saved product numbers and serial numbers into the program
 * @param serialsSeries
 * @param productNumber
 */
void productSerialInfoLoad(std::vector<int> &productNumber, ItemTypeSerial &);

std::string encrypt_string(std::string str);

void DisplayProductionStatistics(std::vector<int> &productNumber, ItemTypeSerial &);

#endif //HELLOWORLD_PROTOTYPES_H
