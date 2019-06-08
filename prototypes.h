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
#include <stdio.h>
#include <string.h>


// these are prototypes
/**
 * @brief  Is the main menu display for employees.
 */
void menu();

/**
 * @brief Process the user's main menu selection and prevents improper selection.
 * @param
 */
void processing(std::vector<std::string> &productLineManufacturer, std::vector<std::string> &productLineName,
                std::vector<std::string> &productLineItemType, std::vector<int> &productNumber, std::vector<int> &Audio,
                std::vector<int> &Visual, std::vector<int> &AudioMobile, std::vector<int> &VisualMobile);
/**
 * @brief  Function that records products made using serial numbers.
 * The result of choosing produce items from main menu.
 */
int produceItems(std::vector<std::string> &productLineManufacturer,
                 std::vector<std::string> &productLineName,
                 std::vector<std::string> &productLineItemType,
                 std::vector<int> &productNumber, std::vector<int> &Audio,
                 std::vector<int> &Visual, std::vector<int> &AudioMobile, std::vector<int> &VisualMobile);


/**
 * @brief where new products are created and displayed
 * @param productLineManufacturer
 * @param productLineName
 * @param productLineItemType
 */

void addToProductLine(std::vector<std::string> &productLineManufacturer,
                      std::vector<std::string> &productLineName,
                      std::vector<std::string> &productLineItemType);

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

void processingNewProductInfo(std::vector<std::string> &productLineManufacturer,
                              std::vector<std::string> &productLineName,
                              std::vector<std::string> &productLineItemType);

/**
 * @brief displays newly add products to the user
 * @param productLineManufacturer
 * @param productLineName
 * @param productLineItemType
 */
void newAvailableDetailedProducts(std::vector<std::string> &productLineManufacturer,
                                  std::vector<std::string> &productLineName,
                                  std::vector<std::string> &productLineItemType);

/**
 * @brief saves the newly added products to a file for safe keeping
 * @param productLineManufacturer
 * @param productLineName
 * @param productLineItemType
 */
void newAvailableDetailedProductsToFile(std::vector<std::string> &productLineManufacturer,
                                        std::vector<std::string> &productLineName,
                                        std::vector<std::string> &productLineItemType);
/**
 * @brief retrieves the products saved to a file and newly created products and displays them
 * @param productLineManufacturer
 * @param productLineName
 * @param productLineItemType
 */

void ReadAvailableDetailedProductsInFile(std::vector<std::string> &productLineManufacturer,
                                         std::vector<std::string> &productLineName,
                                         std::vector<std::string> &productLineItemType);

/**
 * @brief retrieves saved product info to the program
 * @param productLineManufacturer
 * @param productLineName
 * @param productLineItemType
 */
void productInfoLoad(std::vector<std::string> &productLineManufacturer, std::vector<std::string> &productLineName,
                     std::vector<std::string> &productLineItemType);
/**
 * @brief loads saved product numbers and serial numbers into the program
 * @param serialsSeries
 * @param productNumber
 */
void productSerialInfoLoad(std::vector<std::string> &serialsSeries, std::vector<int> &productNumber);



#endif //HELLOWORLD_PROTOTYPES_H
