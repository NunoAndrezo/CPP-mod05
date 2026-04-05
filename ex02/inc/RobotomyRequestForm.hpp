#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <stdlib.h>

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		//constructor
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &src);

		//destrutor
		~RobotomyRequestForm();

		//operator overload
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

		//getter
		std::string getTarget() const;
		//methods
		int execute(Bureaucrat const &executor) const;
};
