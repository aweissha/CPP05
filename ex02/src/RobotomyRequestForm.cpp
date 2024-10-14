/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:57:27 by aweissha          #+#    #+#             */
/*   Updated: 2024/10/14 15:30:40 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("DefaultTarget")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm with target " << _target << " created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& original)
: AForm(original), _target(original._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& original)
{
	if (this != &original)
	{
		AForm::operator=(original);
		this->_target = original._target;	
	}
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const
{
	if (bureaucrat.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (this->getSignedStatus() == false)
		throw FormNotSignedException();
	std::cout << "Makes some drilling noises... " << std::endl;
	this->robotomize();
}

void RobotomyRequestForm::robotomize() const
{
	// srand(time(0));
	if (rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy on " << _target << " failed" << std::endl;
}
