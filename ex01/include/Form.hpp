/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:24:43 by aweissha          #+#    #+#             */
/*   Updated: 2024/10/09 18:55:28 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
	std::string		_name;
	bool			_isSigned;
	int				_signGrade;
	int				_execGrade;

	public:
	Form();
	Form(std::string& name, bool isSigned, const int signGrade, const int execGrade);
	~Form();
	Form(const Form& original);
	Form& operator=(const Form& original);

	const std::string	getName() const;
	bool				getSignedStatus() const;
	const int			getSignGrade() const;
	const int			getExecGrade() const;
	void				beSigned(const Bureaucrat& bureaucrat);
	
	class GradeTooHighException : public std::exception
	{
		public:
		const char *what() const _NOEXCEPT;
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const _NOEXCEPT;
	};
};

std::ostream& operator<<(std::ostream& os, Form& form);

#endif