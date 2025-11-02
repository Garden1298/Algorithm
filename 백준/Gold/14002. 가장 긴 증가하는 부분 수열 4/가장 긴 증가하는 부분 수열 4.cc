#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i)
        cin >> nums[i];

    vector<int> lis;  // LIS 후보
    vector<int> dp(N); // 각 원소가 LIS 상 몇 번째 위치인지 저장

    for (int i = 0; i < N; ++i) {
        auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
        int pos = it - lis.begin();

        if (it == lis.end()) lis.push_back(nums[i]);
        else *it = nums[i];

        dp[i] = pos;
    }

    // LIS 길이
    int lisLength = lis.size();

    // 역추적
    vector<int> answer;
    for (int i = N - 1; i >= 0; --i) {
        if (dp[i] == lisLength - 1) {
            answer.push_back(nums[i]);
            lisLength--;
        }
    }

    reverse(answer.begin(), answer.end());

    cout << answer.size() << '\n';
    for (int x : answer) cout << x << ' ';
}
