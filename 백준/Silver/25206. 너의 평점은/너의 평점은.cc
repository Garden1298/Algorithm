#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <iomanip>

using namespace std;

map<string, float> m;
string str;
double answer = 0;
float sum = 0;

int main()
{
	m.insert(make_pair("A+", 4.5));
	m.insert(make_pair("A0", 4.0));
	m.insert(make_pair("B+", 3.5));
	m.insert(make_pair("B0", 3.0));
	m.insert(make_pair("C+", 2.5));
	m.insert(make_pair("C0", 2.0));
	m.insert(make_pair("D+", 1.5));
	m.insert(make_pair("D0", 1.0));
	m.insert(make_pair("F", 0.0));

	for (int i = 0; i < 20; i++)
	{
		getline(cin, str);

		stringstream ss(str);

		string name, amount, score;

		ss >> name>> amount>> score;

		if (score != "P")
		{
			answer += (stoi(amount) * m[score]);
			sum += stoi(amount);
		}
	}

	answer = answer / sum;

	cout << setprecision(9);
	cout << answer;
}