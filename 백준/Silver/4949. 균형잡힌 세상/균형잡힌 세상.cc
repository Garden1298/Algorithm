#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;
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

			if (str[i] == '(' || str[i] == '[')
			{
				s.push(str[i]);
			}
			else if (str[i] == ')' || str[i] == ']')
			{
				if (s.empty())
				{
					cout << "no" << endl;
					work = false;
					break;
				}

				char symbol = s.top();
				s.pop();

				if (str[i] == ')')
				{
					if (symbol != '(')
					{
						cout << "no" << endl;
						work = false;
						break;
					}
				}
				else if (str[i] == ']')
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