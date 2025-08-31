#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    stack<int> s;
    
    for(int num : arr)
    {
        if(s.empty() || s.top() != num)
        {
            s.push(num);
        }
    }
    
    vector<int> result(s.size());
    for(int i = s.size() -1; i >= 0; i--)
    {
        result[i] = s.top();
        s.pop();
    }
    
    

    return result;
}