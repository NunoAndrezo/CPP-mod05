/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:45:36 by nuno              #+#    #+#             */
/*   Updated: 2026/03/31 18:35:10 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

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
		std::cout << ShrubForm.getName() << " is a ShrubForm with grade to sign " << ShrubForm.getGrade_Sign() << " and grade to execute " << ShrubForm.getGrade_Execute() << std::endl;
		std::cout << "or:\n";
		std::cout << ShrubForm << std::endl;

		bob.signForm(ShrubForm);
		std::cout << ShrubForm.getName() << " is signed: " << ShrubForm.getIsSigned() << std::endl;
		ShrubForm.execute(bob);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}