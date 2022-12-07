//
// Created by Nonthachai Plodthong on 5/12/2022 AD.
//

#include "push_back.h"
#include <list>
#include <algorithm>

using namespace std;

using namespace std;

void task(double val) {
	cout << "this is " << val << endl;
}

int main() {
	sdds::List<int> lst;
	sdds::List<double> doubleTest;
	sdds::List<double> doubleTest2;
	sdds::List<double> doubleTest3;
	std::list<double> okok;
	//okok = std::sort(okok.begin(),okok.end()); // cannot use std:;sort
	sdds::List<int> lst2;
	doubleTest.push_back(203.2);
	doubleTest.push_back(203.2);
	doubleTest.push_back(19.2);
	doubleTest.push_back(19.2);
	doubleTest.push_back(50.2);
	doubleTest.pop();


	for (auto print: doubleTest) {
		cout << "<" << print << ">";
	}
	doubleTest2 = doubleTest;
	doubleTest2.push_back(20.2);
	doubleTest3 = doubleTest2;
	std::cout << '\n';
	for (auto print: doubleTest) {
		cout << "<" << print << ">";
	}
	std::cout << '\n';
	for (auto print: doubleTest3) {
		cout << "<" << print << ">";
	}
}
//	l	cout << "<" << print << ">";        st2.push_back(30);
//	l}                                       st2.push_back(40);
//	lst2.push_back(14);
//	lst2.push_back(14);

//	for (auto &list: lst) {
//	std::cout << "[" << list << "]\n";
//	}
//	std::for_each(lst.begin(), lst.end(), [](const int &k) {
//		std::cout << "<" << k << ">\n";
//	});



//	for(auto& ok : lst){
//		std::cout << "<" << ok << ">\n";
//	}


