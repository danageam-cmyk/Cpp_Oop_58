#pragma once
#include <string>

class vector2_t {
private:
    double x;
    double y;

public:
    // Аксесори (геттери та сеттери)
    double get_x();
    double get_y();

    void set_x(double);
    void set_y(double);

    std::string to_string();

    // Конструктори
    vector2_t();
    vector2_t(double, double);
};