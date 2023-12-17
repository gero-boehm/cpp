#include "Form.hpp"

Form::Form(void): _name("Form"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &form): _name(form._name), _signed(form._signed), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute) {}

Form &Form::operator=(const Form &form) {
	if (this == &form)
		return *this;
	const_cast<std::string &>(_name) = form._name;
	_signed = form._signed;
	const_cast<unsigned int &>(_gradeToSign) = form._gradeToSign;
	const_cast<unsigned int &>(_gradeToExecute) = form._gradeToExecute;
	return *this;
}

Form::~Form() {}

const std::string &Form::getName(void) const {
	return _name;
}

bool Form::isSigned(void) const {
	return _signed;
}

unsigned int Form::getGradeToSign(void) const {
	return _gradeToSign;
}

unsigned int Form::getGradeToExecute(void) const {
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (_signed)
	{
		std::cerr << "Form " << _name << " is already signed" << std::endl;
		return;
	}

	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();

	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}
