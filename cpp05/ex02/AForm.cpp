#include "AForm.hpp"

AForm::AForm(void): _name("Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &form): _name(form._name), _signed(form._signed), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute) {}

AForm &AForm::operator=(const AForm &form)
{
	if (this == &form)
		return *this;
	const_cast<std::string &>(_name) = form._name;
	_signed = form._signed;
	const_cast<unsigned int &>(_gradeToSign) = form._gradeToSign;
	const_cast<unsigned int &>(_gradeToExecute) = form._gradeToExecute;
	return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName(void) const
{
	return _name;
}

bool AForm::isSigned(void) const {
	return _signed;
}

unsigned int AForm::getGradeToSign(void) const
{
	return _gradeToSign;
}

unsigned int AForm::getGradeToExecute(void) const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (_signed)
		throw AForm::AlreadySigned();
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();

	_signed = true;

	std::cout << bureaucrat << " signed " << *this << std::endl;
}

void AForm::execute(const Bureaucrat &bureaucrat) const
{
	if (!_signed)
		throw AForm::NotSigned();
	if (bureaucrat.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *AForm::NotSigned::what() const throw()
{
	return "Form not signed";
}

const char *AForm::AlreadySigned::what() const throw()
{
	return "Form already signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << form.getName() << " (" << (form.isSigned() ? "" : "not ") << "signed, grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute() << ")";
	return out;
}
