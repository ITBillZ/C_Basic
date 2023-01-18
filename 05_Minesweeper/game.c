#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_board(int board[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            board[i][j] = 0;
        }
    }

    srand((unsigned)time(NULL));
    int cnt = 0;

    while (cnt < MINE_NUM) {
        int x = rand() % ROW;
        int y = rand() % COL;
        if (board[x][y] != MINE) {
            board[x][y] = MINE;

            // add 1 to the adjacent block
            int adjs[8][2] = {{x - 1, y - 1}, {x - 1, y},    {x - 1, y + 1},
                              {x, y - 1},     {x, y + 1},    {x + 1, y - 1},
                              {x + 1, y},     {x + 1, y + 1}};
            for (int i = 0; i < 8; i++) {
                int _x = adjs[i][0], _y = adjs[i][1];
                if (_x >= 0 && _x < ROW && _y >= 0 && _y < COL &&
                    board[_x][_y] != MINE) {
                    // in the board and not a mine
                    board[_x][_y]++;
                }
            }

            cnt++;
        }
    }
}

void display_board(int board[ROW][COL], int state[ROW][COL]) {
    // print col num
    printf("    ");
    for (int i = 0; i < COL; i++) {
        printf(" %2d ", i + 1);
    }
    printf("\n    ");
    for (int i = 0; i < COL; i++) {
        printf("----");
    }
    printf("\n");

    for (int i = 0; i < ROW; i++) {
        printf("%2d |", i + 1);
        for (int j = 0; j < COL; j++) {
            if (state[i][j] == 0)
                printf("  - ");
            else if (state[i][j] == 1)
                printf("  M ");
            else if (state[i][j] == 2)
                printf(" %2d ", board[i][j]);
        }
        printf("\n");
    }
}

int mark_mine(int state[ROW][COL], int x, int y) {
    if (state[x][y] == 0) {
        // hidden, can be marked
        state[x][y] = 1;
        return 1;  // mark successfully
    } else if (state[x][y] == 1) {
        state[x][y] = 0;  // cancel mark
        return -1;
    } else {
        printf("Error position.\n");
        return 0;
    }
}

int stack[ROW * COL][2] = {0};
int top;

void dfs(int board[ROW][COL], int state[ROW][COL], int is_visit[ROW][COL]) {
    while (top != -1) {
        int x = stack[top][0], y = stack[top][1];
        top--;
        if (is_visit[x][y])
            continue;

        is_visit[x][y] = 1;
        state[x][y] = 2;

        int adjs[8][2] = {{x - 1, y - 1}, {x - 1, y},    {x - 1, y + 1},
                          {x, y - 1},     {x, y + 1},    {x + 1, y - 1},
                          {x + 1, y},     {x + 1, y + 1}};
        for (int i = 0; i < 8; i++) {
            int _x = adjs[i][0], _y = adjs[i][1];
            if (_x >= 0 && _x < ROW && _y >= 0 && _y < COL &&
                !is_visit[_x][_y]) {
                // expand 0

                if (board[_x][_y] != 0) {
                    // must not be a mine
                    state[_x][_y] = 2;
                } else {
                    top++;
                    stack[top][0] = _x;
                    stack[top][1] = _y;
                    dfs(board, state, is_visit);
                }
            }
        }
    }
}

int click(int board[ROW][COL], int state[ROW][COL], int x, int y) {
    if (state[x][y] != 2) {
        if (board[x][y] == MINE) {
            return 1;  // over
        } else if (board[x][y] == 0) {
            // dfs
            top = -1;
            top++;
            stack[top][0] = x;
            stack[top][1] = y;
            int is_visit[ROW][COL] = {0};
            dfs(board, state, is_visit);
            return 0;
        } else {
            state[x][y] = 2;
            return 0;
        }
    } else {
        printf("Error position.\n");
        return 0;
    }
}

int is_win(int board[ROW][COL], int state[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (board[i][j] != MINE && state[i][j] != 2) {
                // not a mine and not filp, not win
                return 0;
            }
        }
    }
    return -1;
}

void play() {
    int board[ROW][COL];
    init_board(board);

    /*
    0: hidden -
    1: mark mine M
    2: flip : show the board
    */
    int state[ROW][COL] = {0};
    int x, y;
    char type;
    int mark_cnt = 0;
    int is_over = 0;
    while (1) {
        display_board(board, state);

        if (is_win(board, state)) {
            printf("You win!\n");
            break;
        }
        if (is_over) {
            printf("Boom! You click the mine!\n");
            break;
        }

        printf("Switch mode(m-mark mine, c-click) and position: ");
        getchar();
        scanf("%c %d %d", &type, &x, &y);
        printf("\n");
        x--;
        y--;
        switch (type) {
            case 'm':
                mark_cnt += mark_mine(state, x, y);
                break;
            case 'c':
                is_over = click(board, state, x, y);
                break;
            default:
                printf("Error input.\n");
                break;
        }
    }
}