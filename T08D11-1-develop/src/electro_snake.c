#include <stdio.h>
#include <stdlib.h>
/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int *matrix, int n, int m, int **result_matrix);
void bubbleSort(int *a, int size);
int array(int **a, int *size);
void output(int *a, int size);
int *hard_array(int **single_array_matrix, int str, int col, int *buffer);

int main() {
  int **matrix;
  int number, str, col;
  int buffer[1000];
  if (scanf("%d%d", &str, &col) != 2 || (str <= 0) || (col <= 0)) {
    printf("n/a");
    return 1;
  }
  hard_array(matrix, str, col, buffer);
  //*matrix = malloc(str * col * sizeof(int));
  bubbleSort(buffer, str * col);
  sort_horizontal(buffer, str, col, matrix);
  /*for (int i = 0; i < str * col; i++) {
    printf("%d ", buffer[i]);
  }
  */

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

int array(int **a, int *size) {
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

int *hard_array(int **single_array_matrix, int str, int col, int *buffer) {
  const int M = str, N = col;
  single_array_matrix = malloc(M * N * sizeof(int) + M * sizeof(int *));
  int *ptr = (int *)(single_array_matrix + M);
  int count = 0;

  for (int i = 0; i < M; i++) {
    single_array_matrix[i] = ptr + N * i;
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (scanf("%d", &single_array_matrix[i][j]) != 1) {
        printf("n/a");
      }
      count++;
    }
  }

  buffer[str * col];
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      buffer[i * col + j] = single_array_matrix[i][j];
      if (j != col - 1) {
        printf(" ");
      }
    }
    if (i != str - 1) {
      printf("\n");
    }
  }

  // free(single_array_matrix);
  return buffer;
}

void sort_horizontal(int *matrix, int n, int m, int **result_matrix) {
  int flag = 1;
  if (flag == 1) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        printf("%d", matrix[j]);
        if (j % 2 == 1 && j != 0) {
          flag = 1;
        } else {
          flag = -1;
        }
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        printf("%d", matrix[j]);
        if (j % 2 == 1 && j != 0) {
          flag = 1;
        } else {
          flag = -1;
        }
      }
    }
  }
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix);