#include <iostream>
using namespace std;

void printLine(int spaceCount, int starCount) {
    for (int i = 0; i < spaceCount; ++i) cout << " ";
    for (int i = 0; i < starCount; ++i) cout << "*";
    cout << "\n";
}

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        int spaceCount = N - i;
        int starCount = 2 * i - 1;
        printLine(spaceCount, starCount);
    }

    for (int i = N - 1; i >= 1; --i) {
        int spaceCount = N - i;
        int starCount = 2 * i - 1;
        printLine(spaceCount, starCount);
    }

    return 0;
}
