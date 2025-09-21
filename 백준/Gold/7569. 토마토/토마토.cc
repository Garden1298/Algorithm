#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int main()
{
    int m, n, h;
    cin >> m >> n >> h;

    vector<vector<vector<int>>> graph(h, vector<vector<int>>(n, vector<int>(m)));
    queue<tuple<int, int, int, int>> q;  // (x, y, z, day)

    int unripeCount = 0;

    for (int z = 0; z < h; ++z)
    {
        for (int y = 0; y < n; ++y)
        {
            for (int x = 0; x < m; ++x)
            {
                cin >> graph[z][y][x];
                if (graph[z][y][x] == 1)
                {
                    q.emplace(x, y, z, 0);
                }
                else if (graph[z][y][x] == 0)
                {
                    unripeCount++;
                }
            }
        }
    }

    if (unripeCount == 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    int result = 0;

    while (!q.empty())
    {
        auto [x, y, z, day] = q.front();
        q.pop();
        result = day;

        for (int i = 0; i < 6; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && nz >= 0 && nz < h)
            {
                if (graph[nz][ny][nx] == 0)
                {
                    graph[nz][ny][nx] = 1;
                    q.emplace(nx, ny, nz, day + 1);
                }
            }
        }
    }

    for (int z = 0; z < h; ++z)
    {
        for (int y = 0; y < n; ++y)
        {
            for (int x = 0; x < m; ++x)
            {
                if (graph[z][y][x] == 0)
                {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }

    cout << result << '\n';
    return 0;
}
