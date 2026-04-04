#include "../inc/PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("default_target")
{
	std::cout << "[PresidentialPardonForm] -> Default constructor with no Arguments! (default_target)" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : _target(target)
{
	std::cout << "[PresidentialPardonForm] -> Default constructor with -target:" << getTarget() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target)
{
	std::cout << "[PresidentialPardonForm] -> Default constructor with no Arguments!" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm] -> Destructor!\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}



/* PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox */
int PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException(); // if the form is not signed, we can't execute it, so we throw an exception.
	else if (executor.getGrade() > getGrade_Execute())
		throw AForm::GradeTooLowException(); // if the executor's grade is too low to execute the form, we throw an exception.
	else if (executor.getGrade() < 1)
		throw AForm::GradeTooHighException(); // if the executor's grade is too high to execute the form, we throw an exception.
	std::cout << "I inform you that: " << _target << ", has been pardoned by Zaphod Beeblebrox!" << std::endl;
}
