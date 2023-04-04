/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int length, int number, int *numbers);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int numbers[NMAX], buffer[NMAX], length, number;
    if (input(buffer, &length)) {
        printf("n/a");
        return 1;
    }
    number = sum_numbers(buffer, length);
    int j = find_numbers(buffer, length, number, numbers);
    output(j, number, numbers);

    return 0;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int *p = buffer; p - buffer < length; p++) {
        if (*p != 0) {
            if (*p % 2 == 0) {
                sum = sum + *p;
            }
        }
    }
    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0) {
            if (number % buffer[i] == 0) {
                numbers[j] = buffer[i];
                j++;
            }
        }
    }
    return j;
}

int input(int *buffer, int *length) {
    if ((scanf("%d", length) != 1) || (*length <= 0) || (*length > NMAX)) {
        return 1;
    } else {
        char c;
        for (int *p = buffer; p - buffer < *length; p++) {
            if ((scanf("%d%c", p, &c) != 1) && (c != ' ' && c != '\n')) {
                return 1;
            }
        }
    }
    return 0;
}

void output(int length, int number, int *numbers) {
    printf("%d\n", number);
    for (int *p = numbers; p - numbers < length; p++) {
        printf("%d", *p);
        if (p - numbers != length - 1) {
            printf(" ");
        }
    }
}