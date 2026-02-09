/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:24:18 by nuno              #+#    #+#             */
/*   Updated: 2026/02/09 14:06:47 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

Form::Form(): name("Default"), is_signed(false), grade_sign(150), grade_execute(150)
{
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(const int grade_sign, const int grade_execute): name("Default"), is_signed(false), grade_sign(grade_sign), grade_execute(grade_execute)
{
	std::cout << "Form Constructor called, has grade sign: " << getGrade_Sign() << ", grade execute: " << getGrade_Execute() << std::endl;
	if (grade_sign < 1 || grade_execute < 1)
		throw GradeTooHighException();
	else if (grade_sign > 150 || grade_execute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &src): name(src.name + "_copy"), is_signed(src.is_signed), grade_sign(src.grade_sign), grade_execute(src.grade_execute)
{
	std::cout << "Form Copy Constructor called" << std::endl;
	if (src.grade_sign < 1 || src.grade_execute < 1)
		throw GradeTooHighException();
	else if (src.grade_sign > 150 || src.grade_execute > 150)
		throw GradeTooLowException();
}

Form &Form::operator=(const Form &src)
{
	std::cout << "Form Copy Assignment Operator called" << std::endl;
	if (this == &src)
		return (*this);
	(std::string)this->name = (std::string)src.name;
	return (*this); // can't modify values
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

const std::string Form::getName() const { return (this->name); }

bool Form::getIsSigned() const { return (this->is_signed); }

int Form::getGrade_Sign() const
{
	return (this->grade_sign);
}

int Form::getGrade_Execute() const { return (this->grade_execute); }

void Form::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() < 1)
		throw GradeTooHighException();
	else if (signer.getGrade() > 150)
		throw GradeTooLowException();
	if (signer.getGrade() <= this->getGrade_Sign()) // remember grade 1 is higher than grade 2!
	{
		if (this->is_signed == false)
		{
			std::cout << "This Form is now signed and was signed by: " << signer.getName() << std::endl;
			this->is_signed = true;
		}
		else
			std::cout << getName() <<": This Form was aready sign!" << std::endl;
	}
	else
		std::cout << signer.getName() << " couldn't sign Form: [" << getName() << "] because their grade is too low!" << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form: Grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade is too low!");
}

std::ostream &operator<<(std::ostream &out, Form &src)
{
	out << "Form: " << src.getName() <<
	":\n\tsign-grade:\t" << src.getGrade_Sign() <<
	"\n\texec-grade:\t" << src.getGrade_Execute() <<
	"\n\tis signed:\t" << src.getIsSigned() <<
	std::endl;
	return (out);
}