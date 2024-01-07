//C++11+ standard
#include <iostream>
#include <random>

int main() {
    // Create a Mersenne Twister random number generator
    // It's usually a good idea to seed it with a value that changes, like time
    std::mt19937 generator(std::random_device{}());

    // Define a distribution, e.g., a uniform distribution between 1 and 10
    std::uniform_int_distribution<int> distribution(1, 10);

    // Generate and print 5 random numbers
    for (int i = 0; i < 5; ++i) {
        int random_number = distribution(generator);
        std::cout << "Random number " << i + 1 << ": " << random_number << std::endl;
    }

    return 0;
}
