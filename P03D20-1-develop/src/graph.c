#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lex_analyzer.h"
#include "rpn.h"
#include "stack.h"

#define WIDTH 80
#define HEIGHT 25

char *get_string(int *len);
void draw_field(struct token *final_array, int n);
void reverse_polish_notation();
int input(struct token **final_array, int *n);
int another_input(struct token **final_array, int *n, struct token **data_2, int *final_count);

int main() {
    reverse_polish_notation();
    return 0;
}

void reverse_polish_notation() {
    struct token *final_array;
    int n;
    if (input(&final_array, &n)) {
        draw_field(final_array, n);
        free(final_array);
    } else {
        printf("n/a");
    }
}

char *get_string(int *len) {
    *len = 0;
    int capacity = 1;
    char *s = (char *)malloc(sizeof(char));
    char c = getchar();
    while (c != '\n') {
        s[(*len)++] = c;
        if (*len >= capacity) {
            capacity *= 2;
            char *tmp = (char *)realloc(s, capacity * sizeof(char));
            s = tmp;
        }
        c = getchar();
    }
    s[*len] = '\0';
    return s;
}

int input(struct token **final_array, int *n) {
    int final_count = 0;
    int check = 1;
    int len;
    char *s = get_string(&len);
    if (strlen(s) == 0) {
        check = 0;
    }
    if (check) {
        char **data;
        struct token *data_2;
        get_lexems(s, &data, n);
        if (lex_converter(&data_2, data, *n)) {
            check = another_input(final_array, n, &data_2, &final_count);
            free(data_2);
        } else {
            check = 0;
        }
        for (int i = 0; i < *n; i++) {
            free(data[i]);
        }
        free(data);
    }
    free(s);
    *n = final_count;
    return check;
}

int another_input(struct token **final_array, int *n, struct token **data_2, int *final_count) {
    struct node *root = polish_notation(*data_2, *n);
    int check = 1;
    if (root != NULL) {
        struct token temp_token = (peek(&root))->data;
        struct node *root_2 = init(&temp_token);
        free(pop(&root));
        while (root) {
            (*final_count)++;
            temp_token = (peek(&root))->data;
            push(&root_2, &temp_token);
            free(pop(&root));
        }
        (*final_count)--;

        *final_array = malloc(*final_count * sizeof(struct token));
        free(pop(&root_2));
        for (int i = 0; i < *final_count; i++) {
            (*final_array)[i] = (peek(&root_2))->data;
            free(pop(&root_2));
        }
        free(pop(&root_2));
        destroy(root);
        destroy(root_2);
    } else {
        check = 0;
    }
    return check;
}

void draw_field(struct token *final_array, int n) {
    double shift_h = M_PI * 4.0 / (WIDTH - 1);
    double shift_v = 2.0 / (HEIGHT - 1);
    double y;
    double x;
    for (int j = 0; j < HEIGHT; j++) {
        double y_1 = shift_v * j - 1;
        double y_2 = shift_v * (j - 1) - 1;
        for (int i = 0; i < WIDTH; i++) {
            x = i * shift_h;
            y = exec_pfr(final_array, x, n);
            (y >= y_2 && y < y_1) ? printf("*") : printf(".");
        }
        printf("\n");
    }
}
