#include <stdlib.h>
#include "knightsTour.h"

void initBoard(Location ***board, int N) {
    *board = (Location **)malloc(N * sizeof(Location *));
    for(int i = 0; i < N; ++i) {
        (*board)[i] = (Location *)malloc(N * sizeof(Location));
        for(int j = 0; j < N; ++j) {
            (*board)[i][j].x = i;
            (*board)[i][j].y = j;
            (*board)[i][j].isValid = 1;
            (*board)[i][j].validOptions = (struct Location *) (Location *) malloc(8 * sizeof(Location));
        }
    }
    (*board)[0][0].isValid = 0;
}

void freeBoard(Location ***board, int N) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            free((*board)[i][j].validOptions);
        }
        free((*board)[i]);
    }
    free(*board);
}