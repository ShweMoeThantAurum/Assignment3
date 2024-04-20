/**
 * @file UserInterface.cpp
 * @author Shwe Moe Thant (14228423)
 * @brief Testing file to test
 * @version 0.1
 * @date 2024-04-20
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
#include "Constants.h"
#include "Functions.h"

int main()
{
    Database employeeDB;
    UserRole userRole;

    string username, password;
    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    string userCredentialsFile = "usercredentials.txt";

    Manager manager(userCredentialsFile);
    if (!manager.login(username, password, userRole))
    {
        cout << "Login failed. The username and password are not correct." << endl;
        return 1;
    }

    bool done = false;
    if (userRole == UserRole::Manager)
    {
        while (!done)
        {
            int selection = displayManagerMenu();
            switch (selection)
            {
            case MANAGER_QUIT:
                done = true;
                break;
            case MANAGER_HIRE_EMPLOYEE:
                doHire(employeeDB);
                break;
            case MANAGER_FIRE_EMPLOYEE:
                doFire(employeeDB);
                break;
            case MANAGER_PROMOTE_EMPLOYEE:
                doPromote(employeeDB);
                break;
            case MANAGER_DEMOTE_EMPLOYEE:
                doDemote(employeeDB);
                break;
            case MANAGER_LIST_ALL_EMPLOYEES:
                employeeDB.displayAll();
                break;
            case MANAGER_LIST_CURRENT_EMPLOYEES:
                employeeDB.displayCurrent();
                break;
            case MANAGER_LIST_FORMER_EMPLOYEES:
                employeeDB.displayFormer();
                break;
            case MANAGER_GENERATE_NEW_DATABASE:
                doGenerateNewDatabase(employeeDB);
                break;
            case MANAGER_SAVE_TO_FILE:
                doSaveDatabaseToFile(employeeDB);
                break;
            case MANAGER_LOAD_FROM_FILE:
                doLoadDatabaseFromFile(employeeDB);
                break;
            case MANAGER_EDIT_EMPLOYEE:
                doEditEmployee(employeeDB);
                break;
            case MANAGER_SEARCH_EMPLOYEE:
                doSearch(employeeDB);
                break;
            case MANAGER_CREATE_USER:
                createUser(manager);
                break;
            case MANAGER_SAVE_USERS_TO_FILE:
                saveUsersToFile(manager);
                break;
            case MANAGER_LOAD_USERS_FROM_FILE:
                loadUsersFromFile(manager);
                break;
            case MANAGER_DELETE_USER:
                deleteUser(manager);
                break;
            case MANAGER_EDIT_USER:
                editUser(manager);
                break;
            default:
                break;
            }
        }
    }
    if (userRole == UserRole::Employee)
    {
        while (!done)
        {
            int selection = displayEmployeeMenu();
            switch (selection)
            {
            case EMPLOYEE_VIEW_OWN_INFORMATION:
                viewOwnInformation(employeeDB, manager);
                break;
            case EMPLOYEE_QUIT:
                done = true;
                break;
            default:
                break;
            }
        }
    }

    return 0;
}

int validateMenuInput(int minValue, int maxValue)
{
    int input;

    while (true)
    {
        if (!(cin >> input))
        {
            cout << "Invalid input type. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (input < minValue || input > maxValue)
        {
            cout << "Please enter a number between " << minValue << " and " << maxValue << ": ";
        }
        else
        {
            break;
        }
    }

    return input;
}

int displayManagerMenu()
{
    const int MIN_MENU_OPTION = 0;
    const int MAX_MENU_OPTION = 17;

    int selection;

    cout << endl;
    cout << "Manager Menu" << endl;
    cout << "-----------------" << endl;
    cout << "1) Hire a new employee" << endl;
    cout << "2) Fire an employee" << endl;
    cout << "3) Promote an employee" << endl;
    cout << "4) Demote an employee" << endl;
    cout << "5) List all employees" << endl;
    cout << "6) List all current employees" << endl;
    cout << "7) List all former employees" << endl;
    cout << "8) Generate new database" << endl;
    cout << "9) Save database to file" << endl;
    cout << "10) Load database from file" << endl;
    cout << "11) Edit employee" << endl;
    cout << "12) Search employee" << endl;
    cout << "13) Create new user" << endl;
    cout << "14) Save users to a file" << endl;
    cout << "15) Load users from a file" << endl;
    cout << "16) Delete user" << endl;
    cout << "17) Edit user" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "---> ";

    selection = validateMenuInput(MIN_MENU_OPTION, MAX_MENU_OPTION);

    return selection;
}

int displayEmployeeMenu()
{
    const int MIN_MENU_OPTION = 0;
    const int MAX_MENU_OPTION = 1;

    int selection;

    cout << endl;
    cout << "Employee Menu" << endl;
    cout << "-----------------" << endl;
    cout << "1) Display your information" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "---> ";

    selection = validateMenuInput(MIN_MENU_OPTION, MAX_MENU_OPTION);

    return selection;
}

void doHire(Database &db)
{
    string firstName, lastName, middleName, address;

    cout << "First name? ";
    cin >> firstName;
    cout << "Middle name? ";
    cin >> middleName;
    cout << "Last name? ";
    cin >> lastName;
    cout << "Address? ";
    cin >> address;
    db.addEmployee(firstName, middleName, lastName, address);
}

void doFire(Database &db)
{
    int employeeNumber;

    cout << "Employee number? ";
    cin >> employeeNumber;

    try
    {
        Employee &employee = db.getEmployee(employeeNumber);
        employee.fire();
        cout << "Employee " << employeeNumber << " terminated." << endl;
    }
    catch (const logic_error &exceptionCaught)
    {
        cerr << "Unable to terminate employee: " << exceptionCaught.what() << endl;
    }
}

void doPromote(Database &db)
{
    int employeeNumber, raiseAmount;

    cout << "Employee number? ";
    cin >> employeeNumber;
    cout << "How much of a raise? ";
    cin >> raiseAmount;

    try
    {
        Employee &employee = db.getEmployee(employeeNumber);
        employee.promote(raiseAmount);
        cout << "Employee number " << employeeNumber << "'s salary is increased " << raiseAmount << "." << endl;
    }
    catch (const logic_error &exceptionCaught)
    {
        cerr << "Unable to promote employee: " << exceptionCaught.what() << endl;
    }
}

void doDemote(Database &db)
{
    int employeeNumber, deritAmount;

    cout << "Employee number? ";
    cin >> employeeNumber;
    cout << "How much of a derit? ";
    cin >> deritAmount;

    try
    {
        Employee &employee = db.getEmployee(employeeNumber);
        employee.demote(deritAmount);
        cout << "Employee number " << employeeNumber << "'s salary is decreased " << deritAmount << "." << endl;
    }
    catch (const logic_error &exceptionCaught)
    {
        cerr << "Unable to promote employee: " << exceptionCaught.what() << endl;
    }
}

string generateFakeAddress(const vector<string> &streetNames, const vector<string> &cityNames, const vector<string> &postalCodes, mt19937 &gen)
{
    uniform_int_distribution<int> streetDist(0, streetNames.size() - 1);
    uniform_int_distribution<int> cityDist(0, cityNames.size() - 1);
    uniform_int_distribution<int> postalDist(0, postalCodes.size() - 1);

    string fakeAddress = streetNames[streetDist(gen)] + " Street, " +
                         cityNames[cityDist(gen)] + ", " +
                         postalCodes[postalDist(gen)];

    return fakeAddress;
}

Employee generateRandomEmployee(mt19937 &gen, int &employeeNumberCounter, const vector<string> &firstNames, const vector<string> &middleNames, const vector<string> &lastNames, const vector<string> &streetNames, const vector<string> &cityNames, const vector<string> &postalCodes)
{
    string firstName = firstNames[gen() % firstNames.size()];
    string middleName = middleNames[gen() % middleNames.size()];
    string lastName = lastNames[gen() % lastNames.size()];
    string address = generateFakeAddress(streetNames, cityNames, postalCodes, gen);

    Employee newEmployee(firstName, middleName, lastName, address);
    newEmployee.setEmployeeNumber(employeeNumberCounter++);

    return newEmployee;
}

void readDataFromFile(const string &filename, vector<string> &data)
{
    ifstream inFile(filename);
    if (inFile)
    {
        string line;
        while (getline(inFile, line))
        {
            data.push_back(line);
        }
    }
    else
    {
        cerr << "Failed to open file: " << filename << endl;
    }
}

void doGenerateNewDatabase(Database &db)
{

    vector<string> firstNames;
    readDataFromFile("firstnames.txt", firstNames);

    vector<string> middleNames;
    readDataFromFile("middlenames.txt", middleNames);

    vector<string> lastNames;
    readDataFromFile("lastnames.txt", lastNames);

    vector<string> streetNames;
    readDataFromFile("streetnames.txt", streetNames);

    vector<string> cityNames;
    readDataFromFile("citynames.txt", cityNames);

    vector<string> postalCodes;
    readDataFromFile("postalcodes.txt", postalCodes);

    random_device rd;
    mt19937 gen(rd());

    int employeeNumberCounter = kFirstEmployeeNumber;
    for (int employeeNumber = 0; employeeNumber < NUMBER_OF_EMPLOYEES; ++employeeNumber)
    {
        Employee newEmployee = generateRandomEmployee(gen, employeeNumberCounter, firstNames, middleNames, lastNames, streetNames, cityNames, postalCodes);
        db.addEmployee(newEmployee.getFirstName(), newEmployee.getMiddleName(), newEmployee.getLastName(), newEmployee.getAddress());
    }

    cout << "New database generated with " << NUMBER_OF_EMPLOYEES << " employees." << endl;
}

void doSaveDatabaseToFile(const Database &db)
{
    string filename;
    cout << "Enter the file name to save the database: ";
    cin.ignore();
    getline(cin, filename);

    if (ifstream(filename))
    {
        char choice;
        cout << "File already exists. Do you want to overwrite it? (y/n): ";
        cin >> choice;
        if (tolower(choice) != 'y')
        {
            cout << "Database not saved." << endl;
            return;
        }
    }

    db.save(filename);
    cout << "Database saved to file: " << filename << endl;
}

void doLoadDatabaseFromFile(Database &db)
{
    string filename;
    cout << "Enter the file name to load the database: ";
    cin.ignore();
    getline(cin, filename);

    try
    {
        db.load(filename);
        cout << "Database loaded successfully from file: " << filename << endl;
    }
    catch (const exception &exceptionCaught)
    {
        cerr << "Error: " << exceptionCaught.what() << endl;
        cout << "Database loading failed." << endl;
    }
}

int getValidEmployeeNumber(Database &db)
{
    int employeeNumberToEdit;

    while (true)
    {
        cout << "Employee number? ";
        cin >> employeeNumberToEdit;

        if (cin.fail())
        {
            cout << "Invalid input. Please enter a valid input for employee number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (employeeNumberToEdit <= 0)
        {
            cout << "Invalid input. Please enter a positive input for employee number." << endl;
        }
        else if (employeeNumberToEdit > NUMBER_OF_EMPLOYEES)
        {
            cout << "The employee number you entered exceeds the exisiting number of employees." << endl;
        }
        else
        {
            break;
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return employeeNumberToEdit;
}

string getValidNewAddress()
{
    string newAddress;
    cout << "Enter new address (or leave blank to keep current): ";
    getline(cin, newAddress);

    if (newAddress.empty())
    {
        cout << "Address remains unchanged." << endl;
    }

    return newAddress;
}

int getValidNewSalary()
{
    int newSalaryAmount = 0;

    while (true)
    {
        string newSalaryAmountInput;

        cout << "New salary (or leave blank to keep current): ";
        getline(cin, newSalaryAmountInput);

        if (!newSalaryAmountInput.empty())
        {
            try
            {
                newSalaryAmount = stoi(newSalaryAmountInput);
                if (newSalaryAmount < 0)
                {
                    cerr << "Invalid salary input. Salary cannot be negative. Please enter a non-negative integer for the salary." << endl;
                }
                else
                {
                    break;
                }
            }
            catch (const invalid_argument &)
            {
                cerr << "Invalid salary input. Please enter a valid integer for the salary." << endl;
            }
        }
        else
        {
            cout << "Salary remains unchanged." << endl;
            break;
        }
    }

    return newSalaryAmount;
}

bool getValidNewHireStatus(Employee &employee)
{
    bool newHired;
    while (true)
    {
        cout << "Is the employee still hired? (1 for yes, 0 for no, leave blank to keep the current status): ";
        string hiredInput;
        getline(cin, hiredInput);

        if (!hiredInput.empty())
        {
            if (hiredInput == "0")
            {
                employee.fire();
                newHired = false;
                break;
            }
            else if (hiredInput == "1")
            {
                employee.hire();
                newHired = true;
                break;
            }
            else
            {
                cerr << "Invalid input. Please enter either '0' or '1'." << endl;
            }
        }
        else
        {
            newHired = employee.isHired();
            break;
        }
    }

    return newHired;
}

void doEditEmployee(Database &db)
{
    try
    {
        int employeeNumberToEdit = getValidEmployeeNumber(db);
        Employee &employee = db.getEmployee(employeeNumberToEdit);

        string newAddress = getValidNewAddress();
        int newSalaryAmount = getValidNewSalary();
        bool newHired = getValidNewHireStatus(employee);

        db.editEmployee(employeeNumberToEdit, newAddress, newSalaryAmount, newHired);
        cout << "Employee with ID " << employee.getEmployeeNumber() << "'s information updated successfully." << endl;
    }
    catch (const exception &exceptionCaught)
    {
        cerr << "Error editing employee: " << exceptionCaught.what() << endl;
    }
}

void doSearch(Database &db)
{
    const int SEARCH_BY_MINIMUM_THRESHOLD = 1;
    const int SEARCH_BY_MAXIMUM_THRESHOLD = 4;

    int searchBy;
    string searchText;

    while (true)
    {
        cout << "How do you want to search?" << endl;
        cout << "1) First name" << endl;
        cout << "2) Middle name" << endl;
        cout << "3) Last name" << endl;
        cout << "4) Address" << endl;
        cout << "---> ";

        if (cin >> searchBy)
        {
            if (searchBy >= SEARCH_BY_MINIMUM_THRESHOLD && searchBy <= SEARCH_BY_MAXIMUM_THRESHOLD)
            {
                break;
            }
            else
            {
                cerr << "Invalid search option. Please enter a number between "
                     << SEARCH_BY_MINIMUM_THRESHOLD << " and " << SEARCH_BY_MAXIMUM_THRESHOLD << "." << endl;
            }
        }
        else
        {
            cerr << "Invalid input. Please enter a valid integer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "Enter search text: ";
    cin >> searchText;

    transform(searchText.begin(), searchText.end(), searchText.begin(), ::tolower);
    cout << "Matching employees:" << endl;
    db.searchEmployee(searchBy, searchText);
}

int getValidRoleChoice(int roleChoiceInput)
{
    while (true)
    {
        cout << "Enter role (0 for Manager, 1 for Employee): ";
        if (cin >> roleChoiceInput)
        {
            if (roleChoiceInput == 0 || roleChoiceInput == 1)
            {
                break;
            }
            else
            {
                cout << "Invalid role choice. Please enter either 0 or 1." << endl;
            }
        }
        else
        {
            cout << "Invalid input. Please enter a valid integer for the role." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return roleChoiceInput;
}

void createUser(Manager &manager)
{
    {
        string username, password;
        int roleChoice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter username: ";
        getline(cin, username);

        cout << "Enter password: ";
        getline(cin, password);

        roleChoice = getValidRoleChoice(roleChoice);

        UserRole role = (roleChoice == 0) ? UserRole::Manager : UserRole::Employee;

        bool created = manager.createUser(username, password, role);
        if (created)
        {
            cout << "User " << username << " created successfully." << endl;
        }
        else
        {
            cout << "User " << username << " already exists." << endl;
        }
    }
}

void editUser(Manager &manager)
{
    string username, newPassword;
    int newRoleChoice;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter username of the user to edit: ";
    getline(cin, username);

    cout << "Enter new password: ";
    getline(cin, newPassword);

    newRoleChoice = getValidRoleChoice(newRoleChoice);
    UserRole newRole = (newRoleChoice == 0) ? UserRole::Manager : UserRole::Employee;

    if (manager.editUser(username, newPassword, newRole))
    {
        cout << "User " << username << " edited successfully." << endl;
    }
    else
    {
        cout << "User " << username << " not found." << endl;
    }
}

void deleteUser(Manager &manager)
{
    string username;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter the username of the user to delete: ";
    getline(cin, username);

    if (manager.deleteUser(username))
    {
        cout << "User " << username << " is deleted successfully." << endl;
    }
    else
    {
        cout << "User " << username << " is not found." << endl;
    }
}

void saveUsersToFile(Manager &manager)
{
    try
    {
        manager.saveUserDataToFile();
        cout << "Users saved to file successfully." << endl;
    }
    catch (const runtime_error &exceptionCaught)
    {
        cerr << "Error: " << exceptionCaught.what() << endl;
    }
}

void loadUsersFromFile(Manager &manager)
{
    try
    {
        manager.loadUserDataFromFile();
        cout << "Users loaded from file successfully." << endl;
    }
    catch (const runtime_error &exceptionCaught)
    {
        cerr << "Error: " << exceptionCaught.what() << endl;
    }
}

void viewOwnInformation(Database &db, Manager &manager)
{
    const string EMPLOYEE_DATABASE_FILENAME = "database.txt";

    int employeeNumber;
    cout << "Enter your employee number: ";
    cin >> employeeNumber;

    try
    {

        db.load(EMPLOYEE_DATABASE_FILENAME);
        Employee &employee = db.getEmployee(employeeNumber);
        cout << "\nYour Information" << endl;
        cout << "-------------------" << endl;
        cout << "First Name: " << employee.getFirstName() << endl;
        cout << "Middle Name: " << employee.getMiddleName() << endl;
        cout << "Last Name: " << employee.getLastName() << endl;
        cout << "Address: " << employee.getAddress() << endl;
        cout << "Salary: $" << employee.getSalary() << endl;
        cout << "Status: " << (employee.isHired() ? "Hired" : "Not Hired") << endl;
    }
    catch (const logic_error &exceptionCaught)
    {
        cerr << "Error: " << exceptionCaught.what() << endl;
    }
}