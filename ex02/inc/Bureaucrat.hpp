/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:23:20 by nuno              #+#    #+#             */
/*   Updated: 2026/03/31 18:17:51 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;

	public:
		// constructors
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat const &src);
		
		// destructor
		~Bureaucrat();
		
		// operators
		Bureaucrat &operator=(Bureaucrat const &src);
		
		// getters
		const std::string	getName() const;
		int					getGrade() const;
		
		// public methods
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm &form);

		// Nested exception classes
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

// Overload of the insertion operator for Bureaucrat
std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj);

#endif