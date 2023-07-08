#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int N, K, L;
int map[101][101] = { 0, };
deque<pair<int, int>> snake; // x좌표, y좌표
queue<pair<int, char>> change; // 방향 바꾸는 시간, 좌표
int curTime = 0;
int x = 0, y = 0;

int dir = 0;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void print()
{
	cout << ":::::::::::::::::::" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << ":::::::::::::::::::" << endl;
}

int main()
{
	cin >> N >> K;

	//사과 정보 넣기
	int ax, ay;
	for (int i = 0; i < K; i++)
	{
		cin >> ax >> ay;
		map[ax - 1][ay - 1] = 1;
	}

	cin >> L;

	//방향 전환 정보 넣기
	int ctime;
	char direction;
	for (int i = 0; i < L; i++)
	{
		cin >> ctime >> direction;
		change.push(make_pair(ctime, direction));
	}

	snake.push_back(make_pair(0, 0));
	map[0][0] = 2;

	while (true)
	{
		curTime++;
		//cout << "순서: " << curTime << endl;

		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) // 맵이 아닐때
		{
			//cout << "게임 오버 : 맵 밖으로 나감" << endl;
			break;
		}

		if (map[nx][ny] == 0) // 빈 맵 일때
		{
			map[nx][ny] = 2; //머리 이동
			snake.push_front(make_pair(nx, ny));// 뱀 머리 추가
			map[snake.back().first][snake.back().second] = 0; // 맵에서 꼬리 삭제
			snake.pop_back();// 뱀에서 꼬리 삭제
		}
		else if (map[nx][ny] == 1) // 사과 일때
		{
			//cout << "사과 먹음" << endl;
			map[nx][ny] = 2; //머리 이동
			snake.push_front(make_pair(nx, ny));// 뱀 머리 추가
		}
		else if (map[nx][ny] == 2) // 뱀의 몸통일때
		{
			//cout << "게임 오버 : 뱀의 몸에 부딪힘" << endl;
			break;
		}

		if (change.size() == 0) {}
		else if (curTime == change.front().first)
		{
			//cout << "방향 바꿈" << endl;

			char direction = change.front().second;
			change.pop();

			if (direction == 'L') // 왼쪽으로 돌기
			{
				if (dir == 0) dir = 2;
				else if (dir == 1) dir = 3;
				else if (dir == 2) dir = 1;
				else if (dir == 3) dir = 0;
			}
			else if (direction == 'D') // 오른쪽으로 돌기
			{
				if (dir == 0) dir = 3;
				else if (dir == 1) dir = 2;
				else if (dir == 2) dir = 0;
				else if (dir == 3) dir = 1;
			}
		}

		x = nx;
		y = ny;
		//print();
	}

	cout << curTime << endl;

}