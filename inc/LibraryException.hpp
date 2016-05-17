#pragma once

#include <exception>
#include <iostream>

//base class for exceptions to be thrown when library functions fail
class LibraryException : public std::exception {
	private:
		const char *message;
		const char *libError;
		const bool reportLibError;
	public:
		LibraryException(const char *message, const char *libError, const bool reportLibError = true)
			: message(message), reportLibError(reportLibError) {}
		virtual const char* what() { return "Library Exception"; }
		friend std::ostream& operator<<(std::ostream& out, LibraryException& e);
};