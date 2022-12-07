#include <iostream>
#include <string>
#include <variant>
#include <vector>
#include "pre-processor.h"

namespace sdds {

}

int main_container() {
	std::string str("GoodMorning");
	str += '\0';
	str += "non";
	std::cout << "[";

	std::string_view ok(str);
	for (int i = 0; i < str.size(); ++i) {
		if (str[i++] == '\0') {
			std::cout << "Null byte at str [ " << i - 1 << " ]\n";
		}
		std::cout << " " << str[i];
	}
	std::cout << "[" << ok << "]\n";

	/*container template classes
			sequential containers
			container adapters
			associative containers (beyond scope)
					iterators
					algorithms
					function objects*/

	// CONTAINER -> Iterators <- Algorithms
	/*std::Ref() << <functional> return lvalue reference ita arugment*/
	/*std::move() << <utility> return rvalue reference its a arguments*/

	std::variant<double, long> a, b;

// std::variant <prototype,prototype> name,name;
	a = 12.32;
	b = std::get<double>(a);

	std::cout << "[" << (int *) (&b) << "]\n";


	try {
		double c = std::get<long>(b); // Narrowing conversion double to long.
		std::cout << " [ " << c << " ] \n";

	} catch (std::bad_variant_access &msg) {
		std::cout << "bad type access " << &msg << '\n';
	}


	/* array = contiguous storage of fixed size
	 * vector - contiguous storage of variable size
	 * deuqe - non-continue storage of variable size and double-ended que
	 * forward-list - non continue storage variable size, singly linked list
	 * list  - non-continue storage of variable size , doubly linked list
	 * */

	std::vector<std::string> names;

	if (names.empty()) {
		std::cout << "names is empty" << std::endl;
	}

	std::string nameStorage[]{"Test",
	                          "Non", "QA", "AutoMation"};

	for (auto &namess: nameStorage) {
		names.push_back(namess);
	}

	for (int i = 0; i < names.size(); ++i) {
		std::cout << names[i] << " ";
	}
	std::cout << '\n';

	std::cout << "Print first of container[names] : [" << names.front() << "]\n";
	names.front() = "Job Offer";
	std::cout << "Print first of container[names] : [" << names.front() << "]\n";

	std::cout << "Print last of container[names] : [" << names.back() << "]\n";
	names.pop_back();
	std::cout << "Print last of container[names] : [" << names.back() << "]\n";

	for (int j = 0; j < names.size(); ++j) {
		std::cout << names[j] << " ";
	}
	std::cout << "\n";

	std::string nameColumn[5][5] = {{"row1", "ok2", "ok3", "ok4", "ok5"},
	                                {"row2", "ok2", "ok3", "ok4", "ok5"},
	                                {"row3", "ok2", "ok3", "ok4", "ok5"},
	                                {"row4", "ok2", "ok3", "ok4", "ok5"},
	                                {"row5", "ok2", "ok3", "ok4", "ok5"}};

	{
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				std::cout << " " << nameColumn[i][j] << " ";
			}
			std::cout << '\n';
		}
	}

	**nameColumn = "try insert"; // จะไปอยุ่ตัวแรกสุด

	{
		auto *tmp = new std::string[5];
		for (int i = 0; i < tmp->size(); ++i) {
			tmp = nameColumn[i];
		}
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				std::cout << " " << tmp[i][j] << " ";
			}

		}
		{
			for (int i = 0; i < 5; ++i) {
				for (int j = 0; j < 5; ++j) {
					std::cout << " " << nameColumn[i][j] << " ";
				}
				std::cout << '\n';
			}
		}


		return 0;
	}
}
