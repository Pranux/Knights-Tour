# Knight's Tour

This program finds knights moving pattern for any N*N chess board where N>4. It prints out every squares coordinate, where knight is at a current moment till it visits every square. Here are different functions that I used:

* [initBoard](#initBoard)
* [findValidSquares](#findValidSquares)
* [move](#move)
* [finalMove](#finalMove)
* [finished](#finished)
* [freeBoard](#freeBoard)

---

In them I am mainly using 3 varaibles:

 *  `board` - 2D Array of Location structs
 * `N` - size of a chess board
 * `square` - specific Location, where our knight is currently standing

---

Also, in my struct `Location` I declared some variables:

* `x` and `y` - coordinates of a square
* `isValid` - tels if square is valid or not
    * 1: We can go there
    * 0: We don't know if we can go there
    * -1: We can't go there
---

## initBoard

This function initialises a N*N chess board.

## findValidSquares

This function finds valid squares and adds them to valid options parameter in Location structs.


## move

This function moves our knight to a different location.

## finalMove

This function initializes final move

## finished

This function checks if we finished our knights tour

## freeBoard

This functions frees up used space