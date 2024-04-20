/**
 * @file Employee.h
 * @author Shwe Moe Thant (14228423)
 * @brief Declare an Employee class
 * @version 0.1
 * @date 2024-04-19
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

namespace Records
{
	const int kDefaultStartingSalary = 30000;

	class Employee
	{
	public:
		Employee() = default;
		/**
		 * @brief Construct a new Employee object
		 *
		 * @param firstName
		 * @param middleName
		 * @param lastName
		 * @param address
		 */
		Employee(const string &firstName, const string &middleName, const string &lastName, const string &address);
		~Employee(){};

		/**
		 * @brief Promote by rasing salary amount
		 *
		 * @param raiseAmount
		 */
		void promote(int raiseAmount = 1000);

		/**
		 * @brief Demote by decreasing salary amount
		 *
		 * @param demeritAmount
		 */
		void demote(int demeritAmount = 1000);

		/**
		 * @brief Hire an employee
		 *
		 * @return 1 which means true and an employee is hired
		 */
		void hire();

		/**
		 * @brief Fire an employee
		 *
		 * @return 0 which means false and an employee is fired
		 */
		void fire();

		/**
		 * @brief Display employees' information
		 *
		 * @return employees' details
		 */
		void display() const;

		/**
		 * @brief Set the employee's first name
		 *
		 * @param firstName
		 */
		void setFirstName(const string &firstName);

		/**
		 * @brief Get the employee's first name
		 *
		 * @return first name of the employee
		 */
		const string &getFirstName() const;

		/**
		 * @brief Set the employee's middle name
		 *
		 * @param middleName
		 */
		void setMiddleName(const string &middleName);

		/**
		 * @brief Get the employee's middle name
		 *
		 * @return middle name of the employee
		 */
		const string &getMiddleName() const;

		/**
		 * @brief Set the employee's last name
		 *
		 * @param lastName
		 */
		void setLastName(const string &lastName);

		/**
		 * @brief Get the employee's last name
		 *
		 * @return last name of the employee
		 */
		const string &getLastName() const;

		/**
		 * @brief Set the employee's address
		 *
		 * @param address
		 */
		void setAddress(const string &address);

		/**
		 * @brief Get the employee's address
		 *
		 * @return address of the employee
		 */
		const string &getAddress() const;

		/**
		 * @brief Set the employee's number
		 *
		 * @param employeeNumber
		 */
		void setEmployeeNumber(int employeeNumber);

		/**
		 * @brief Get the employee's number
		 *
		 * @return employee number of the employee
		 */
		int getEmployeeNumber() const;

		/**
		 * @brief Set the employee's salary
		 *
		 * @param newSalary
		 */
		void setSalary(int newSalary);

		/**
		 * @brief Get the employee's salary
		 *
		 * @return salary of the employee
		 */
		int getSalary() const;

		/**
		 * @brief Handle whether the employee is hired or fired
		 *
		 * @return boolen of the employee hired(0) or fired status (1)
		 */
		bool isHired() const;

	private:
		string m_firstName;
		string m_middleName;
		string m_lastName;
		string m_address;
		int m_employeeNumber = -1;
		int m_Salary = kDefaultStartingSalary;
		bool m_Hired = false;
	};
}

#endif