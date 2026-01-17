/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:45:36 by nuno              #+#    #+#             */
/*   Updated: 2026/01/17 14:34:17 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int	main(void)
{
	try {
	Bureaucrat noData;
	//Bureaucrat tooHighGrade("High", 0); // add for error
	//Bureaucrat tooLowGrade("Low", 151); // add for error

	Bureaucrat fine("Inspector Gadget", 1);

	std::cout << "fine in the beginning: " <<fine << std::endl;

	//fine.incrementGrade(); // add for error
	fine.decrementGrade();
	std::cout << "Name: " << fine.getName() << ", grade after decrementing: " << fine.getGrade() << std::endl;

	std::cout << "Decrementing once more: \n";
	fine.decrementGrade();
	
	std::cout <<fine;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}