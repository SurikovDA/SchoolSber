#include <stdio.h>
#include <stdlib.h>

int input(int **a, int *size);
void output(int *a, int size);
void bubbleSort(int *a, int size);

int main() {
    int is_error = 0, n;
    int *data = NULL;
    is_error = input(&data, &n);
    if (is_error == 0) {
        bubbleSort(data, n);
        output(data, n);
    } else {
        printf("n/a");
    }
    free(data);
    return 0;
}

void bubbleSort(int *a, int size) {
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

int input(int **a, int *size) {
    if ((scanf("%d", size) != 1) || (*size <= 0)) {
        return 1;
    } else {
        *a = (int *)calloc(*size, sizeof(int));
        if (NULL == a) {
            printf("n/a");
            return 1;
        }
        char c;
        for (int *p = *a; p - *a < *size; p++) {
            if ((scanf("%d%c", p, &c) != 2) || (c != ' ' && c != '\n')) {
                return 1;
            }
        }
    }
    return 0;
}

void output(int *a, int size) {
    for (int *p = a; p - a < size; p++) {
        printf("%d", *p);
        if (p - a != size - 1) {
            printf(" ");
        }
    }
}
