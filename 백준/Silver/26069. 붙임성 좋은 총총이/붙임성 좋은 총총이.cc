#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_map<string, bool> chongchongDance;
    chongchongDance["ChongChong"] = true;

    string A, B;
    for (int i = 0; i < N; i++) {
        cin >> A >> B;

        if (chongchongDance[A] == true || chongchongDance[B] == true) {
            chongchongDance[A] = true;
            chongchongDance[B] = true;
        }
    }

    int result = 0;
    for (const auto& pair : chongchongDance) {
        if (pair.second == true) {
            result++;
        }
    }

    cout << result;

    return 0;
}
