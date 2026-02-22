/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:34:02 by azorlutu          #+#    #+#             */
/*   Updated: 2026/02/18 15:34:02 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm() : _name("Default form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::~AForm() 
{

}

AForm::AForm(AForm const &other) : _name(other._name),
                                _isSigned(other._isSigned), 
                                _gradeToSign(other._gradeToSign), 
                                _gradeToExecute(other._gradeToExecute)
{}

AForm& AForm::operator=(AForm const &other)
{
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) :  _name(name),
                                                                            _isSigned(false),
                                                                            _gradeToSign(gradeToSign),
                                                                            _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

const std::string &AForm::getName() const
{
    return this->_name;
}

bool AForm::isSigned() const
{
    return this->_isSigned;
}

int AForm::getGradeToSign() const
{
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    this->_isSigned = true;
}

void AForm::execute(Bureaucrat const &bureaucrat) const
{
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    if (bureaucrat.getGrade() > this->_gradeToExecute)
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& o, const AForm& form){
    o << "Form " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no") 
      << ", grade to sign: " << form.getGradeToSign() 
      << ", grade to execute: " << form.getGradeToExecute();
    return o;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low.";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed.";
}