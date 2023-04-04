#include <stdio.h>
#define size 10
int input(int *a);
void output(int *a);
void bubbleSort(int *a);

int main() {
    int is_error = 0;
    int data[10];
    is_error = input(data);
    if (is_error == 0) {
        bubbleSort(data);
        output(data);
    } else {
        printf("n/a");
    }
    return 0;
}

void bubbleSort(int *a) {
    for (int i = 0; i < size; i++) {
        for (int *p = a; p - a < size - 1; p++) {
            if (*p > *(p + 1)) {
                int tmp = *p;
                *p = *(p + 1);
                *(p + 1) = tmp;
            }
        }
    }
}

int input(int *a) {
    int is_error = 0;

    for (int *p = a; p - a < size; p++) {
        if (scanf("%d", p) != 1) {
            is_error = 1;
            return is_error;
        }
    }
    return is_error;
}

void output(int *a) {
    for (int *p = a; p - a < size; p++) {
        printf("%d", *p);
        if (p - a != size - 1) {
            printf(" ");
        }
    }
}