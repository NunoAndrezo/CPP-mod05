#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("default_file")
{
	std::cout << "ShrubberyCreationForm Default Constructor called with default target: " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Constructor called with target: " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target)
{
	std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) //: AForm("ShrubberyCreationForm", 145, 137)
{
	if (this != &src)
	{
		AForm::operator=(src); // Call the base class assignment operator to copy the base class members
		this->_target = src._target;
		// what about is_signed?
	}
	return (*this);
}

const std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}


