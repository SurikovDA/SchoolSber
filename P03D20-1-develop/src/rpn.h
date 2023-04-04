#ifndef SRC_RPN_H_
#define SRC_RPN_H_

#include <math.h>
#include <stdio.h>

#include "lex_analyzer.h"

struct node *polish_notation(struct token *data, int n);
int priority(char c);
int push_all(struct node **node_char, struct node **node_double);
void clear_node_char_stack(struct node **node_double, struct node **node_char);
int stack_on_double(struct node **node_double, struct node **node_char, struct token data);

double exec_pfr(struct token *root, double x, int n);
void inverse(struct node **execution);
void sinus(struct node **execution);
void cosinus(struct node **execution);
void tangent(struct node **execution);
void cotangent(struct node **execution);
void base(struct node **execution);
void logarithm(struct node **execution);
void add(struct node **execution);
void sub(struct node **execution);
void mult(struct node **execution);
void divis(struct node **execution);
void power(struct node **execution);
void replace(struct node **execution, double x);
int choose_res(char c);

#endif  // SRC_RPN_H_
