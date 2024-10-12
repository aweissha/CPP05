/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:54:07 by aweissha          #+#    #+#             */
/*   Updated: 2024/10/12 15:43:56 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
	const std::string _name;
	int			_grade;

	public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& original);
	Bureaucrat& operator=(const Bureaucrat& original);

	std::string			getName() const;
	int					getGrade() const;
	void				increment();
	void				decrement();

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
	void	signForm(Form& form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif