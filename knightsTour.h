#ifndef KNIGHTSTOUR_H
#define KNIGHTSTOUR_H

typedef struct {
    int x, y;
    int isValid;
    struct Location* validOptions;
} Location;

void initBoard(Location ***board, int N);

void freeBoard(Location ***board, int N);

#endif
