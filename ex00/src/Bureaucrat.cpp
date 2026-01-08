/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:57:23 by nuno              #+#    #+#             */
/*   Updated: 2026/01/08 14:47:13 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Mr. Bureaucrat") , grade(75)
{
	std::cout << "[Bureaucrat] -> Default Constructor with no arguments" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	try
	{
		if (grade < 1)
			throw -1;
		if (grade > 150)
			throw 1;
	}
	catch (outOfRange)
	{
		if (outOfRange == -1)
			GradeTooHighException(name, grade);
		else
			GradeTooLowException(name, grade);
	}
	(std::string)this->name = name;
	this->grade = grade;
	std::cout << "[Bureaucrat] -> Default Constructor with arguments" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	this->grade = src.grade;
	(std::string)this->name = src.name;
	std::cout << "[Bureaucrat] -> Copy Constructor" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
	{
		this->grade = src.grade;
		(std::string)this->name = src.name;
	}
	std::cout << "[Bureaucrat] -> Copy Assignment Operator" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat() { std::cout << "[Bureaucrat] -> Default Destructor" << std::endl; }

const std::string Bureaucrat::getName() { return (this->name); }

int Bureaucrat::getGrade() { return (this->grade); }

void	GradeTooHighException()
{
	
}

void	GradeTooLowException()
{

}

void	incrementGrade()
{

}

void	decrementGrade()
{

}
