#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;

    vector<int> visit(N+1, 0); // 0:스티커 없음, 1:있음, 2:제거됨
    int currentSticker= 0;
    int maxSticker = 0;

    for(int i = 0; i<N*2; ++i)
    {
        int menu;
        cin>>menu;

        visit[menu]++;

        if(visit[menu]==1)
        {
            currentSticker++;
            maxSticker = max(maxSticker, currentSticker);
        }
        else if (visit[menu]==2)
        {
            currentSticker--;
        }
    }

    cout<<maxSticker<<endl;
}