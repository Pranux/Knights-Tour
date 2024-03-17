#ifndef KNIGHTSTOUR_H
#define KNIGHTSTOUR_H

typedef struct Location Location;

struct Location {
    int x, y;
    int isValid; //1 - I can go, 0 - IDK, -1 - Can not go
    int validMoves; //Number of valid moves
    int score; //Number of valid moves
    Location *validOptions; //Squares that we can go to
};

void initBoard(Location ***board, int N);

void findValidSquares(Location **board, Location square, int N);

void move(Location **board, Location *square);

void finalMove(Location **board, Location *square);

int finished(Location **board, int N);

void freeBoard(Location ***board, int N);

#endif
