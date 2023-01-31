#include <iostream>

int main(void)
{
    int val1, val2, val3;
    int result;

    std::cout << "1st & 2nd input: ";
    std::cin >> val1 >> val2;
    std::cout << "3rd input: ";
    std::cin >> val3;

    result = (val1 + val2) / val3;
    std::cout << "(A + B) / C = " << result << std::endl;

    return 0;
}
