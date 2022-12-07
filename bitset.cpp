//
// Created by Nonthachai Plodthong on 2/12/2022 AD.
//
#include<iostream>
#include<bitset>
#include<iomanip>
#include "pre-processor.h"
#include "testPredirective.h"
#include <array>


using namespace std;

// ~       compliment operator (flip all bits)
// &       bitwise AND
// |	   bitwise OR
// ^	   XOR (can flip selected bits)
// << >>
double increment(int &x, int& y){
	x++, y++;
	return x+y + 0.3;
}

int increment2(int &x, int &y){
	x++, y++;
	return x+y;
}
struct Multiply { // functor
	int operator()(int& k , int&y){
		return k - y;
	}
};
int main() {
	/* the notation of [ , )
	 * mean = " [ " < starting point
	 *      = " ) " < ending point */
	std::array<int, 20> array20member = {10,20,30,40,50,60,70,70,80,80,10,20,30,40,50,60,70,70,80,80};
	int n = std::count(array20member.begin(),array20member.end(),30);
	std::cout << "<" << n << ">\n";
	std::function<int(int&,int&)> f1 = increment2;
	std::function<int(int&,int&)> f4 = Multiply();
	std::function<double(int&,int&)> f7 = increment;
	std::function<int(int&,int&)> f2 = [&](int& ok, int& ko){
		return ok * ko - 100;
	};
	int a1 = 11;
	int b2 = 22;
	double c2 = 30.2;
	std::cout << "f1 use function std : <" << f1(a1,b2) << ">\n";
	std::cout << "f7 use function std : <" << f7(a1,b2) << ">\n";
	std::cout << "f2 use function std : <" << f2(a1,b2) << ">\n";
	std::cout << "f4 use function std : <" << f4(a1,b2) << ">\n";
	auto inc = std::bind(increment,a1,b2);
	inc();
	std::cout << "a value is : <" << a1 << ">\n";
	std::cout << "b value is : <" << b2 << ">\n";
//	main_inheritance();
//	main_preprocessor();
//	main_container();
	unsigned short bits = 108u;
	//128/64/32/16/8/4/2/1
	//0 / 1 /1/0/1/1/0/0 = 64 + 32 + 8 +4 = (12 + 32 = 44 + 64 = 108 )
	cout << " " << setw(10) << bits << " - " << bitset<8>(bits) << endl;
	//128/64/32/16/8/4/2/1
	//0 / 1 /1/0/1/1/0/0 = 64 + 32 + 8 +4 = (12 + 32 = 448 + 64 = 108 )
	// 1 / 0 / 0 / 1 / 0 / 0 / 1 / 1 = -128 + 16 + 2 + 1 = 127 , 125 - 16 = -109
	cout << " ~ " << setw(10) << ~bits << " - " << bitset<8>(~bits) << endl;

	unsigned short bitAnd = 209u;
	cout << "bitwise AND -> &\n";
	cout << "  " << setw(10) << bits << " - " << bitset<8>(bits) << endl;
	cout << "  " << setw(10) << bitAnd << " - " << bitset<8>(bitAnd) << endl;
	cout << " & " << setw(9) << (bitAnd & bits) << " - " << bitset<8>(bitAnd & bits) << endl;

	cout << "bitwise OR &\n";
	cout << "  " << setw(10) << bits << " - " << bitset<8>(bits) << endl;
	cout << "  " << setw(10) << bitAnd << " - " << bitset<8>(bitAnd) << endl;
	cout << " | " << setw(9) << (bitAnd | bits) << " - " << bitset<8>(bitAnd | bits) << endl;

	cout << "XOR ^\n";
	cout << "  " << setw(10) << bits << " - " << bitset<8>(bits) << endl;
	cout << "  " << setw(10) << bitAnd << " - " << bitset<8>(bitAnd) << endl;
	cout << " ^ " << setw(9) << (bitAnd ^ bits) << " - " << bitset<8>(bitAnd ^ bits) << endl;

	// to see if perticular bit is 1 or 0
	unsigned short mask1 = 1u << 7u;
	cout << "  " << setw(10) << bits << " - " << bitset<16>(bits) << endl;
	cout << "  " << setw(10) << bitAnd << " - " << bitset<16>(mask1) << endl;
	cout << " & " << setw(9) << (bits & mask1) << " & " << bitset<16>(bits & mask1) << endl;

	if (bits & mask1)
		cout << "1\n";
	else
		cout << "0\n";
	{
		// to set a certain bit to 1 / turn off certain bit
		unsigned short mask1 = 1u << 7u;
		cout << "  " << setw(10) << bits << " - " << bitset<16>(bits) << endl;
		cout << "  " << setw(10) << bitAnd << " - " << bitset<16>(mask1) << endl;
		cout << " |" << setw(9) << (bits | mask1) << " | " << bitset<16>(bits | mask1) << endl;
	}

	{
		// to set a certain bit to 0 / turn on certain bit
		unsigned short mask1 = ~(1u << 6u);
		cout << "  " << setw(10) << bits << " - " << bitset<16>(bits) << endl;
		cout << "  " << setw(10) << bitAnd << " - " << bitset<16>(mask1) << endl;
		cout << " & " << setw(9) << (bits & mask1) << " & " << bitset<16>(bits & mask1) << endl;
	}

	{
		// to flip bit at certain position
		unsigned short mask1 = 1u << 7u;
		cout << "  " << setw(10) << bits << " - " << bitset<16>(bits) << endl;
		cout << "  " << setw(10) << bitAnd << " - " << bitset<16>(mask1) << endl;
		cout << " ^ " << setw(9) << (bits ^ mask1) << " ^ " << bitset<16>(bits ^ mask1) << endl;
	}

	{
		// to flip 2 bit at certain position
		unsigned short mask1 = (1u << 7u) | (1u << 6);
		cout << "  " << setw(10) << bits << " - " << bitset<16>(bits) << endl;
		cout << "  " << setw(10) << bitAnd << " - " << bitset<16>(mask1) << endl;
		cout << " ^ " << setw(9) << (bits & mask1) << " ^ " << bitset<16>(bits ^ mask1) << endl;
	}


	return 0;
}