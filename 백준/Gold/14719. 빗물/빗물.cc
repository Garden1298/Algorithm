#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    int height[501];
    for (int i = 0; i < W; i++)
    {
        cin >> height[i];
    }

    int answer = 0;

    // 양 끝은 물이 고일 수 없음
    for (int i = 1; i < W - 1; i++)
    {
        int leftMax = 0;
        int rightMax = 0;

        // 왼쪽 최대 높이
        for (int l = 0; l < i; l++)
        {
            leftMax = max(leftMax, height[l]);
        }

        // 오른쪽 최대 높이
        for (int r = i + 1; r < W; r++)
        {
            rightMax = max(rightMax, height[r]);
        }

        int water = min(leftMax, rightMax) - height[i];
        if (water > 0)
        {
            answer += water;
        }
    }

    cout << answer << endl;
}
