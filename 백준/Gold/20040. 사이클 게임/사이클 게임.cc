#include <iostream>

using namespace std;

int arr[500000];
int n, m;
int answer = 0;

/// <summary>
/// 찾기
/// x가 속한 집합의 대표값(루트 노드 값)을 반환한다.
/// x가 어떤 집합에 속해 있는지 찾는 연산
/// </summary>
int Find(int x)
{
	if (arr[x] == x)
	{
		return x;
	}
	else
	{
		return Find(arr[x]);
	}
}

/// <summary>
/// 합하기
/// x가 속한 집합과 y가 속한 집합을 합친다.
/// x와 y가 어떤 집합에 속해 있는지 찾는 연산
/// </summary>
bool Union(int x, int y)
{

	x = Find(x);
	y = Find(y);

	if (x == y)
	{
		return true;
	}

	arr[y] = x;

	return false;
}

int main()
{
	cin >> n >> m;

	//초기화
	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		if (Union(a, b))
		{
			answer = i;
			break;
		}
	}

	if (answer == 0)
	{
		cout << "0";
	}
	else
	{

		cout << answer + 1;
	}
}