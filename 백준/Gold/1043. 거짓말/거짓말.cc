#include <iostream>

using namespace std;

int n, m;
int truth[50];
int party[50][50];
int partyGusetCnt[50];
int result[51] = { 0, };

int Find(int x)
{
	if (x == result[x])
	{
		return x;
	}
	return result[x] = Find(result[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x > y)
	{
		result[x] = y;
	}
	else
	{
		result[y] = x;
	}
}

int main()
{
	cin >> n >> m;

	int truthCnt; // 진실을 알고있는 사람 수
	cin >> truthCnt;

	for (int i = 1; i <= truthCnt; i++)
	{
		cin >> truth[i];
	}

	for (int i = 1; i <= n; i++)
	{
		result[i] = i;
	}

	// 파티 개수
	for (int i = 0; i < m; i++)
	{
		int cnt; // 현재 파티 멤버 수
		cin >> cnt;
		partyGusetCnt[i] = cnt;

		int input;
		int firstGuest = 0; // 첫번째 파티 멤버
		for (int j = 0; j < cnt; j++)
		{
			cin >> input;
			party[i][j] = input;

			if (j == 0)
			{
				firstGuest = input;
			}
		}

		for (int j = 1; j < cnt; j++)
		{
			Union(firstGuest, party[i][j]);
		}
	}

	int answer = 0;
	for (int i = 0; i < m; i++)
	{
		bool skip = false;
		for (int j = 0; j < partyGusetCnt[i]; j++)
		{
			// 진실을 알고있는 사람의 부모 노드와 결과 비교
			for (int k = 0; k < truthCnt; k++)
			{
				//cout << "진실을 알고있는 사람 " << truth[k + 1] << endl;
				//cout << "진실을 알고있는 사람의 부모 노드 " << result[truth[k + 1]] << endl;
				//cout << endl;
				//cout << "현재 파티의 참가자 " << party[i][j] << endl;
				//cout << "현재 파티의 참가자의 부모 노드 " << result[party[i][j]] << endl;
				//cout << endl;

				if(Find(truth[k + 1]) == Find(party[i][j]))
				{
					skip = true;
					break;
				}
			}
		}

		if (skip == false)
		{
			answer += 1;
		}
	}

	cout << answer;
}