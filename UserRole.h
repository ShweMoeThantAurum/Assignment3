/**
 * @file UserRole.h
 * @author Shwe Moe Thant (14228423)
 * @brief Declare a UserRole class
 * @version 0.1
 * @date 2024-04-19
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef USERROLE_H
#define USERROLE_H

#include <iostream>
#include <string>

using std::string;

enum class UserRole
{
    Manager,
    Employee
};

class User
{
public:
    User() = default;
    /**
     * @brief Construct a new User object
     *
     * @param username
     * @param password
     * @param role
     */
    User(const string &username, const string &password, UserRole role);
    ~User(){};

    /**
     * @brief Get the User's username
     *
     * @return username of the User object
     */
    const string &getUsername() const;

    /**
     * @brief Get the User's password
     *
     * @return password of the User object
     */
    const string &getPassword() const;

    /**
     * @brief Set the User's password
     *
     * @param password
     */
    void setPassword(const string &password);

    /**
     * @brief Get the UserRole's role
     *
     * @return role of the UserRole object
     */
    UserRole getRole() const;
    /**
     * @brief Set the UserRole's role
     *
     * @param role
     */
    void setRole(UserRole role);

private:
    string m_username;
    string m_password;
    UserRole m_role;
};

#endif
