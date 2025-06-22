#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int BusCount, ArriveTime, MAX_TIME = 1000001;
    cin >> BusCount >> ArriveTime;

    int minWait = MAX_TIME;
    for (int i = 0; i < BusCount; ++i) {
        int time, term, Count;
        cin >> time >> term >> Count;

        for (int j = 0; j < Count; ++j) {
            int startTime = time + j * term;
            if (startTime >= ArriveTime) {
                minWait = min(minWait, startTime - ArriveTime);
                break;
            }
        }
    }

    if (minWait == MAX_TIME) {
        cout << -1 << '\n';
    } else {
        cout << minWait << '\n';
    }

    return 0;
}
