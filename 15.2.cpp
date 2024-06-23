#include <iostream>

struct Integers {
    int A;
    int B;
    int C;

    bool check_two_positive() const {
        int positive_count = 0;
        if (A > 0) positive_count++;
        if (B > 0) positive_count++;
        if (C > 0) positive_count++;
        return positive_count == 2;
    }
};

int main() {
    Integers numbers = {1, -2, 99};
    bool result = numbers.check_two_positive();
    std::cout << std::boolalpha << result << std::endl;

    return 0;
}
