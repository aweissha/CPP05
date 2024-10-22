/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:18:31 by aweissha          #+#    #+#             */
/*   Updated: 2024/10/22 11:29:09 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	private:
	AForm *createShrubberyForm(const std::string& target);
	AForm *createRobotomyForm(const std::string& target);
	AForm *createPresidentialForm(const std::string& target);

	public:
	Intern();
	Intern(const Intern &original);
	~Intern();
	Intern &operator=(const Intern &original);
	AForm *makeForm(const std::string& formName, const std::string &target);
	class FormDoesNotExistException : public std::exception
	{
		public:
		const char *what() const throw();
	};
};

#endif