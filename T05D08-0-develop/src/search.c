#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
int search(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 1) {
        printf("n/a");
        return 1;
    } else {
        printf("%d", search(data, n));
    }

    return 0;
}

int input(int *a, int *n) {
    if ((scanf("%d", n) != 1) || (*n <= 0) || (*n > NMAX)) {
        return 1;
    } else {
        char c;
        for (int *p = a; p - a < *n; p++) {
            if ((scanf("%d%c", p, &c) != 1) && (c != ' ' && c != '\n')) {
                return 1;
            }
        }
    }
    return 0;
}

double mean(int *a, int n) {
    double mean = 0;
    double probability = 1 / (double)n;
    for (int *p = a; p - a < n; p++) {
        mean += (double)*p * probability;
    }
    return mean;
}

double variance(int *a, int n) {
    double mean = 0, square_mean = 0, variance = 0;
    double probability = 1 / (double)n;
    for (int *p = a; p - a < n; p++) {
        mean += (double)*p * probability;
        square_mean += (double)(*p * *p) * probability;
    }
    variance = square_mean - mean * mean;
    return variance;
}

int search(int *a, int n) {
    double mean_v = mean(a, n);
    double variance_v = variance(a, n);
    for (int *p = a; p - a < n; p++) {
        if (*p >= mean_v && *p <= (mean_v + 3 * sqrt(variance_v)) && *p != 0 && *p % 2 == 0) {
            return *p;
        }
    }
    return 0;
}
