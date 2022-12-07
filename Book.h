//
// Created by Nonthachai Plodthong on 4/12/2022 AD.
//

#ifndef MULTIINHERITANCE_BOOK_H
#define MULTIINHERITANCE_BOOK_H

#include <iostream>
#include <string>

using namespace std;
namespace sdds {

	class Book {
	private:
		string authors{};
		string titles{};
		string countrys{};
		size_t years{}; // same as size_t
		double prices{};
		string summaryBooks{};
	public:
		Book() = default;

		Book(const std::string& strBook);

		const string &title() const;

		const string &country() const;

		const size_t &year() const;

		double& price();
		const std::string& autor() const;
	};

	std::ostream& operator<<(std::ostream& os, const Book& b);
}
#endif //MULTIINHERITANCE_BOOK_H
