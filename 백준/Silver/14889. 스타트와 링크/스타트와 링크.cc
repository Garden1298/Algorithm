#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int skill[21][21] = { 0, };
int arr[21] = { 0, };
bool isVisted[21] = { false };
int N, teamCnt, answer = 100000;

int Calculate()
{
	int sum1 = 0, sum2 = 0;
	int x, y;

	for (int i = 0; i < teamCnt; i++)
	{
		x = arr[i];

		for (int j = 0; j < teamCnt; j++)
		{
			if (i == j) continue;
			y = arr[j];
			sum1 += skill[x][y];
		}
	}
	for (int i = teamCnt; i < N; i++)
	{
		x = arr[i];
		for (int j = teamCnt; j < N; j++)
		{
			if (i == j) continue;
			y = arr[j];
			sum2 += skill[x][y];
		}
	}
	return abs(sum1 - sum2);
}


void Combination(int index, int depth)
{
	if (depth == teamCnt)
	{
		for (int i = 0; i < N; i++)
		{
			if (!isVisted[i])
			{
				arr[depth] = i;
				depth++;
			}
		}
		answer = min(answer, Calculate());
		return;
	}

	for (int i = index + 1; i < N; i++)
	{
		if (isVisted[i])continue;

		// m=n/2 길이의 조합을 뽑기 위해 dfs에서 다음에 탐색할 index 번호의 조건
		// n - 1 : 숫자 배열의 마지막 index
		// i : 탐색할 번호의 index
		// n - 1 - i : 탐색할 번호 다음에 남은 수들의 개수
		// teamCnt - 1 - depth : 현재 depth 다음 depth에서 앞으로 추가해야할 수들의 개수 (teamCnt = n / 2)
		if ((N - 1 - i) >= (teamCnt - 1 - depth))
		{
			isVisted[i] = true;
			arr[depth] = i;
			Combination(i, depth + 1);
			isVisted[i] = false;
		}
	}
}

int main()
{
	cin >> N;
	teamCnt = N / 2;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> skill[i][j];
		}
	}

	isVisted[0] = true;
	Combination(0, 1);

	cout << answer;

	return 0;
}