/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:23:20 by nuno              #+#    #+#             */
/*   Updated: 2026/01/07 10:57:52 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureucrat
{
	private:
		const std::string	name;
		int					grade;
	protected:
		
	public:
		Bureucrat();
		Bureucrat(const std::string name);
		Bureucrat(const Bureucrat &src);
		Bureucrat const &operator=(const Bureucrat &src);
		~Bureucrat();

		const std::string	getName();
		int					getGrade();
};

#endif