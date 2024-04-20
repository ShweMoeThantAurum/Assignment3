/**
 * @file Database.cpp
 * @author Shwe Moe Thant (14228423)
 * @brief Implement a Database class
 * @version 0.1
 * @date 2024-04-19
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "Database.h"

using namespace std;

namespace Records
{
	Employee &Database::addEmployee(const string &firstName, const string &middleName,
									const string &lastName, const string &address)
	{
		Employee theEmployee(firstName, middleName, lastName, address);
		theEmployee.setEmployeeNumber(m_nextEmployeeNumber++);
		theEmployee.hire();
		m_employees.push_back(theEmployee);

		return m_employees[m_employees.size() - 1];
	}

	Employee &Database::getEmployee(int employeeNumber)
	{
		for (Employee &employee : m_employees)
		{
			if (employee.getEmployeeNumber() == employeeNumber)
			{
				return employee;
			}
		}
		throw logic_error("No employee found.");
	}

	Employee &Database::getEmployee(const string &firstName, const string &middleName,
									const string &lastName, const string &address)
	{
		for (Employee &employee : m_employees)
		{
			if (employee.getFirstName() == firstName &&
				employee.getMiddleName() == middleName &&
				employee.getLastName() == lastName &&
				employee.getAddress() == address)
			{
				return employee;
			}
		}
		throw logic_error("No employee found.");
	}

	void Database::displayAll() const
	{
		if (m_employees.empty())
		{
			throw logic_error("No employees in the database. The database is empty.");
			return;
		}

		for (const Employee &employee : m_employees)
		{
			employee.display();
		}
	}

	void Database::displayCurrent() const
	{
		if (m_employees.empty())
		{
			throw logic_error("No employees in the database. The database is empty.");
			return;
		}
		for (const Employee &employee : m_employees)
		{
			if (employee.isHired())
				employee.display();
		}
	}

	void Database::displayFormer() const
	{
		if (m_employees.empty())
		{
			throw logic_error("No employees in the database. The database is empty.");
			return;
		}
		for (const Employee &employee : m_employees)
		{
			if (!employee.isHired())
				employee.display();
		}
	}

	void Database::save(const string &filename) const
	{
		ofstream outFile(filename, ios::trunc);
		if (!outFile)
		{
			throw runtime_error("Failed to open file: " + filename);
		}

		try
		{
			for (const auto &employee : m_employees)
			{
				outFile << employee.getEmployeeNumber() << "\t"
						<< employee.getFirstName() << "\t"
						<< employee.getMiddleName() << "\t"
						<< employee.getLastName() << "\t\""
						<< employee.getAddress() << "\"\t"
						<< employee.getSalary() << "\t"
						<< (employee.isHired() ? "true" : "false") << "\n";

				if (!outFile)
				{
					throw runtime_error("An error occurred while writing employee data to the file.");
				}
			}
		}
		catch (const exception &e)
		{
			outFile.close();
			throw;
		}

		outFile.close();
	}

	void Database::load(const string &filename)
	{
		m_employees.clear();

		ifstream inFile(filename);
		if (!inFile)
		{
			throw runtime_error("Failed to open file: " + filename);
		}

		int employeeNumber, salary;
		string firstName, middleName, lastName, address, statusStr;
		while (inFile >> employeeNumber >> firstName >> middleName >> lastName)
		{
			getline(inFile >> ws, address, '\"');
			getline(inFile >> ws, address, '\"');
			inFile >> salary >> statusStr;

			bool status = (statusStr == "true");
			Employee employee(firstName, middleName, lastName, address);
			employee.setEmployeeNumber(employeeNumber);
			employee.setSalary(salary);
			if (status)
			{
				employee.hire();
			}
			else
			{
				employee.fire();
			}
			m_employees.push_back(employee);
		}

		inFile.close();
	}

	void Database::editEmployee(int employeeNumber, const string &newAddress, int newSalary, bool newHired)
	{
		Employee &employee = getEmployee(employeeNumber);

		if (!newAddress.empty())
		{
			employee.setAddress(newAddress);
		}
		if (newSalary > 0)
		{
			employee.setSalary(newSalary);
		}
		else
		{
			employee.getSalary();
		}
		if (newHired)
		{
			employee.hire();
		}
		else
		{
			employee.fire();
		}
	}

	void Database::searchEmployee(int searchBy, const string &searchText)
	{
		vector<Employee> results;

		const int SEARCH_BY_FIRST_NAME = 1;
		const int SEARCH_BY_MIDDLE_NAME = 2;
		const int SEARCH_BY_LAST_NAME = 3;
		const int SEARCH_BY_ADDRESS = 4;

		for (const Employee &employee : m_employees)
		{
			string targetSearch;
			switch (searchBy)
			{
			case SEARCH_BY_FIRST_NAME:
				targetSearch = employee.getFirstName();
				break;
			case SEARCH_BY_MIDDLE_NAME:
				targetSearch = employee.getMiddleName();
				break;
			case SEARCH_BY_LAST_NAME:
				targetSearch = employee.getLastName();
				break;
			case SEARCH_BY_ADDRESS:
				targetSearch = employee.getAddress();
				break;
			}

			string targetSearchLower = targetSearch;
			string searchTextLower = searchText;
			transform(targetSearchLower.begin(), targetSearchLower.end(), targetSearchLower.begin(), ::tolower);
			transform(searchTextLower.begin(), searchTextLower.end(), searchTextLower.begin(), ::tolower);

			if (targetSearchLower.find(searchTextLower) != string::npos)
			{
				results.push_back(employee);
			}
		}

		if (results.empty())
		{
			throw logic_error("No matching employees found.");
		}
		else
		{
			for (const Employee &result : results)
			{
				result.display();
			}
		}
	}
}