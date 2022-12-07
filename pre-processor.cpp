//
// Created by Nonthachai Plodthong on 30/11/2022 AD.
//

#include <iostream>
#include <memory>
#include "pre-processor.h"
//#include <iomanip>

//define

#define P 3.5
#define AREA(R) P * R * R
#define COLOR(A, B, C) (A * B * C * 10) // macro should close with parentness
//#define AREA (R) PI * R * R  // error because parameter R has one white space after DEFINITION
#define PRODUCT(X, Y) ((X) * (Y))
#define NITER 1000000000
#define SQUARE(x) ((x) * (x)) /* PARENTHESE */
//#define SQUARES(x) X * X /* ERROR */


double product(double x, double y) {
	return x * y;
}

int main_preprocessor() {
	//string literal cannot be change
	// const char* p = "hello";
	const char *pk = "hello"; /* String Literal*/
	std::string ok = "HelloWorld"; /*String can be changed*/
	ok[1] = 'o';
	//pk[1] = 'k';
	// double area = AREA(42040.24);
	double cl = COLOR(255, 94, 20);
	std::cout << "Area is [" << std::fixed << area << "]" << '\n';
	std::cout << "\nColor is [" << std::fixed << cl << "]" << '\n';


	double x;
	int i = 0;
	std::clock_t c0, c1;

	x = 1;
	c0 = std::clock();

	for (i = 0; i < NITER; i++) {
		x = PRODUCT(x, 1.0000000001);
	}
	c1 = std::clock();

	std::cout << "Process time is "
	          << (double) (c1 - c0) / CLOCKS_PER_SEC << " sec\n";
	std::cout << "Values of  x is " << x << "\n";


	{
		double k = 1;
		std::clock_t s0, s1;
		s0 = clock();
		for (int ii = 0; ii < NITER; ii++) {
			k = product(x, 1.0000000001);
		}
		s1 = clock();
		std::cout << "\n\nProcess normal function time is "
		          << (double) (s1 - s0) / CLOCKS_PER_SEC << " sec\n";
		std::cout << "Values of k  is " << k << "\n";
	}

	{
		//Precedence Errors ข้อผิดพลาดในการเรียงลำดับความสำคัญ
		std::cout << "SQUARE IS " << P * SQUARE(2.35) << '\n';
		std::cout << "PI(2.35)^2 is " << 3.5 * 2.35 * 2.35 << std::endl; /* OK */
		//std::cout << "SQUARE IS " << P * SQUARES(2.35 + 1) << '\n'; /* ERROR */

		std::cout << "SQUARE IS " << P * SQUARE(2.35 + 1) << '\n';
		//into
		std::cout << "PI(2.35)^2 is " << 3.5 * 2.35 + 1 * 2.35 + 1 << std::endl; /* OK */

		std::cout << "PI(2.35 + 1)^2 is " << 3.14 * 2.35 + 1 * 2.35 + 1 << std::endl;
		std::cout << "PI(2.35 + 1)^2 is " << 3.14 * 2.35 + 3.35 + 1 << std::endl;
		std::cout << "PI(2.35 + 1)^2 is " << 3.14 * 2.35 + 4.35 << std::endl;
		std::cout << "PI(2.35 + 1)^2 is " << 7.379 + 4.35 << std::endl;
		std::cout << "PI(2.35 + 1)^2 is " << 11.729 << std::endl;
	}
	/*
	__FILE__ = name the current source file expressed as a string literal
	__DATE__ = calendar date of the pre-processing expressed as string literal (MM / DD / YYYY)
	__TIME = time of the pre-processing expressed as string literal ( HH:MM:SS)
	 */
	{
		std::cout << "We are current in the file name : [" << __FILE__ << "]\n";
		/* We are current in the file name :
		 * [/Users/nonaom7775/Documents/OOP345W1P2_OOP345/SDDS/multiInheritance/pre-processor.cpp]*/

		std::cout << "The time we are pre-processing : [" << __TIME__ << "]\n";

		/*The time we are pre-processing : [22:28:52]*/

		std::cout << "The date we are compling this applica : [" << __DATE__ << "]\n";

		/*The date we are compling this applica : [Nov 30 2022]*/
	}
	{
		//#include <> search system directory first
		//#include "" search current directory first
		//* or we can define first */
#define MAINSS "testPredirective.h"

#include MAINSS
	}

	{
		/*Logical Directives #*/
#define CASE_A 1
#define CASE_B 2
#define CASE_C 3
#define CASE CASE_B

#if   CASE == CASE_A
#include "case_a.h"
#elif CASE == CASE_B

#include "case_b.h"

#elif CASE == CASE_C
#include "case_c.h"
#endif
		/*#include "case_b.h"*/
	}

	{
		//Unique Pointer
		auto uq = std::make_unique<double>(69.2);
		auto testMove = std::make_shared<double>(202.2);
		/*uq = std::move(testMove);*/

		std::unique_ptr<double> foo;
		std::unique_ptr<double> bar;
		/// check prototype has to be match as unique pointer to use get().
		double *p = nullptr;
		foo = std::make_unique<double>(2020.2);
		bar = std::move(foo); // can move unique  pointer;

		// raw pointer
		p = bar.get();
		*p = 20;
		p = nullptr;
		// the different betweent std::unique_ptr and make_unique is how to initialize
		/*
		 * std;:unique_ptr<prototype>(new allocate (value));
		 * std::unique_ptr<double>(new double(20230.2));
		 *
		 * std::make_unique<prototype>(value);
		 * std::make_unique<double>(2020.2);
		 * */
		foo = std::unique_ptr<double>(new double(20230.2));
		p = foo.release();
		*p = 40;

		std::cout << "foo: ";
		if (foo) {
			std::cout << *foo << '\n';
		} else {
			std::cout << "(foo = nullptr (novalue)\n";
		}

		std::cout << "bar: ";
		if (bar) {
			std::cout << *bar << '\n';
		} else {
			std::cout << "(boo = nullptr ( no value) \n";
		}
		std::cout << "p: ";
		std::cout << *p << '\n';

		delete p;
	}
	return 0;
}

// 4724 0906 5117 6305
// 04/27
// 482

//thread is block of code executed