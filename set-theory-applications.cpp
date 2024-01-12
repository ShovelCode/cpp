#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

int main() {
    std::vector<int> setA = {1, 2, 3, 4, 5};
    std::vector<int> setB = {4, 5, 6, 7, 8};
    std::vector<int> result;

    // Set Union
    result.clear();
    std::set_union(setA.begin(), setA.end(), setB.begin(), setB.end(), std::back_inserter(result));
    std::cout << "Union: ";
    for (int num : result) std::cout << num << " ";
    std::cout << std::endl;

    // Set Intersection
    result.clear();
    std::set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(), std::back_inserter(result));
    std::cout << "Intersection: ";
    for (int num : result) std::cout << num << " ";
    std::cout << std::endl;

    // Set Difference (A - B)
    result.clear();
    std::set_difference(setA.begin(), setA.end(), setB.begin(), setB.end(), std::back_inserter(result));
    std::cout << "Difference (A - B): ";
    for (int num : result) std::cout << num << " ";
    std::cout << std::endl;

    // Set Symmetric Difference
    result.clear();
    std::set_symmetric_difference(setA.begin(), setA.end(), setB.begin(), setB.end(), std::back_inserter(result));
    std::cout << "Symmetric Difference: ";
    for (int num : result) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
