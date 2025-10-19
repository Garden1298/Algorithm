#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int,int> countMap;
    
    for(int t : tangerine)
    {
        countMap[t]++;
    }
    
    vector<int> counts;
    for(auto& p : countMap)
    {
        counts.push_back(p.second);
    }
    
    sort(counts.begin(), counts.end(), greater<int>());
    
    int answer  = 0;
    for(int c :counts)
    {
        k -= c;
        answer++;
        if(k<=0)
        {
            break;
        }
    }
    
    return answer;
}