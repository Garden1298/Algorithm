#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
vector<vector<bool>> visited;
vector<vector<int>> grid;
int n, m;

int dfs(int x, int y)
{
    visited[x][y] = true;
    int sum = grid[x][y];
    grid[x][y] = -1;
    
    for(int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        
        if(!visited[nx][ny] && grid[nx][ny] != -1)
        {
            sum += dfs(nx, ny);
        }
    }
    
    return sum;
}

vector<int> solution(vector<string> maps) 
{
    for(const string& str : maps)
    {
        vector<int> gridchar;
        for(char ch : str)
        {
            if(ch == 'X')
            {
                gridchar.push_back(-1);
            }
            else
            {
                gridchar.push_back(ch - '0');
            }
        }
        grid.push_back(gridchar);
    }
    
    
    n = grid.size();
    m = grid[0].size();
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    vector<int> answer;
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(!visited[i][j] && grid[i][j] != -1)
            {
                answer.push_back(dfs(i,j));
            }
        }
    }

    if(answer.size() > 0)
    {
        sort(answer.begin(), answer.end());
        return answer;
    }
    else
    {
        answer.push_back(-1);
        return answer;
    }
}