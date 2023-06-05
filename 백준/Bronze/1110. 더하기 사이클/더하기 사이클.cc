#include <iostream>
#include <string>
using namespace std;

int main()
{
	string N;
	cin >> N;

	if (N.length() == 1)
	{
		N = "0" + N;
	}

	int cnt = 0;
	string curN = N;

	int first = N[0] - '0';
	int second = N[1] - '0';

	int answer = first + second;
	string str_answer = to_string(answer);

	curN = to_string(second) + str_answer[str_answer.length() - 1];

	cnt++;

	while (true)
	{
		if (N == curN)
		{
			cout << cnt;
			return 0;
		}

		int first = curN[0]-'0';
		int second = curN[1]-'0';

		int answer = first + second;
		string str_answer = to_string(answer);

		curN = to_string(second) + str_answer[str_answer.length() - 1];

		cnt++;
	}
}