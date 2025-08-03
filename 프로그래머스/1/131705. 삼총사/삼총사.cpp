#include <string>
#include <vector>

using namespace std;

int total, pick = 3, answer = 0;
vector<int> numbers;

void Combination(int lastIdx, vector<int>& currentCombi)
{
    if(currentCombi.size() == pick)
    {
        int addResult = 0;
        for(int val : currentCombi)
        {
            addResult+=val;
        }
        if(addResult == 0)
        {
            answer++;
        }
        return;
    }
    
    for(int nextIdx = lastIdx +1; nextIdx < total; nextIdx++)
    {
        currentCombi.push_back(numbers[nextIdx]);
        Combination(nextIdx, currentCombi);
        currentCombi.pop_back();
    }
}

int solution(vector<int> number) {
    numbers = number;
    total = number.size();
    vector<int> combi;
    Combination(-1, combi);
    return answer;
}