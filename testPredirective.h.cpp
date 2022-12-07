//
// Created by Nonthachai Plodthong on 3/12/2022 AD.
//

#include "testPredirective.h"

int main_inheritance() {
	TeachAssistant foo;
	foo.Faculty::display();
	foo.Student::display();

	Complex com1(3.0, 20);
	if (com1 == (Complex) 33) {
		std::cout << "Same";
	} else {
		std::cout << "Not same\n";
	}
	return 0;
}


