#ifndef KNIGHTSTOUR_H
#define KNIGHTSTOUR_H

typedef struct Location Location;

struct Location {
    int x, y; //Coordinates
    int isValid; //1 - We can go there, 0 - We don't know, -1 - We can't go there
    int validMoves; //Number of valid moves
    int score; //Number of valid moves for validOptions squares
    Location *validOptions; //Squares that we can go to
};

/**
 * This function initialises a N*N chess board
 * @param board 2D Array of Location structs
 * @param N size of a board
 */
void initBoard(Location ***board, int N);

/**
 * This function finds valid squares and adds them to valid options parameter in Location structs
 * @param board 2D Array of Location structs
 * @param square specific Location, where our knight is currently
 * @param N size of a board
 */
void findValidSquares(Location **board, Location square, int N);

/**
 * This function moves our knight to a different location
 * @param board 2D Array of Location structs
 * @param square specific Location, where our knight is currently
 */
void move(Location **board, Location *square);

/**
 * This function initializes final move
 * @param board 2D Array of Location structs
 * @param square specific Location, where our knight is currently
 */
void finalMove(Location **board, Location *square);

/**
 * This function checks if we finished our knights tour
 * @param board 2D Array of Location structs
 * @param N size of a board
 * @return 1 if finished, 0 if unfinished
 */
int finished(Location **board, int N);

/**
 * This functions frees up used space
 * @param board 2D Array of Location structs
 * @param N size of a board
 */
void freeBoard(Location ***board, int N);

#endif
