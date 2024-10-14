/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.cpp										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aweissha <aweissha@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/09 12:52:18 by aweissha		  #+#	#+#			 */
/*   Updated: 2024/10/14 15:37:30 by aweissha		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main(void)
{
	srand(time(0));
	
	std::cout << "\n===========Test: ShrubberyCreationForm============" << std::endl;
	Bureaucrat bob("Bob", 140);
	Bureaucrat alice("Alice", 100);
	ShrubberyCreationForm shrubForm("Home");

	try
	{
		std::cout << shrubForm << std::endl;
		alice.signForm(shrubForm);
		alice.executeForm(shrubForm);
		bob.signForm(shrubForm);
		bob.executeForm(shrubForm);	// Should fail
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n===========Test: RobotomyRequestForm==========" << std::endl;
	Bureaucrat charlie("Charlie", 40);
	Bureaucrat dave("Dave", 80);
	RobotomyRequestForm robotomyForm("Sam");
	try
	{
		std::cout << robotomyForm << std::endl;
		charlie.signForm(robotomyForm);
		charlie.executeForm(robotomyForm);
		dave.executeForm(robotomyForm);	// Should fail
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n==========Test: PresidentialPardonForm==========" << std::endl;
	Bureaucrat president("President", 1);
	Bureaucrat assistant("Assistant", 30);
	PresidentialPardonForm pardonForm("PardonTarget");
	try
	{
		std::cout << pardonForm << std::endl;
		president.signForm(pardonForm);
		president.executeForm(pardonForm);
		assistant.executeForm(pardonForm);	// Should fail
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
