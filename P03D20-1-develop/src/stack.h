#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include <stdio.h>
#include <stdlib.h>

#include "lex_analyzer.h"

struct node {
    struct token data;
    struct node* next;
};

struct node* peek(struct node** head);
struct node* init(struct token* data);
void push(struct node** head, struct token* data);
struct node* pop(struct node** head);
void destroy(struct node* root);
int stack_count(struct node* root);

#endif  // SRC_STACK_H_
