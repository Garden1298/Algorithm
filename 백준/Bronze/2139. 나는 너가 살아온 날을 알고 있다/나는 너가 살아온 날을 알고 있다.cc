#include <iostream>
using namespace std;

int main() 
{
    int mArr[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int d, m, y;

    while (1) 
    {
        cin >> d >> m >> y;
        if (d == 0 && m == 0 && y == 0) break;

        int leap = 0;
        if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) leap = 1;

        int total = 0;
        for (int i = 0; i < m; i++) {
            total += mArr[i];
        }
        if (leap && m > 2) total++;

        total += d;
        cout << total << "\n";
    }
    return 0;
}
