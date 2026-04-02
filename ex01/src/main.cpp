/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:45:36 by nuno              #+#    #+#             */
/*   Updated: 2026/03/31 18:16:25 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int	main(void)
{
	try
	{
		Form form_A(79, 150);
		Bureaucrat Inspector("Inspector Gadget", 80);
		std::cout << "Name: " << Inspector.getName() << ", grade: " << Inspector.getGrade() << std::endl;
		Inspector.incrementGrade(); // swap decrement and increment to test both exceptions
		std::cout << "Name: " << Inspector.getName() << ", grade after decrementing: " << Inspector.getGrade() << std::endl;
		Inspector.signForm(form_A);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}