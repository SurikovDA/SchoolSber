#include "rpn.h"

#include "stack.h"

int priority(char c) {
    int res = -1;
    if (c == '(' || c == ')') res = 2;
    if (c == '^') res = 10;
    if (c == '!') res = 9;
    if (c == 's' || c == 'c' || c == 't' || c == 'g' || c == 'q' || c == 'l') res = 8;
    if (c == '*' || c == '/') res = 7;
    if (c == '+' || c == '-') res = 6;
    return res;
}

struct node *polish_notation(struct token *data, int n) {
    struct token token_tmp = {-1, '0', 0};
    struct node *node_char = init(&token_tmp);
    struct node *node_double = init(&token_tmp);
    int check = 1;
    for (int i = 0; i < n; i++) {
        if (data[i].type == 0 || data[i].operation == 'x') {
            push(&node_double, &data[i]);
        } else {
            if (data[i].operation == '(') {
                push(&node_char, &data[i]);
            } else if (data[i].operation == ')') {
                check = push_all(&node_char, &node_double);
            } else if (priority(data[i].operation) == 8) {
                push(&node_char, &data[i]);
            } else if (priority(peek(&node_char)->data.operation) >= priority(data[i].operation)) {
                check = stack_on_double(&node_double, &node_char, data[i]);
            } else {
                push(&node_char, &data[i]);
            }
        }
        if (!check) {
            break;
        }
    }
    if (!check) {
        destroy(node_char);
        destroy(node_double);
        node_double = NULL;
    } else {
        clear_node_char_stack(&node_double, &node_char);
        destroy(node_char);
    }
    return node_double;
}

int push_all(struct node **node_char, struct node **node_double) {
    int check = 1;
    while ((*node_char != NULL) && peek(node_char)->data.operation != '(') {
        struct token temp_token = peek(node_char)->data;
        free(pop(node_char));
        push(node_double, &temp_token);
    }
    if (*node_char != NULL) {
        free(pop(node_char));
    } else {
        check = 0;
    }
    return check;
}

int stack_on_double(struct node **node_double, struct node **node_char, struct token data) {
    int check = 1;
    while ((*node_char == NULL) || (priority(peek(node_char)->data.operation) == 8 ||
                                    priority(peek(node_char)->data.operation) >= priority(data.operation))) {
        struct token temp_token = peek(node_char)->data;
        free(pop(node_char));
        push(node_double, &temp_token);
    }
    if (*node_char != NULL) {
        push(node_char, &data);
    } else {
        check = 0;
    }
    return check;
}

void clear_node_char_stack(struct node **node_double, struct node **node_char) {
    while (peek(node_char) != NULL) {
        struct token temp_token = peek(node_char)->data;
        free(pop(node_char));
        push(node_double, &temp_token);
    }
}

double exec_pfr(struct token *root, double x, int n) {
    double result;
    void (*func[12])(struct node **) = {sinus, cosinus, tangent, cotangent, base,  logarithm,
                                        add,   sub,     mult,    divis,     power, inverse};
    struct token garbage = {-1, '0', 0};
    struct node *execution = init(&garbage);
    for (int i = 0; i < n; i++) {
        if (root[i].type == 1) {
            int h = choose_res(root[i].operation);
            if (h != 13) {
                if ((h >= 7 && h <= 11 && stack_count(execution) < 3) ||
                    (h >= 1 && h <= 6 && stack_count(execution) < 2) ||
                    (h == 12 && stack_count(execution) < 2)) {
                    break;
                }
                func[h - 1](&execution);
            } else {
                replace(&execution, x);
            }
        } else if (root[i].type == 0) {
            push(&execution, &root[i]);
        }
    }
    result = peek(&execution)->data.operand;
    free(pop(&execution));
    destroy(execution);
    return result;
}

void inverse(struct node **execution) { peek(execution)->data.operand = -(peek(execution)->data.operand); }

void sinus(struct node **execution) { peek(execution)->data.operand = sin(peek(execution)->data.operand); }

void cosinus(struct node **execution) { peek(execution)->data.operand = cos(peek(execution)->data.operand); }

void tangent(struct node **execution) { peek(execution)->data.operand = tan(peek(execution)->data.operand); }

void cotangent(struct node **execution) {
    peek(execution)->data.operand = 1.0 / tan(peek(execution)->data.operand);
}

void base(struct node **execution) { peek(execution)->data.operand = sqrt(peek(execution)->data.operand); }

void logarithm(struct node **execution) {
    peek(execution)->data.operand = log(peek(execution)->data.operand);
}

void add(struct node **execution) {
    double second_oper = peek(execution)->data.operand;
    free(pop(execution));
    double first_oper = peek(execution)->data.operand;
    free(pop(execution));
    struct token inner;
    inner.type = 0;
    inner.operand = first_oper + second_oper;
    push(execution, &inner);
}

void sub(struct node **execution) {
    double second_oper = peek(execution)->data.operand;
    free(pop(execution));
    double first_oper = peek(execution)->data.operand;
    free(pop(execution));
    struct token inner;
    inner.type = 0;
    inner.operand = first_oper - second_oper;
    push(execution, &inner);
}

void mult(struct node **execution) {
    double second_oper = peek(execution)->data.operand;
    free(pop(execution));
    double first_oper = peek(execution)->data.operand;
    free(pop(execution));
    struct token inner;
    inner.type = 0;
    inner.operand = first_oper * second_oper;
    push(execution, &inner);
}

void divis(struct node **execution) {
    double second_oper = peek(execution)->data.operand;
    free(pop(execution));
    double first_oper = peek(execution)->data.operand;
    free(pop(execution));
    struct token inner;
    inner.type = 0;
    inner.operand = first_oper / second_oper;
    push(execution, &inner);
}

void power(struct node **execution) {
    double second_oper = peek(execution)->data.operand;
    free(pop(execution));
    double first_oper = peek(execution)->data.operand;
    free(pop(execution));
    struct token inner;
    inner.type = 0;
    inner.operand = pow(first_oper, second_oper);
    push(execution, &inner);
}

void replace(struct node **execution, double x) {
    struct token inner;
    inner.type = 0;
    inner.operand = x;
    push(execution, &inner);
}

int choose_res(char c) {
    int res = 0;
    res += 1 * (c == 's') + 2 * (c == 'c') + 3 * (c == 't');
    res += 4 * (c == 'g') + 5 * (c == 'q') + 6 * (c == 'l');
    res += 7 * (c == '+') + 8 * (c == '-') + 9 * (c == '*');
    res += 10 * (c == '/') + 11 * (c == '^') + 12 * (c == '!');
    res += 13 * (c == 'x');
    return res;
}
