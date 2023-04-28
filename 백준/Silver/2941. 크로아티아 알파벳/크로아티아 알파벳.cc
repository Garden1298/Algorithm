#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> croatia = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

int main() {

	int answer = 0;

	string input;
	cin >> input;

	for (int i = 0; i < croatia.size(); i++) {
		while (true) {
			int index = input.find(croatia[i]);

			if (index == string::npos) {
				break;
			}

			input.replace(index, croatia[i].length(), "*");
		}
	}

	answer = input.length();

	cout << answer << "\n";
}