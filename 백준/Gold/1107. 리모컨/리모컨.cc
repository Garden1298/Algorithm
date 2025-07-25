// https://yjios.tistory.com/8 참고
// 1. 이 채널에 고장난 버튼이 들어가지 않는지 확인
// 2. 이 채널에 가는 데 필요한 버튼 클릭 수와 최솟값을 비교

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> dp;
vector<bool> button(10, false);

bool check(int now) {

    string s = to_string(now);

    for (int i = 0; i < s.length(); i++) 
    {
        // 멀쩡한 버튼이라면 false 리턴
        if (button[s[i] - 48]) 
        {
            return false;
        }
    }

    // 고장난 버튼이라면 true 리턴
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 이동하려고 하는 채널 N (0 ≤ N ≤ 500,000), 고장난 버튼의 개수 M (0 ≤ M ≤ 10)
    int n, m;
    cin >> n >> m;

    int input;

    for (int i = 0; i < m; i++) 
    {
        cin >> input;
        button[input] = true;
    }

    // int -> string
    string st = to_string(n);

    // +/- 버튼만으로 채널 이동하는 횟수
    int minimum = abs(n - 100);

    for (int i = 0; i <= 1000000; i++) 
    {
        if (check(i)) 
        {
            int tmp = abs(n - i) + to_string(i).length();
            minimum = min(minimum, tmp);
        }
    }

    cout << minimum << endl;

    return 0;
}