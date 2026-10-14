
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

        std::cout << "Copy constructor: copy from -> "
            << (void*)other.name << " to "
            << (void*)name << std::endl;
    }
    else {
        name = NULL;
    }
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
