/**
 * @file UserRole.cpp
 * @author Shwe Moe Thant (14228423)
 * @brief Implement a UserRole class
 * @version 0.1
 * @date 2024-04-19
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "UserRole.h"

User::User(const string &username, const string &password, UserRole role)
    : m_username(username), m_password(password), m_role(role) {}

const string &User::getUsername() const
{
    return m_username;
}

const string &User::getPassword() const
{
    return m_password;
}

void User::setPassword(const string &password)
{
    m_password = password;
}

UserRole User::getRole() const
{
    return m_role;
}

void User::setRole(UserRole role)
{
    m_role = role;
}
