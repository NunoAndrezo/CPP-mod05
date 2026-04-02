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

/* ShrubberyCreationForm: Required grades: sign 145, exec 137
Creates a file <target>_shrubbery in the working directory and writes ASCII trees
inside it. */
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw AForm::GradeTooLowException(); // if the form is not signed, we can't execute it, so we throw an exception.
	else if (executor.getGrade() > getGrade_Execute())
		throw AForm::GradeTooLowException(); // if the executor's grade is too low to execute the form, we throw an exception.
	std::ofstream file((getTarget() + "_shrubbery").c_str()); // create a file with the name of the target + "_shrubbery"
	if (!file.is_open())
	{
		std::cerr << "Error: Could not open file " << getTarget() + "_shrubbery" << std::endl;
		return;
	}
	else
	{
		for(int i = 0; i < 3; i++)
		{
			file << "                                                    ." << std::endl;
			file << "                                              .         ;  " << std::endl;
			file << "                 .              .              ;%     ;;    " << std::endl;
			file << "                   ,           ,                :;%  %;   " << std::endl;
			file << "                    :         ;                   :;%;'     .,   " << std::endl;
			file << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
			file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
			file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' "<< std::endl;
			file << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
			file << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
			file << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
			file << "                    `:%;.  :;bd%;          %;@%;'   "<< std::endl;
			file << "                      `@%:.  :;%.         ;@@%;'    "<< std::endl;  
			file << "                        `@%.  `;@%.      ;@@%;      "<< std::endl;      
			file << "                          `@%%. `@%%    ;@@%;       "<< std::endl;    
			file << "                            ;@%. :@%%  %@@%;        "<< std::endl;  
			file << "                              %@bd%%%bd%%:;         "<< std::endl;
			file << "                                #@%%%%%:;;          "<< std::endl;
			file << "                                %@@%%%::;           "<< std::endl;
			file << "                                %@@@%(o);  . '      "<< std::endl;      
			file << "                                %@@@o%;:(.,'        "<< std::endl;    
			file << "                            `.. %@@@o%::;           "<< std::endl; 
			file << "                               `)@@@o%::;           "<< std::endl; 
			file << "                                %@@(o)::;           "<< std::endl;
			file << "                               .%@@@@%::;           "<< std::endl; 
			file << "                               ;%@@@@%::;.          "<< std::endl;   
			file << "                              ;%@@@@%%:;;;.         "<< std::endl;
			file << "                          ...;%@@@@@%%:;;;;,..      " << std::endl;
			file << std::endl;
		}
		std::cout << "Shrubbery created in file: " << getTarget() + "_shrubbery" << std::endl;
	}
}
