#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    char game;
    cin >> N >> game;

    unordered_set<string> people;
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        people.insert(name);
    }

    int need;
    if (game == 'Y') need = 1;
    else if (game == 'F') need = 2;
    else need = 3; // 'O'

    cout << people.size() / need;
}
