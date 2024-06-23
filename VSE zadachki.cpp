#include <iostream>
#include <iomanip>
#include <cmath>

// Завдання 1
struct TTime {
    int hours;
    int minutes;

    void NextMin() {
        if (hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60) {
            minutes++;
            if (minutes == 60) {
                minutes = 0;
                hours++;
                if (hours == 24) {
                    hours = 0;
                }
            }
        }
    }

    void Print() const {
        std::cout << std::setw(2) << std::setfill('0') << hours << ":"
                  << std::setw(2) << std::setfill('0') << minutes << std::endl;
    }
};

// Завдання 2
struct Points {
    double A;
    double B;
    double C;
};

struct Result {
    double AC;
    double BC;
    double sum_segments;

    void Print() const {
        std::cout << "AC: " << AC << ", BC: " << BC << ", Sum: " << sum_segments << std::endl;
    }
};

Result calculate_segments(const Points& points) {
    Result result;
    result.AC = std::abs(points.A - points.C);
    result.BC = std::abs(points.B - points.C);
    result.sum_segments = result.AC + result.BC;
    return result;
}

// Завдання 3
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
    // Завдання 1
    std::cout << "Завдання 1:" << std::endl;
    TTime times[5] = {{23, 59}, {12, 30}, {8, 45}, {0, 0}, {25, 61}};
    for (auto& time : times) {
        std::cout << "Original time: ";
        time.Print();
        time.NextMin();
        std::cout << "Next minute: ";
        time.Print();
    }

    // Завдання 2
    std::cout << "\nЗавдання 2:" << std::endl;
    Points points = {1.0, 2.0, 3.0};
    Result result = calculate_segments(points);
    result.Print();

    // Завдання 3
    std::cout << "\nЗавдання 3:" << std::endl;
    Integers numbers = {1, -2, 3};
    bool is_two_positive = numbers.check_two_positive();
    std::cout << std::boolalpha << is_two_positive << std::endl;

    return 0;
}
