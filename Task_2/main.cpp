#include <iostream>

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
    std::cout << "Программа, вычисляющая сумму ряда d_n = 1 / 2^n + 1 / 3^n для всех d_n >= eps, с помощью цикла do while\n";
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
        double eps = 1e-3, d = 0, sum = 0;
        double two = 1, three = 1;
        do {
            two /= 2.0;
            three /= 3.0;
            d = two + three;
            sum += d;
        } while (d >= eps);
        std::cout << "Сумма ряда равна " << sum << "\n\n";
    }
    return 0;
}