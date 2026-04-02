#pragma once

#include <iostream>
#include <fstream>
#include <exception>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		//constructors
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		// operator overload
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		// destructor
		~ShrubberyCreationForm();

		const std::string getTarget() const; //why const after the function? because we don't want to modify the object when we call this function, we just want to return the value of the target. but if it was changeTarget() we would want to modify the object, so we wouldn't put const after the function.
		int execute(Bureaucrat const &executor) const;
};
