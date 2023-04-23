#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, temp;
priority_queue<int, vector<int>, greater<int>> q;

int main() 
{
    ios::sync_with_stdio();
    cin.tie(NULL);

    cin >> N;

    while (N--) {
        cin >> temp;

        if (temp == 0) {
            if (q.size() == 0)
                cout << "0\n";
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else {
            q.push(temp);
        }
    }
}