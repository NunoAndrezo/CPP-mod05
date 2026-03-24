/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:45:36 by nuno              #+#    #+#             */
/*   Updated: 2026/03/13 14:02:14 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int	main(void)
{
	try
	{
		Form form_A(79, 150);
		Bureaucrat fine("Inspector Gadget", 80);
		std::cout << "Name: " << fine.getName() << ", grade: " << fine.getGrade() << std::endl;
		fine.decrementGrade();
		std::cout << "Name: " << fine.getName() << ", grade after decrementing: " << fine.getGrade() << std::endl;
		fine.signForm(form_A);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}