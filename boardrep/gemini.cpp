#include <iostream>
#include <vector>
#include <string>


using namespace std;

enum class Piece {
    EMPTY = 0, //empty square

    //white pieces
    W_PAWN = 1,
    W_KNIGHT = 2,
    W_BISHOP = 3,
    W_ROOK = 4,
    W_KING = 5,
    W_QUEEN = 6,

    //black pieces
    B_PAWN = 7,
    B_KNIGHT = 8,
    B_BISHOP = 9,
    B_ROOK = 10,
    B_KING = 11,
    B_QUEEN = 12

};


//VISUALIZE HE BOARD TO THE CONSOLE

char getPieceViz(Piece piece) {
    switch (piece) {
        case Piece::EMPTY:   return '.'; // Dot for empty squares
        case Piece::W_PAWN:  return 'P';
        case Piece::W_KNIGHT:return 'N';
        case Piece::W_BISHOP:return 'B';
        case Piece::W_ROOK:  return 'R';
        case Piece::W_QUEEN: return 'Q';
        case Piece::W_KING:  return 'K';
        case Piece::B_PAWN:  return 'p';
        case Piece::B_KNIGHT:return 'n';
        case Piece::B_BISHOP:return 'b';
        case Piece::B_ROOK:  return 'r';
        case Piece::B_QUEEN: return 'q';
        case Piece::B_KING:  return 'k';
        default:             return '?'; // Fallback for unexpected values (should not happen)
    }

}


//Board class

class Board {
     

    public:

        //define board at a 2D vector
        //board[row][col] will store the piece at that position
        // std::vector<std::vector<Piece>> board;

        // typedef std::vector<std::vector<Piece>> BOARD;
        std::vector<std::vector<Piece>> chessBoard; //define board, Global variable so member functions can modify it 

        struct Move{
            std::string start;
            std::string end;
        };

        Move lastMove;

        //board constructor. The stuff after the colon are initialized variables
        Board() : chessBoard(8,std::vector<Piece>(8, Piece::EMPTY)) {
            initializeBoard();
        }

        //initialize the board to starting positions
        void initializeBoard() {

            //make all squares empty
            for (int r = 0; r < 8; r++) {
                for (int c = 0; c < 8; c++) {
                    chessBoard[r][c] = Piece::EMPTY; //initializes the all 8 elements in 8 arrays to all zeros 
                }
            }

            //put in pawns
            for (int c = 0; c < 8; c++) {
                chessBoard[1][c] = Piece::W_PAWN; 
                chessBoard[6][c] = Piece::B_PAWN; 
            }


            //now manually place pieces for black and white
            chessBoard[0][0] = Piece::W_ROOK;
            chessBoard[0][1] = Piece::W_KNIGHT;
            chessBoard[0][2] = Piece::W_BISHOP;
            chessBoard[0][3] = Piece::W_QUEEN;
            chessBoard[0][4] = Piece::W_KING;
            chessBoard[0][5] = Piece::W_BISHOP;
            chessBoard[0][6] = Piece::W_KNIGHT;
            chessBoard[0][7] = Piece::W_ROOK;

            chessBoard[7][0] = Piece::B_ROOK;
            chessBoard[7][1] = Piece::B_KNIGHT;
            chessBoard[7][2] = Piece::B_BISHOP;
            chessBoard[7][3] = Piece::B_QUEEN;
            chessBoard[7][4] = Piece::B_KING;
            chessBoard[7][5] = Piece::B_BISHOP;
            chessBoard[7][6] = Piece::B_KNIGHT;
            chessBoard[7][7] = Piece::B_ROOK;



        }



        void printBoard() {
            cout << " -----------------" << endl;
            for (int r = 7; r >= 0; r--) { //top down
                cout << r + 1 << "|"; //row labels
                for (int c = 7; c >= 0; c--) {
                    cout << getPieceViz(chessBoard[r][c]) << " "; //this prints the associated piece letter based on its integer stored in the array
                }
                cout << "|" << endl;
            }
            cout << " -----------------" << endl; //row labels
        }

        // void newMove(std::vector<std::vector<Piece>> b) {
        //     board = b;
        // }

        // std::vector<std::vector<Piece>> movePiece(int startRow, int startCol, int endRow, int endCol) {
        //     //move piece from start to end
        //     board[endRow][endCol] = board[startRow][startCol];
        //     board[startRow][startCol] = Piece::EMPTY;

        //     return board;
        // }

