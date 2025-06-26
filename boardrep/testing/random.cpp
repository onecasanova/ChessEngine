#include <iostream>
#include <string>

using namespace std;

int main() {
    string S = "e7";
    char s = std::toupper(S[0]);
    int r0 = s - 'A';
    int r = S[1] - '0';

    cout << "Move is " << S << endl;
    cout << "Board coordinates are (" << r0 << ", " << r << ")" << endl;
    

}
