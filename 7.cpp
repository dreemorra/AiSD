#include <iostream>
#include <math.h>

int main() {
    int N, M, X1, Y1, X2, Y2 = 0;
    std::cin >> N >> M >> X1 >> Y1 >> X2 >> Y2;
    if(abs(Y1 - Y2) == abs(X1 - X2))
        std::cout << "NO";
    else std::cout << "YES";
}