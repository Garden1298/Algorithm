#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;//동전의 종류
	int K;//가치의 합
	int answer = 0;
	int coin[10];//동전의 가치

	cin >> N >> K;

	
	for (int i = 0; i < N; i++)
	{
		cin >> coin[i];
	}

	for (int i = N - 1; i >= 0; i--)
	{
		if (coin[i] <= K)
		{
			answer = answer + K / coin[i];
			K = K % coin[i];
		}
		if (K == 0) break;
	}

	cout << answer << endl;
}