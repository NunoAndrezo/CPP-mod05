#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string _target;
	public:
		//constructors
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		// destructor
		~ShrubberyCreationForm();
		// operator overload
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

		//getters
		const std::string getTarget() const; //why const after the function? because we don't want to modify the object when we call this function, we just want to return the value of the target. but if it was changeTarget() we would want to modify the object, so we wouldn't put const after the function.
		//methods
		void execute(Bureaucrat const &executor) const;
};
