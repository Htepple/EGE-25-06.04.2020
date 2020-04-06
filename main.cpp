#include <iostream>

#define N 2018

int main() {
    int a[N], i, mx, mn, cnt, x;

    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    mx = -99999, mn = 99999, cnt = 0, x = 0;

    //mx = макс. четные
    //mn = мин. нечентыне
    //cnt = кол-во четных
    // x = temporary data

    //получаем макс. из четных эл-тов и мин. из нечентных эл-тов
    for (int i = 0; i < N; i++) {
        x = a[i];

        while (x / 10 != 0) {
            x /= 10;
        }

        if (x % 2 == 0) {
            if (a[i] > mx) mx = a[i]; //выявление максимального четного
        } else {
            if (a[i] < mn) mn = a[i]; //выявление минимального нечетного
        }
    }

    //получаем количество четных
    for (int i = 0; i < N; i++) {
        x = a[i];

        while (x / 10 != 0) {
            x /= 10;
        }

        if (x % 2 == 0) {
            cnt++;
        }
    }

    if (cnt > N / 2) { //четных больше половины
        for (int i = 0; i < N; i++) {
            x = a[i];

            while (x / 10 != 0) {
                x /= 10;
            }

            if (x % 2 == 0) a[i] = mx;
        }
    } else { //нечетных больше половины
        for (int i = 0; i < N; i++) {
            x = a[i];

            while (x / 10 != 0) {
                x /= 10;
            }

            if (x % 2 != 0) a[i] = mn;
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << a[i] << " ";
    }

    return 0;
}
