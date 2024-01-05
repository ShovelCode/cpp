//compile with g++ -std=c++20 myprogram.cpp -o myprogram

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

int main() {
    // Using auto for type deduction
    auto numbers = std::vector<int>{1, 2, 3, 4, 5};

    // Range-based for loop
    std::cout << "Numbers in the vector: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Smart pointer (unique_ptr)
    auto myUniquePtr = std::make_unique<std::vector<int>>(numbers);

    // Lambda expression
    std::cout << "Squared numbers: ";
    std::for_each(myUniquePtr->begin(), myUniquePtr->end(), [](int &n) {
        n = n * n;
        std::cout << n << " ";
    });
    std::cout << "\n";

    return 0;
}
