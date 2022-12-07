//
// Created by Nonthachai Plodthong on 30/11/2022 AD.
//

#ifndef MULTIINHERITANCE_TESTPREDIRECTIVE_H

#include <iostream>

#define MULTIINHERITANCE_TESTPREDIRECTIVE_H


int main_inheritance();

struct Item {
	std::string itemName;
	std::string itemId;

};

class Complex {
private:
	double real;
	double imag;

public:
	explicit Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {

		std::cout << " Complex(double,double) called\n";

	}

	bool operator==(const Complex& rha) const {
		std::cout << "Complex == called()\n";
		return (real == rha.real && imag == rha.imag);
	}

	~Complex() {
		std::cout << "~Complex() called\n";
	}
};

class Student {
	std::string name;
	int id = 0;
	Item *item_list{};
	int64_t m_cnt;
public:
	Student() {
		name = "Nonthachai";
		id = id + 1;
		id++;
		std::cout << "Student Constructor called\n";
	}

	//single arguement should mark as explicit
	explicit Student(const std::string &item) {
		bool flag = false;
		int count = 0;
		for (int i = 0; i < m_cnt; ++i) {
			if (item_list[i].itemName != item) {
				std::cout << "This is out of order\n";
			} else {
				count = i;
				item_list[count].itemName = item;
				std::cout << "Added item into the lists\n";
			}
		}
	}

	~Student() {
		std::cout << "Destructor Called Student\n";
	}

	void display() {
		std::cout << "Student name is : " << name << '\n';
		std::cout << "Student name is : " << id << '\n';

	}
};


class Faculty {
	std::string name;
	double salary;
	Item *item_list{};
	int64_t m_cnt{};
public:
	Faculty(const Item *item) {
		int count = 0;
		for (int i = 0; i < m_cnt; ++i) {
			if (item_list[i].itemId != item[i].itemId) {
				count = i;
				item_list[count] = *item;
			}
		}
	}

	Faculty() {
		name = "Porrutai";
		salary = 5000;
		std::cout << "Faculty Constructor called\n";
	}

	~Faculty() {
		std::cout << "Destructor Faculty called\n";
	}

	void display() {
		std::cout << "Faculty name is : " << name << '\n';
		std::cout << "Salary daily is : " << salary << '\n';
	}
};

class TeachAssistant : public Student, public Faculty { // private by default
	/*called by sequence here Student() > Faculty() > TA() > ~TA() > ~Faculty() > ~Student()*/
	/*Destructor call reverse orders
	 * Student() > Faculty() > TA()
	 * ~TA() > ~Faculty() > ~Student()*/
public:
	explicit TeachAssistant(const Item *item) {
		std::cout << "Called One Argument Constructor\n";
	}

	TeachAssistant() {
		std::cout << "TA()\n";
	}

	~TeachAssistant() {
		std::cout << "~Ta()\n";
	}

};

#endif //MULTIINHERITANCE_TESTPREDIRECTIVE_H
