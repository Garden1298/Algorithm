#include <iostream>
#include <map>

using namespace std;

int N, M;
int num;
map<int, int> m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	// 입력받은 숫자의 값을 하나 더하기
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		m[num]++;
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> num;
		cout << m[num] << " ";
	}
}