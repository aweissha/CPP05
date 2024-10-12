/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:24:43 by aweissha          #+#    #+#             */
/*   Updated: 2024/10/12 15:41:32 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_execGrade;

	public:
	AForm();
	AForm(const std::string& name, int signGrade, int execGrade);
	virtual ~AForm();
	AForm(const AForm& original);
	AForm& operator=(const AForm& original);

	std::string			getName() const;
	bool				getSignedStatus() const;
	int					getSignGrade() const;
	int					getExecGrade() const;
	void				beSigned(const Bureaucrat& bureaucrat);
	virtual void		execute(const Bureaucrat& bureaucrat) const = 0;

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

std::ostream& operator<<(std::ostream& os, AForm& form);

#endif