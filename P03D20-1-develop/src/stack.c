#include "stack.h"

struct node* init(struct token* data) {
    struct node* lst;
    lst = (struct node*)malloc(sizeof(struct node));
    data += 0;
    lst->data = *data;
    lst->next = NULL;
    return lst;
}

void push(struct node** head, struct token* data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->next = *head;
    if (data) {
        data += 0;
        temp->data = *data;
    }
    *head = temp;
}

struct node* pop(struct node** head) {
    struct node* out;
    if (*head == NULL) {
        out = NULL;
    } else {
        out = *head;
        *head = (*head)->next;
        out->next = NULL;
    }
    return out;
}

struct node* peek(struct node** head) {
    struct node* out;
    if (*head == NULL) {
        out = NULL;
    } else {
        head += 0;
        out = *head;
    }
    return out;
}

void destroy(struct node* root) {
    struct node* temp;
    temp = root;
    while (temp != NULL) {
        root = temp->next;
        free(temp);
        temp = root;
    }
}

int stack_count(struct node* root) {
    int count = 0;
    struct node* temp = root;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}
