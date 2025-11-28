#include <iostream>
using namespace std;

// Helper: print a character 'ch' exactly 'count' times
void printChars(char ch, int count) {
    for (int i = 0; i < count; ++i) {
        cout << ch;
    }
}

void printRow(int row, int maxRow) {
    int leftStars = maxRow + 1 - row;

    if (row == 1) {
        // Special case to match exactly: 11 stars, 3 spaces, 11 stars
        printChars('*', leftStars);
        printChars(' ', 3);
        printChars('*', leftStars);
    } else {
        int midStars = 2 * (row - 1) - 1;
        printChars('*', leftStars);     // left block
        printChars(' ', 2);             // left gap
        printChars('*', midStars);      // middle block
        printChars(' ', 2);             // right gap
        printChars('*', leftStars);     // right block
    }

    cout << '\n';
}

void printDiamond(int row, int maxRow) {
    // Print the current row on the way down
    printRow(row, maxRow);

    // Base case: center row should only print once
    if (row == maxRow) {
        return;
    }

    // Recursive step: go one row deeper
    printDiamond(row + 1, maxRow);

    // Print the same row again on the way back up (mirror)
    printRow(row, maxRow);
}

int main() {
    const int width  = 25;  // total characters per line
    const int maxRow = 11;  // number of "inside" rows above the center

    // Top solid line
    printChars('*', width);
    cout << '\n';

    // Recursive inside part
    printDiamond(1, maxRow);

    // Bottom solid line
    printChars('*', width);
    cout << '\n';

    return 0;
}
