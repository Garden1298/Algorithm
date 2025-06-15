#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    bool num[10] = {false};
    int numberSize = numbers.size();
    
    for(int i = 0; i<numberSize; i++)
    {
        num[numbers[i]] = true;
    }
    
    for(int i = 0; i<10; i++)
    {
        if(!num[i])
        {
            answer += i;
        }
    }
    
    return answer;
}