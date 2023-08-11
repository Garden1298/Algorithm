#include <iostream>
#include <stdio.h>
//#include <iomanip>

using namespace std;

int main()
{
	double A, B;
	double answer;

	cin >> A >> B;

	answer = A / B;

	//cout << setprecision(20);
	//cout << answer;

	printf("%.10f\n", answer);
}