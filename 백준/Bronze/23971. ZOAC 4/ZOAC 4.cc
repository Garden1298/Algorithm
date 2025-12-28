#include <iostream>
using namespace std;

int main() {
    long long H, W, N, M;
    cin >> H >> W >> N >> M;

    long long rows = (H + N) / (N + 1);
    long long cols = (W + M) / (M + 1);

    cout << rows * cols;
}
