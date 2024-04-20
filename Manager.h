/**
 * @file Manager.h
 * @author Shwe Moe Thant (14228423)
 * @brief Declare a Manager Class
 * @version 0.1
 * @date 2024-04-19
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef MANAGER_H
#define MANAGER_H

#include "UserRole.h"
#include <fstream>
#include <map>

using std::endl;
using std::ifstream;
using std::map;
using std::ofstream;
using std::ostream;
using std::pair;
using std::runtime_error;
using std::string;

class Manager
{
public:
    Manager() = default;
    /**
     * @brief Construct a new Manager object
     *
     * @param filename
     */
    Manager(const string &filename);
    ~Manager(){};

    /**
     * @brief Check whether the user is a manager or an employee
     *
     * @param username
     * @param password
     * @param userRole
     * @return manager login if a user is a manager or employee login if a user is an employee
     */
    bool login(const string &username, const string &password, UserRole &userRole);

    /**
     * @brief Create a User object
     *
     * @param username
     * @param password
     * @param role
     * @return a User object
     */
    bool createUser(const string &username, const string &password, UserRole role);

    /**
     * @brief Delete a User object
     *
     * @param username
     * @return delete a User if the username exists
     */
    bool deleteUser(const string &username);

    /**
     * @brief Edit a User object
     *
     * @param username
     * @param newPassword
     * @param newRole
     * @return edit a User's username, password, and role
     */
    bool editUser(const string &username, const string &newPassword, UserRole newRole);

    /**
     * @brief Check whether a User object exists or not
     *
     * @param username
     * @return true if a User exists or false if a User doesn't
     */
    bool userExists(const string &username) const;

    /**
     * @brief Save a User object to a text file
     *
     */
    void saveUserDataToFile() const;

    /**
     * @brief Load a User object from a text file
     *
     */
    void loadUserDataFromFile();

    /**
     * @brief Get the User objects
     *
     * @return users of the User object
     */
    const map<string, User> &getUsers() const;

private:
    map<string, User> users;
    string m_filename;
};

#endif
