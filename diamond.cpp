#include <iostream>
using namespace std;

/*
    Recursive Diamond Pattern
    -------------------------
    This function prints a single line of the diamond.
    It receives the current row and total size as parameters.

    Logic:
    1. Print left stars      → (size - row)
    2. Print left spaces     → (row * 2 - 1)
    3. Print middle stars    → 1
    4. Print right spaces    → (row * 2 - 1)
    5. Print right stars     → (size - row)

    Recursion reduces & then increases row count, forming symmetry.
*/

void printDiamond(int row, int size) {

    // BASE CASE – when row passes size, stop
    if (row > size) return;

    // Print left stars
    for (int i = 0; i < size - row; i++)
        cout << "*";

    // Print left gap
    for (int i = 0; i < row * 2 - 1; i++)
        cout << " ";

    // Print middle star
    cout << "*";

    // Print right gap
    for (int i = 0; i < row * 2 - 1; i++)
        cout << " ";

    // Print right stars
    for (int i = 0; i < size - row; i++)
        cout << "*";

    cout << endl;

    // Recursive call (DOWNWARD half)
    printDiamond(row + 1, size);

    // Print bottom half on **unwinding**
    for (int i = 0; i < size - row; i++)
        cout << "*";

    for (int i = 0; i < row * 2 - 1; i++)
        cout << " ";

    cout << "*";

    for (int i = 0; i < row * 2 - 1; i++)
        cout << " ";

    for (int i = 0; i < size - row; i++)
        cout << "*";

    cout << endl;
}

int main() {
    int size = 11;  // 11 → prints 23 total rows, matching assignment requirement
    printDiamond(1, size);
    return 0;
}
