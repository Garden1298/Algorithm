#include <iostream>
using namespace std;

void printLine(int stars, int spaces) {
    for (int i = 0; i < stars; ++i) cout << "*";
    for (int i = 0; i < spaces; ++i) cout << " ";
    for (int i = 0; i < stars; ++i) cout << "*";
    cout << "\n";
}

int main() {
    int N;
    cin >> N;

    for (int i = 1; i < N; ++i) {
        int spaceCount = 2 * (N - i);
        printLine(i, spaceCount);
    }

    for (int i = 0; i < 2 * N; ++i) cout << "*";
    cout << "\n";

    for (int i = N - 1; i >= 1; --i) {
        int spaceCount = 2 * (N - i);
        printLine(i, spaceCount);
    }

    return 0;
}
