#include <stdio.h>
#include "knightsTour.h"
#define N 8

int main(void) {
    Location **board;
    initBoard(&board, N);
    Location current = board[0][0];
    int iteration = 0;

    printf("Moving pattern:\n");

    while(!finished(board, N)) {
        ++iteration;
        findValidSquares(board, current, N);
        move(board, &current);

        if(iteration % 2 == 1)
            printf("(%d; %d)\n", current.y, current.x);
    }

    finalMove(board, &current);
    printf("(%d; %d)\n", current.y, current.x);

    freeBoard(&board, N);
    return 0;
}