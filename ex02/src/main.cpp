/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:52:18 by aweissha          #+#    #+#             */
/*   Updated: 2024/10/12 14:39:27 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main(void)
{
	try 
	{
		Bureaucrat alice("Alice", 3);
		Bureaucrat bob("Bob", 50);

		Form taxForm("Tax Form", 5, 10);
		std::cout << taxForm << std::endl;

		alice.signForm(taxForm);
		std::cout << taxForm << std::endl;

		bob.signForm(taxForm);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form invalidForm("Invalid Form", 0, 10);
    }
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form invalidForm2("Invalid Form 2", 5, 151);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
