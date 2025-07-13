#include <iostream>
#include <climits>

using namespace std;

int arr[31][11];
int n, m, h;
int ans = INT_MAX;

bool check() 
{
	for (int i = 1; i <= n; i++) 
	{
		int start = i;
		for (int j = 1; j <= h; j++)
		{
			if (arr[j][start])
            {
                start++;
            }
            else if (arr[j][start-1])
            {
                start--;
            }
		}
		if (start != i) 
        {
            return false;
        }
	}
	return true;
}

void DFS(int count, int x, int y) 
{
    if(count >= ans)
    {
        return;
    }

	if (check())
	{
		ans = count;
		return;
	}
    
    if(count == 3)
    {
        return;
    }
    
		for (int i = x; i <= h; i++) 
		{
			for (int j = (i==x?y:1); j < n; j++) 
			{
				if (arr[i][j - 1] || arr[i][j] || arr[i][j + 1]) continue;
                
					arr[i][j] = 1;
					DFS(count + 1, i, j+2);
					arr[i][j] = 0;
			}
		}
	

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> h;

	int a, b;
	for (int i = 0; i < m; i++) 
	{
		cin >> a >> b;
		arr[a][b] = true;
	}

	DFS(0, 1, 1);

	if (ans <= 3) 
	{
		cout << ans << '\n';
	}
	else 
	{
		cout << -1 << '\n';
	}

	return 0;
}