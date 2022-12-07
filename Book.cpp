//
// Created by Nonthachai Plodthong on 4/12/2022 AD.
//

#include "Book.h"
#include <algorithm>
#include <fstream>
#include <vector>
#include <regex>


namespace sdds {


	Book::Book(const std::string &strBook) {
		std::string record{};
		std::vector<std::string> tmp;
		size_t pos = 0;
		size_t received = 0;
		record = strBook;
		char delimeter = ',';
		size_t delim = record.find(delimeter);

		pos = record.find_first_not_of(delimeter) != string::npos;
		if (pos) {
			record = std::regex_replace(record, std::regex("^ +| +$|( ) +"), "$1");
			record = record.substr(0, delim);
			this->authors = record;
			std::cout << "[" << authors << "]";
			record = record.substr(pos + 1);
			std::cout << "\n[" << record << "]";
			/*this->titles = record.substr(record.find_first_not_of(delimeter), delim);
			std::cout << "[" << titles << "]";*/
//
//
//
//				received = pos;
//				this->titles = record.substr(received, pos);
//				std::cout << "[" << titles << "]";
//				record = record.substr(pos - 1);

//				for_each(record.begin(), record.end(), [&](char copy) {
//					std::cout << "" << copy << "";
//				});
//				std::cout << "\n";



			/*for (auto &print: tmp) {
				std::cout << "" << print << "";
			}*/

		}
	}

	const string &Book::title() const {
		return titles;
	}

	const string &Book::country() const {
		return countrys;
	}

	const size_t &Book::year() const {
		return years;
	}

	double &Book::price() {
		return prices;
	}

	const std::string &Book::autor() const {
		return this->authors;
	}

	std::ostream &operator<<(std::ostream &os, const Book &b) {
		os << std::left << setw(20) << b.autor() << b.country() << " | " << b.title() << " | " << b.year() << " |\n";
		return os;
	}
}