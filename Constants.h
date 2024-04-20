/**
 * @file Constants.h
 * @author Shwe Moe Thant (14228423)
 * @brief Constants of the manager menu and the employee menu
 * @version 0.1
 * @date 2024-04-20
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef CONSTANTS_H
#define CONSTANTS_H

enum ManagerMenuOption
{
    MANAGER_QUIT = 0,
    MANAGER_HIRE_EMPLOYEE = 1,
    MANAGER_FIRE_EMPLOYEE = 2,
    MANAGER_PROMOTE_EMPLOYEE = 3,
    MANAGER_DEMOTE_EMPLOYEE = 4,
    MANAGER_LIST_ALL_EMPLOYEES = 5,
    MANAGER_LIST_CURRENT_EMPLOYEES = 6,
    MANAGER_LIST_FORMER_EMPLOYEES = 7,
    MANAGER_GENERATE_NEW_DATABASE = 8,
    MANAGER_SAVE_TO_FILE = 9,
    MANAGER_LOAD_FROM_FILE = 10,
    MANAGER_EDIT_EMPLOYEE = 11,
    MANAGER_SEARCH_EMPLOYEE = 12,
    MANAGER_CREATE_USER = 13,
    MANAGER_SAVE_USERS_TO_FILE = 14,
    MANAGER_LOAD_USERS_FROM_FILE = 15,
    MANAGER_DELETE_USER = 16,
    MANAGER_EDIT_USER = 17
};

enum EmployeeMenuOption
{
    EMPLOYEE_QUIT = 0,
    EMPLOYEE_VIEW_OWN_INFORMATION = 1
};

const int NUMBER_OF_EMPLOYEES = 8000;

#endif