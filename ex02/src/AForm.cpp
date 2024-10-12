/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:25:59 by aweissha          #+#    #+#             */
/*   Updated: 2024/10/12 14:19:00 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::AForm() : _name("Default AForm"), _isSigned(false), _signGrade(150), _execGrade(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int signGrade, int execGrade) :
_name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	std::cout << "AForm with name " << _name << " created" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const AForm& original) : _name(original._name), _isSigned(original._isSigned),
_signGrade(original._signGrade), _execGrade(original._execGrade)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& original)
{
	if (this != &original)
		this->_isSigned = original._isSigned;
	std::cout << "AForm copy assignment operator called" << std::endl;
	return (*this);
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSignedStatus() const
{
	return (this->_isSigned);
}

int AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int AForm::getExecGrade() const
{
	return (this->_execGrade);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, AForm& Aform)
{
	os << "AForm Name: " << Aform.getName() << std::endl;
	os << "Signed Status: " << Aform.getSignedStatus() << std::endl;
	os << "Reqired Sign Grade: " << Aform.getSignGrade() << std::endl;
	os << "Required Execution Grade: " << Aform.getExecGrade() << std::endl;
	return (os);
}
