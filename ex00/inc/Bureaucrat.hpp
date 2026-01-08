/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:23:20 by nuno              #+#    #+#             */
/*   Updated: 2026/01/08 12:27:08 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	protected:
		
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat& operator=(const Bureaucrat &src);
		Bureaucrat GradeTooHighException(const std::string name, int grade);
		Bureaucrat GradeTooLowException(const std::string name, int grade);
		~Bureaucrat();

		const std::string	getName();
		int		getGrade();
		void	incrementGrade();
		void	decrementGrade();
};

#endif