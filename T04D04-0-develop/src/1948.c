#include <math.h>
#include <stdio.h>

int div(int a, int b) {
  int quotient = 0, remains = 0;
  for (int i = a - b; i >= 0; i -= b) {
    quotient++;
    remains = i;
  }
  if (remains == 0) {
    return quotient;
  }
}

// C program to check if a
// number is prime
int simple(int n) {
  int i, flag = 1;

  // Ask user for input
  // printf("Enter a number: \n");

  // Store input number in a variable
  // scanf("%d", &n);

  // Iterate from 2 to sqrt(n)
  for (i = 2; i <= sqrt(n); i++) {
    // If n is divisible by any number between
    // 2 and n/2, it is not prime
    if (n % i == 0) {
      flag = 1;
      break;
    }
  }

  if (n <= 1) flag = 0;

  if (flag == 1) {
    return 1;
  } else {
    return -1;
  }
}

int main() {
  int a = 4, divider;
  // scanf("%d", &a);
  for (int k = 1; k <= a; k = k + 1) {
    divider = div(a, k);
    int maxDivider;
    if (simple(divider) == 1) {
      maxDivider = divider;
      printf("%d", maxDivider);
    }
  }
  printf("%d", divider);
  return 0;
}
