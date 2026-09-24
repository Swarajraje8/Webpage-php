#include <iostream>
#include <limits>

int main() {
    unsigned int n;

    std::cout << "Enter a non-negative integer: ";
    if (!(std::cin >> n)) {
        std::cerr << "Invalid input. Please enter a valid non-negative integer.\n";
        return 1;
    }

    unsigned long long factorial = 1;
    for (unsigned int i = 2; i <= n; ++i) {
        factorial *= i;
    }

    std::cout << "Factorial of " << n << " is " << factorial << "\n";
    return 0;
}
