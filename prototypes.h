//
// Created by joses on 5/29/2019.
//

#ifndef HELLOWORLD_PROTOTYPES_H
#define HELLOWORLD_PROTOTYPES_H

// these are prototypes
/**
 * @brief  Is the main menu display for employees.
 */
void menu();

/**
 * @brief Process the user's main menu selection and prevents improper selection.
 * @param Takes the user's number input for main menu selection: userMenuSelection.
 */
void processing(int, std::vector<std::string> &productLineManufacturer,
                std::vector<std::string> &productLineName,
                std::vector<std::string> &productLineItemType,
                std::vector<int> &productNumber);

/**
 * @brief  Function that records products made using serial numbers.
 * The result of choosing produce items from main menu.
 */
int produceItems(std::vector<std::string> &productLineManufacturer,
                 std::vector<std::string> &productLineName,
                 std::vector<std::string> &productLineItemType,
                 std::vector<int> &productNumber);

int menuSelection();

void addToProductLine(std::vector<std::string> &productLineManufacturer,
                      std::vector<std::string> &productLineName,
                      std::vector<std::string> &productLineItemType);

void processingNewProductInfo(std::vector<std::string> &productLineManufacturer,
                              std::vector<std::string> &productLineName,
                              std::vector<std::string> &productLineItemType);

void newAvailableDetailedProducts(std::vector<std::string> &productLineManufacturer,
                                  std::vector<std::string> &productLineName,
                                  std::vector<std::string> &productLineItemType);

void output_sorted_product_names(std::vector<std::string> &productLineName);

#endif //HELLOWORLD_PROTOTYPES_H
