/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:42:15 by aweissha          #+#    #+#             */
/*   Updated: 2024/10/14 12:17:39 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
	std::string _target;

	public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& original);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& original);

	void execute(const Bureaucrat& bureaucrat) const;
	void robotomize() const;
};

#endif