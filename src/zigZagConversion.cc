// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"


#include <iostream>
#include <vector>
#include <string>

using namespace std;

string convert(string &s, int n) {
    int size = static_cast<int>(s.size());

    if (n == 1 || n >= size) {
        return s;
    }

    vector<string> r(n);

    int row = 0;
    int step = 1;

    for (int i = 0; i < size; ++i) {
        if (row == 0) {
            step = 1;
        }
        if (row == n - 1) {
            step = -1;
        }
        r[row] += s[i];
        row += step;
    }

    string result;
    for (int i = 0; i < n; ++i) {
        result += r[i];
    }

    return result;
}

int main() {
    string s = "PAYPALISHIRING";
    int row = 3;
    cout << s << ": " << convert(s, row) << endl;
    return 0;
}
