#include <iostream>
#include <complex>

int main() {
    // Define two complex numbers
    std::complex<double> num1(2.0, 3.0); // 2 + 3i
    std::complex<double> num2(1.0, -1.0); // 1 - 1i

    // Perform some operations
    auto sum = num1 + num2; // Complex addition
    auto product = num1 * num2; // Complex multiplication
    auto magnitude = std::abs(num1); // Magnitude of num1

    // Output results
    std::cout << "Sum: " << sum << "\n";
    std::cout << "Product: " << product << "\n";
    std::cout << "Magnitude of num1: " << magnitude << "\n";

    return 0;
}
