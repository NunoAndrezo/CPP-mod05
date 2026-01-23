/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:30:54 by nuno              #+#    #+#             */
/*   Updated: 2026/01/19 19:42:40 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Form
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			grade_sign;
		const int			grade_execute;
	protected:
	public:
		Form();
		Form(const std::string name, const int grade_sign, const int grade_execute);
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form();

		const std::string getName();
		bool getIsSigned();
		const int getGrade_Sign();
		const int getGrade_Execute();

		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

std::ostream operator<<(std::ostream &out, const Form &src);

#endif