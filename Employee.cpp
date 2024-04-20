/**
 * @file Employee.cpp
 * @author Shwe Moe Thant (14228423)
 * @brief Implement an Employee class
 * @version 0.1
 * @date 2024-04-19
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "Employee.h"

namespace Records
{
	Employee::Employee(const std::string &firstName, const std::string &middleName, const std::string &lastName, const std::string &address)
		: m_firstName(firstName), m_middleName(middleName), m_lastName(lastName), m_address(address)
	{
	}

	void Employee::promote(int raiseAmount)
	{
		setSalary(getSalary() + raiseAmount);
	}

	void Employee::demote(int demeritAmount)
	{
		setSalary(getSalary() - demeritAmount);
	}

	void Employee::hire()
	{
		m_Hired = true;
	}

	void Employee::fire()
	{
		m_Hired = false;
	}

	void Employee::display() const // Display the employee's information in a nice format
	{
		cout << "Employee: " << getFirstName() << " " << getMiddleName() << " " << getLastName() << endl;
		cout << "-------------------------" << endl;
		cout << (isHired() ? "Current Employee" : "Former Employee") << endl;
		cout << "Employee Number: " << getEmployeeNumber() << endl;
		cout << "Address: " << getAddress() << endl;
		cout << "Salary: $" << getSalary() << endl;
		cout << endl;
	}

	void Employee::setFirstName(const string &firstName)
	{
		m_firstName = firstName;
	}

	const string &Employee::getFirstName() const
	{
		return m_firstName;
	}

	void Employee::setMiddleName(const std::string &middleName)
	{
		m_middleName = middleName;
	}

	const std::string &Employee::getMiddleName() const
	{
		return m_middleName;
	}

	void Employee::setLastName(const string &lastName)
	{
		m_lastName = lastName;
	}

	const string &Employee::getLastName() const
	{
		return m_lastName;
	}

	void Employee::setAddress(const std::string &address)
	{
		m_address = address;
	}

	const std::string &Employee::getAddress() const
	{
		return m_address;
	}

	void Employee::setEmployeeNumber(int employeeNumber)
	{
		m_employeeNumber = employeeNumber;
	}

	int Employee::getEmployeeNumber() const
	{
		return m_employeeNumber;
	}

	void Employee::setSalary(int salary)
	{
		m_Salary = salary;
	}

	int Employee::getSalary() const
	{
		return m_Salary;
	}

	bool Employee::isHired() const
	{
		return m_Hired;
	}
}
