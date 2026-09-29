#include <iostream>

class Number {
public:
    explicit Number(int value) : value_(value) {}

    Number operator-() const {
        return Number(-value_);
    }

    Number& operator++() {
        ++value_;
        return *this;
    }

    Number operator+(const Number& other) const {
        return Number(value_ + other.value_);
    }

    int value() const {
        return value_;
    }

private:
    int value_;
};

int main() {
    Number first(5);
    Number second(3);

    const Number negated = -first;
    const Number sum = first + second;
    ++first;

    std::cout << "Unary minus of 5: " << negated.value() << '\n';
    std::cout << "5 + 3: " << sum.value() << '\n';
    std::cout << "Prefix increment of 5: " << first.value() << '\n';
}
