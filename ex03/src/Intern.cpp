/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:05:16 by nuno              #+#    #+#             */
/*   Updated: 2026/04/06 16:05:17 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern(void)
{
	std::cout << "[Intern] -> Default Constructor!\n";
}

Intern::Intern(const Intern &src)
{
	Intern(); // call the default constructor to initialize the object
	std::cout << "[Intern] -> Copy Constructor!\n";
	// we could use the copy assignment operator to copy the values of the src to this object, but since we don't have any values to copy, we can just return.
	(void)src; // to avoid unused parameter warning
}

Intern &Intern::operator=(const Intern &src)
{
	std::cout << "[Intern] -> Copy Assignment Operator!\n";
	if (this == &src)
		return (*this);
	// we could copy the values of the src to this object, but since we don't have any values to copy, we can just return.
	(void)src; // to avoid unused parameter warning
	return (*this);
}

Intern::~Intern()
{
	std::cout << "[Intern] -> Destructor!\n";
}

AForm *Intern::makeForm(std::string name_of_form, std::string target_of_form)
{
	static std::string names_for_forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm* (Intern::*formCreators[])(std::string) = {&Intern::makeRobotomy, &Intern::makePardon, &Intern::makeShrubbery};

	int i = 0;
	while (i < 3)
	{
		if (name_of_form == names_for_forms[i])
		{
			std::cout << "Intern created: " << names_for_forms[i] << std::endl;
			return (this->*formCreators[i])(target_of_form);
		}
		i++;
	}
	std::cerr << "Intern could not create: " << name_of_form << std::endl;
	return (NULL);
}

AForm *Intern::makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}
