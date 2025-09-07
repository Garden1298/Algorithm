#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    if (N == 1) 
    {
        cout << 0 << "\n";
        return 0;
    }

    vector<vector<int>> dp(N, vector<int>(3, 0));
    dp[0][0] = 1;

    for (int i = 0; i < N-1; i++) 
    {
        for (int r = 0; r < 3; r++) 
        {
            int val = dp[i][r];
            if (!val) continue;
            dp[i+1][(r+1)%3] = (dp[i+1][(r+1)%3] + val) % MOD;
            dp[i+1][(r+2)%3] = (dp[i+1][(r+2)%3] + val) % MOD;
        }
    }

    cout << dp[N-1][1] << "\n";
    return 0;
}
