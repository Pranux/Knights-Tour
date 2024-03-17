#include <stdio.h>
#include "knightsTour.h"

void gettingN(int *N) {
    printf("Enter a size of a chess board: ");
    if(scanf("%d", N) != 1 || *N <= 4 || getchar() != '\n') {
        printf("N must be an integer, higher than a 4.");
        return;
    }
}

int main(void) {
    Location **board;
    int N = 0;
    int iteration = 0;

    gettingN(&N);
    if(N == 0) { return 0; }
    initBoard(&board, N);
    Location current = board[0][0];

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