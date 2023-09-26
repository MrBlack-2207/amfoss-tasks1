#include <iostream>
#include <cmath>

bool isPrime(int num) {
    if (num < 2) {
        return false;
    } else if (num == 2 || num == 3) {
        return true;
    } else if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }

    int i = 5;
    while (i * i <= num) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
        i += 6;
    }

    return true;
}

int getInput() {
    int k = 0;
    while (k < 2) {
        std::cout << "Type a number: ";
        std::cin >> k;
    }
    return k;
}

void printPrimes(int n) {
    if (n >= 2) {
        printPrimes(n - 1);
        if (isPrime(n)) {
            std::cout << n << std::endl;
        }
    }
}

int main() {
    int k = getInput();
    printPrimes(k);
    return 0;
}
