/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:57:23 by nuno              #+#    #+#             */
/*   Updated: 2026/01/17 14:34:53 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Mr. Bureaucrat") , grade(150)
{
	std::cout << "[Bureaucrat] -> Default Constructor with no arguments" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
: name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
	std::cout << "[Bureaucrat] -> Default Constructor with arguments" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	(std::string)this->name = src.name;
	if (src.grade < 1)
		throw GradeTooHighException();
	else if (src.grade > 150)
		throw GradeTooHighException();
	this->grade = src.grade;
	std::cout << "[Bureaucrat] -> Copy Constructor" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
	if (this != &src)
	{
		(std::string)this->name = src.name;
		if (src.grade < 1)
			throw GradeTooHighException();
		else if (src.grade > 150)
			throw GradeTooLowException();
		this->grade = src.grade;
	}
	std::cout << "[Bureaucrat] -> Copy Assignment Operator" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat() { std::cout << "[Bureaucrat] -> Default Destructor" << std::endl; }

const std::string Bureaucrat::getName() const { return (this->name); }

int Bureaucrat::getGrade() const { return (this->grade); }

void	Bureaucrat::incrementGrade()
{
	this->grade--;
	if (this->grade < 1)
		throw GradeTooHighException();
	else if (this->grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::decrementGrade()
{
	this->grade++;
	if (this->grade > 150)
		throw GradeTooLowException();
	else if (this->grade < 1)
		throw GradeTooHighException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too High!\n";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too Low!\n";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return out;
}