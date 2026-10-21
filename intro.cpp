#include "intro.h"
#include <iostream>
#include "fraction.h"

void intro() {
	// запуск демонстрації
	std::cout << "Intro to OOP" << std::endl;
	// створення об'єктів
	fraction_t frac1;   // статичне оголошення - об'єкт у стеку
	fraction_t* frac2 = new fraction_t;  // динамічне оголошення - об'єкт у "купі"
	std::cout                                // без ініціалізації бачимо випадкові числа 
		<< frac1.to_string() << std::endl    // до об'єктів звертаємось через "."
		<< frac2->to_string() << std::endl;  // до покажчиків - через "->"

	// за допомогою конструкторів з параметрами можна задавати початкові значення
	fraction_t frac3(10);
	fraction_t* frac4 = new fraction_t(1, 10);
	std::cout
		<< frac3.to_string() << std::endl
		<< frac4->to_string() << std::endl;

	fraction_t frac5(1, 2, new char[] {"Half"});  // params contructor
	fraction_t* frac6 = new fraction_t(frac5);     // copy constructor
	std::cout
		<< frac5.to_string() << std::endl
		<< frac6->to_string() << std::endl;

	fraction_t d = std::move(fraction_t::decil());  // move constructor
	std::cout << d.to_string() << std::endl;

	std::cout
		<< frac5.to_string() << " + " << d.to_string()
		<< " = " << (frac5 + d).to_string() << std::endl;

	std::cout << "-------------------------" << std::endl;
	fraction_t f;   // default constructor: (0/1)
	std::cout << f.to_string() << std::endl;
	f = d;          // copy assignment (operator =(&)): (1/10Decil)
	std::cout << f.to_string() << std::endl;

	std::cout << "-------------------------" << std::endl;
	f = f + frac5;  // Move assignment (operator =(&&)): результат додавання, що повертається
	// оператором +, підлягає руйнуванню f = (move) <--ret--(f + f5) 
	std::cout << f << std::endl;

	f = f * frac5;
	std::cout << f << std::endl;

	f = f / frac5;
	std::cout << f << std::endl;

	std::cout << -f << std::endl;

	f += 1;
	std::cout << "f += 1: " << f << std::endl;
	f += frac5;
	std::cout << f << std::endl;

	delete frac2;
	delete frac4;
	delete frac6;


	std::cout << "\n--- VECTOR OPERATORS ---" << std::endl;

	vector2_t v1(10, 20, "Vector A");
	vector2_t v2(3, 5, "Vector B");

	vector2_t v3 = v1 + v2;
	vector2_t v4 = v1 - v2;

	std::cout << "v1: " << v1.to_string() << std::endl;
	std::cout << "v2: " << v2.to_string() << std::endl;
	std::cout << "v1 + v2: " << v3.to_string() << std::endl;
	std::cout << "v1 - v2: " << v4.to_string() << std::endl;

	vector2_t v5(v1);
	std::cout << "Copy: " << v5.to_string() << std::endl;

	vector2_t v6(vector2_t(7, 8, "Temporary"));
	std::cout << "Move constructor: "
		<< v6.to_string() << std::endl;

	vector2_t v7;
	v7 = v1;
	std::cout << "Copy assignment: "
		<< v7.to_string() << std::endl;

	vector2_t v8;
	v8 = vector2_t(50, 60, "Moved");
	std::cout << "Move assignment: "
		<< v8.to_string() << std::endl;



	vector2_t v1(10, 20, "Vector A");
	vector2_t v2(3, 5, "Vector B");
	std::cout << "v1 + v2 = " << v1 + v2 << std::endl;
	std::cout << "v1 - v2 = " << v1 - v2 << std::endl;
	std::cout << "v1 * 2 = " << v1 * 2 << std::endl;
	std::cout << "v1 / 2 = " << v1 / 2 << std::endl;

	v1 += v2;
	std::cout << "v1 += v2: " << v1 << std::endl;

	v1 -= v2;
	std::cout << "v1 -= v2: " << v1 << std::endl;

	std::cout << "v2: " << v2 << std::endl;


}