        //just change the board
        void makeMove() {

            string start = lastMove.start;
            string end = lastMove.end;

            char start_letter = std::toupper(start[0]);
            char end_letter = std::toupper(end[0]);

            int sRow = start_letter - 'A';
            int eRow = end_letter - 'A';
            int sCol = start[1] - '0';
            int eCol = end[1] - '0';

            chessBoard[eRow][eCol] = chessBoard[sRow][sCol];
            chessBoard[sRow][sCol] = Piece::EMPTY;
        }

        // void movePiece(int startRow, int startCol, int endRow, int endCol) {
        //     //move piece from start to end
        //     board[endRow][endCol] = board[startRow][startCol];
        //     board[startRow][startCol] = Piece::EMPTY;

        // }

        bool validateMove(Move move) { 
            
            bool c1 = false;
            bool c2 = false;
            bool c3 = false;
            bool c4 = false;
            bool c5 = false;

            //check if move is 2 characters long
            if (move.start.length() ==2 & move.end.length() == 2) {
                c1 = true;
            }

            //character is within bounds
            if ((std::toupper(move.start[0]) - 'A' >= 0) & (std::toupper(move.start[0] - 'A') < 8)) {
                c2 = true;
            }

            if ((std::toupper(move.end[0] - 'A') >= 0) & (std::toupper(move.end[0] - 'A') < 8)) {
                c3 = true;
            }


            //check for number ranges
            if ((std::toupper(move.start[1] - '1') >= 0) & (std::toupper(move.start[1] - '1') < 8)) {
                c4 = true;
                
            }
            if ((std::toupper(move.end[1] - '1') >= 0) & (std::toupper(move.end[1] - '1') < 8)) {
                c5 = true;
                cout << "c5: " << c5 << endl;
            }


            //debugging
            cout << "c1: " << c1 << endl;
            cout << "c2: " << c2 << endl;
            cout << "c3: " << c3 << endl;
            cout << "c4: " << c4 << endl;
            cout << "c5: " << c5 << endl;

            int testc2 = std::toupper(move.start[0]) - 'A' >= 0;
            cout << endl << "c2: " << testc2 << endl;
            int testc3 = std::toupper(move.end[0]) - 'A';
            cout << "c3: " << testc3 << endl;

            if (c1 & c2 & c3 & c4 & c5) { //if all true
                return true;
            } else {
                return false;
            }

        }

        void showMove() {
            //just print the moves that are current.
            // cout << "Start: " << lastMove.start << endl;
            // cout << "End: " << lastMove.end << endl;
            cout << "Your move is " << lastMove.start << " to " << lastMove.end << "." << endl;
        }

        void promptMove() {
            //prompt user to move piece
            Move checking;
            string tryAgain;

            //check string length
            cout << "Type starting move: ";
            cin >> checking.start;
            cout << "Type ending move: ";
            cin >> checking.end;

            

            if (validateMove(checking)) {
                lastMove = checking;
                cout << "Move saved" << endl;
                // return lastMove;
            } else {
                cout << "Invalid moves.. try again? (y/n) ";
                cin >> tryAgain;
                if (tryAgain == "y") {
                    promptMove();
                }
                
            }
            
        }

        Move getMoves() const {
            return lastMove;
        }


};




int main() {
    Board chessBoard;
    chessBoard.printBoard();

    // Example move: Move a white pawn from e2 to e4

    // chessBoard.movePiece(6, 4, 4, 4); // Move from (6, 4) to (4, 4)
    // cout << "After moving the white pawn from e2 to e4:" << endl;
    // chessBoard.printBoard();

    //prompt loop

    while (true) {  

        // chessBoard.printBoard();
        string ans;
        string ans2;
        
        // Board::myMoves move = chessBoard.getMoves() //if I want to get the last move
        
        
        chessBoard.promptMove();
        chessBoard.showMove();

        // string choice_to_move;
        // cout << "Make this move? (y/n) ";
        // cin >> choice_to_move;
        // if (choice_to_move == "y") {
        //     chessBoard.makeMove();
        // }

        // while (true) {
        //     cout << "Show board> (y/n) ";
        //     cin >> ans;
        //     if (ans == "y") {
        //         chessBoard.printBoard();
        //         break;
        //     } else if (ans == "n") {
        //         break;
        //     } else {
        //         cout << "Invalid input, try again.." << endl;
        //     }
        // }

        
        // cout << "Are you making another move? (y/n) ";
        // cin >> ans2;
        // if (ans2 == "n"){
        //     break;
        // }

        
    }


    return 0;
}


