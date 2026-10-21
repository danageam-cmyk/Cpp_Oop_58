
#pragma once
#include <string>
#include <iosfwd>

class vector2_t {
private:
    double x;
    double y;
    char* name;

public:
    double get_x();
    double get_y();
    char* get_name();

    void set_x(double);
    void set_y(double);
    void set_name(const char*);

    std::string to_string();

    vector2_t();
    vector2_t(double);
    vector2_t(double, double);
    vector2_t(double, double, const char*);
    vector2_t(const vector2_t&);
    vector2_t(vector2_t&&);

    ~vector2_t();

    vector2_t operator+(const vector2_t&);
    vector2_t operator-(const vector2_t&);

    vector2_t operator*(double);
    vector2_t operator/(double);

    vector2_t& operator+=(const vector2_t&);
    vector2_t& operator-=(const vector2_t&);

    vector2_t& operator=(const vector2_t&);
    vector2_t& operator=(vector2_t&&);

    friend std::ostream& operator<<(std::ostream&, const vector2_t&);
};
