/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:15:10 by aweissha          #+#    #+#             */
/*   Updated: 2024/10/09 16:46:50 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default name"), _grade(0)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
	std::cout << "Bureaucrat with name " << _name << " and grade " << _grade << " created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& original) : _name(original._name), _grade(original._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& original)
{
	if (this != &original)
	{
		this->_name = original._name;
		this->_grade = original._grade;
	}
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	return (*this);
}

void Bureaucrat::increment()
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
	std::cout << "Bureaucrat with name " << _name << " incremented to grade " << _grade << std::endl;
}

void Bureaucrat::decrement()
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
	std::cout << "Bureaucrat with name " << _name << " decremented to grade " << _grade << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return ("GradeTooHighException");
}

const char *Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return ("GradeTooLowException");
}

const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::ostream& operator<<(std::ostream& os,  const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << " , bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}
