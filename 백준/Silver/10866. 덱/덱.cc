#include <iostream>
#include <deque>
using namespace std;

int N;
deque<int> d;

int main()
{
	cin >> N;

	string str = "";
	int num = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> str;

		if (str == "push_front")
		{
			cin >> num;

			d.push_front(num);
		}
		else if (str == "push_back")
		{
			cin >> num;

			d.push_back(num);
		}
		else if (str == "pop_front")
		{
			if (d.empty())
			{
				cout << "-1" << endl;
			}
			else
			{
				num = d.front();
				d.pop_front();

				cout << num << endl;
			}
		}
		else if (str == "pop_back")
		{
			if (d.empty())
			{
				cout << "-1" << endl;
			}
			else
			{
				num = d.back();
				d.pop_back();

				cout << num << endl;
			}
		}
		else if (str == "size")
		{
			cout << d.size() << endl;
		}
		else if (str == "empty")
		{
			if (d.empty())
			{
				cout << "1" << endl;
			}
			else
			{
				cout << "0" << endl;
			}
		}
		else if (str == "front")
		{
			if (d.empty())
			{
				cout << "-1" << endl;
			}
			else
			{
				num = d.front();

				cout << num << endl;
			}
		}
		else if (str == "back")
		{
			if (d.empty())
			{
				cout << "-1" << endl;
			}
			else
			{
				num = d.back();

				cout << num << endl;
			}
		}
	}


}