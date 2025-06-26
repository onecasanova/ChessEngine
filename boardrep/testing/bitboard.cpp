#include <iostream> 
#include <cstdint>

using namespace std;



typedef uint64_t Bitboard; //make 64 bit variable to represent a set of pieces on the board

int main() {
    Bitboard blackpawns = 0x00FF0000000000;
    //print_bitboard(blackpawns);
    cout << blackpawns << endl;
    return 0;

}


// void print_bitboard(Bitboard bb) {
//     cout << "/nBitboard view/n";
//     for (int rank = 7; rank >=0; rank--) { //top down
//         for (int file = 0; file < 8; file++){
//             int square = rank * 8 + file;
//             if (bb >> square) & 1ULL){
//                 cout << "1";
//             }
//             else {cout << ". "}

//         }    
//     }
//     cout << "A B C D E F G H\n" << endl;
// }


