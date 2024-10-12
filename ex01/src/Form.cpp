/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:25:59 by aweissha          #+#    #+#             */
/*   Updated: 2024/10/09 18:55:20 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _signGrade(150), _execGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string& name, bool isSigned, int signGrade, int execGrade) : 
_name(name), _isSigned(isSigned)
{
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	this->_signGrade = signGrade;
	this->_execGrade = execGrade;
	std::cout << "Form with name " << _name << " created" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form& original) : _name(original._name), _isSigned(original._isSigned),
_signGrade(original._signGrade), _execGrade(original._execGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& original)
{
	if (this != &original)
	{
		this->_name = original._name;
		this->_isSigned = original._isSigned;
		this->_signGrade = original._signGrade;
		this->_execGrade = original._execGrade;
	}
	return (*this);
}

const std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSignedStatus() const
{
	return (this->_isSigned);
}

const int Form::getSignGrade() const
{
	return (this->_signGrade);
}

const int Form::getExecGrade() const
{
	return (this->_execGrade);
}

const char *Form::GradeTooHighException::what() const _NOEXCEPT
{
	return ("GradeTooHighException");
}

const char *Form::GradeTooLowException::what() const _NOEXCEPT
{
	return ("GradeTooLowException");
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, Form& form)
{
	os << "Form Name: " << form.getName() << std::endl;
	os << "Signed Status: " << form.getSignedStatus() << std::endl;
	os << "Reqired Sign Grade: " << form.getSignGrade() << std::endl;
	os << "Required Execution Grade: " << form.getExecGrade() << std::endl;
}
