
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	std::cout << " [RobotomyRequestForm] -> Default constructor called with no arguments" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << " [RobotomyRequestForm] -> Constructor called with target: " << this->_target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target)
{
	std::cout << "[RobotomyRequestForm] -> Copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	std::cout << "[RobotomyRequestForm] -> Assignment operator called" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm] -> Destructor called!" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

/*RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed.*/
int RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException(); // if the form is not signed, we can't execute it, so we throw an exception.
	else if (executor.getGrade() > getGrade_Execute())
		throw AForm::GradeTooLowException(); // if the executor's grade is too low to execute the form, we throw an exception.
	else if (executor.getGrade() < 1)
		throw AForm::GradeTooHighException(); // if the executor's grade is too high to execute the form, we throw an exception.
	std::cout << "rrrRREEE-rrr... vvvvv-ROOOM... K-CHUNK — k-chunk — k-chunk... DZZZZZ…DZZZZZ…DZZZZZ… eeeeee—eew\n";
	int	i;
	srand(time(NULL));
	if ((i = rand()) > RAND_MAX)
		return (1);
	if (i % 2 == 0)
		std::cout << getTarget() << " <- Has been robotomized successfully" << std::endl;
	else
		std::cout << getTarget() << " <- Robotomy failed" << std::endl;
	return (0);
}

