#include <iostream>
#include <iomanip>

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

int main() {
    TTime times[5] = { {23, 59}, {12, 30}, {8, 45}, {0, 0}, {23, 1} };

    for (auto& time : times) {
        std::cout << "Original time: ";
        time.Print();
        time.NextMin();
        std::cout << "Next minute: ";
        time.Print();
    }

    return 0;
}
