
#include "vector2.h"
#include <format>
#include <cstring>

vector2_t::vector2_t() {
    x = 0.0;
    y = 0.0;
    name = nullptr;
}

vector2_t::vector2_t(double x, double y) {
    this->x = x;
    this->y = y;
    name = nullptr;
}

vector2_t::vector2_t(double x, double y, const char* name) {
    this->x = x;
    this->y = y;

    if (name != nullptr) {
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);
    }
    else {
        this->name = nullptr;
    }
}


vector2_t::vector2_t(const vector2_t& other) {
    x = other.x;
    y = other.y;

    if (other.name != nullptr) {
        name = new char[strlen(other.name) + 1];
        strcpy_s(name, strlen(other.name) + 1, other.name);
    }
    else {
        name = nullptr;
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
    char* new_name = nullptr;

    if (name != nullptr) {
        new_name = new char[strlen(name) + 1];
        strcpy_s(new_name, strlen(name) + 1, name);
    }

    delete[] this->name;
    this->name = new_name;
}

std::string vector2_t::to_string() {
    if (name != nullptr && name[0] != '\0') {
        return std::format("{}: ({}, {})", name, x, y);
    }

    return std::format("({}, {})", x, y);
}
