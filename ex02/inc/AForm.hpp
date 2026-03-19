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
		
		//destructor
		~AForm();

		//operators overloads
		AForm &operator=(const AForm &src);
		
		//public methods
		void beSigned(Bureaucrat &signer);

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

//Overload of the insertion operator for AForm
std::ostream &operator<<(std::ostream &out, AForm &src);

#endif