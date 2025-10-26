#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

	int N;//물건 개수
	int K;//배낭 크기
	int dp[101][100001] = { 0, };
	int W[101] = { 0, };//무개
	int V[101] = { 0, };//가치

int main() {

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> W[i] >> V[i];
	}

	//1부터 k까지
	for (int i = 1; i <= K; i++)//배낭 무개
	{
		for (int j = 1; j <= N; j++)//물건 무개 인덱스
		{
			//담을 수 있으면
			if (W[j] > i)
			{
				dp[j][i] = dp[j - 1][i];
			}
			//담을 수 없으면
			else 
			{
				dp[j][i] = max(dp[j-1][i-W[j]]+V[j], dp[j-1][i]);
			}
		}
	}

	cout << dp[N][K] << endl;
}