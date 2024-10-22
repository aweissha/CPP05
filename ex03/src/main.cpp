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
#include "../include/Intern.hpp"

int main(void)
{
	Intern intern;

	try 
	{
	// AForm *shrubForm = intern.makeForm("shrubbery creation", "home");
	AForm *shrubForm = intern.makeForm("None Existing Form", "home");
	Bureaucrat b1("Bob", 137);
	Bureaucrat b2("John", 145);
	b2.signForm(*shrubForm);
	b1.executeForm(*shrubForm);

	b2.executeForm(*shrubForm);
	delete shrubForm;
	}
	catch (std::exception &e) 
	{
	std::cout << "Exception: " << e.what() << std::endl;
	}
}
