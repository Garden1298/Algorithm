#include <iostream>
#include <deque>
#include <vector>

using namespace std;
int input[1000000];

int main()
{
	int N;
	deque<int>card;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
	}

	int index = 1;
	for (int i = N-1; i >= 0; i--)
	{
		int curInput = input[i];

		if (curInput == 1)
		{
			card.push_back(index);
		}
		else if (curInput == 2)
		{
			int firstCard = card.back();
			card.pop_back();
			card.push_back(index);
			card.push_back(firstCard);
		}
		else
		{
			card.push_front(index);
		}
		index++;
	}

	for (int i = N - 1; i >= 0; i--)
	{
		cout << card[i] << " ";
	}
}