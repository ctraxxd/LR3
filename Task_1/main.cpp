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
    std::cout << "Программа, вычисляющая N = (a_i - b_i)^2 для всех i от 1 до 30, с помощью цикла while\n";
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
        int i = 1, N = 0;
        while (i <= 30) {
            int a, b;
            if (i & 1)
                a = i, b = i * i;
            else a = i / 2, b = i * i * i;
            N += (a - b) * (a - b);
            i++;
        }
        std::cout << "N = " << N << "\n\n";
    }
    return 0;
}