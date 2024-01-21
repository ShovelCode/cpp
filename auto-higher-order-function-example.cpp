#include <iostream>
#include <functional>

auto twice = [](const std::function<int(int)>& f)
{
    return [f](int x) {
        return f(f(x));
    };
};

auto plus_three = [](int i)
{
    return i + 3;
};

int main()
{
    auto g = twice(plus_three);

    std::cout << g(7) << '\n'; // 13
}
