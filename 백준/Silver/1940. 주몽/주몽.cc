#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m;

    vector<int> input_ar(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> input_ar[i];
    }

    sort(input_ar.begin(), input_ar.end());

    int left = 0;
    int right = n - 1;
    int cnt = 0;

    while (left < right) 
    {
        int sum = input_ar[left] + input_ar[right];
        if (sum == m) 
        {
            cnt++;
            left++;
            right--;
        } else if (sum < m) 
        {
            left++;
        } else 
        {
            right--;
        }
    }

    cout << cnt;
}
