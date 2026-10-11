#pragma once
#include <string>
#include <format>


class fraction_t {

private:
	int numerator;
	int denominator;
public:
	int get_numerator();
	int get_denominator();

	void set_numerator();
	void set_denominator();

};

