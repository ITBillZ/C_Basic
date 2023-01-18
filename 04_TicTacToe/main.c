#include <stdio.h>
#include "game.h"

void print_menu() {
    printf("*******************************************\n");
    printf("********* 1.Play       0.Exit *************\n");
    printf("*******************************************\n");
}

void run() {
    int input = 0;
    do {
        print_menu();
        printf("Please switch: ");
        scanf("%d", &input);

        switch (input) {
            case 1:
                printf("Start game.\n");
                play();
                break;
            case 0:
                printf("Exit game.\n");
                break;
            default:
                printf("Error input. Try again.\n");
                break;
        }

    } while (input);
}

int main() {
    run();
    return 0;
}
