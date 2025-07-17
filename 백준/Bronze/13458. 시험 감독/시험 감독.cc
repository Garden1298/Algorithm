#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> student(N);
    for (int i = 0; i < N; ++i) {
        cin >> student[i];
    }

    int B, C;
    cin >> B >> C;

    long long totalTeacher = 0;

    for (int i = 0; i < N; ++i) {
        totalTeacher += 1;
        int remaining = student[i] - B;

        if (remaining > 0) {
            totalTeacher += (remaining + C - 1) / C;
        }
    }

    cout << totalTeacher << '\n';
    return 0;
}