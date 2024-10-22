/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:18:33 by aweissha          #+#    #+#             */
/*   Updated: 2024/10/22 11:38:27 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &original)
{
	(void) original;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &original)
{
	(void) original;
	std::cout << "Intern copy assignment operator called" << std::endl;
	return (*this);
}

AForm *Intern::createShrubberyForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::createRobotomyForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createPresidentialForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string& formName, const std::string &target)
{
	const std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*createFormFunction[])(const std::string&) = {
		&Intern::createShrubberyForm,
		&Intern::createRobotomyForm,
		&Intern::createPresidentialForm
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formNames[i] << std::endl;
			return ((this->*createFormFunction[i])(target));
		}
	}
	throw (FormDoesNotExistException());
}

const char *Intern::FormDoesNotExistException::what() const throw()
{
	return ("FormDoesNotExistException");
}
