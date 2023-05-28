#include <iostream>
using namespace std;

int R, C, answer = 0;
char board[21][21];
bool alpha[26] = {false,};

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int x, int y, int cnt)
{
	answer = answer > cnt ? answer : cnt;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		int alphabet = board[nx][ny] - 'A';

		if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
		if (alpha[alphabet]) continue;

		alpha[alphabet] = true;
		dfs(nx, ny, cnt + 1);
		alpha[alphabet] = false;
	}
}


int main()
{
	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];
		}
	}

	alpha[board[0][0]-'A'] = "true";

	dfs(0, 0, 1);

	cout << answer;
}