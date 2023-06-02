#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int answer = 0;
	int number = 0;
	string str_number = "";
	int cnt = 1;

	while (true)
	{
		number++;
		str_number = to_string(number);

		if (str_number.find("666")!=string::npos)
		{
			answer++;
		}

		if (answer == N) break;
	}

	cout << str_number;
}