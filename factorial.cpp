#include <iostream>
int main() {
    long long input;

    std::cout << "Enter a non-negative integer: ";
    if (!(std::cin >> input)) {
        std::cerr << "Invalid input. Please enter a valid non-negative integer.\n";
        return 1;
    }
    if (input < 0) {
        std::cerr << "Invalid input. Please enter a non-negative integer.\n";
        return 1;
    }
    const unsigned int n = static_cast<unsigned int>(input);
    if (n > 20) {
        std::cerr << "Input too large. This program supports values from 0 to 20.\n";
        return 1;
    }

    unsigned long long factorial = 1;
    for (unsigned int i = 2; i <= n; ++i) {
        factorial *= i;
    }

    std::cout << "Factorial of " << n << " is " << factorial << "\n";
    return 0;
}
