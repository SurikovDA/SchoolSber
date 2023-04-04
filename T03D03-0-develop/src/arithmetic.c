#include <stdio.h>

int main() {
    int a, b;
    char c;

    if (scanf("%d%d%c", &a, &b, &c) != 2 && (c != '\n')) {
        printf("n/a\n");
    } else {
        printf("%d %d %d ", a + b, a - b, a * b);
        if (b == 0) {
            printf("n/a\n");
        } else {
            printf("%d\n", a / b);
        }
    }
    return 0;
}
