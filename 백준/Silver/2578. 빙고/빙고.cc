#include <iostream>

using namespace std;

int table[5][5];

void solve(int d)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (d == table[i][j])
			{
				table[i][j] = 0;
				break;
			}
		}
	}
}

bool verify() {

	//가로
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		int sum = 0;

		for (int j = 0; j < 5; j++)
		{
			sum += table[i][j];
		}

		if (sum == 0)
		{
			count++;
		}
	}

	//세로
	for (int i = 0; i < 5; i++)
	{
		int sum = 0;

		for (int j = 0; j < 5; j++)
		{
			sum += table[j][i];
		}

		if (sum == 0)
		{
			count++;
		}
	}

	//대각선
	int cand = 0;
	for (int i = 0; i < 5; i++)
	{
		cand += table[i][i];
	}

	if (cand == 0)
	{
		count++;
	}

	//대각선
	cand = 0;
	for (int i = 0; i < 5; i++)
	{
		cand += table[0 + i][5 - 1 - i];
	}

	if (cand == 0) {
		count++;
	}

	//빙고 3개 이상인지 체크
	if (count >= 3) {
		return true;
	}

	return false;
}

int main() {


	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> table[i][j];
		}
	}

	int sol = 0;
	for (int i = 0; i < 25; i++) 
	{
		int cand; 
		cin >> cand;
		solve(cand);
		if (verify()) 
		{
			cout << i + 1;
			break;
		}
	}
	return 0;
}
