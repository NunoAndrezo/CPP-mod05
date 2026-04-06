/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 16:22:46 by nuno              #+#    #+#             */
/*   Updated: 2026/04/06 15:52:43 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		AForm *makeRobotomy(std::string target);
		AForm *makePardon(std::string target);
		AForm *makeShrubbery(std::string target);
	protected:
	public:
		Intern(void);
		Intern(const Intern &src);
		Intern &operator=(const Intern &src);
		~Intern();
		//methods
		AForm *makeForm(std::string name_of_form, std::string target_of_form);
};