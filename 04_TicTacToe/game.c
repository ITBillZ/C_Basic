#include "game.h"
#include <stdio.h>

void init_board(char board[ROW][COL], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            board[i][j] = ' ';
        }
    }
}

void display_board(char board[ROW][COL], int row, int col) {
    for (int i = 0; i < row - 1; i++) {
        for (int j = 0; j < col - 1; j++) {
            printf(" %c |", board[i][j]);
        }
        printf(" %c\n", board[i][col - 1]);

        for (int j = 0; j < col - 1; j++) {
            printf("---|");
        }
        printf("---\n");
    }
    for (int j = 0; j < col - 1; j++) {
        printf(" %c |", board[row - 1][j]);
    }
    printf(" %c\n", board[row - 1][col - 1]);
}

int place(char board[ROW][COL], int x, int y, int player) {
    if (x >= 0 && x < ROW && y >= 0 && y < COL && board[x][y] == ' ') {
        // blank, can place
        board[x][y] = (player == 1 ? 'X' : 'O');
        return 1;
    } else {
        printf("Row%d col%d is not blank. Try again. \n", x + 1, y + 1);
        return 0;
    }
}

int is_win(char board[ROW][COL], int player) {
    char c = player == 1 ? 'X' : 'O';
    // judge each row
    int flag;
    for (int i = 0; i < ROW; i++) {
        flag = 1;
        for (int j = 0; j < COL; j++) {
            if (board[i][j] != c) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            return 1;  // player wins
        }
    }

    // judge each col
    for (int i = 0; i < COL; i++) {
        flag = 1;
        for (int j = 0; j < ROW; j++) {
            if (board[j][i] != c) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            return 1;  // player wins
        }
    }

    // judge diagonal
    flag = 1;
    for (int i = 0; i < COL; i++) {
        if (board[i][i] != c) {
            flag = 0;
            break;
        }
    }
    if (flag) {
        return 1;  // player wins
    }

    flag = 1;
    for (int i = 0; i < COL; i++) {
        if (board[i][COL - i - 1] != c) {
            flag = 0;
            break;
        }
    }
    if (flag) {
        return 1;  // player wins
    }

    return 0;  // player does not win
}

int is_over(char board[ROW][COL], int cnt) {
    if (is_win(board, 1)) {
        printf("Player 1 wins!\n");
        return 1;
    } else if (is_win(board, 2)) {
        printf("Player 2 wins!\n");
        return 1;
    } else if (cnt == ROW * COL) {
        printf("Draw!\n");
        return 1;
    }

    return 0;  // go on
}

void play() {
    char board[ROW][COL] = {0};
    init_board(board, ROW, COL);

    int x, y;
    int player = 1;  // player 1 and player 2
    int cnt = 0;     // count and help to judge whether the board is full

    while (1) {
        printf("\n");
        display_board(board, ROW, COL);

        if (cnt >= 5 && is_over(board, cnt)) {
            break;
        }

        printf("Player %d(%c) choose placing position(row col): ", player,
               player == 1 ? 'X' : 'O');
        scanf("%d %d", &x, &y);
        if (place(board, x - 1, y - 1, player)) {
            // place successfully
            player = (player == 1 ? 2 : 1);
            cnt++;
        }
    }
}
