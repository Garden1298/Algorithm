#include <iostream>
#include <queue>
using namespace std;

int computerNum, computerPairNum, answer = 0;
int map[101][101] = { 0, };

void bfs(int node) {
	bool visited[101] = { 0, };
	visited[node] = true;

	queue<int> q;
	q.push(node);

	while (!q.empty())
	{
		node = q.front();
		q.pop();

		for (int i = 1; i <= computerNum; i++)
		{
			if (visited[i] == 0 && map[node][i] == 1)
			{
				q.push(i);
				visited[i] = true;
				answer++;
			}
		}
	}

}

int main() {
	
	cin >> computerNum >> computerPairNum;

	//입력받기
	for (int i = 0; i< computerPairNum; i++)
	{
		int comA, comB;

		cin >> comA >> comB;

		map[comA][comB] = 1;
		map[comB][comA] = 1;
	}

	bfs(1);

	cout << answer;
}