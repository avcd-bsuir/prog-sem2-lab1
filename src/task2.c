// License: CC BY-NC-SA 4.0
/*
 * task2.c
 *
 * Serial manager.
 *
 * Written by AlexeyFilich
 * 19 feb 2021
 */

#define STORAGE_OPTIMAL

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <Interactions.h>
#include <storage/Storage.h>

typedef struct {
    int seasons;
    char release_date[10];
} ReleaseInfo;

typedef struct {
    int episodes;
    char * name;
    ReleaseInfo info;
} Serial;

// Add serial to array
void pushSerial(Array * array, int episodes, char * name, int seasons, char release_date[]) {
    Serial serial;
    serial.episodes = episodes;
    serial.name = name;
    serial.info.seasons = seasons;
    strcpy(serial.info.release_date, release_date);
    aArrayPush(array, &serial);
}

// Print fields
void printSerial(Serial serial) {
    printf("Serial information:\n");
    printf("  Name: %s\n", serial.name);
    printf("  Episodes: %d\n", serial.episodes);
    printf("  Seasons: %d\n", serial.info.seasons);
    printf("  Release date: %s\n\n", serial.info.release_date);
}

void findSerial(Array * array) {
    int option;
    aScanCheck("Episodes: ", "%d", &option);
    for (int i = 0; i < array->size; i++)
        if ((*(Serial *)aArrayGet(array, i)).episodes < option)
            printSerial(*(Serial *)aArrayGet(array, i));
}

void deleteSerial(Array * array) {
    char name[128];

    printf("Name of a serial to delete: ");
    fgets(name, 128, stdin);
    for (int i = 0; i < 128; i++) {
        if (name[i] == '\n') {
            name[i] = '\0';
            break;
        }
    }

    for (int i = 0; i < array->size; i++) {
        if (!strcmp((*(Serial *)aArrayGet(array, i)).name, name)) {
            aArrayRemove(array, i);
            i--;
            printf("A serial was deleted\n");
        }
    }

    printf("\n");
}

int main(int argc, char* args[]) {
    // Init serials
    Array array;
    aArrayInit(&array, 0, Serial);
    pushSerial(&array, 51, "Breaking Bad", 5, "19.10.2002");
    pushSerial(&array, 31, "WinX Club", 2, "12.03.2004");
    pushSerial(&array, 12, "The Walking Dead", 1, "15.03.2015");

    // Menu
    while (true) {
        printf("-- Serial manager\n");
        printf("  1. Print data of all serials\n");
        printf("  2. Find all serials with episodes less than given\n");
        printf("  3. Delete serial with specific name\n");
        printf("  4. Exit\n");

        int option;
        do {
            aScanCheck("> ", "%d", &option);
        } while (option < 1 || option > 4);
        printf("\n");

        switch (option) {
            case 1:
                for (int i = 0; i < array.size; i++)
                    printSerial(*(Serial *)aArrayGet(&array, i));
                break;
            case 2:
                findSerial(&array);
                break;
            case 3:
                deleteSerial(&array);
                break;
            case 4:
                aArrayDestroy(&array);
                printf("Goodbye...\n");
                exit(0);
                break;
        }
    }

    return 0;
}
