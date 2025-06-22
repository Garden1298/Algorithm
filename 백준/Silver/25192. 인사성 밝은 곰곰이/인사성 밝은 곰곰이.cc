#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int recordCount, gomgomCount = 0;
    string input;
    unordered_set<string> nicknames;

    cin >> recordCount;

    for (int i = 0; i < recordCount; ++i) {
        cin >> input;

        if (input == "ENTER") {
            gomgomCount += (int)nicknames.size();
            nicknames.clear();
        } else {
            nicknames.insert(input);
        }
    }

    gomgomCount += (int)nicknames.size();

    cout << gomgomCount << '\n';

    return 0;
}
