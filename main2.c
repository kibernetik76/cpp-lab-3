#include <stdio.h>
#include <stdlib.h> // malloc - динамическое выделение памяти
#include <locale.h>
int minimum(int a, int b) { // функция для поиска минимального из двух чисел
	if (a < b) {
		return a;
	}
	else {
		return b;
	}

}
int rec(int i, int n, int Masha, int Petr, int* massiv) { // функция с рекурсией
    if (i == n) { // выход из рекурсии
        if (Masha < Petr)
            return Petr - Masha;
        else
            return Masha - Petr;

    }
    int a = rec(i + 1, n, Masha + massiv[i], Petr, massiv);
    int b = rec(i + 1, n, Masha, Petr + massiv[i], massiv);
    return minimum(a, b); //следующий шаг рекурсии
}
int main() {
    setlocale(LC_ALL, "Rus");// подключение русского языка
    int i, m, n; // задаем переменные (вспомогательная, шрамовки чашек, количество чашек)

    printf("Введите число чашек: ");
    scanf("%i", &n);
    printf("Введите грамовки чашек: \n");
    int* massiv = (int*)malloc(n * sizeof(int));// sizeoff показывает сколько бйтов нужно для хранения, в данном случае, типа int

    for (i = 0; i < n; i++) { // заполняем массив
        scanf("%i", &m);
        massiv[i] = m;
    }

    int x;
    x = rec(0, n, 0, 0, massiv);
    printf("Минимальная разница между порциями: %i", x);

}