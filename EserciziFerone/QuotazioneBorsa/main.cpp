#include <iostream>

int search(float quot[], int begin, int end) {
    if(begin + 1 == end) {
        return begin;
    }
    int med = (begin + end) / 2;
    if(quot[begin] < quot[med]) {
        return search(quot, begin, end);
    } else {
        return search(quot, med, end);
    }
}

int main() {
    int n = 10;
    float quotazioni[n] = {1,2,3,4,4,6,7,8,9,10};
    std::cout << "Coppia di giorni: " << search(quotazioni, 0, n) << std::endl;
    return 0;
}