#include <stdio.h>
#include <locale.h>
int minimum(int a, int b) { // функция для поиска минимального из двух чисел
	if (a < b) {
		return a;
	}
	else {
		return b;
	}

}
int rec(int i, int n, int Masha, int Petr, long *massiv) { // функция с рекурсией
    if (i == n) { // выход из рекурсии
        if (Masha < Petr)
            return Petr - Masha;
        else
            return Masha - Petr;

    }
    return minimum(rec(i + 1, n, Masha + massiv[i], Petr, massiv), rec(i + 1, n, Masha, Petr + massiv[i], massiv)); //следующий шаг рекурсии
}
int main() {
    setlocale(LC_ALL, "Rus");// подключение русского языка
    int i, m, n; // задаем переменные (вспомогательная, шрамовки чашек, количество чашек)

    printf("Введите число чашек: ");
    scanf_s("%i", &n);
    printf("Введите грамовки чашек: \n");
    long *massiv = new long[n];

    for (i = 0; i < n; i++) { // заполняем массив
        scanf_s("%i", &m);
        massiv[i] = m;
    }

    int x;
    x = rec(0, n, 0, 0, massiv);
    printf("Минимальная разница между порциями: %i", x);

}