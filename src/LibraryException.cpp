#include "LibraryException.hpp"

std::ostream& operator<<(std::ostream& out, LibraryException& e) {
	out << e.what() << ": " << e.message;
	if (e.reportLibError) out << " [" << e.libError << "]";
	return out;
}