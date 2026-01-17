/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:23:20 by nuno              #+#    #+#             */
/*   Updated: 2026/01/17 13:54:30 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <stdexcept>

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	protected:
		
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat &operator=(Bureaucrat const &src);
		~Bureaucrat();

		const std::string	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();

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

std::ostream &operator<<(std::ostream& out, Bureaucrat const &obj);

#endif