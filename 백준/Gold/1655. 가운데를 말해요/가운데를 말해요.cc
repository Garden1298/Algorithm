#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct compare {
    bool operator()(int a, int b) 
    {
        return a > b;
    }
};

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int> maxHeap; //중간값 이하의 모든 수를 저장합니다. 여기서 가장 큰 값(루트)이 현재까지의 중간값이 됩니다.
    priority_queue<int, vector<int>, compare> minHeap; //중간값 초과의 모든 수를 저장합니다.

    int N;
    cin >> N;

    while (N--) 
    {
        int num;
        cin >> num;

        //만약 두 힙 크기가 같다면, max heap에 추가하고 그렇지 않으면 min heap에 추가합니다.
        if (maxHeap.size() == minHeap.size())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        // 만약 max heap의 루트 값(현재까지의 중간값)이 min heap의 루트 값보다 크다면, 
        // 잘못된 위치에 있으므로 두 값을 교환(swap)합니다.
        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) 
        {
            int tmpMax = maxHeap.top();
            int tmpMin = minHeap.top();

            maxHeap.pop();
            minHeap.pop();

            maxHeap.push(tmpMin);
            minHeap.push(tmpMax);
        }

        //max heap의 루트 값을 출력합니다.
        cout << maxHeap.top() << "\n";
    }

    return 0;
}