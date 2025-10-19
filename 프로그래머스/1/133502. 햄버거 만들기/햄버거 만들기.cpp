#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    stack<int> s;
    int answer = 0;
    
    for(int i = 0; i < ingredient.size(); i++)
    {
        s.push(ingredient[i]);
        
        if(s.size() >= 4)
        {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            int c = s.top(); s.pop();
            int d = s.top(); s.pop();
            
            if(a == 1 && b == 3 && c == 2 && d == 1)
            {
                answer++;
            }
            else
            {
                s.push(d);
                s.push(c);
                s.push(b);
                s.push(a);
            }
        }
    }
    return answer;
}