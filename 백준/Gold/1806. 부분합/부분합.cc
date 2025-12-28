#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S;
    cin >> N >> S;

    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int left = 0;
    long long sum = 0;
    int minLength = INT_MAX;

    for (int right = 0; right < N; right++) {
        sum += nums[right];

        while (sum >= S) {
            minLength = min(minLength, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }

    if (minLength == INT_MAX) {
        cout << 0;
    } else {
        cout << minLength;
    }

    return 0;
}
