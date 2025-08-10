#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int deptCount;
    cin >> deptCount;

    long long totalSum = 0;
    long long deptTimes[1000] = {};

    for (int dept = 0; dept < deptCount; ++dept) 
    {
        int memberCount;
        cin >> memberCount;
        while (memberCount--) 
        {
            int interviewTime;
            cin >> interviewTime;
            deptTimes[dept] += interviewTime;
        }
    }

    sort(deptTimes, deptTimes + deptCount);

    for (int i = 1; i < deptCount; ++i) 
    {
        deptTimes[i] += deptTimes[i - 1];
    }

    for (int i = 0; i < deptCount; ++i) 
    {
        totalSum += deptTimes[i];
    }

    cout << totalSum << "\n";
    return 0;
}
