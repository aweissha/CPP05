/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:52:18 by aweissha          #+#    #+#             */
/*   Updated: 2024/10/09 16:47:20 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main(void)
{
	try
	{
		// Bureaucrat b1("Tom", 0);
		// Bureaucrat b1("Tom", 42);
		Bureaucrat b1("Tom", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat b2("John", 150);
		b2.increment();
		b2.decrement();
		b2.decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b3("Bob", 1);
		b3.decrement();
		b3.increment();
		b3.increment();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
