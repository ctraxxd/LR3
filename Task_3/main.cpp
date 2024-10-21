#include <iostream>

const double Pi = 3.14159265358979323846;

double comp(double x) {
    double d = 2 * Pi;
    while (d <= x)
        d *= 2;
    while (d >= 2 * Pi) {
        while (x >= d)
            x -= d;
        d /= 2;
    }
    return x;
}

double Sin(double x) {
    x = comp(x);
    double res = x;
    double lst = x;
    for (double n = 1; n < 1000; n++) {
        lst = lst * (-1) * x * x / (2 * n) / (2 * n + 1);
        res += lst;
    }
    return res;
}

double Cos(double x) {
    x = comp(x);
    double res = 1;
    double lst = 1;
    for (double n = 1; n < 1000; n++) {
        lst = lst * (-1) * x * x / (2 * n) / (2 * n - 1);
        res += lst;
    }
    return res;
}

int readInt() {
    int input;
    if (!(std::cin >> input) || (std::cin.peek() != '\n')) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        return -2147483648;
    }
    return input;
}

int main() {
    setlocale(LC_ALL, "RU");
    std::cout << "Программа, вычисляющая значения y = sin(x) - cos(x) в точках\n";
    std::cout << "Выполнил Ефременко Валерий, группа 453502\n\n";
    while (true) {
        std::cout << "Введите 1, чтобы выполнить программу, или введите 2, чтобы закончить работу программы: ";
        int type = readInt();
        if (type != 1 && type != 2) {
            std::cout << "Неправильный формат ввода.\n\n";
            continue;
        }
        if (type == 2) {
            std::cout << "Выполнение программы завершено.\n";
            break;
        }
        double A = 0, B = Pi / 2, M = 20, H = (B - A) / M;
        for (int i = 0; i <= M; i++) {
            double x = A + i * H;
            double y = Sin(x) - Cos(x);
            std::cout << "y(" << x << ") = " << y << '\n';
        }
        std::cout << '\n';
    }
    return 0;
}
