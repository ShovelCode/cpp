//
//  main.cpp
//  HomeSliceAdvance
//
//  Created by Cr on 1/7/24.
//
#include <iostream>
#include <format>

int main() {
    int year = 2024;
    double pi = 3.14159;
    std::string name = "World";

    // Basic usage with different types
    std::string text = std::format("Hello, {}! The year is {} and pi is {:.2f}.", name, year, pi);
    std::cout << text << std::endl;

    // Formatting with alignment and width
    std::string alignedText = std::format("{:>10} {:>10} {:>10}", "Year", "Name", "Pi");
    std::cout << alignedText << std::endl;

    // You can also format directly to std::cout
    std::cout << std::format("Year: {}, Name: {}, Pi: {:.2f}", year, name, pi) << std::endl;

    return 0;
}
