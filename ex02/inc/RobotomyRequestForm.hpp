#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

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

		//methods
		int execute(Bureaucrat const &executor) const;
		//getter
		std::string getTarget() const;

};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm &src);