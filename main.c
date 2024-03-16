#include <stdio.h>
#include "knightsTour.h"
#define N 8

int main(void) {
    Location **board;
    initBoard(&board, N);

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            printf("(%d; %d), ", board[i][j].x, board[i][j].y);
        }
        printf("\n");
    }

    freeBoard(&board, N);
    return 0;
}