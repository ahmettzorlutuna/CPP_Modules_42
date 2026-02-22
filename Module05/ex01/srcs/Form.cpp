/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:35:56 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/18 12:35:59 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::Form() : _name("Default form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::~Form() 
{

}

Form::Form(Form const &other) : _name(other._name),
                                _isSigned(other._isSigned), 
                                _gradeToSign(other._gradeToSign), 
                                _gradeToExecute(other._gradeToExecute)
{}

Form& Form::operator=(Form const &other)
{
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) :  _name(name),
                                                                            _isSigned(false),
                                                                            _gradeToSign(gradeToSign),
                                                                            _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

const std::string &Form::getName() const
{
    return this->_name;
}

bool Form::isSigned() const
{
    return this->_isSigned;
}

int Form::getGradeToSign() const
{
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& o, const Form& form){
    o << "Form " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no") 
      << ", grade to sign: " << form.getGradeToSign() 
      << ", grade to execute: " << form.getGradeToExecute();
    return o;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high.";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low.";
}