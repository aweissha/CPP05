/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:32:44 by aweissha          #+#    #+#             */
/*   Updated: 2024/10/14 11:49:25 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("DefaultTarget")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm with target " << _target << " created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& original)
: AForm(original), _target(original._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& original)
{
	if (this != &original)
	{
		AForm::operator=(original);
		this->_target = original._target;	
	}
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const
{
	if (bureaucrat.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (this->getSignedStatus() == false)
		throw FormNotSignedException();
	try
	{
		createShrubbery();
	}
	catch (const char *e)
	{
		std::cerr << "Error: " << e << std::endl;
	}
}

void ShrubberyCreationForm::createShrubbery() const
{
	std::ofstream newFile(_target + "_shrubbery");
	if (newFile.is_open())
	{
		newFile << "          *\n";
		newFile << "         /_\\\n";
		newFile << "        /*o*\\\n";
		newFile << "       /o* *o\\\n";
		newFile << "      /* *o o*\\\n";
		newFile << "     /o* o * *o\\\n";
		newFile << "    /* o * * o *\\\n";
		newFile << "   /o * o * o * o\\\n";
		newFile << "         |||\n";
		newFile << "         |||\n";
		newFile.close();
	}
	else
		throw "Could not open file";
}
