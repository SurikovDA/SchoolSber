#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void output(struct door* doors, int n);

void sort(struct door* a, int size);

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort(doors, DOORS_COUNT);
    output(doors, DOORS_COUNT);

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort(struct door* a, int size) {
    for (int i = 0; i < size; i++) {
        a[i].status = 0;
        for (int j = 0; j < size; j++) {
            if (a[j].id > a[j + 1].id) {
                struct door tmp;
                tmp.id = a[j].id;
                a[j].id = a[j + 1].id;
                a[j + 1].id = tmp.id;
            }
        }
    }
}

void output(struct door* doors, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", doors[i].id);
        printf(", ");
        printf("%d", doors[i].status);
        if (i < n - 1) {
            printf("\n");
        }
    }
}