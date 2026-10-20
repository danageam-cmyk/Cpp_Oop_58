
#include "vector2.h"
#include <format>
#include <iostream>
#include <cstring>

vector2_t::vector2_t() {
    x = 0;
    y = 0;
    name = NULL;
}

vector2_t::vector2_t(double x) {
    this->x = x;
    y = 0;
    name = NULL;
}

vector2_t::vector2_t(double x, double y)
    : x{ x }, y{ y } {
    name = NULL;
}

vector2_t::vector2_t(double x, double y, const char* name)
    : x{ x }, y{ y } {

    if (name != NULL) {
        size_t len = strlen(name);
        this->name = new char[len + 1];
        strcpy_s(this->name, len + 1, name);
    }
    else {
        this->name = NULL;
    }
}

vector2_t::vector2_t(const vector2_t& other) {
    x = other.x;
    y = other.y;

    if (other.name != NULL) {
        size_t len = strlen(other.name);
        name = new char[len + 1];
        strcpy_s(name, len + 1, other.name);
    }
    else {
        name = NULL;
    }

    std::cout << "Copy constructor" << std::endl;
}

vector2_t::vector2_t(vector2_t&& other) {
    x = other.x;
    y = other.y;
    name = other.name;

    other.x = 0;
    other.y = 0;
    other.name = NULL;

    std::cout << "Move constructor" << std::endl;
}

vector2_t::~vector2_t() {
    delete[] name;
}
double vector2_t::get_x() {
    return x;
}

double vector2_t::get_y() {
    return y;
}

char* vector2_t::get_name() {
    return name;
}
void vector2_t::set_x(double x) {
    this->x = x;
}

void vector2_t::set_y(double y) {
    this->y = y;
}

void vector2_t::set_name(const char* name) {
    char* new_name = NULL;

    if (name != NULL) {
        size_t len = strlen(name);
        new_name = new char[len + 1];
        strcpy_s(new_name, len + 1, name);
    }

    delete[] this->name;
    this->name = new_name;
}

std::string vector2_t::to_string() {
    if (name != NULL && name[0] != '\0') {
        return std::format("{}: ({}, {})", name, x, y);
    }

    return std::format("({}, {})", x, y);
}


vector2_t vector2_t::operator+(const vector2_t& other) {
    return vector2_t(x + other.x, y + other.y);
}

vector2_t vector2_t::operator-(const vector2_t& other) {
    return vector2_t(x - other.x, y - other.y);
}


vector2_t& vector2_t::operator=(const vector2_t& other) {
    if (this != &other) {
        char* new_name = NULL;

        if (other.name != NULL) {
            size_t len = strlen(other.name);
            new_name = new char[len + 1];
            strcpy_s(new_name, len + 1, other.name);
        }

        delete[] name;

        x = other.x;
        y = other.y;
        name = new_name;
    }

    std::cout << "Copy assignment operator" << std::endl;
    return *this;
}

vector2_t& vector2_t::operator=(vector2_t&& other) {
    if (this != &other) {
        delete[] name;

        x = other.x;
        y = other.y;
        name = other.name;

        other.x = 0;
        other.y = 0;
        other.name = NULL;
    }

    std::cout << "Move assignment operator" << std::endl;
    return *this;
}
