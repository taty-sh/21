#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID 100000

void initialize_doors(struct door* doors);
void sorting(struct door* doors);
void output(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sorting(doors);
    output(doors);

    return 0;
}

void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % MAX_ID;
        doors[i].status = rand() % 2;
    }
}

void sorting(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        for (int j = 0; j < DOORS_COUNT -i - 1; j++) {
            if (doors[i].id > doors[i+1].id) {
                int a = doors[i].id;
                doors[i].id = doors[i+1].id;
                doors[i+1].id = a;
            }
        }
    }
}

void output(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
    doors[i].status = 0;
    printf("%d %d\n", doors[i].id , doors[i].status);
    }
}
