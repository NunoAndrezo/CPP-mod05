/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:30:54 by nuno              #+#    #+#             */
/*   Updated: 2026/03/19 12:52:24 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			grade_sign;
		const int			grade_execute;

	public:
		//constructors
		AForm();
		AForm(const int grade_sign, const int grade_execute);
		AForm(const AForm &src);
		AForm(const std::string name, const int grade_sign, const int grade_execute);
		

		//destructor
		virtual ~AForm(); // virtual destructor to allow proper cleanup of derived classes
		// Making this class abstract by declaring a pure virtual function (execute) ensures that it cannot be instantiated directly and must be inherited by derived classes that implement the execute method.

		//operators overloads
		AForm &operator=(const AForm &src);
		
		//public methods
		void beSigned(Bureaucrat &signer);
		virtual void execute(Bureaucrat const &executor) const = 0;

		//getters
		const std::string getName() const;
		bool getIsSigned() const;
		int getGrade_Sign() const;
		int getGrade_Execute() const;

		//Nested exception classes
		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, AForm &src);

#endif