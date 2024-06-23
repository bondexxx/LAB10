#include <iostream>
#include <cmath>

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

int main() {
    Points points = {1.0, 2.0, 3.0};
    Result result = calculate_segments(points);
    result.Print();

    return 0;
}
