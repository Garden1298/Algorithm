#include <iostream>
#include <vector>

using namespace std;

int workTime[1001];
int money[1001];
int dp[1001];

int main()
{
	int N;

	cin >> N;

	int inputTime, intputMoney;
	for (int i = 1; i <= N; i++)
	{
		cin >> inputTime >> intputMoney;
		workTime[i] = inputTime;
		money[i] = intputMoney;
	}

	for (int i = N; i > 0; i--)
	{
		int curWorkTime = i + workTime[i];

		if (curWorkTime > N + 1) // 일할 수 없다.
		{
			dp[i] = dp[i + 1];
		}
		else // 일할 수 있다.
		{
			if (dp[i + 1] > dp[curWorkTime] + money[i])
			{
				dp[i] = dp[i + 1];
			}
			else
			{
				dp[i] = dp[curWorkTime] + money[i];
			}
		}
	}

	cout << dp[1] << endl;

}