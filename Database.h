/**
 * @file Database.h
 * @author Shwe Moe Thant (14228423)
 * @brief Declare a Database class
 * @version 0.1
 * @date 2024-04-19
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef DATABASE_H
#define DATABASE_H

#include "Employee.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

using std::logic_error;
using std::string;
using std::vector;

namespace Records
{
	const int kFirstEmployeeNumber = 1;

	class Database
	{
	public:
		/**
		 * @brief Get the employee's number
		 *
		 * @param employeeNumber
		 * @return employee number of the employee
		 */
		Employee &getEmployee(int employeeNumber);

		/**
		 * @brief Get the employee's first name, middle name, last name and address
		 *
		 * @param firstName
		 * @param middleName
		 * @param lastName
		 * @param address
		 * @return the employee object with first name, middle name, last name and address
		 */
		Employee &getEmployee(const string &firstName, const string &middleName,
							  const string &lastName, const string &address);

		/**
		 * @brief Add the employee to the employees vector
		 *
		 * @param firstName
		 * @param middleName
		 * @param lastName
		 * @param address
		 * @return the employee object to the employees vector
		 */
		Employee &addEmployee(const string &firstName,
							  const string &middleName,
							  const string &lastName,
							  const string &address);

		/**
		 * @brief Display all employees in the vector
		 *
		 * @return all employees from the vector
		 */
		void displayAll() const;

		/**
		 * @brief Display all hired employees
		 *
		 * @return hired employees
		 */
		void displayCurrent() const;

		/**
		 * @brief Display all fired employees
		 *
		 * @return fired employees
		 */
		void displayFormer() const;

		/**
		 * @brief Save employees to a text file with a proper format
		 *
		 * @param filename
		 */
		void save(const string &filename) const;

		/**
		 * @brief Load employees from a text file where it stored employees
		 *
		 * @param filename
		 */
		void load(const string &filename);

		/**
		 * @brief Edit an employee's address, salary amount and hired or fired status
		 *
		 * @param employeeNumber
		 * @param newAddress
		 * @param newSalary
		 * @param newHired
		 */
		void editEmployee(int employeeNumber, const string &newAddress, int newSalary, bool newHired);

		/**
		 * @brief Search an employee by using a fraction of text which are first name, middle name, last name and address
		 *
		 * @param searchBy
		 * @param searchText
		 */
		void searchEmployee(int searchBy, const string &searchText);

	private:
		vector<Employee> m_employees;
		int m_nextEmployeeNumber = kFirstEmployeeNumber;
	};
}
#endif