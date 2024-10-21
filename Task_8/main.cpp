#include <iostream>

long long readLong() {
    long long input;
    if (!(std::cin >> input) || (std::cin.peek() != '\n')) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        return -9223372036854775807;
    }
    return input;
}

int main() {
    setlocale(LC_ALL, "RU");
    std::cout << "Программа, вычисляющая a - 2a + 4a - 8a + ... + 2^(n - 1) * (-1)^(n - 1) * a\n";
    std::cout << "Выполнил Ефременко Валерий, группа 453502\n\n";
    while (true) {
        std::cout << "Введите 1, чтобы выполнить программу, или введите 2, чтобы закончить работу программы: ";
        int type = readLong();
        if (type != 1 && type != 2) {
            std::cout << "Неправильный формат ввода.\n\n";
            continue;
        }
        if (type == 2) {
            std::cout << "Выполнение программы завершено.\n";
            break;
        }
        std::cout << "Введите число n: ";
        long long n = readLong();
        while (n < 1) {
            std::cout << "Заново введите число n: ";
            n = readLong();
        }
        std::cout << "Введите число a: ";
        long long a = readLong();
        while (a < 1) {
            std::cout << "Заново введите число a: ";
            a = readLong();
        }
        long long res = 0;
        for (long long i = 0; i < n; i++) {
            res = res * -2 + a;
        }
        std::cout << "Ответ равен " << res << "\n\n";
    }
    return 0;
}
