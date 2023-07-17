#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int N;

int main()
{
	cin >> N;

	string command = "";
	int num = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> command;

		if (command == "push")
		{
			cin >> num;
			q.push(num);
		}
		else if (command == "pop")
		{
			if (q.empty())
			{
				cout << "-1" << endl;
			}
			else
			{
				num = q.front();
				q.pop();
				cout << num << endl;
			}
		}
		else if (command == "size")
		{
			cout << q.size() << endl;
		}
		else if (command == "empty")
		{
			if (q.empty())
			{
				cout << "1" << endl;
			}
			else
			{
				cout << "0" << endl;
			}
		}
		else if (command == "front")
		{
			if (q.empty())
			{
				cout << "-1" << endl;
			}
			else
			{
				cout << q.front() << endl;
			}
		}
		else if (command == "back")
		{
			if (q.empty())
			{
				cout << "-1" << endl;
			}
			else
			{
				cout << q.back() << endl;
			}
		}
	}
}