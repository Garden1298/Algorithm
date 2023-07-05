#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	map<string, pair<int, int>> color = { { "black",{0,1}},{"brown",{1,10}},{ "red",{ 2,100 } },
										 { "orange",{ 3,1000 } },{ "yellow",{ 4,10000 } },{ "green",{ 5,100000 } },
										 { "blue",{ 6,1000000 } },{ "violet",{ 7,10000000 } },
										 { "grey",{ 8,100000000 } },{ "white",{ 9,1000000000 } } };

	string a, b, c;
	cin >> a >> b >> c;

	string color1 = to_string(color[a].first);
	string color2 = to_string(color[b].first);
	long color3 = color[c].second;

	long long answer = stoi(color1 + color2) * color3;

	cout << answer;
}