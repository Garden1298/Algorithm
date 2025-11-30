#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt;
    cin >> cnt;

    vector<long long> v(cnt);
    for (int i = 0; i < cnt; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    long long N = v.front() * v.back();
    cout << N << "\n";

    return 0;
}
