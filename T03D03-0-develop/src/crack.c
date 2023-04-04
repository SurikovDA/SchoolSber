#include <stdio.h>

int main() {
    float x, y;
    if (scanf("%f%f", &x, &y) != 2) {
        printf("n/a\n");
    } else {
        float circle = x * x + y * y;
        if (circle <= 25) {
            printf("GOTCHA\n");
        } else {
            printf("MISS\n");
        }
    }
    return 0;
}
