/**
 * @file Manager.cpp
 * @author Shwe Moe Thant (14228423)
 * @brief Implement a Manager class
 * @version 0.1
 * @date 2024-04-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Manager.h"

Manager::Manager(const string &filename)
    : m_filename(filename)
{
    loadUserDataFromFile(); // Load user data from file at very first to login with those credentials
}

bool Manager::login(const string &username, const string &password, UserRole &userRole)
{
    map<string, User>::iterator userIterator = users.find(username);
    if (userIterator != users.end() && userIterator->second.getPassword() == password)
    {
        userRole = userIterator->second.getRole();
        return true;
    }
    return false;
}

bool Manager::createUser(const string &username, const string &password, UserRole role)
//// Create a new User object with given username, password, and role
{
    User newUser(username, password, role);

    auto result = users.insert(make_pair(username, newUser));

    return result.second;
}

bool Manager::deleteUser(const string &username)
{
    map<string, User>::iterator userIterator = users.find(username);
    if (userIterator != users.end())
    {
        users.erase(userIterator);
        return true;
    }
    return false;
}

bool Manager::editUser(const string &username, const string &newPassword, UserRole newRole)
{
    map<string, User>::iterator userIterator = users.find(username);
    if (userIterator != users.end())
    {
        userIterator->second.setPassword(newPassword);
        userIterator->second.setRole(newRole);
        return true;
    }
    return false;
}

bool Manager::userExists(const string &username) const
{
    return users.find(username) != users.end();
}

const map<string, User> &Manager::getUsers() const
{
    return users;
}

void Manager::saveUserDataToFile() const
{
    ofstream outFile(m_filename);
    if (outFile.is_open())
    {
        for (const auto &pair : users)
        {
            outFile << pair.second.getUsername() << " "
                    << pair.second.getPassword() << " "
                    << static_cast<int>(pair.second.getRole()) << endl;
        }
        outFile.close();
    }
    else
    {
        throw runtime_error("Unable to open file for writing.");
    }
}

void Manager::loadUserDataFromFile()
{
    ifstream inFile(m_filename);
    if (inFile.is_open())
    {
        string username, password;
        int role;
        while (inFile >> username >> password >> role)
        {
            UserRole userRole = static_cast<UserRole>(role);
            users[username] = User(username, password, userRole);
        }
        inFile.close();
    }
    else
    {
        throw runtime_error("Unable to open file for reading.");
    }
}
