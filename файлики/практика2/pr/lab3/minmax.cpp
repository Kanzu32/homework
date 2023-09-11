#include "minmax.h"

void findMinMax(const vector<double>& numbers, double& min, double& max) {
    if (numbers.size() > 0) {
        min = numbers[0];
        max = numbers[0];
    } else {
        return;
    }
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
        else if (numbers[i] > max) {
            max = numbers[i];
        }
    }
}