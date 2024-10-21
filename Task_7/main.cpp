#include <iostream>

int bp(int a, int x) {
    if (x == 0)
        return 1;
    if (x & 1)
        return bp(a, x - 1) * a;
    int t = bp(a, x >> 1);
    return t * t;
}

int res(int x) {
    int y = x, cnt = 0;
    while (y)
        cnt++, y /= 10;
    int res = 0;
    while (x)
        res += bp(x % 10, cnt), x /= 10;
    return res;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        if (res(i) == i)
            std::cout << i << "\n";
}
