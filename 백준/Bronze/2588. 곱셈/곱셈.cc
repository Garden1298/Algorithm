#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a;
	string b;

	cin >> a >> b;

	for (int i = b.size()-1; i >= 0; i--)
	{

		cout << a * (b[i] - '0') << endl;;
	}

	cout << a * stoi(b);
}