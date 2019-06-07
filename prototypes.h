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
 * @param Takes the user's number input for main menu selection: userMenuSelection.
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




void addToProductLine(std::vector<std::string> &productLineManufacturer,
                      std::vector<std::string> &productLineName,
                      std::vector<std::string> &productLineItemType);

void AddEmployeeAccount();

void CreateEmployeePassword();

void processingNewProductInfo(std::vector<std::string> &productLineManufacturer,
                              std::vector<std::string> &productLineName,
                              std::vector<std::string> &productLineItemType);

void newAvailableDetailedProducts(std::vector<std::string> &productLineManufacturer,
                                  std::vector<std::string> &productLineName,
                                  std::vector<std::string> &productLineItemType);

void newAvailableDetailedProductsToFile(std::vector<std::string> &productLineManufacturer,
                                        std::vector<std::string> &productLineName,
                                        std::vector<std::string> &productLineItemType);

void ReadAvailableDetailedProductsInFile(std::vector<std::string> &productLineManufacturer,
                                         std::vector<std::string> &productLineName,
                                         std::vector<std::string> &productLineItemType);

void productInfoLoad(std::vector<std::string> &productLineManufacturer, std::vector<std::string> &productLineName,
                     std::vector<std::string> &productLineItemType);

void productSerialInfoLoad(std::vector<std::string> &serialsSeries, std::vector<int> &productNumber);

//void output_sorted_product_names(std::vector<std::string> &productLineName);


#endif //HELLOWORLD_PROTOTYPES_H

