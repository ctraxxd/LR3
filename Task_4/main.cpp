#include <iostream>
#include <cmath>

int readInt() {
    int input;
    if (!(std::cin >> input) || (std::cin.peek() != '\n')) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        return -2147483648;
    }
    return input;
}

double readDouble() {
    double input;
    if (!(std::cin >> input) || (std::cin.peek() != '\n')) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        return -2147483648;
    }
    return input;
}

int n;

double S(double x) {
    double res = 1;
    double lst = 1;
    for (double i = 0; i < n - 1; i++) {
        lst = lst * ((i + 1) * (i + 1) + 1) / (i * i + 1) / (i + 1) * x / 2.0;
        res += lst;
    }
    return res;
}

double Y(double x) {
    return (x * x / 4.0 + x / 2.0 + 1) * exp(x / 2.0);
}

int main() {
    setlocale(LC_ALL, "RU");
    std::cout << "Программа, вычисляющая функцию Y(x) при помощи разложения формулы в ряд S(x)\n";
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
        std::cout << "Введите количество членов ряда: ";
        n = readInt();
        while (n < 1) {
            std::cout << "Введите количество членов ряда заново: ";
            n = readInt();
        }
        std::cout << "Введите количество чисел, от которых надо посчитать функцию: ";
        int k = readInt();
        while (k < 1) {
            std::cout << "Введите количество чисел, от которых надо посчитать функцию заново: ";
            k = readInt();
        }
        int cnt = 0;
        while (k--) {
            cnt++;
            std::cout << "Введите число x_" << cnt << ", для которого вы хотите посчитать S(x_" << cnt << "): ";
            double x = readDouble();
            while (x > 1 || x < 0.1) {
                std::cout << "Заново введите число x_" << cnt << ", для которого вы хотите посчитать S(x_" << cnt << "): ";
                x = readDouble();
            }
            std::cout << "S(x_" << cnt << ") = " << S(x) << "\t" << "Y(x_" << cnt << ") = " << Y(x) << "\n\n";
        }
        std::cout << "\n";
    }
    return 0;
}
