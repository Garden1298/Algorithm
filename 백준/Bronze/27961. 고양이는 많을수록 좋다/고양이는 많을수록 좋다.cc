#include <iostream>
using namespace std;

int main()
{
    long long N, answer = 0, cat = 0;
    cin >> N;
    

    while(cat < N)
    {
        if(cat == 0)
        {
            cat++;
        }
        else
        {
            cat *=2 ;
        }
        
        answer++;
    }
    
    cout << answer << endl;
    return 0;
}