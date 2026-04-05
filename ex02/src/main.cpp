/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:45:36 by nuno              #+#    #+#             */
/*   Updated: 2026/04/05 13:33:09 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		//TESTING bureaucreat
		Bureaucrat	bob("Bob", 1);
		std::cout << bob.getName() << " is a bureaucrat with grade " << bob.getGrade() << std::endl;
		std::cout << "or:\n";
		std::cout << bob << std::endl;

		//TESTING ShrubberyCreationForm with AForm
		ShrubberyCreationForm ShrubForm("Stupid_form_for_testing");
		ShrubberyCreationForm ShrubForm2(void); // default constructor
		ShrubberyCreationForm ShrubForm3 = ShrubForm; // copy constructor
		ShrubberyCreationForm ShrubForm4(ShrubForm); // copy constructor
		ShrubberyCreationForm ShrubForm5; // default constructor

		ShrubForm5 = ShrubForm; // copy assignment operator
		
		std::cout << ShrubForm.getName() << " is a ShrubForm with grade to sign " << ShrubForm.getGrade_Sign() << " and grade to execute " << ShrubForm.getGrade_Execute() << std::endl;
		std::cout << "or:\n";
		std::cout << ShrubForm << std::endl;

		bob.signForm(ShrubForm);
		std::cout << ShrubForm.getName() << " is signed: " << ShrubForm.getIsSigned() << std::endl;
		bob.executeForm(ShrubForm);
		

		//testing RobotomyRequestForm with AForm
		RobotomyRequestForm RobotForm("Robot_form_for_testing");
		std::cout << RobotForm.getName() << " is a RobotForm with grade to sign " << RobotForm.getGrade_Sign() << " and grade to execute " << RobotForm.getGrade_Execute() << std::endl;
		std::cout << "or:\n";
		std::cout << RobotForm << std::endl;
		bob.signForm(RobotForm);
		std::cout << RobotForm.getName() << " is signed: " << RobotForm.getIsSigned() << std::endl;
		bob.executeForm(RobotForm);

		//testing PresidentialPardonForm with AForm
		PresidentialPardonForm PardonForm("Pardon_form_testing");
		std::cout << PardonForm.getName() << " is a PardonForm with grade to sign " << PardonForm.getGrade_Sign() << " and grade to execute " << PardonForm.getGrade_Execute() << std::endl;
		std::cout << "or:\n";
		std::cout << PardonForm << std::endl;
		//bob.signForm(PardonForm); //not signed,so error expected
		std::cout << PardonForm.getName() << " is signed: " << PardonForm.getIsSigned() << std::endl;
		bob.executeForm(PardonForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}