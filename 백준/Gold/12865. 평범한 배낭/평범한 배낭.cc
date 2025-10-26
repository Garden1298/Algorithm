#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int N, K;
    cin >> N >> K;

    vector<int> W(N + 1), V(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> W[i] >> V[i];
    }
        
    // 1차원 DP로 변경
    vector<int> dp(K + 1, 0);

    // 물건 하나씩 처리
    for (int i = 1; i <= N; i++) 
    {
        for (int w = K; w >= W[i]; w--) 
        {
            dp[w] = max(dp[w], dp[w - W[i]] + V[i]);
        }
    }

    cout << dp[K] << endl;
    return 0;
}
