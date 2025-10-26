#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;
char c;
int main()
{
	while (true)
	{
		stack<char> s;
		bool work = true;

		getline(cin, str);

		if (str == ".")
		{
			return 0;
		}

		for (int i = 0; i < str.length(); i++)
		{
			c = str[i];

			if (c == '(' || c == '[')
			{
				s.push(c);
			}
			else if (c == ')' || c == ']')
			{
				if (s.empty())
				{
					cout << "no" << endl;
					work = false;
					break;
				}

				char symbol = s.top();
				s.pop();

				if (c == ')')
				{
					if (symbol != '(')
					{
						cout << "no" << endl;
						work = false;
						break;
					}
				}
				else if (c == ']')
				{
					if (symbol != '[')
					{
						cout << "no" << endl;
						work = false;
						break;
					}
				}
			}
		}

		if (work == true)
		{
			if (s.empty())
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
	}
}