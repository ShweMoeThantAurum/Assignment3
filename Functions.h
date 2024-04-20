/**
 * @file Functions.h
 * @author Shwe Moe Thant (14228423)
 * @brief Declaration of functions used in UserInterface.cpp
 * @version 0.1
 * @date 2024-04-20
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <random>
#include "Database.h"
#include "Manager.h"
#include "UserRole.h"

using namespace std;
using namespace Records;
int validateMenuInput(int minValue, int maxValue);
int displayManagerMenu();
int displayEmployeeMenu();
void doHire(Database &db);
void doFire(Database &db);
void doPromote(Database &db);
void doDemote(Database &db);
string generateFakeAddress(const vector<string> &streetNames, const vector<string> &cityNames,
                           const vector<string> &postalCodes, mt19937 &gen);
Employee generateRandomEmployee(mt19937 &gen, int &employeeNumberCounter, const vector<string> &firstNames,
                                const vector<string> &middleNames, const vector<string> &lastNames, const vector<string> &streetNames,
                                const vector<string> &cityNames, const vector<string> &postalCodes);
void readDataFromFile(const string &filename, vector<string> &data);
void doGenerateNewDatabase(Database &db);
void doSaveDatabaseToFile(const Database &db);
void doLoadDatabaseFromFile(Database &db);
int getValidEmployeeNumber(Database &db);
string getValidNewAddress();
int getValidNewSalary();
bool getValidNewHireStatus(Employee &employee);
void doEditEmployee(Database &db);
int getValidRoleChoice(int roleChoiceInput);
void doSearch(Database &db);
void createUser(Manager &manager);
void editUser(Manager &manager);
void deleteUser(Manager &manager);
void saveUsersToFile(Manager &manager);
void loadUsersFromFile(Manager &manager);
void viewOwnInformation(Database &dB, Manager &manager);

#endif