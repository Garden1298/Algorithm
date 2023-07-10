#include <iostream>
using namespace std;

int N, M;
int bucket[101] = { 0, };
int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		for (int i = a; i <= b; i++)
		{
			bucket[i - 1] = c;

		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << bucket[i] << " ";
	}
}