#include <iostream>

using namespace std;

int Dday, loseAmount, weight = 500, answer = 0;
int arr[8], workKit[8];
bool isVisited[8];

void Calculate()
{
	int curWeight = 500;
	for (int i = 0; i < Dday; i++)
	{
		curWeight = curWeight - loseAmount + workKit[arr[i]-1];

		if (curWeight < weight)
		{
			return;
		}
	}
	answer++;
}

void Perm(int depth)
{
	if (depth == Dday)
	{
		Calculate();

		return;
	}

	for (int i = 1; i <= Dday; i++)
	{
		if (!isVisited[i])
		{
			isVisited[i] = true;
			arr[depth] = i;
			Perm(depth + 1);
			isVisited[i] = false;
		}
	}
}

int main()
{
	cin >> Dday >> loseAmount;

	for (int i = 0; i < Dday; i++)
	{
		cin >> workKit[i];
	}

	Perm(0);

	cout << answer;

	return 0;
}