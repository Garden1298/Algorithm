#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A;
    while (true) {
        cin >> A;
        if (A == 0) break;

        long long A2 = (long long)pow(A, 2); // A^2
        int cnt = 0;

        for (long long i = 1; i <= A; i++) {
            if (A2 % i == 0) {
                long long sub = i;
                long long sum = A2 / i;

                if ((sum - sub) / 2 > A && (sub - sum) % 2 == 0) {
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
