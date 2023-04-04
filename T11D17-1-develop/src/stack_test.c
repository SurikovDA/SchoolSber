#include "stack.h"

#include <stdio.h>

void test();

int main() { test(); }

void test() {
    struct elem* head = init(33);
    printf("INITIALIZING WITH VALUE 33\n");
    printf("head->val = %d\n", head->val);
    if (head->val == 33)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    push(&head, -333);
    printf("PUSHING VALUE -333\n");
    printf("head->val = %d\n", head->val);
    if (head->val == -333)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    printf("POP MUST RETURN -333\n");

    int res = pop(&head);
    printf("pop = %d\n", res);
    if (res == -333)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");

    printf("NOW HEAD MUST BE VALUE 33\n");
    printf("head->val = %d\n", head->val);
    if (head->val == 33)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    destroy(&head);
}
