#include <iostream>
#include <string>
#include <stack>
using namespace std;

string input, output;
stack<char> temp;

void ReverseOutput()
{
	if (!temp.empty())
	{
		while (true)
		{
			if (temp.empty()) break;
			output += temp.top();
			temp.pop();
		}
	}
}

int main()
{
	getline(cin, input);

	for (int i = 0; i < input.size(); i++)
	{

		// '<'라면 '>'를 만날때까지 문자 출력
		if (input[i] == '<')
		{
			ReverseOutput();
			while (true)
			{
				output += input[i];
				if (input[i] == '>') break;
				i++;
			}
		}
		else
		{
			temp.push(input[i]);
			if (input[i] == ' ')
			{
				temp.pop();

				ReverseOutput();

				output += ' ';
			}
		}
	}

	if (!temp.empty())
	{
		ReverseOutput();
	}

	cout << output;
}