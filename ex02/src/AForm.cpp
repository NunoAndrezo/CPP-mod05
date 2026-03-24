/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:24:18 by nuno              #+#    #+#             */
/*   Updated: 2026/03/19 19:16:02 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm(): name("Default"), is_signed(false), grade_sign(150), grade_execute(150)
{
	std::cout << "AForm Default Constructor called" << std::endl;
}

AForm::AForm(const int grade_sign, const int grade_execute): name("Default"), is_signed(false), grade_sign(grade_sign), grade_execute(grade_execute)
{
	std::cout << "AForm Constructor called, has grade sign: " << getGrade_Sign() << ", grade execute: " << getGrade_Execute() << std::endl;
	if (grade_sign < 1 || grade_execute < 1)
		throw GradeTooHighException();
	else if (grade_sign > 150 || grade_execute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const std::string name, const int grade_sign, const int grade_execute): name(name), is_signed(false), grade_sign(grade_sign), grade_execute(grade_execute)
{
	std::cout << "AForm Constructor called, has grade sign: " << getGrade_Sign() << ", grade execute: " << getGrade_Execute() << std::endl;
	if (grade_sign < 1 || grade_execute < 1)
		throw GradeTooHighException();
	else if (grade_sign > 150 || grade_execute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &src): name(src.name + "_copy"), is_signed(src.is_signed), grade_sign(src.grade_sign), grade_execute(src.grade_execute)
{
	std::cout << "AForm Copy Constructor called" << std::endl;
	if (src.grade_sign < 1 || src.grade_execute < 1)
		throw GradeTooHighException();
	else if (src.grade_sign > 150 || src.grade_execute > 150)
		throw GradeTooLowException();
}

AForm &AForm::operator=(const AForm &src)
{
	std::cout << "AForm Copy Assignment Operator called" << std::endl;
	if (this == &src)
		return (*this);
	(std::string)this->name = (std::string)src.name;
	return (*this); // can't modify values since they are const. (technically we could modify the grade_sign and grade_execute but that would be a bad idea since they are const, so we just return the object without modifying it)
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called" << std::endl;
}

const std::string AForm::getName() const { return (this->name); }

bool AForm::getIsSigned() const { return (this->is_signed); }

int AForm::getGrade_Sign() const
{
	return (this->grade_sign);
}

int AForm::getGrade_Execute() const { return (this->grade_execute); }

void AForm::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() < 1)
		throw GradeTooHighException();
	else if (signer.getGrade() > 150)
		throw GradeTooLowException();
	if (signer.getGrade() <= this->getGrade_Sign()) // remember grade 1 is higher than grade 2!
	{
		if (this->is_signed == false)
		{
			std::cout << "This AForm is now signed and was signed by: " << signer.getName() << std::endl;
			this->is_signed = true;
		}
		else
			std::cout << getName() <<": This AForm was aready sign!" << std::endl;
	}
	else
		std::cout << signer.getName() << " couldn't sign AForm: [" << getName() << "] because their grade is too low!" << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("AForm: Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("AForm: Grade is too low!");
}

std::ostream &operator<<(std::ostream &out, AForm &src)
{
	out << "AForm: " << src.getName() <<
	":\n\tsign-grade:\t" << src.getGrade_Sign() <<
	"\n\texec-grade:\t" << src.getGrade_Execute() <<
	"\n\tis signed:\t" << src.getIsSigned() <<
	std::endl;
	return (out);
}