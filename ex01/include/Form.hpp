/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:24:43 by aweissha          #+#    #+#             */
/*   Updated: 2024/10/12 15:41:53 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_execGrade;

	public:
	Form();
	Form(const std::string& name, int signGrade, int execGrade);
	~Form();
	Form(const Form& original);
	Form& operator=(const Form& original);

	std::string			getName() const;
	bool				getSignedStatus() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	void				beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, Form& form);

#endif