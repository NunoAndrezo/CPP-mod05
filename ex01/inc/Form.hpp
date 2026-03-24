/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:30:54 by nuno              #+#    #+#             */
/*   Updated: 2026/03/19 12:46:12 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			grade_sign;
		const int			grade_execute;

	public:
		//constructors
		Form();
		Form(const int grade_sign, const int grade_execute);
		Form(const Form &src);
		
		//destructor
		~Form();

		//operators overloads
		Form &operator=(const Form &src);
		
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

#endif