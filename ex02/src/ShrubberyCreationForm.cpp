#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("default_file")
{
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{

}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	
}

const std::string ShrubberyCreationForm::getTarget() const
{
	
}

/* 
      *             ,
                  _/^\_
                 <     >
*                 /.-.\         *
         *        `/&\`                   *
                 ,@.*;@,
                /_o.I %_\    *
   *           (`'--:o(_@;
              /`;--.,__ `')             *
             ;@`o % O,*`'`&\
       *    (`'--)_@ ;o %'()\      *
            /`;--._`''--._O'@;
           /&*,()~o`;-.,_ `""`)
*          /`,@ ;+& () o*`;-';\
          (`""--.,_0 +% @' &()\
          /-.,_    ``''--....-'`)  *
     *    /@%;o`:;'--,.__   __.'\
         ;*,&(); @ % &^;~`"`o;@();         *
         /(); o^~; & ().o@*&`;&%O\
   jgs   `"="==""==,,,.,="=="==="`
      __.----.(\-''#####---...___...-----._
    '`         \)_`"""""`
            .--' ')
          o(  )_-\
            `"""` `
 */