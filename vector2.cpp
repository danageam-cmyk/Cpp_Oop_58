#include "vector2.h"
#include <format>

vector2_t::vector2_t() {
    x = 0.0;
    y = 0.0;
}

vector2_t::vector2_t(double x, double y)
    : x{ x }, y{ y } {
}

double vector2_t::get_x() {
    return x;
}

double vector2_t::get_y() {
    return y;
}

void vector2_t::set_x(double x) {
    this->x = x;
}

void vector2_t::set_y(double y) {
    this->y = y;
}

std::string vector2_t::to_string() {
    return std::format("({}, {})", x, y);
}