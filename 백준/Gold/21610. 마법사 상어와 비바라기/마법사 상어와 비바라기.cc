#include <iostream>
#include <queue>
using namespace std;

int N, M;
int A[51][51];
int dx[9] = { 0, 0,-1,-1,-1,0,1,1,1 };
int dy[9] = { 0,-1,-1,0,1,1,1,0,-1 };

queue<pair<int, int>> cloud;

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> A[i][j];

    cloud.push({N, 1});
    cloud.push({N, 2});
    cloud.push({N - 1, 1});
    cloud.push({N - 1, 2});

    while (M--) {
        int d, s;
        cin >> d >> s;

        bool visited[51][51] = { false, };
        queue<pair<int, int>> moved;

        int size = cloud.size();
        while (size--) {
            auto [x, y] = cloud.front();
            cloud.pop();

            int nx = ((x - 1 + dx[d] * s) % N + N) % N + 1;
            int ny = ((y - 1 + dy[d] * s) % N + N) % N + 1;

            A[nx][ny]++;
            visited[nx][ny] = true;
            moved.push({nx, ny});
        }

        // 물복사 버그
        while (!moved.empty()) {
            auto [x, y] = moved.front(); moved.pop();

            int cnt = 0;
            for (int k = 2; k <= 8; k += 2) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
                if (A[nx][ny] > 0) cnt++;
            }
            A[x][y] += cnt;
        }

        // 새 구름 생성
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (!visited[i][j] && A[i][j] >= 2) {
                    cloud.push({i, j});
                    A[i][j] -= 2;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            ans += A[i][j];

    cout << ans;
}
