#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <functional>
#include <list>
#include <iomanip>
#include <bitset>
#include <chrono>
#include <thread>
#include <mutex>


void reportTime(const char *msg, std::chrono::steady_clock::duration span) {
	std::mutex lock;
	lock.lock();
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(span);
	std::cout << "[" << msg << "] - [" << ms.count() << "] milisecs\n\n";
	lock.unlock();
}


class A {
	std::string name;
public:
	A(const std::string &nams) {

	}

	A() {
		std::cout << "Calling class A Constructor\n";
	}
};

class B : public A {
public:
	B() {
		std::cout << "Calling class B Constructor\n";
	}
};

class C : public A {
	// need to mark as public as well to prevent default private class.
public:
	C() {
		std::cout << "Calling class C Constructor\n";
	}
};

class D : public B, public C {
public:
	D() {
		std::cout << "Calling class D Constructor\n";
	}

	~D() {
		std::cout << "Calling class D Destructor\n";
	}

	void display() const {
		std::cout << "Display class D\n";
	}
};


int main() {

	std::vector<double> xx(1 << 27, 0.5);
	std::chrono::steady_clock::time_point ts, te;
	ts = std::chrono::steady_clock::now();
	//double par = std::reduce(std::exception::par,x.begin(),x.end());
	std::thread th1(reportTime, "Hello", te - ts);
	std::cout << "[" << th1.get_id() << "]\n";
	std::thread th2(reportTime, "Nonthachai", te - ts);
	std::cout << "[" << th2.get_id() << "]\n";
	reportTime("Main Non Without Task", te - ts);

	/*th2.join();
	th1.join();*/
	std::vector<std::thread> threads;
	threads.push_back(std::move(th1));
	threads.push_back(std::move(th2));
	for (auto &join: threads) {
		join.join();
	}

	std::vector<int> aa{0, 1, 2, 3, 4, 2};
	std::vector<int> bb{5, 4, 2, 3, 1, 50}; // คุณลงมา
	//0 ,4 ,4  9  4   8 + 9 = 17 + 4 = 21

	int r1 = std::inner_product(aa.begin(), aa.end(), bb.begin(), 0);
	int r2 = std::inner_product(aa.begin(), aa.end(), bb.begin(), 0,
	                            std::plus<>(), std::equal_to<>());

	std::cout << "[" << r1 << "]\n";
	std::cout << "[" << r2 << "]\n";
	std::list<int> test1;
	test1.push_back(40); // add 40
	test1.push_back(41);// add 41
	test1.push_back(42);// add 42
	test1.insert(++test1.begin(), 12); // add 12 after 40;
	test1.erase(-- --test1.end()); // remove 41;


	for (auto test: test1) {
		std::cout << " " << test << " ";
	}
	std::cout << '\n';
	//FF0000 = FF = red / 00 = green / 00 = blue
	// 1byte = 8 bits;
	// 1byte = 256;
	// 256 * 256 * 256 = 16 millions;
	// HDR - 10 -> 1024 x 1024 x 1024 = 107 milions
	// ~ work on bits not byte
	std::stack<double> prices;
	prices.push(10.20);
	prices.push(3003);
	prices.push(20);
	//prices.top() = 5;
	prices.push(989.8);
	//STACK push 10 -> push 3003 -> push -> 20
	// 20 / 3003 / 10;  first in first out
	// prices.top = 5
	// 5 / 3033 / 10;


	for (int i = 0; i < prices.size(); ++i) {
		std::cout << " " << prices.top() << " ";
		prices.pop();
	}
	std::cout << "Hello, World!" << std::endl;
	// ~, & , | ,^ , << , >> // work only with integer
	D non;
	non.display();
	unsigned short bits = 108u;
	std::cout << " " << std::setw(10)
	          << bits << " - " << std::bitset<8>(bits)
	          << std::endl;
	/* templated class */
	std::cout << "~" << std::setw(10)
	          << ~bits << " - " << std::bitset<8>(~bits)
	          << std::endl;
	unsigned short bit_wise = 27u;
	std::cout << " " << std::setw(10) << bit_wise << " - " << std::bitset<8>(bit_wise) << std::endl;
	std::cout << ">>" << std::setw(10) << (bit_wise >> 2) << " - " << std::bitset<10>(bit_wise >> 2) << std::endl;

	int ooo[4][4] = {{0,  12, 23,  23},
	                 {10, 12, 32,  43},
	                 {23, 33, 223, 40},
	                 {20, 30, 40,  50}};

	std::vector<short> bitV;
	bitV.push_back(bits);
	short array[10] = {20, 49, 29, 12, 345, 67, 23, 29, 48, 50};
	for (auto &p: array) {
		bitV.push_back(p);
	}
	for (auto &k: bitV) {
		std::cout << std::right << "  " << "    " << k << " = " << std::bitset<8>(k) << std::endl;
		std::cout << '\n';
		std::cout << std::right << ">>" << "    " << (k >> 2) << " >> " << std::bitset<8>(k >> 2) << std::endl;
	}

	int c;
	int *a;

	std::cout << "Number you want to created : ";
	std::cin >> c;

	a = new int[c]; // allocate memory same line as user selected

	{
		for (int i = 0; i < c; i++) {
			a[i] = (i + 1) * (i + 1);
			// 1
			// 2 * 2 = 4;
			// 3 * 3 = 9;
			// 4 * 4 = 16;
			// 5 * 5 = 25;
		}
		{
			for (int i = 0; i < c; ++i) {
				std::cout << "\n[" << (i + 1) << "]" << " ";
				std::cout << "[" << a[i] << "]";
				std::cout << "\nOriginal Binary Number\n";
				std::cout << "Bit_wise [" << (a[i]) << "] 8 bits as : [" << std::bitset<8>(a[i]) << "]";
				std::cout << '\n' << "\nLet make shift operand to the left\n";
				std::cout << "Bit_wise [" << (a[i] << 2) << "] 8 bits as : [" << std::bitset<8>(a[i] << 2) << "]";
				std::cout << '\n' << "\nLet swap bit-shifting by '~' \n";
				std::cout << "Bit_wise [" << (~a[i]) << "] 8 bits as : [" << std::bitset<8>(~a[i]) << "]";
				std::cout << std::endl;
			}
			//Ragged Arrays

			//Ragged arrays are commonly used to store sets of strings. A ragged array is an array of addresses.
			// array of *
			//Each element of the array holds an address. The data stored at each address may be of different size.
			// not the same size
			//For example, C-style null terminated strings may differ in length,
			// Hello World , GoodMorning;
			//but the size of the pointer to each string is the same for every string.\

			char *name[] = {"Non", "Aom", "Jeremy", "Liam", "Homer"};
			// C++11 not allow literal to char*

			for (int i = 0; i < 4; ++i) {
				std::cout << "\t\t" << &name[i] << '\t' << std::hex
				          << name[i][0] << std::dec << ' ' << name[i]
				          << '\n';
			}

			//Type (*pointer)[ n ]; // pointer to an array with n columns
			int (*ptr)[20];
			int *ptrr[30];

			{
				const int size = 3;
				int i = 0;
				int (*ptrs)[size] = (int (*)[size]) new int[size];
				// the size of pointer has to be match with new;
				*ptrs[0] = 10;
				*ptrs[1] = 100;
				*ptrs[2] = 1000;

				for (i = 0; i < size; ++i) {
					std::cout << (*ptrs[i]) << ' ';
				}
				std::cout << '\n';
				delete[] ptrs;
			}
		}
	}
	delete[] a;


	//01011001 11001101 11101011 11100010
	//00000000 00000000 00001111 00000000
	//01011001 11001101 11100100 11100010         -> exclusive or  "^"

	/* templated class */
	//operator bits and &
	/*
	 * true & true = true;
	 * true & false = false;
	 * false & false = false;
	 * false & true = false;
	 * only true if both side are true;
	 * */
	char x = 'x';
	int pick = 0;
	//std::cin >> pick;
	// ~ complement operator (flips all bits 0 to 1 , 1 to 0 )

//	//128/64/32/16/8/4/2/1
	// 0/ 1/ 1/ 0/1/1/0/0 = 108u;
	// 1/ 0/ 0/ 1/0/0/1/1 = 147u; ~
	//128 - 16 - 2 - 1  =
	// 0/ 0/ 0/ 1/1/0/1/1 =  27
	// 0/0 /0 /0 /0/1/1/0 = 6

	// 0/ 0/ 0/ 1/1/0/1/1 = 27u
	// 0/ 1/1/ 0/0/1/1/0 = 102u
	// the sequences of calling constructor : Calling B check B derieved from A call A
	// A > B ;
	// Call C
	// A > C ;
	// D
	// A > C > A > B > D;
	return 0;
}
