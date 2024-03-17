#include <stdlib.h>
#include "knightsTour.h"

void initBoard(Location ***board, int N) {
    *board = (Location **)malloc(N * sizeof(Location *));
    for(int i = 0; i < N; ++i) {
        (*board)[i] = (Location *)malloc(N * sizeof(Location));
        for(int j = 0; j < N; ++j) {
            (*board)[i][j].x = j;
            (*board)[i][j].y = i;
            (*board)[i][j].isValid = 0;
            (*board)[i][j].validMoves = 0;
            (*board)[i][j].score = 0;
            (*board)[i][j].validOptions = (Location*)malloc(8 * sizeof(Location));
            for(int k = 0; k < 8; ++k) {
                (*board)[i][j].validOptions[k].x = 0;
                (*board)[i][j].validOptions[k].y = 0;
                (*board)[i][j].validOptions[k].isValid = 0;
                (*board)[i][j].validOptions[k].validMoves = 0;
                (*board)[i][j].validOptions[k].score = 0;
            }
        }
    }
}

int findScore(Location **board, Location square, int N) {
    int score = 0;
    if(square.x >= 1 && square.y >= 2) {
        if(board[square.y-2][square.x-1].isValid != -1) {
            ++score;
        }
    }
    if(square.x <= N-2 && square.y >= 2) {
        if(board[square.y-2][square.x+1].isValid != -1) {
            ++score;
        }
    }
    if(square.x <= N-3 && square.y >= 1) {
        if(board[square.y-1][square.x+2].isValid != -1) {
            ++score;
        }
    }
    if(square.x <= N-3 && square.y <= N-2) {
        if(board[square.y+1][square.x+2].isValid != -1) {
            ++score;
        }
    }
    if(square.x <= N-2 && square.y <= N-3) {
        if(board[square.y+2][square.x+1].isValid != -1) {
            ++score;
        }
    }
    if(square.x >= 1 && square.y <= N-3) {
        if(board[square.y+2][square.x-1].isValid != -1) {
            ++score;
        }
    }
    if(square.x >= 2 && square.y <= N-2) {
        if(board[square.y+1][square.x-2].isValid != -1) {
            ++score;
        }
    }
    if(square.x >= 2 && square.y >= 1) {
        if(board[square.y-1][square.x-2].isValid != -1) {
            ++score;
        }
    }
    return score;
}

void findValidSquares(Location **board, Location square, int N) {

    board[square.y][square.x].isValid = -1;
    int options = 0;
    board[square.y][square.x].validMoves = 0;

    if(square.x >= 1 && square.y >= 2) {
        if(board[square.y-2][square.x-1].isValid != -1) {
            board[square.y-2][square.x-1].isValid = 1;
            board[square.y][square.x].validOptions[options] = board[square.y-2][square.x-1];
            board[square.y-2][square.x-1].score = findScore(board, board[square.y-2][square.x-1], N);
            ++(board[square.y][square.x].validMoves);
            ++options;
        }
    }
    if(square.x <= N-2 && square.y >= 2) {
        if(board[square.y-2][square.x+1].isValid != -1) {
            board[square.y-2][square.x+1].isValid = 1;
            board[square.y][square.x].validOptions[options] = board[square.y-2][square.x+1];
            board[square.y-2][square.x+1].score = findScore(board, board[square.y-2][square.x+1], N);
            ++(board[square.y][square.x].validMoves);
            ++options;
        }
    }
    if(square.x <= N-3 && square.y >= 1) {
        if(board[square.y-1][square.x+2].isValid != -1) {
            board[square.y-1][square.x+2].isValid = 1;
            board[square.y][square.x].validOptions[options] = board[square.y-1][square.x+2];
            board[square.y-1][square.x+2].score = findScore(board, board[square.y-1][square.x+2], N);
            ++(board[square.y][square.x].validMoves);
            ++options;
        }
    }
    if(square.x <= N-3 && square.y <= N-2) {
        if(board[square.y+1][square.x+2].isValid != -1) {
            board[square.y+1][square.x+2].isValid = 1;
            board[square.y][square.x].validOptions[options] = board[square.y+1][square.x+2];
            board[square.y+1][square.x+2].score = findScore(board, board[square.y+1][square.x+2], N);
            ++(board[square.y][square.x].validMoves);
            ++options;
        }
    }
    if(square.x <= N-2 && square.y <= N-3) {
        if(board[square.y+2][square.x+1].isValid != -1) {
            board[square.y+2][square.x+1].isValid = 1;
            board[square.y][square.x].validOptions[options] = board[square.y+2][square.x+1];
            board[square.y+2][square.x+1].score = findScore(board, board[square.y+2][square.x+1], N);
            ++(board[square.y][square.x].validMoves);
            ++options;
        }
    }
    if(square.x >= 1 && square.y <= N-3) {
        if(board[square.y+2][square.x-1].isValid != -1) {
            board[square.y+2][square.x-1].isValid = 1;
            board[square.y][square.x].validOptions[options] = board[square.y+2][square.x-1];
            board[square.y+2][square.x-1].score = findScore(board, board[square.y+2][square.x-1], N);
            ++(board[square.y][square.x].validMoves);
            ++options;
        }
    }
    if(square.x >= 2 && square.y <= N-2) {
        if(board[square.y+1][square.x-2].isValid != -1) {
            board[square.y+1][square.x-2].isValid = 1;
            board[square.y][square.x].validOptions[options] = board[square.y+1][square.x-2];
            board[square.y+1][square.x-2].score = findScore(board, board[square.y+1][square.x-2], N);
            ++(board[square.y][square.x].validMoves);
            ++options;
        }
    }
    if(square.x >= 2 && square.y >= 1) {
        if(board[square.y-1][square.x-2].isValid != -1) {
            board[square.y-1][square.x-2].isValid = 1;
            board[square.y][square.x].validOptions[options] = board[square.y-1][square.x-2];
            board[square.y-1][square.x-2].score = findScore(board, board[square.y-1][square.x-2], N);
            ++(board[square.y][square.x].validMoves);
            ++options;
        }
    }
}

int findMinScore(Location **board, Location square) {

    int minimum = 8;

    for(int i = 0; i < board[square.y][square.x].validMoves; ++i) {
        if(board[square.y][square.x].validOptions[i].score > 0) {
            if(board[square.y][square.x].validOptions[i].score < minimum) {
                minimum = board[square.y][square.x].validOptions[i].score;
            }
        }
    }

    return minimum;
}

void move(Location **board, Location *square) {

    int minScore, tempX, tempY;
    minScore = findMinScore(board, *square);

    for(int i = 0; i < board[square->y][square->x].validMoves; ++i) {
        if(board[square->y][square->x].validOptions[i].score == minScore) {
            for(int j = 0; j < board[square->y][square->x].validMoves; ++j) {
                if(j != i) {
                    tempX = board[square->y][square->x].validOptions[j].x;
                    tempY = board[square->y][square->x].validOptions[j].y;
                    board[tempY][tempX].score = 0;
                    board[tempY][tempX].isValid = 0;
                }
            };

            board[square->y][square->x].validMoves = 0;
            *square = board[square->y][square->x].validOptions[i];
            return;
        }
    }
}

void finalMove(Location **board, Location *square) {
    *square = board[square->y][square->x].validOptions[0];
}

int finished(Location **board, int N) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(!board[i][j].isValid)
                return 0;
        }
    }
    return 1;
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