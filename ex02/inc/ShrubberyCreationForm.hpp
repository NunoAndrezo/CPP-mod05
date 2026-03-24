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

		//methods
		void execute(Bureaucrat const &executor) const;
		//getters
		const std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm &src);