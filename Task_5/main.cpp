#include <iostream>

double ln10;
const double E = 2.71828182845904509080;

double ABS(double x) {
    return x >= 0 ? x : -x;
}

double sinh(double x) {
    double res = x;
    double lst = x;
    for (double n = 1; n < 1000; n++) {
        lst = lst * x * x / (2 * n) / (2 * n + 1);
        res += lst;
    }
    return res;
}

double cosh(double x) {
    double res = 1;
    double lst = 1;
    for (double n = 1; n < 1000; n++) {
        lst = lst * x * x / (2 * n) / (2 * n - 1);
        res += lst;
    }
    return res;
}

double tanh(double x) {
    return sinh(x) / cosh(x);
}

double ln(double x) {
    int add = 0;
    while (x > 2)
        x /= E, add++;
    x--;
    double res = x;
    double lst = x;
    for (double n = 1; n <= 1000; n++) {
        lst = lst * (-x) * n / (n + 1);
        res += lst;
    }
    return res + add;
}

double lg(double x) {
    return ln(x) / ln10;
}

double f(double x) {
    return lg(cosh(x)) - tanh(x) + 0.5;
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
    ln10 = ln(10);
    setlocale(LC_ALL, "RU");
    std::cout << "Программа, примерно находящая корень уравнения f(x) = 0\n";
    std::cout << "Выполнил Ефременко Валерий, группа 453502, вариант 9\n\n";
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
        std::cout << "Введите на сколько частей необходимо разделить область поиска корня: ";
        int cnt = readInt();
        while (cnt < 1) {
            std::cout << "Заново введите на сколько частей необходимо разделить область поиска корня: ";
            cnt = readInt();
        }
        double L = 0, R = 2;
        double len = (R - L) / cnt;
        double mn = f(L), res = L;
        double i = L;
        while (i <= R) {
            double val = f(i);
            if (ABS(val) < ABS(mn))
                res = i, mn = val;
            i += len;
        }
        std::cout << "f(" << res << ") = " << mn << "\n\n";
    }
    return 0;
}