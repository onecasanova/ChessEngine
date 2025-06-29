#include <iostream>
#include <vector>

using namespace std;

int empty = 1;
int piece1 = 0;

typedef std::vector<std::vector<int>> grid; 

struct pieceLoc {
    int c1;
    int c2;
};

grid initialize() {
    grid board(3, std::vector<int>(3,empty));
    return board;
}

void printBoard(grid board) {
    for (int r = 2; r >= 0; r--) {
        cout << "| ";
        for (int c = 2; c >= 0; c--) {
            cout << board[r][c] << " ";
        }
        cout << "|" << endl;
    }
}

grid movePiece(grid board, pieceLoc start, pieceLoc end) {
    board[end.c1][end.c2] = board[start.c1][start.c2];
    board[start.c1][start.c2] = empty;
    return board;
}

grid changePiece(grid board, pieceLoc coord, int piece) {
    board[coord.c1][coord.c2] = piece;
    return board;
}

int main() {

    pieceLoc init_piece;
    init_piece.c1 = 0; //row from bottom
    init_piece.c2 = 1; //col from bottom
    grid board = initialize();
    cout << "initial board: " << endl;
    printBoard(board); //show initial board
    board = changePiece(board, init_piece, piece1); //initilaize piece 1
    cout << endl << "initial board with piece: " << endl;
    printBoard(board);

    pieceLoc move1;
    move1.c1 = 2; //row from bottom
    move1.c2 = 1; //col from bottom

    board = movePiece(board, init_piece, move1);
    //print out board
    cout << endl << "after: " << endl;
    printBoard(board);

    return 0;
}

