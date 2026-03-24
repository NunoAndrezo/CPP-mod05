#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string _target;
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
		void execute(Bureaucrat const &executor) const;
		//getter
		const std::string getTarget() const;

};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm &src);